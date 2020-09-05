#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include "Binary_Tree.cpp"
#include "Translate.h"
using namespace std;


class File_Manager
{

	private:
		string nombreArchivo;
		ifstream archivoLectura; //archivo de lectura
		ofstream archivoEscritura; //archivo de escritura

	public:
		File_Manager(string);
		File_Manager();
		bool crearLectura();
		bool crearEscritura();
		void agregarLinea(string);
		void cerrarLectura();
		void cerrarEscritura();
		string leerArchivo();

		
		void load_file(Binary_Tree<Translate>*);
};

