//#include "Conection_DB.h"
//
////Conection_DB* Conection_DB::instance = 0;
////
////Conection_DB* Conection_DB::getInstance()
////{
////	if (instance == 0)
////	{
////		instance = new Conection_DB();
////	}
////
////	return instance;
////}
////
////Conection_DB::Conection_DB()
////{
////	mongocxx::instance instance{};	 // This should be done only once.
////}
//
//void Conection_DB::insert_data_DB(Translate word)
//{
//	//agregar a la base de datos
//	
//	auto builder = bsoncxx::builder::stream::document{};
//	bsoncxx::document::value doc_value = builder
//		<< "english" << word.get_english()
//		<< "spanish" << word.get_spanish()
//		<< bsoncxx::builder::stream::finalize;
//	auto result = coll.insert_one(move(doc_value));
//
//}
//
//void Conection_DB::read_DB(Binary_Tree<Translate>* _tree)
//{
//	mongocxx::cursor cursor = coll.find({});
//	for (auto doc : cursor) {
//		bsoncxx::document::element data = doc["english"];
//		bsoncxx::document::element data2 = doc["spanish"];
//		cout << data.get_utf8().value<< endl;
//		cout << data2.get_utf8().value << endl;
//		new_word.set_english((string)data.get_utf8().value);
//		new_word.set_spanish((string)data2.get_utf8().value);
//		_tree->_add(new_word,_tree->get_root(),NULL);
//	}
//
//}
