#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int inputArg(double *arg);
int inputN(double *n);

double arSin(double arg)
{
	double ang = asin(arg);
	double res = pow((ang/arg), 2);
	return res;
}

double sumAll(double arg, double n, int *cnt)
{
	double x1 = 0; // пердыдущий элемент ряда
	double x2 = 1; //следующий элемент ряда
	double res = 1;
	int i = 1;
	double y = arg*arg;
	while (fabs(x1 - x2) >= n)
	{
		x1 = x2;
		x2 = x1 *  (4 * i * i * y) / ((2 * i + 1) * (2 * i + 2));
		res += x2;
		i++;
		*cnt += 1;
	}
	return res;
}

int main()
{
	double arg;
	double n;
	int cnt = 0;
	int inp = 10;
	while (inp != 0)
	{
		printf("Enter arg: ");
		inp = inputArg(&arg);
	/*	printf(" debug: inp = %d\n", inp);
		printf(" debug: arg = %lf\n", arg);*/
		if(inp == 3)
			return 0;
	}
	inp = 10;
	while (inp != 0)
	{
		printf("Enter accurasy: ");
		inp = inputN(&n);
		/*printf(" debug: inp = %d\n", inp);
		printf(" debug: n = %lf\n", n);*/
		if(inp == EOF)
			return 0;
		
	}
	double left = arSin(arg);
	double right = sumAll(arg, n, &cnt);
	printf("arSin = %.15lf\n", left);
	printf("Row = %.15lf\n", right);
	printf("count = %d\n", cnt + 1);
	return 0;
}

int inputArg(double *arg)
{
	int scr;
	double num;
	char c;
	scr = scanf("%lf%c", &num, &c);
	if (scr == EOF)
		{
		    printf("вы прожали ctrl + D\n");
			return 3;
		}

	if ((scr == 0) || (c != '\n'))
	{
	    while (getchar() != '\n'){}
	    printf("некорректный ввод\n");
		return 1;
	}
	
		
	if ((scr == 2) && (c == '\n'))
	{
	   if ((num >= -1) && (num <= 1 ))
	   	{
	   	    *arg = num;
	   		return 0;
	   	}
	   	else
	   	{
	   	    printf("Неверный диапазон\n");
	   		return 2;
	   	}
	}
	
	
}

int inputN(double *n)
{
	double num;
	char c;
	int scr = scanf("%lf%c", &num, &c);
	if (scr == EOF)
	{
	    printf("вы прожали ctrl + D\n");
		return EOF;
	}

	if ((scr == 0) || (c != '\n'))
	{
	    while (getchar() != '\n'){}
	    printf("некорректный ввод\n");
		return 1;
	}
		
	if ((scr == 2) || (c == '\n'))
	{
	    if ((num > 0) && (num < 1.0))
	    {
	    	*n = num;
	    	return 0;
	    }
	    else
	    {
	        printf("Неверный диапазон\n");
	        return 2;
	    }
	}
}
