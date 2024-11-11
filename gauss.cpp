#include <iostream>
#include <cmath>
using namespace std;

void MethodGaus(float matrix[3][4], float xx[3], const int N)
{
	float tmp;
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		tmp = matrix[i][i];
		for (j = N; j >= i; j--)
			matrix[i][j] /= tmp;
		for (j = i + 1; j < N; j++)
		{
			tmp = matrix[j][i];
			for (k = N; k >= i; k--)
				matrix[j][k] -= tmp * matrix[i][k];
		}
	}
	xx[N - 1] = matrix[N - 1][N];
	for (i = N - 2; i >= 0; i--)
	{
		xx[i] = matrix[i][N];
		for (j = i + 1; j < N; j++) xx[i] -= matrix[i][j] * xx[j];
	}
	printf("\nРешение: \n");
	for (i = 0; i < N; i++)
		printf("a%d=%3.3f\n", i + 1, xx[i]);
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	const int N = 3;
	float matrix[3][4] = { {206.125, 84.858, 10, 45.339},
						   {939.692, 206.125, 84.858, 387.778},
						   {180,      82,       39,      101 } };

	cout << "Исходная матрица:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	float xx[N];

	MethodGaus(matrix, xx, N);

	return 0;
}
