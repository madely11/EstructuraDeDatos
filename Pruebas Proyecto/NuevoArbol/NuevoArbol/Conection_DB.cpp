#include "Conection_DB.h"
#include <cstdint>
#include <vector>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/exception/exception.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>


using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

void Conection_DB::insert_data_DB(Translate word)
{

	mongocxx::instance instance{};	 // This should be done only once.
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["Translate"];
	mongocxx::collection coll = db["word"];
	//agregar a la base de datos
	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_value = builder
		<< "english" << word.get_english()
		<< "spanish" << word.get_spanish()
		<< bsoncxx::builder::stream::finalize;
	auto result = coll.insert_one(move(doc_value));

}

void Conection_DB::read_DB(Binary_Tree<Translate>* _tree)
{
	
	mongocxx::instance instance{};	 // This should be done only once.
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["Translate"];
	mongocxx::collection coll = db["word"];
	mongocxx::cursor cursor = coll.find({});
	for (auto doc : cursor) {
		bsoncxx::document::element data = doc["english"];
		bsoncxx::document::element data2 = doc["spanish"];
		cout << data.get_utf8().value<< endl;
		cout << data2.get_utf8().value << endl;
		new_word.set_english((string)data.get_utf8().value);
		new_word.set_spanish((string)data2.get_utf8().value);
		_tree->_add(new_word,_tree->get_root(),NULL);
	}

}
