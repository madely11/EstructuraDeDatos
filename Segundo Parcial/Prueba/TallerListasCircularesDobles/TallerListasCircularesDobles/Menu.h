#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <math.h>
#include"Lista.h"
//#include"Persona.h"
#include"IngresoPersona.h"
using namespace std;

class Menu {
public:
	void MenuTeclas();
	Lista* lista = new Lista();
};


