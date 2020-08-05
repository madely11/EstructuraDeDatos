#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <math.h>
#include "Ingreso.h"
#include "Validacion.h"
#include"Lista.h"
#include"IngresoPersona.h"
using namespace std;
#ifndef Menu_H
#define Menu_H
class Menu {
public:
	void MenuTeclas();
	Lista* lista = new Lista();
};
#endif 

