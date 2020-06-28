#include "pch.h"
#include "CppUnitTest.h"
#include "..//Funciones Trigonometricas/Funciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebaUnidadFactorial
{
	TEST_CLASS(PruebaUnidadFactorial)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Funciones funciones;
			float resulEsperado = 120;
			float resultado;

			//Act
			resultado = funciones.factorial(5);

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
