#pragma once
#include "Mongo_DB_Instance.h"
#include "Mongo_DB_Access.h"
#include "Binary_Tree.cpp"
#include <thread>

class Mongo_DB_Thread
{
private:
    Mongo_DB_Access objDB_access;
    Translate _word_J;
    Binary_Tree<Translate> _tree_DB;
    //std::string   strJSON_doc;
public:
    /*Mongo_DB_Thread(mongocxx::client& client, std::string db_name,
        std::string coll_name, Translate _word, Binary_Tree<Translate> _tree) :
        objDB_access(client, db_name, coll_name), _word_J(_word), _tree_DB(_tree)
    {}*/

    Mongo_DB_Thread(mongocxx::client& client, std::string db_name,
        std::string coll_name, Translate _word) :
        objDB_access(client, db_name, coll_name), _word_J(_word)
    {}

    void operator()() {
        //objDB_accessGet.get_Word(_tree_DB);
        objDB_access.insert(_word_J);
       // objDb_access_Insert.get_Word(&_tree_DB);
    }

    void db_ops(Translate _word_J) {

        Mongo_DB_Instance::GetInstance()->createPool("mongodb://localhost:27017");

        auto dbClient_A =
            Mongo_DB_Instance::GetInstance()->getClientFromPool();
     

        std::thread thread_A{
          Mongo_DB_Thread(*dbClient_A, "Translate", "word", _word_J)
        };
     
        thread_A.join();
    }
    
};

