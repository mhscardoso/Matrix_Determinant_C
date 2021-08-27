#include <stdio.h>
#include "det.h"

int main(void)
{
	// Determinant = 80
	double matrix[3][3] = {

		{1, 3, 4},
		{6, 2, 0},
		{1, 7, 5},
		
	};

	printf("%.3f\n", det(3, matrix));
}


