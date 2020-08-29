#include <stdio.h>
#include <math.h>
#include <assert.h>

const int INF = -1;
const double epsilon = 1e-9;

int is_zero(double n);

int checker(int check_n, double check_x1, double check_x2, int true_n, double true_x1, double true_x2);

void tests();

int super_pooper_squareSolver(double a, double b, double c, double* ptr_x1, double* ptr_x2);


int main()
{
	printf("Welcome! This is SquareSolver program.\nInput a, b, c coefficients of square equation.\n");

	double a = 0, b = 0, c = 0;
	scanf("%lg %lg %lg", &a, &b, &c);

	printf("Trying to solve the square equation:\n%lg*x^2%+lg*x%+lg = 0\n", a, b, c);

	double x1 = 0, x2 = 0;
	int amount_of_roots = super_pooper_squareSolver(a, b, c, &x1, &x2);

	switch (amount_of_roots)
	{
	case(0):

		printf("No roots\n");
		break;

	case(1):

		printf("One root:\nx1 = %lg\n", x1);
		break;

	case(2):

		printf("Two roots:\nx1 = %lg\nx2 = %lg\n", x1, x2);
		break;

	case(-1):

		printf("Infinite amount of roots\n");
		break;

	default:

		printf("I do not fucking know what happened, but if you wanna know: amount of roots = %d\n", amount_of_roots);
		break;
	}

	int INPUT = 0;
	
	printf("Do you want to launch unit tests? 1 or 0.\n");
	scanf("%d", &INPUT);
	
	if (INPUT) tests();
	
	return 0;
}

int is_zero(double n)
{
	return (fabs(n) < epsilon) ? 1 : 0;
}

int checker(int check_n, double check_x1, double check_x2, int true_n, double true_x1, double true_x2)
{
	return (check_n == true_n && check_x1 == true_x1 && check_x2 == true_x2);
}

/*!
Решает квадратное уравнение
\param[in]  a  коэффициент квадратного уравнения при x^2
\param[in]  b  коэффициент квадратного уравнения при x^1
\param[in]  c  коэффициент квадратного уравнения при x^0
\param[out] ptr_x1 указатель на корень квадратного уравнения
\param[out] ptr_x2 указатель на корень квадратного уравнения
\return Количество корней квадратного уравнения
\warning Зимой лучше надевать шапку, иначе голову застудишь
*/

int super_pooper_squareSolver(double a, double b, double c, double* ptr_x1, double* ptr_x2)
{

	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(ptr_x1 != NULL);
	assert(ptr_x2 != NULL);
	assert(ptr_x2 != ptr_x1);

	if (is_zero(a))
	{
		if (is_zero(b))
		{
			if (c == 0) return INF;
			else return 0;
		}
		else
		{
			(*ptr_x1) = -c / b;

			return 1;
		}
	}

	else
	{
		double discriminant = b * b - 4 * a * c;
		if (discriminant < 0 && !is_zero(discriminant))
		{
			return 0;
		}
		else if (is_zero(discriminant))
		{
			(*ptr_x1) = (-b) / (2 * a);

			return 1;
		}
		else
		{
			(*ptr_x1) = (-b + sqrt(discriminant)) / (2 * a);
			(*ptr_x2) = (-b - sqrt(discriminant)) / (2 * a);

			return 2;
		}

	}
}

void tests()
{
	double coeffs[21] = { 1e-5, -2e-5, -3e-5, 1, 1, -2, 1e5, -1e5, -2e5, 1, 2, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0 };

	double double_roots[6] = { 3, -1, 1, -2, 2, -1};
	double single_roots[2] = { -1 , 0 };
	double check_x1 = 0, check_x2 = 0;
	int check_n = 0;
	int passed = 0;

	//double roots
	for (int i = 0; i < 3; ++i)
	{
		check_n = super_pooper_squareSolver(coeffs[3 * i], coeffs[3 * i + 1], coeffs[3 * i + 2], &check_x1, &check_x2);
		
		if (checker(check_n, check_x1, check_x2, 2, double_roots[2 * i], double_roots[2 * i + 1])) passed = 1;
		else passed = 0;

		if (passed) printf("Test #%d passed.\n", i + 1);
		else printf("Test #%d failed. nRoots: %d, x1: %lg, x2: %lg.\n", i + 1, check_n, check_x1, check_x2);
	}

	//single roots
	for (int i = 3; i < 5; ++i)
	{
		check_n = super_pooper_squareSolver(coeffs[3 * i], coeffs[3 * i + 1], coeffs[3 * i + 2], &check_x1, &check_x2);
		
		if (checker(check_n, check_x1, check_x1, 1, single_roots[i - 3], single_roots[i - 3])) passed = 1;
		else passed = 0;

		if (passed) printf("Test #%d passed.\n", i + 1);
		else printf("Test #%d failed. nRoots: %d, x1: %lg.\n", i + 1, check_n, check_x1);
	}

	//no root
	check_n = super_pooper_squareSolver(coeffs[3 * 5], coeffs[3 * 5 + 1], coeffs[3 * 5 + 2], &check_x1, &check_x2);

	if (check_n == 0) passed = 1;
	else passed = 0;
	
	if (passed) printf("Test #%d passed.\n", 6);
	else printf("Test #%d failed. nRoots: %d, x1: %lg.\n", 6, check_n, check_x1);

	//inf root
	check_n = super_pooper_squareSolver(coeffs[3 * 6], coeffs[3 * 6 + 1], coeffs[3 * 6 + 2], &check_x1, &check_x2);

	if (check_n == INF) passed = 1;
	else passed = 0;

	if (passed) printf("Test #%d passed.\n", 7);
	else printf("Test #%d failed. nRoots: %d, x1: %lg.\n", 7, check_n, check_x1);
}