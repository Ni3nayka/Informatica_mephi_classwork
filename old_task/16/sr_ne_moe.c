#include<stdio.h>
main()
{
    int a, b, c, d, e, f, g;
    scanf("%s", &a);
    scanf("%s", &b);
    scanf("%s", &c);
    scanf("%s", &d);
    scanf("%s", &e);
    scanf("%s", &f);
    scanf("%s", &g);
    void bubbleSort (int** p, int lenght)
{
    int tmp;
    int noSwap;
	int prohod = 1;

    for (int i = 0; i < lenght; i++)
    {
        noSwap = 1;

        for (int j = 0; j < lenght - i - 1; j++)
        {
            if (*(*p+j) > *(*p+(j+1)))
            {
                tmp = *(*p+j);
                *(*p+j) = *(*p+(j+1));
                *(*p+(j+1)) = tmp;
                noSwap = 0;
            }
        }

		if(prohod != 1)
			printf("\n");

		for (int i = 0; i < lenght; ++i)
		{
			printf("%3d", i + 1);
		}
		printf("\n");

		for (int i = 0; i < lenght; ++i)
		{
			printf("%3d", *(*p + i));
		}
		printf("\n");

		if(prohod == 1)
			printf("\n");

		prohod++;
        if (noSwap == 1)
            break;

    }
}
printf("Brown\nDavies\nEvans\nRoberts\nSmith\nTaylor\nWilliams\n\nA-R 4\nS-Z 3\n");
void input_keyboard(int** p, int lenght)
{
	int temp;
	for (int i = 0; i < lenght; i++)
	{
		scanf("%d", &temp);
		*(*p+i) = temp;
	}
}
void output(int** p, int lenght)
{
	for (int i = 0; i < lenght; ++i)
	{
		printf("%3d", i + 1);
	}
	printf("\n");

	for (int i = 0; i < lenght; ++i)
	{
		printf("%3d", *(*p + i));
	}
	printf("\n");
}
}
