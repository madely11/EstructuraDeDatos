#include "pch.h"
#include "CppUnitTest.h"
#include "..//Funciones Trigonometricas/Funciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebaUnidadConvierte
{
	TEST_CLASS(PruebaUnidadConvierte)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Funciones funciones;
			float resulEsperado = 0;
			float resultado;

			//Act
			resultado = funciones.convierte(360);

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
