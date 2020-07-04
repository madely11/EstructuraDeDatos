#include "pch.h"
#include "CppUnitTest.h"
#include "..//Funciones Trigonometricas/Funciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebasUnidadPotencia
{
	TEST_CLASS(PruebasUnidadPotencia)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Funciones funciones;
			float resulEsperado = 8;
			float resultado;

			//Act
			resultado = funciones.potencia(2, 3);

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
