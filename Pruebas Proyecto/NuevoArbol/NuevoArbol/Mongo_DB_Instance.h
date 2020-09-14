/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE INGRESO                                                   *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 1/09/20									  *
* FECHA DE MODIFICACIÓN: 13/09/20								  *
******************************************************************/

/**
    @file Mongo_DB_Instance.h
    @brief Clase que contiene metodos para instanciar la base de Datos
    @author Madely Betancourt y Kevin Caicedo
    @date 9/2020
*/
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
    ~Mongo_DB_Instance() {}
};

