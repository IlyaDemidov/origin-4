#include "sql.h"

SQL::SQL(const std::string& connection) : link{ connection } { };

void SQL::create_tables()
{
    
    
        pqxx::work txn(link);
        txn.exec(R"(CREATE TABLE IF NOT EXISTS clients(id SERIAL PRIMARY KEY, name TEXT, surname TEXT, email TEXT UNIQUE);  
            CREATE TABLE IF NOT EXISTS phones(id SERIAL PRIMARY KEY, client_id INT REFERENCES clients(id), phone TEXT UNIQUE);)");
        txn.commit();
    
}

void SQL::add_data(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone)
{
        pqxx::work txn(link);
        link.set_client_encoding("UTF8");
        pqxx::result res = txn.exec_params("INSERT INTO clients (name, surname, email) VALUES ($1, $2, $3) RETURNING id", name, surname, email);
        if (!res.empty())
        {
            int client_id = res[0][0].as<int>();
            txn.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2);", client_id, phone);
            txn.commit();
        }
        else
        {
            txn.abort();
            std::cerr << "Не удалось добавить клиента" << std::endl;
        }
    
}

void SQL::add_phone(const std::string& name, const std::string& phone)
{
    pqxx::work txn(link);
    pqxx::result res = txn.exec_params("SELECT id, surname FROM clients WHERE name = $1", name);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        txn.exec_params("INSERT INTO phones (client_id, phone) VALUES ($1, $2)", client_id, phone);

        std::string client_surname = res[0][1].as<std::string>();
        txn.commit();
    }
    else
    {
        txn.abort();
        std::cerr << "Клиент не найден: " << name << std::endl;
    }
}

void SQL::update_data(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail)
{
    pqxx::work txn(link);
    pqxx::result res = txn.exec_params("SELECT id FROM clients WHERE email = $1", email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        txn.exec_params(R"(UPDATE clients SET name = $1, surname = $2, email = $3 WHERE id = $4)", newName, newSurname, newEmail, client_id);
        txn.commit();
    }
    else
    {
        txn.abort();
        std::cerr << "Клиент не найден: " << newName << std::endl;
    }
}

void SQL::delete_phone(const std::string& email, const std::string& phone)
{
    pqxx::work txn(link);
    pqxx::result res = txn.exec_params("SELECT id, name, surname FROM clients WHERE email = $1", email);
    if (!res.empty())
    {
        int client_id = res[0][0].as<int>();
        txn.exec_params("DELETE FROM phones WHERE client_id = $1 AND phone = $2", client_id, phone);
        txn.commit();
        std::string client_name = res[0][1].as<std::string>();
        std::string client_surname = res[0][2].as<std::string>();
    }
    else
    {
        txn.abort();
        std::cerr << "Клиент не найден: " << email << std::endl;
    }
}

void SQL::delete_data(const std::string& email)
{
    pqxx::work txn(link);
    pqxx::result res = txn.exec_params("SELECT id, name, surname FROM clients WHERE email = $1", email);
    if (!res.empty()) {
        int client_id = res[0][0].as<int>();
        std::string client_name = res[0][1].as<std::string>();
        std::string client_surname = res[0][2].as<std::string>();
        txn.exec_params("DELETE FROM phones WHERE client_id = $1", client_id);
        txn.exec_params("DELETE FROM clients WHERE id = $1", client_id);
        txn.commit();
    }
    else {
        txn.abort();
        std::cerr << "Клиент не найден: " << email << std::endl;
    }
}

std::vector<Data> SQL::select_data(const std::string& query)
{
    std::vector<Data> result;
    pqxx::work txn(link);
    pqxx::result res = txn.exec_params(
        "SELECT * "
        "FROM clients "
        "LEFT JOIN public.phones on public.clients.id = public.phones.client_id "
        "WHERE clients.name = $1 OR clients.surname = $1 OR clients.email = $1 OR phones.phone = $1;", query);
    txn.commit();
    for (auto row : res) {
        Data client;
        client.data_name = row["name"].as<std::string>();
        client.data_surname = row["surname"].as<std::string>();
        client.data_email = row["email"].as<std::string>();
        result.push_back(client);
    }
    return result;
}