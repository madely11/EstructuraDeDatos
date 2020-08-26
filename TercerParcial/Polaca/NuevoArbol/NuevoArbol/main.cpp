#include "Validar.h"
void main() {
	Validar v;
	string exp;
	cout << "Ingrese la expresion matematica: " << endl;
	cin >> exp;
	if (v.validarExpresion(exp))
		cout << "expresion valida" << endl;
	else
		cout << "expresion no valida" << endl;
	v.separarExpresion(exp);
}