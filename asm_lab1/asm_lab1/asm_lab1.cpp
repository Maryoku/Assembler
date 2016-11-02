#include "stdio.h"
#pragma warning (disable: 4996)

int main()
{
	int a, b, c, d, e, x;

	printf("Please, tell me five number between(1, 100):\n");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	//x=(((a+b)*c)-d)/e
	//1.a+b
	//2.1*c
	//3.2-d
	//4.3/e

	_asm
	{
		mov eax, a;
		mov ebx, b;
		add eax, ebx;
		mov ebx, c;
		imul eax, ebx;
		mov ebx, d;
		sub eax, ebx;
		mov ebx, e;
		cdq;
		idiv ebx;
		mov x, eax;
	}

	printf("(((%d + %d) * %d) - %d) / %d = %d\n", a, b, c, d, e, x);
}
