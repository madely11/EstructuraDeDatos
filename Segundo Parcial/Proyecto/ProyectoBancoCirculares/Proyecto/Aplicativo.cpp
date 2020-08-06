#include <iostream>
#include "Menu.h"
#include"ManejoArchivo.h"

int main()
{
    //ManejoArchivo archivo("cliente.txt");
   // cout << archivo.leerArchivo();

    Menu menu;
    //cout << "CLIENTES" << endl;
    menu.listaCliente->llenarLista("cliente.txt");
   // menu.listaCliente->mostrar();
    //cout << "CUENTAS" << endl;
    menu.listaCuentas->llenarCuenta("cuenta.txt");
   // menu.listaCuentas->mostrarCuenta();
    //cout << "TRANSACCIONES" << endl;
    menu.listaTrans->llenarTrans("transacciones.txt");
    //menu.listaTrans->mostrarTrans();
    system("pause");
    menu.menuTeclas();

}