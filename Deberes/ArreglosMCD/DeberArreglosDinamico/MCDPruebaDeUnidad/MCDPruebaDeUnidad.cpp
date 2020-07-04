#include "pch.h"
#include "CppUnitTest.h"
#include "../DeberArreglosDinamico/Arreglo.h"
#include "../DeberArreglosDinamico/Operaciones.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MCDPruebaDeUnidad
{
	TEST_CLASS(MCDPruebaDeUnidad)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Arreglo <int> arr1;
			arr1.ingresar(5);
			arr1.ingresar(14);
			int resulEsperado = 1;
			int resultado;

			//Act
			Operaciones <int> op;
			resultado = op.calcularMCD(arr1.getArreglo(), arr1.getLongitud());

			//Assert
			Assert::AreEqual(resulEsperado, resultado);
		}
	};
}
