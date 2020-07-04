
#include "pch.h"
#include "CppUnitTest.h"
#include "..//Funciones Trigonometricas/Funciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebaUnidadCoseno
{
	TEST_CLASS(PruebaUnidadCoseno)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			// Arrange
			Funciones funciones;
			float resulEsperado = -0.99900;
			float resultado;

			//Act
			resultado = funciones.miCoseno(180);

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
