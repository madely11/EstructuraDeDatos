#include <iostream>
#include<Windows.h>
#include "Menu.h"
#include"ManejoArchivo.h"
#include "Marquesina.h"
void RunDialogOne();
void RunDialogTwo();
HANDLE tPrimary, tSecond;
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void RunDialogOne()
{
    Marquesina mr;

    string cadena = "UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";

    while (!_kbhit()) {
        gotoxy(25, 10);
        cout << cadena;
        cadena = mr.realizarMarquezina(cadena);
    }

    system("Pause");
    return;
}

void RunDialogTwo()
{   
    WaitForSingleObject(tPrimary, INFINITE);
    Menu menu;
    menu.listaCliente->llenarLista("cliente.txt");
    menu.listaCuentas->llenarCuenta("cuenta.txt");
    menu.listaTrans->llenarTrans("transacciones.txt");
    menu.menuTeclas();
}

int main()
{  
    DWORD ThreadID;

    tPrimary = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)RunDialogOne, NULL, CREATE_SUSPENDED, &ThreadID);

    tSecond = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)RunDialogTwo, NULL, CREATE_SUSPENDED, &ThreadID);

    ResumeThread(tPrimary);

    ResumeThread(tSecond);

    HANDLE ThreadContainer[2];
    ThreadContainer[0] = tPrimary;
    ThreadContainer[1] = tSecond;

    DWORD dwSuccess = WaitForMultipleObjects(2, ThreadContainer, TRUE, INFINITE);

    if (dwSuccess == WAIT_FAILED)
        MessageBox(NULL, (LPCWSTR)"Espera a fallado!", (LPCWSTR)"ERROR", MB_OK | MB_ICONERROR);
    else
        MessageBox(NULL, (LPCWSTR)"Exito!", (LPCWSTR)"EXITO", MB_OK | MB_ICONINFORMATION);

    CloseHandle(tPrimary);
    CloseHandle(tSecond);

    return 0;
   
   

}

