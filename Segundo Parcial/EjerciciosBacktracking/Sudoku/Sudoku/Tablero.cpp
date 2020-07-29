#include "Tablero.h"

Tablero::Tablero()
{
    matriz = (int**)malloc(TAM * sizeof(int*));
    for (int j = 0; j < TAM; j++) {
        *(matriz + j) = (int*)malloc(TAM * sizeof(int));
    }
    llenarMatriz();
}


int Tablero::generarDato()
{
    int dato = 0;
    dato = 1 + rand() % (10 - 1);
    return dato;
}

void Tablero::llenarMatriz()
{
    srand(time(NULL));
    int valorPosicion, cont=0;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            //cout << "Dato: " << *(*(matriz + i) + j) << "    fila: " << i << " columna: " << j << endl;
           // resolverTablero(matriz, i, j);
            *(*(matriz + i) + j) = 0;
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            valorPosicion = generarDato();
            //*(*(matriz + i) + j) = generarDato();
            resolverTablero(matriz, i, j, valorPosicion, cont);
            imprimirTablero();
        }
    }

    imprimirTablero();
    //free(matriz);

    
}

bool Tablero::verificarFila(int** matriz, int f, int c, int valorP)
{
   // cout << "Dato fila  " << (*(*matriz + f) + c) << endl;
    for (int i = 0; i < TAM; i++)
    {
        if (i != c && *(*(matriz + f) + i) != 0 && valorP == *(*(matriz + f) + i)) {
           // cout << "Entro fila" << endl;
            //cout << "Dato comparado " << *(*(matriz + f) + i) << endl;
            return false;
        }  
    }

    return true;
}

bool Tablero::verificarColumna(int** matriz, int f, int c, int valorP)
{
    //cout << "Dato columna  " << (*(*matriz + f) + c) << endl;
    for (int i = 0; i < TAM; i++)
    {
        if (i != f && *(*(matriz + i) + c) != 0 && valorP == *(*(matriz + i) + c)) {
            //cout << "Dato comparado " << *(*(matriz + i) + c) << endl;
            //cout << "Entro columna" << endl;
            return false;
        }
            
    }
    return true;
}

bool Tablero::verificarCuadro(int** matriz, int f, int c, int valorP)
{
    int x = (f / 3) * 3;
    int y = (c / 3) * 3;
    int xAux, yAux;
    for (int j = 0; j < TAM/3; j++)
    {
        xAux = x + j;
        for (int k = 0; k < TAM/3; k++)
        {
            yAux = y + k;
             if (j != f  && k !=c && ((*(*(matriz + xAux) + yAux)) == valorP)) {
               // cout << "Entro cuadradito" << endl;
                return false;
            }
        }
    }
    return true;
}

bool Tablero::validarInsertar(int** matriz, int f, int c, int valorP)
{
    if (!(verificarCuadro(matriz, f, c, valorP))) {
        return false;
    }

    if (!(verificarFila(matriz, f, c, valorP))) {
        return false;
    }

    if (!(verificarColumna(matriz, f, c, valorP))) {
        return false;
    }

    return true;
}

void Tablero::resolverTablero(int** matriz, int f, int c, int valorPosicion, int cont)
{
    //cout << "Dato: " << *(*(matriz + f) + c) << "    fila: " << f << " columna: " << c << endl;
    if (!validarInsertar(matriz, f, c, valorPosicion)) {   //si se retorna F se hace V
        cont += 1;
        if (cont > 9) {
            cont = 1;
        }
        //cout << "Valos posicion " << cont << endl;
        valorPosicion = cont;
        resolverTablero(matriz, f, c, valorPosicion, cont);
    }
    else {
        *(*(matriz + f) + c) = valorPosicion;
    } 
}

void Tablero::encerarFila(int** matriz, int f)
{
    for (int i = 0; i < TAM; i++)
    {
        *(*(matriz + f) + i) = 0;
    }
   // imprimirTablero();
}

void Tablero::imprimirTablero()
{
    cout << endl;
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            cout << *(*(matriz + i) + j) << "  ";
        }
        cout << endl;
    }
}




