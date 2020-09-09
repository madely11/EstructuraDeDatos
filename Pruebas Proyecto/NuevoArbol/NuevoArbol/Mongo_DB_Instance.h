#pragma once
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp> 
#include <iostream>
#include <memory>

class Mongo_DB_Instance
{
private:
    mongocxx::instance m_dbInstance;
    std::unique_ptr<mongocxx::pool> m_client_pool;
    Mongo_DB_Instance() { }

public:

    static Mongo_DB_Instance* GetInstance() {
        static Mongo_DB_Instance objMongoDBInstance;
        return &objMongoDBInstance;
    }

    /* Create a pool object only once from MongoDB URI */
    void createPool(std::string uri_) {
        if (!m_client_pool) {
            m_client_pool = (std::unique_ptr<mongocxx::pool>)
                new mongocxx::pool{ mongocxx::uri {uri_} };
        }
    }

    /* Acquire a client from the pool */
    mongocxx::pool::entry
        getClientFromPool() { return m_client_pool->acquire(); }
    ~Mongo_DB_Instance();

    
};

