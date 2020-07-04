/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* PROGRAMA PARA SUMAR DOS FRACCIONES                              *
* AUTORA: Madely Betancourt										  *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396														  *
* FECHA DE CREACIÓN: 26/05/20									  *
* FECHA DE MODIFICACIÓN: 26/05/20								  *
******************************************************************/

//#if !defined(__SumaDeFracciones2_Fraccion_h)
//#define __SumaDeFracciones2_Fraccion_h

class Fraccion
{
public:
	Fraccion Suma(Fraccion frac1, Fraccion frac2);
	int getNumerador(void);
	void setNumerador(int newNumerador);
	int getDenominador(void);
	void setDenominador(int newDenominador);
	Fraccion();

protected:
private:
	int Numerador = 0;
	int Denominador = 0;

};

/**
	@brief Funcion sumar fracciones
	@param primera fraccion de tipo fraccion, segunda fraccion de tipo fraccion
	@returns resultado
*/

Fraccion Fraccion::Suma(Fraccion frac1, Fraccion frac2)
{
	Fraccion resultado;
	if (frac1.Numerador == 0) {
		resultado.Numerador = frac2.Numerador;
		resultado.Denominador = frac2.Denominador;
		return resultado;
	}
	if (frac2.Numerador == 0) {
		resultado.Numerador = frac1.Numerador;
		resultado.Denominador = frac1.Denominador;
		return resultado;
	}

	resultado.Numerador = (frac1.Numerador * frac2.Denominador) + (frac2.Numerador * frac1.Denominador);
	resultado.Denominador = (frac1.Denominador * frac2.Denominador);
	return resultado;
}

/**
	@brief Funcion get de Numerador
	@param void
	@returns Numerdor
*/

int Fraccion::getNumerador(void)
{
	return Numerador;
}

/**
	@brief Funcion set del Arreglo
	@param int 
*/

void Fraccion::setNumerador(int newNumerador)
{
	Numerador = newNumerador;
}

/**
	@brief Funcion get de Denominador
	@param void
	@returns Denominador
*/

int Fraccion::getDenominador(void)
{
	return Denominador;
}


/**
	@brief Funcion set de Denominador
	@param int
	@returns denominador
*/

void Fraccion::setDenominador(int newDenominador)
{
	Denominador = newDenominador;
}


/**
	@brief Funcion constrcutor de fraccion
*/
Fraccion::Fraccion()
{
}

//#endif
