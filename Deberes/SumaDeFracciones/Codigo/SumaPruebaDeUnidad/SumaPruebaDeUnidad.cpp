#include "pch.h"
#include "CppUnitTest.h"
#include "../SumaDeFracciones/Fraccion.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SumaPruebaDeUnidad
{
	TEST_CLASS(SumaPruebaDeUnidad)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Fraccion frac1;
			frac1.setNumerador(1);
			frac1.setDenominador(4);
			Fraccion frac2;
			frac2.setNumerador(1);
			frac2.setDenominador(3);
			Fraccion resultadoEsperado;
			resultadoEsperado.setNumerador(7);
			resultadoEsperado.setDenominador(12);

			//Act
			Fraccion resultado;

			//Assert
			Assert::AreEqual(resultadoEsperado.getNumerador(), resultado.Suma(frac1, frac2).getNumerador());
			Assert::AreEqual(resultadoEsperado.getDenominador(), resultado.Suma(frac1, frac2).getDenominador());
		}
	};
}
