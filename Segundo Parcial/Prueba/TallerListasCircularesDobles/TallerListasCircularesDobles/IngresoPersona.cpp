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
	persona.setNombre(ingreso.leerString("\nIngrese el nombre: ", 1));
	persona.setApellido(ingreso.leerString("\nIngrese el apellido: ", 1));
	
	dato = dato.assign(ingreso.ingresaNumericos("Ingrese la cedula: "), 10);
	while (!validar.cedula(dato)) {
		dato = dato.assign(ingreso.ingresaNumericos("\nIngrese la cedula: "), 10);
	}
	persona.setCedula(dato);

	dato = ingreso.leer("Ingrese su edad: ", 1);
	persona.setEdad(atoi(dato.c_str()));

	dato = ingreso.leer("Ingrese el dia: ", 1);
	dia = atoi(dato.c_str());
	dato = ingreso.leer("Ingrese el mes: ", 1);
	mes = atoi(dato.c_str());
	dato = ingreso.leer("Ingrese el anio: ", 1);
	anio = atoi(dato.c_str());
	Fecha f(dia, mes, anio);
	persona.setFecha(f);
}
