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

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::Suma(Fraccion frac1, Fraccion frac2)
// Purpose:    Implementation of Fraccion::Suma()
// Parameters:
// - frac1
// - frac2
// Return:     Fraccion
////////////////////////////////////////////////////////////////////////

Fraccion Fraccion::Suma(Fraccion frac1, Fraccion frac2)
{
	Fraccion resultado;
	resultado.Numerador = (frac1.Numerador * frac2.Denominador) + (frac2.Numerador * frac1.Denominador);
	resultado.Denominador = (frac1.Denominador * frac2.Denominador);
	return resultado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getNumerador()
// Purpose:    Implementation of Fraccion::getNumerador()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fraccion::getNumerador(void)
{
	return Numerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setNumerador(int newNumerador)
// Purpose:    Implementation of Fraccion::setNumerador()
// Parameters:
// - newNumerador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::setNumerador(int newNumerador)
{
	Numerador = newNumerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getDenominador()
// Purpose:    Implementation of Fraccion::getDenominador()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fraccion::getDenominador(void)
{
	return Denominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setDenominador(int newDenominador)
// Purpose:    Implementation of Fraccion::setDenominador()
// Parameters:
// - newDenominador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::setDenominador(int newDenominador)
{
	Denominador = newDenominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::Fraccion()
// Purpose:    Implementation of Fraccion::Fraccion()
// Return:     
////////////////////////////////////////////////////////////////////////
Fraccion::Fraccion()
{
}

//#endif
