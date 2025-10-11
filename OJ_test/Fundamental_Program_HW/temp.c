#include <stdio.h>
int main()
{
	float data[3];
	while (scanf("%f%f%f", &data[0], &data[1], &data[2]) == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			int label = 0;
			float Min = 190;
			for (int k = 0; k < 3; k++)
			{
				if (data[k] != -1)
				{
					if (data[k] < Min)
					{
						Min = data[k];
						label = k;
					}
				}
			}
			data[label] = -1;
			if (i < 2)
				printf("%.1f ", Min);
			else
				printf("%.1f\n", Min);
		}
	}
	return 0;
}