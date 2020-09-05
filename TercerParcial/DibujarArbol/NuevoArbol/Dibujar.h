#pragma once
#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Dibujar
{
public:
	RenderWindow *ventana;
public:
	Dibujar();
	void dibujarNodo(int, int, string);
};

