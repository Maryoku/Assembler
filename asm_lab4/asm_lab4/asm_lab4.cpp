#include "stdio.h"
#pragma warning (disable: 4996)

int main()
{
	int a;

	printf("Please, tell me number: ");
	scanf("%d", &a);
	printf("%d! = ", a);

	_asm
	{
		mov eax, a;
		push eax;
		call fact;
		add esp, 4;
		mov a, eax;
		jmp ext;

	fact:
		mov eax, [esp + 4];
		cmp eax, 1;
		jne calc;
		ret;

	calc:
		dec eax;
		push eax
			call fact
			add esp, 4
			imul[esp + 4];
		ret;

	ext:
	}

	printf("%d\n", a);

	return 0;
}

