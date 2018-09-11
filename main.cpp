#include <stdio.h>
#include <stdlib.h>
/*
**setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：将x
**中从第p位开始的n个（二进制）位设置为y中最右边n位的值，x的其余
**各位保持不变。
**invert(x, p, n)，该函数返回对x执行下列操作后的结果值：将x中从
**第p位开始的n个（二进制）位求反（即，1变成0，0变成1），x的其余
**各位保持不变。
**rightrot(x, n)，该函数返回将x循环右移（即从最右端移出的位将从
**最左端移入）n（二进制）位后所得到的值。
*/

int setbits(int x, int p, int n, int y);
int invert(int x, int p, int n);
int rightrot(int x, int n);

int main()
{
	int x, p, n, y;
	char *str;
	printf("INPUT is Decimal, RESULT is Binary.\n");
	printf("setbits INPUT: x, p, n, y: \n");
	scanf_s("%d%d%d%d", &x, &p, &n, &y);
	x = setbits(x, p, n, y);
	str = (char*)malloc(sizeof(x) * 8);
	_itoa(x, str, 2);
	printf("setbits RESULT: \n%s\n", str);
	free(str);
	
	printf("invert INPUT: x, p, n: \n");
	scanf_s("%d%d%d", &x, &p, &n);
	x = invert(x, p, n);
	str = (char*)malloc(sizeof(x) * 8);
	_itoa(x, str, 2);
	printf("invert RESULT: \n%s\n", str);
	free(str);

	printf("rightrot INPUT: x, n: \n");
	scanf_s("%d%d", &x, &n);
	x = rightrot(x, n);
	str = (char*)malloc(sizeof(x) * 8);
	_itoa(x, str, 2);
	printf("rightrot RESULT: \n%s\n", str);
	free(str);

	return 0;
}

int setbits(int x, int p, int n, int y)
{
	return (x & ((~0 << n + p - 1) + ~(~0 << p - 1))) 
		+ ((y << p - 1) & ~((~0 << n + p - 1) + ~(~0 << p - 1)));
}

int invert(int x, int p, int n)
{
	return (x & (~0 << n + p - 1) + ~(~0 << p - 1))
		+ ~(x | (~0 << n + p - 1) + ~(~0 << p - 1));
}

int rightrot(int x, int n)
{
	return (x >> (sizeof(x) * 8 - n) & ~(~0 << n)) + x << n;
}