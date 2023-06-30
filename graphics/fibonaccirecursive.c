#include<stdio.h>
int fibonacci(int);
int main()
{
	int limit;
	printf("Enter the number of terms to be printed.");
	scanf("%d",&limit);
	fibonacci(limit);
	return 0;
}
int fibonacci(int num)
{
	int n1=0,n2=1,n3,count;
	printf("\n Fibonacci Series...\n");
	printf("1.%d\n 2.%d\n",n1,n2);
	for (count=3;count<=num;count++)
	{
		n3=n1+n2;
		printf("%d%d\n",count,n3);
		n1=n2;
		n2=n3;
	}
}
