#pragma once

#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <string>
#include <codecvt>

struct Data
{
	std::string data_name;
	std::string data_surname;
	std::string data_email;
	std::vector<std::string> data_phones;
};

class SQL
{
private:
	pqxx::connection link;

public:
	SQL(const std::string& connection);

	void create_tables();
	void add_data(const std::string& name, const std::string& surname, const std::string& email, const std::string& phone);
	void add_phone(const std::string& name, const std::string& phone);
	void update_data(const std::string& email, const std::string& newName, const std::string& newSurname, const std::string& newEmail);
	void delete_phone(const std::string& email, const std::string& phone);
	void delete_data(const std::string& email);

	std::vector<Data> select_data(const std::string& query);

};