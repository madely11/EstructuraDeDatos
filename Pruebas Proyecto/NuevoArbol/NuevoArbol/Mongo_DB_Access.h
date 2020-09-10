#pragma once
#include <iostream>
#include <mongocxx/database.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/client.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/exception/bulk_write_exception.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/exception/exception.hpp>
#include "Translate.h"
#include "Binary_Tree.cpp"

class Mongo_DB_Access
{
private:
    mongocxx::client& m_client;
    std::string m_dbName;
    std::string m_collectionName;
    mongocxx::database m_db;
    mongocxx::collection m_collection;

public:

    Mongo_DB_Access(mongocxx::client& client_, std::string dbName_,
        std::string collName_) : m_client(client_), m_dbName(dbName_),
        m_collectionName(collName_) {
        m_db = m_client[dbName_];
        m_collection = m_db[collName_];
    } 

    
    
    int insert(Translate word) {
        try {
     
            auto builder = bsoncxx::builder::stream::document{};
            bsoncxx::document::value doc_value = builder
                << "english" << word.get_english()
                << "spanish" << word.get_spanish()
                << bsoncxx::builder::stream::finalize;
            auto result = m_collection.insert_one(move(doc_value));
        }
        
        catch (const bsoncxx::exception& e) {
            std::string errInfo = std::string("Error saving data, Err Msg:" ) + e.what();
                return -1;
        }
        catch (mongocxx::bulk_write_exception e) {
            std::string errInfo = std::string("Error saving data, Err Msg : ") + e.what();
                return -1;
        }
        return 0;
    }

    int get_Word(Binary_Tree<Translate>* _tree) {
        try {
            Translate new_data;
            mongocxx::cursor cursor = m_collection.find({});
            for (auto doc : cursor) {
                bsoncxx::document::element data = doc["english"];
                bsoncxx::document::element data2 = doc["spanish"];
                new_data.set_english((string)data.get_utf8().value);
                new_data.set_spanish((string)data2.get_utf8().value);
                _tree->_add(new_data, _tree->get_root(), NULL);
            }
        }
        catch (const bsoncxx::exception& e) {
            std::string errInfo = std::string("Error saving data, Err Msg:") + e.what();
            return 0;
        }
        catch (mongocxx::bulk_write_exception e) {
            std::string errInfo = std::string("Error saving data, Err Msg : ") + e.what();
            return 0;
        }
        return 0;
    }

   /* int get_all_documents() {
        try {
            mongocxx::cursor cursor = m_collection.find({});
            for (auto doc : cursor) {
                bsoncxx::document::element data = doc["english"];
                bsoncxx::document::element data2 = doc["spanish"];

            }
        }
        catch (const bsoncxx::exception& e) {
            std::string errInfo = std::string("Error saving data, Err Msg:") + e.what();
            return 0;
        }
        catch (mongocxx::bulk_write_exception e) {
            std::string errInfo = std::string("Error saving data, Err Msg : ") + e.what();
            return 0;
        }
        return 0;
    }*/

   
};


