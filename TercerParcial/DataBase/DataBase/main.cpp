#include <cstdint>
#include <iostream>
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

using namespace std;

void main() {
	mongocxx::instance instance{}; // This should be done only once.
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["Translate"];
	mongocxx::collection coll = db["word"];

	//agregar a la base de datos
	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_value = builder
		<< "english" << "dog"
		<< "spanish" << "perro"
	<< bsoncxx::builder::stream::finalize;
	auto result = coll.insert_one(move(doc_value));
	
	//obtener datos de base de datos
	mongocxx::cursor cursor = coll.find({});
	for (auto doc : cursor) {
		bsoncxx::document::element data = doc["english"];
		bsoncxx::document::element data2 = doc["spanish"];
		cout << data.get_utf8().value << endl;
		cout << data2.get_utf8().value << endl;
	}
}