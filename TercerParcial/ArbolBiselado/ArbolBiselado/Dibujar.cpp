#include "Dibujar.h"
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CLASE PARA DIBUJAR EL ARBOL               *
* AUTORES: Madely Betancourt, Kevin Caicedo                       *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 04/07/20									  *
* FECHA DE MODIFICACIÓN: 09/07/20								  *
******************************************************************/

Dibujar::Dibujar()
{
    ventana = new RenderWindow(VideoMode(1800, 900), "Ventana de Dibujo");
    ventana->setVisible(false);
}

void Dibujar::dibujarNodo(int x, int y, string dato)
{

    Font fuente;
    Text texto;
    String cadena;

    // Intentamos cargarla
    if (!fuente.loadFromFile("HandCraftedItalic.ttf"))
    {
        cout << "No se puede usar el tipo de letra" << endl;
    }

    cadena = dato;
    texto.setString(cadena);
    texto.setFont(fuente);


    RectangleShape rectangulo(Vector2f(60, 30));
    rectangulo.setFillColor(Color::Green);
    rectangulo.setPosition(x, y);


    texto.setCharacterSize(20);
    texto.setFillColor(Color(150, 50, 250));
    x += 10;
    texto.setPosition(x, y);

    ventana->draw(rectangulo);
    ventana->draw(texto);
}
