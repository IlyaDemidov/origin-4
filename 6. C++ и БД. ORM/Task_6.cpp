#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <Windows.h>

#include "Wt/Dbo/Dbo.h"
#include "Wt/Dbo/backend/Postgres.h"

#include "Task_6.h"


void findShop(Wt::Dbo::Session& s, std::string namePublisher) 
{
	Wt::Dbo::ptr<Publisher> findPublisher = s.find<Publisher>().where("name = ?").bind(namePublisher);
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books = s.find<Book>().where("publisher_id = ?").bind(findPublisher);
	std::vector<Wt::Dbo::collection<Wt::Dbo::ptr<Stock>>> stocks;
	for (const auto& id : books) 
	{
		stocks.push_back(s.find<Stock>().where("book_id = ?").bind(id.id()));
	}
	std::vector<Wt::Dbo::collection<Wt::Dbo::ptr<Shop>>> shops;
	for (const auto& col : stocks) 
	{
		for (const auto& id : col) 
		{
			shops.push_back(s.find<Shop>().where("id = ?").bind(id->shop));
		}
	}
	std::cout << "Shops with books by this publisher " << namePublisher << ": \n";
	std::set<std::string> names;
	for (const auto& col : shops) 
	{
		for (const auto& id : col) 
		{
			names.insert(id->name);
		}
	}
	for (const auto& name : names) 
	{
		std::cout << name << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	try {
		std::string connection = "host=localhost port=5432 dbname=Task_6 user=postgres password=248650";
			
		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connection);
		
		Wt::Dbo::Session s;

		s.setConnection(std::move(postgres));
		s.mapClass<Publisher>("publisher");
		s.mapClass<Book>("book");
		s.mapClass<Shop>("shop");
		s.mapClass<Stock>("stock");
		s.mapClass<Sale>("sale");
		
		try 
		{
			s.createTables();
		}
		catch (const Wt::Dbo::Exception& ex) {
			std::cout << ex.what() << std::endl;
		}

		Wt::Dbo::Transaction tx(s);


		std::unique_ptr<Publisher> Publisher_1{ new Publisher() };
		Publisher_1->name = "Publisher_1";
		Wt::Dbo::ptr<Publisher> Publisher_1_ptr = s.add(std::move(Publisher_1));

		std::unique_ptr<Publisher> Publisher_2{ new Publisher() };
		Publisher_2->name = "Publisher_2";
		Wt::Dbo::ptr<Publisher> Publisher_2_ptr = s.add(std::move(Publisher_2));

		std::unique_ptr<Publisher> Publisher_3{ new Publisher() };
		Publisher_3->name = "Publisher_3";
		Wt::Dbo::ptr<Publisher> Publisher_3_ptr = s.add(std::move(Publisher_3));


		std::unique_ptr <Book> Book_1{ new Book() };
		Book_1->title = "Book_1";
		Book_1->publisher = Publisher_1_ptr;
		Wt::Dbo::ptr<Book> Book_1_ptr = s.add(std::move(Book_1));

		std::unique_ptr <Book> Book_2{ new Book() };
		Book_2->title = "Book_2";
		Book_2->publisher = Publisher_2_ptr;
		Wt::Dbo::ptr<Book> Book_2_ptr = s.add(std::move(Book_2));

		std::unique_ptr <Book> Book_3{ new Book() };
		Book_3->title = "Book_3";
		Book_3->publisher = Publisher_3_ptr;
		Wt::Dbo::ptr<Book> Book_3_ptr = s.add(std::move(Book_3));

		std::unique_ptr <Book> Book_4{ new Book() };
		Book_4->title = "Book_4";
		Book_4->publisher = Publisher_1_ptr;
		Wt::Dbo::ptr<Book> Book_4_ptr = s.add(std::move(Book_4));

		std::unique_ptr <Book> Book_5{ new Book() };
		Book_5->title = "Book_5";
		Book_5->publisher = Publisher_2_ptr;
		Wt::Dbo::ptr<Book> Book_5_ptr = s.add(std::move(Book_5));

		std::unique_ptr <Book> Book_6{ new Book() };
		Book_6->title = "Book_6";
		Book_6->publisher = Publisher_3_ptr;
		Wt::Dbo::ptr<Book> Book_6_ptr = s.add(std::move(Book_6));

		std::unique_ptr <Book> Book_7{ new Book() };
		Book_7->title = "Book_7";
		Book_7->publisher = Publisher_1_ptr;
		Wt::Dbo::ptr<Book> Book_7_ptr = s.add(std::move(Book_7));

		std::unique_ptr <Book> Book_8{ new Book() };
		Book_8->title = "Book_8";
		Book_8->publisher = Publisher_2_ptr;
		Wt::Dbo::ptr<Book> Book_8_ptr = s.add(std::move(Book_8));

		std::unique_ptr <Book> Book_9{ new Book() };
		Book_9->title = "Book_9";
		Book_9->publisher = Publisher_3_ptr;
		Wt::Dbo::ptr<Book> Book_9_ptr = s.add(std::move(Book_9));


		std::unique_ptr<Shop> Shop_1{ new Shop() };
		Shop_1->name = "Shop_1";
		Wt::Dbo::ptr<Shop> Shop_1_ptr = s.add(std::move(Shop_1));

		std::unique_ptr<Shop> Shop_2{ new Shop() };
		Shop_2->name = "Shop_2";
		Wt::Dbo::ptr<Shop> Shop_2_ptr = s.add(std::move(Shop_2));

		std::unique_ptr<Shop> Shop_3{ new Shop() };
		Shop_3->name = "Shop_3";
		Wt::Dbo::ptr<Shop> Shop_3_ptr = s.add(std::move(Shop_3));


		std::unique_ptr<Stock> Stock_1{ new Stock() };
		Stock_1->book = Book_1_ptr;
		Stock_1->shop = Shop_1_ptr;
		Stock_1->count = 100;
		Wt::Dbo::ptr<Stock> Stock_1_ptr = s.add(std::move(Stock_1));

		std::unique_ptr<Stock> Stock_2{ new Stock() };
		Stock_2->book = Book_2_ptr;
		Stock_2->shop = Shop_2_ptr;
		Stock_2->count = 200;
		Wt::Dbo::ptr<Stock> Stock_2_ptr = s.add(std::move(Stock_2));

		std::unique_ptr<Stock> Stock_3{ new Stock() };
		Stock_3->book = Book_3_ptr;
		Stock_3->shop = Shop_3_ptr;
		Stock_3->count = 300;
		Wt::Dbo::ptr<Stock> Stock_3_ptr = s.add(std::move(Stock_3));

		std::unique_ptr<Stock> Stock_4{ new Stock() };
		Stock_4->book = Book_4_ptr;
		Stock_4->shop = Shop_1_ptr;
		Stock_4->count = 400;
		Wt::Dbo::ptr<Stock> Stock_4_ptr = s.add(std::move(Stock_4));


		std::unique_ptr<Sale> Sale_1{ new Sale() };
		Sale_1->price = 100;
		Sale_1->date_sale = "2023-10-01";
		Sale_1->stock = Stock_1_ptr;
		Sale_1->count = 10;
		s.add(std::move(Sale_1));

		std::unique_ptr<Sale> Sale_2{ new Sale() };
		Sale_2->price = 200;
		Sale_2->date_sale = "2023-10-01";
		Sale_2->stock = Stock_2_ptr;
		Sale_2->count = 20;
		s.add(std::move(Sale_2));


		std::string namePublisher;
		std::cout << "Еnter the name of the publisher: ";
		std::cin >> namePublisher;
		findShop(s, namePublisher);
		tx.commit();

	}
	catch (Wt::Dbo::Exception& e) 
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}