//#pragma once
//#include <cstdint>
//#include <iostream>
//#include <vector>
//#include <bsoncxx/json.hpp>
//#include <bsoncxx/builder/stream/document.hpp>
//#include <bsoncxx/exception/exception.hpp>
//#include <mongocxx/database.hpp>
//#include <mongocxx/pool.hpp>
//#include <mongocxx/client.hpp>
//#include <mongocxx/stdx.hpp>
//#include <mongocxx/uri.hpp>
//#include <mongocxx/instance.hpp>
//#include <mongocxx/collection.hpp>
//#include "Translate.h"
//#include "Binary_Tree.cpp"
//
//using bsoncxx::builder::stream::close_array;
//using bsoncxx::builder::stream::close_document;
//using bsoncxx::builder::stream::document;
//using bsoncxx::builder::stream::finalize;
//using bsoncxx::builder::stream::open_array;
//using bsoncxx::builder::stream::open_document;
//
//using namespace std;
//
//class Conection_DB
//{
//public:
//	Translate new_word;
//	//static Conection_DB* instance;
//	//Conection_DB();
//
//public:
//	//static Conection_DB* getInstance();
//	void insert_data_DB(Translate word);
//	void read_DB(Binary_Tree<Translate>*);
//	//mongocxx::database db;
//	//mongocxx::collection coll = db["word"];
//};
