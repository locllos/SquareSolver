
#include <stdio.h>
#include <math.h>
#include <assert.h>

const int INF = -1;
const double epsilon = 1e-9;

bool is_zero(double n)
{
	return (abs(n) < epsilon) ? true : false;
}

/*!
Решает квадратное уравнение
\param[in]  a  коэффициент квадратного уравнения при x^2
\param[in]  b  коэффициент квадратного уравнения при x^1
\param[in]  c  коэффициент квадратного уравнения при x^0
\param[out] x1 указатель на корень квадратного уравнения
\param[out] x2 указатель на корень квадратного уравнения
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

	printf("Trying to solve the square equation:\n(%lg)*x^2 + (%lg)*x + (%lg) = 0\n", a, b, c);

	if (is_zero(a)) 
	{ 
		if (is_zero(b)) 
		{
			if (c == 0) return INF;
			else return 0;
		}
		else 
		{ 
			(*ptr_x1) = -c/b; 

			return 1; 
		}
	}

	else
	{
		double discriminant = b*b - 4 * a * c;
		printf("%lg\n", discriminant);
		if (discriminant < 0 && !is_zero(discriminant))  
		{
			return 0;
		}
		else if (is_zero(discriminant))
		{ 
			(*ptr_x1) = (-b)/(2 * a);

			return 1;
		}
		else 
		{
			(*ptr_x1) = (-b + sqrt(discriminant))/(2 * a);
			(*ptr_x2) = (-b - sqrt(discriminant))/(2 * a);

			return 2;
		}

	}
}


int main()
{	
	printf("Welcome! This is SquareSolver programm.\nInput a, b, c coefficients of square equation.\n");

	double a = 0, b = 0, c = 0;
	scanf("%lg %lg %lg", &a,&b, &c);

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

			printf("Two roots:\nx1 = %lg\nx2 = %lg\n", x1,x2);
			break;

		case(INF): 

			printf("Infinite amount of roots\n");
			break;

		default:

			printf("I do not fucking know what happened, but if you wanna know: amount of roots = %d\n", amount_of_roots);
			break;
	}

}