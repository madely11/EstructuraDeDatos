#include "IngresoPersona.h"

void IngresoPersona::imprimirDatos()
{
	cout << "El nombre es: " << persona.getNombre()<<endl;
	cout << "El apellido es: " << persona.getApellido()<<endl;
	cout << "La cedula es: " << persona.getCedula()<<endl;
	Fecha f;
	f = persona.getFecha();
	cout << f.toString();

}

void IngresoPersona::ingresoDatos()
{
	string dato;
	int valor, dia, mes, anio;
	cout << "Ingrese el nombre: ";
	cin >> dato;
	persona.setNombre(dato);
	cout << "Ingrese el apellido: ";
	cin >> dato;
	persona.setApellido(dato);
	cout << "Ingrese su edad: ";
	cin >> valor;
	persona.setEdad(valor);
	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;
	cout << "Ingrese el anio: ";
	cin >> anio;
	Fecha f(dia, mes, anio);
	persona.setFecha(f);
}
