#include <stdio.h>
#include <math.h>

double getFuncValue(double x)
{
	return log(x) - 5 * cos(x);
}

double simpsonIntegral(double a, double b, int n)
{
	double width = (b - a) / n;
	double x1, x2;
	double simps_integral = 0;

	for (int step = 0; step < n; step++) {
		x1 = a + step * width;
		x2 = a + (step + 1) * width;

		simps_integral += (x2 - x1) / 6.0 * (getFuncValue(x1) + 4.0 * getFuncValue(0.5 * (x1 + x2)) + getFuncValue(x2));
	}

	return simps_integral;
}

int main()
{
	double a = 1, b = 8, n = 15;

	printf("%lf\n", simpsonIntegral(a, b, n));

	puts("Press any key to continue...");
	getch();

	return 0;
}