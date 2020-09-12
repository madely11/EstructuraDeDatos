#include "Validar.h"
void main() {
	Validar v;
	string exp;
	cout << "Ingrese la expresion matematica: " << endl;
	cin >> exp;
	if (v.validarExpresion(exp))
		cout << "Expresion valida" << endl;
	else
		cout << "Epresion no valida" << endl;
	v.separarExpresion(exp);
}