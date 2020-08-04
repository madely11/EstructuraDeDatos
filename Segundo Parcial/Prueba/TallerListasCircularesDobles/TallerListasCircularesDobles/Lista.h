#include"Nodo.h"
#include"Persona.h"
using namespace std;

class Lista {
public:
    Lista();

    void insertarInicio(Persona dato);
    void insertarEntre(Persona dato, int pos);
    void insertarFinal(Persona dato);
    void borrar(string cedula);
    bool listaVacia();
    void mostrar();
    

private:
    Nodo* lista;
    Nodo* listaFinal;
};
