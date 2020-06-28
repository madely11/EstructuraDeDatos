#include "pch.h"
#include "CppUnitTest.h"
#include "../ElevaMatriz/Matriz.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ElevaMatrizTest
{
	TEST_CLASS(ElevaMatrizTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Arrange
			int** mat, ** matA, ** matB;
			int matAux[2][2];
			int matResult[2][2] = { {7,10},{15,22} };
			Matriz<int> mat1, mat2, mat3;
			int aux = 1;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					*(*(mat + i) + j) = aux++;
				}
			}

			int a = 7;
			int b = 10;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					*(*(matB + i) + j) = a;
					a += 3;
					if (i == 1)
						a += 7;
				}
				a = 15;
			}

			mat1 = Matriz<int>::Matriz(mat, 2);
			mat2 = Matriz<int>::Matriz(matA, 2);
			mat3 = Matriz<int>::Matriz(matB, 2);

			//Act
			mat1.elevar(mat1, mat2, 2);
			//resultado = op.calcularMCD(arr1.getArreglo(), arr1.getLongitud());
			/*for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					matAux[i][j] = *(*(mat2.getMatriz() + i) + j);
				}
			}*/

			//Assert
			Assert::AreEqual(mat2, mat3);
		}
	};
}
