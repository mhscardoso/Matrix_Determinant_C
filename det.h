void copy(int column, int order, double arr[order][order])
{
	int i, k;

	// Lines
	for(i = 0; i < order - 1; ++i)
	{
		for (k = 0; k < order; ++k)
		{
			arr[i][k] = arr[i + 1][k];

			if (i == order - 2)
			{
				arr[i + 1][k] = 0;
			}
		}

	}

	// Columns
	for (i = 0; i < order - 1; ++i)
	{
		for (k = 0; k < order - 1; ++k)
		{
			if (k >= column)
			{
				arr[i][k] = arr[i][k + 1];
			}

			if (k == order - 2)
			{
				arr[i][k + 1] = 0;
			}
		}
	}

}

double det(int order, double arr[order][order])
{

	double value = 0;

	if(order == 1)
	{
		return arr[0][0];
	}

	double copied[order][order];
	double copied2[order - 1][order - 1];

	for (int i = 0; i < order; ++i)
	{

		for (int a = 0; a < order; ++a)
		{
			for (int b = 0; b < order; ++b)
			{
				copied[a][b] = arr[a][b];
			}
		}

		copy(i, order, copied);

		for (int a = 0; a < order - 1; ++a)
		{
			for (int b = 0; b < order - 1; ++b)
			{
				copied2[a][b] = copied[a][b];
			}
		}

		if (i % 2 == 0)
		{
			value += arr[0][i] * det(order - 1, copied2);
		}
		else
		{
			value -= arr[0][i] * det(order - 1, copied2);

		}

	}

	return value;
}