#include "pch.h"
#include "CppUnitTest.h"
#include "..//Funciones Trigonometricas/Funciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebaUnidadSeno
{
	TEST_CLASS(PruebaUnidadSeno)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Funciones funciones;
			float resulEsperado = 1.0000000;
			float resultado;

			//Act
			resultado = funciones.miSeno(90);

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
