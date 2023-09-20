#include "sql.h"

int main()
{
        std::string link = "host=127.0.0.1 port=5432 dbname=Task_5 user=postgres password=248650";
        SQL a(link);

        a.create_tables();

        a.add_data("Andrey", "Ivanov", "AIvanov@mail.ru", "89201112233");
        a.add_data("Dmitry", "Petrov", "DPetrov@mail.ru", "89534445566");
        a.add_data("Sergey", "Sidorov", "SSidorov@mail.ru", "89157778899");
      
        a.add_phone("Andrey", "79150001010");
        a.add_phone("Dmitry", "79181110202");
                      
        a.update_data("SSidorov@mail.ru", "Sergey", "Sidorov_2", "S@mail.ru");
       
        a.delete_phone("DPetrov@mail.ru", "89658756541");
        a.delete_data("DPetrov@mail.ru");

        std::vector<Data> foundClients = a.select_data("Sergey");
        for (const auto& client : foundClients)
        {
            std::cout << "Найден клиент: " << client.data_name << " " << client.data_surname << " " << client.data_email << " " << std::endl;
        }

};
