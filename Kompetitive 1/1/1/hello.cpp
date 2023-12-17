#include <iostream>

using namespace std;

int N;

void tulis(int kedalaman)
{
	if (kedalaman >= N)
	{
		// Cetak password
		for (int i = 0; i < N; i++)
		{
			printf("%d", catat[i]); // Cetak
		}
		printf("\n");
	}
	else
	{
		// Masuk ke lapisan lebih dalam
		for (int i = 1; i <= N; i++)
		{
			if (!pernah[i])
			{						  // i belum pernah?
				pernah[i] = true;	  // Gunakan
				catat[kedalaman] = i; // Catat di sini
				tulis(kedalaman + 1);
				pernah[i] = false; // Selesai menggunakan
			}
		}
	}
}

int main()
{
	cin >> N;

	tulis(0);

	return 0;
}