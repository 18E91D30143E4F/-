#include <stdio.h>

int recursionNOD(int M, int N)
{
	if (M % N == 0)
	{
		return N;
	}
	else
	{
		recursionNOD(N % M, M);
	}

}

int simpleNOD(int M, int N)
{
	int tmp;

	while (1)
	{
		if (M % N != 0)
		{
			tmp = M;
			M = N % M;
			N = tmp;
		}
		else
		{
			break;
		}
	}

	return N;
}

int main()
{
	int M, N;

	puts("Input M and N");
	scanf_s("%d %d", &M, &N);

	printf("Recursion variant : %d\nItaration variant : %d\n", recursionNOD(M, N), simpleNOD(M, N));

	puts("Press any key to continue...");
	getch();

	return 0;
}