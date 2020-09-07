#ifndef __Dibujar_h
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
//#include <Windows.h>
using namespace sf;
using namespace std;

class Dibujar
{
public:
	RenderWindow* ventana;
public:
	Dibujar();
	void dibujarNodo(int, int, string);
};

#endif __Dibujar_h