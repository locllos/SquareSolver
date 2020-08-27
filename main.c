//SquareSolver 

#include <stdio.h>
#include <math.h>
#include <assert.h>

const int INF = -1;
const int epsilon = 1e-6;

int super_pooper_squareSolver(double a, double b, double c, double* pointer_x1, double* pointer_x2)
{	

	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(pointer_x1 != NULL);
	assert(pointer_x2 != NULL);
	assert(pointer_x2 != pointer_x1);

	printf("Trying to solve the square equation:\n(%lg)*x^2 + (%lg)*x + (%lg) = 0\n", a, b, c);

	if (a == 0) 
	{ 
		if (b == 0) 
		{
			if (c == 0) return INF;
			else return 0;
		}
		else 
		{ 
			(*pointer_x1) = -c/b; 

			return 1; 
		}
	}

	else
	{
		double discriminant = pow(b, 2) - 4*a*c;
		if (discriminant < 0) 
		{
			return 0;
		}
		else if (abs(discriminant - 0) < epsilon)
		{ 
			(*pointer_x1) = (-b)/(2*a);

			return 1;
		}
		else 
		{
			(*pointer_x1) = (-b + sqrt(discriminant))/(2*a);
			(*pointer_x2) = (-b - sqrt(discriminant))/(2*a);

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
	int amount_of_roots = super_pooper_squareSolver(a,b,c, &x1, &x2);

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