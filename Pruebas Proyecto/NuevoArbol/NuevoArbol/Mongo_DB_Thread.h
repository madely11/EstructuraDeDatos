#pragma once
#include "Mongo_DB_Instance.h"
#include "Mongo_DB_Access.h"
class Mongo_DB_Thread
{
private:
    Mongo_DB_Access objDB_access;
    Translate _word;
    //std::string   strJSON_doc;
public:
    Mongo_DB_Thread(mongocxx::client& client, std::string db_name,
        std::string coll_name, std::string json_doc) :
        objDB_access(client, db_name, coll_name)
    {}
    void operator()() {
        objDB_access.insert(_word);
    }

    void db_ops(std::string json_doc_a, std::string json_doc_b) {
        Mongo_DB_Instance::GetInstance()->createPool(mongodb_uri_path);

        auto dbClient_A =
            Mongo_DB_Instance::GetInstance()->getClientFromPool();
        auto dbClient_B =
            Mongo_DB_Instance::GetInstance()->getClientFromPool();
        std::thread thread_A{
          Mongo_DB_Thread(*dbClient_A, "db_name_A", "coll_a", json_doc_a)
        };
        std::thread thread_B{
          MongoDBThread(*dbClient_B, "db_name_B", "coll_b", json_doc_b)
        };
        thread_A.join();
        thread_B.join();
    }
    
};

