#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double my_func(double x)

{
	return pow(x, 3) - 3 * pow(x, 2) - 14 * x - 8;
}

double my_func_df(double x)//производная функции

{
	return 3 * pow(x, 2) - 6 * x - 14;
}

double mathematical_root(double left, double right, double eps, long* iter)
{
	*iter = 1;
	double x = (left + right) / 2;
	while (abs(right - left) > eps)
	{
		if (my_func(left) * my_func(x) < 0)
		{
			(*iter)++;
			right = x;
			x = (left + right) / 2;
		}
		else
		{
			(*iter)++;
			left = x;
			x = (left + right) / 2;
		}
	}
	return x;
}

int main()

{
	double eps;
	// cout << "Enter eps: ";
	// cin >> eps;
	eps = 1E-6;
	cout << endl;
	long iter1 = 0;
	long iter2 = 0;
	long iter3 = 0;
	double x1 = mathematical_root(-2.6, -1.6, eps, &iter1);
	double x2 = mathematical_root(-1.0, 0.0, eps, &iter2);
	double x3 = mathematical_root(5.5, 6, eps, &iter3);
	cout << "Dichotomy method:\n" << setprecision(12) << x1 << " and iterations: " << iter1 << 	"\n" << setprecision(12) << x2 << " and iterations: " << iter2 << "\n" << setprecision(12) << 	x3 << " and iterations: " << iter3 << endl;

	double x, param;
	x = -3;
	param = 2 / (my_func_df(-2.6) + my_func_df(-1.6));
	long iter = 1;

	while (my_func(x - eps) * my_func(x + eps) > 0)

	{
		x = x - param * my_func(x);
		param = 1 / my_func_df(x);
		iter++;
	}

	cout << "\nRelaxation method:\n" << x << " and iterations: " << iter << endl;
	x = 0; 
	param = -2 / (my_func_df(-1.0) + my_func_df(0.0));
	iter = 1;
	
	while (my_func(x - eps) * my_func(x + eps) > 0)
	{
		x = x - param * my_func(x);
		param = 1 / my_func_df(x);
		iter++;
	}

	cout << x << " and iterations: " << iter << endl;
	x = 6.5;
	param = -2 / (my_func_df(5.5) + my_func_df(6.0));
	iter = 1;
	while (my_func(x - eps) * my_func(x + eps) > 0)
	{
		x = x - param * my_func(x);
		param = 1 / my_func_df(x);
		iter++;
	}
	cout << x << " and iterations: " << iter << endl;
	return 0;
}

