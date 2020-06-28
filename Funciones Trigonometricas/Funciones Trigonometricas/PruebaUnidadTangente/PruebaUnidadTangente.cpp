#include "pch.h"
#include "CppUnitTest.h"
#include "..//Funciones Trigonometricas/Funciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebaUnidadTangente
{
	TEST_CLASS(PruebaUnidadTangente)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Funciones funciones;
			float resulEsperado = 0;
			float resultado;

			//Act
			resultado = funciones.miTangente(180);

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
