#include<stdio.h>
struct book
{
	int a;
	int b;
}ref1,ref2;
int main()
{
	ref1.a=5;
	ref1.b=10;
	ref2=ref1;
	printf("%d and %d",ref2.a,ref2.b);
	return 0;
}
