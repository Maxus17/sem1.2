#include <stdio.h>
#include <math.h>

int inputArg(double *arg);
int inputN(int *n);

double arcSin(double arg)
{
	double ang = asin(arg);
	double res = pow((ang / arg),2);
	return res;
}

double sumAll(double arg, int n)
{
    double y = arg * arg;
    double x2 = 1;
    double res = x2;
    for(int i = 1; i <= n; i++)
    {
    	x2 = x2 * (4 * i * i * y) / ((2 * i + 1) * (2 * i + 2));
    	res += x2;
    }
    return res;
}

int main()
{
    double arg;
    int n; 
    int inp = 5;
    while (inp != 0)
    {
    	printf("Enter arg: ");
    	inp = inputArg(&arg);
    	if(inp == 3){
    		return 0;
    	}
    }
   inp = 5;
    while (inp != 0)
    {
    	printf("Enter n: ");
    	inp = inputN(&n);
    	if(inp == 3){
    	   return 0;
    	}
    }
    double left = arcSin(arg);
    double right = sumAll(arg, n);
    printf("arcsin = %.15lf\n", left);
    printf("row_of_numb = %.15lf\n", right);
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
	    printf("Вы прожали ctrl + D\n");
		return 3;
	}
	
	if ((c != '\n') || (scr != 2))
	{
	    while (getchar() != '\n'){}
	    printf("Некоретный ввод\n");
		return 1;	
	}
	
	if ((c == '\n') && (scr == 2))
	{
		if ((num >= -1) && (num <= 1))
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

int inputN(int *n)
{
	int scr;
	int num;
	char c;
	scr = scanf("%d%c", &num, &c);
	if (scr == EOF)
	{
	    printf("Вы прожали ctrl + D\n");
		return 3;
	}

	if ((c != '\n') || (scr != 2))
	{
	    while (getchar() != '\n'){}
	    printf("Некоретный ввод\n");
		return 1;	
	}
		
	if ((c == '\n') && (scr == 2))
	{
		if (num > 0) 
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
