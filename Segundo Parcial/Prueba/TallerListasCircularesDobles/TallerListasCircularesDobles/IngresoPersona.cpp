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
	cin.ignore();
	persona.setNombre(ingreso.leerString("\nIngrese el nombre: ", 1));
	cin.clear();
	persona.setApellido(ingreso.leerString("\nIngrese el apellido: ", 1));
	cin.clear();
	cout << endl;
	cin.clear();
	dato = dato.assign(ingreso.ingresaNumericos("Ingrese la cedula: "), 10);
	while (!validar.cedula(dato)) {
		dato = dato.assign(ingreso.ingresaNumericos("\nIngrese la cedula: "), 10);
		cin.clear();
	}
	persona.setCedula(dato);
	cin.clear();
	cout << endl;
	cin.clear();
	dato = ingreso.leer("Ingrese su edad: ", 1);
	cin.clear();
	persona.setEdad(atoi(dato.c_str()));
	cout << endl;
	Fecha f;
	do{
		cin.clear();
		dato = ingreso.leer("Ingrese el dia: ", 1);
		dia = atoi(dato.c_str());
		cin.clear();
		cout << endl;
		cin.clear();
		dato = ingreso.leer("Ingrese el mes: ", 1);
		mes = atoi(dato.c_str());
		cin.clear();
		cout << endl;
		cin.clear();
		dato = ingreso.leer("Ingrese el anio: ", 1);
		anio = atoi(dato.c_str());
		cin.clear();
		cout << endl;
		cin.clear();
		f.setDia(dia);
		f.setMes(mes);
		f.setAnio(anio);
	} while (!f.validarFecha());
	f.diferencia();
	persona.setFecha(f);
}
