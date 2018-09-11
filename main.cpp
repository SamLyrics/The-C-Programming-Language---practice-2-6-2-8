#include <stdio.h>
#include <stdlib.h>
/*
**setbits(x, p, n, y)���ú������ض�xִ�����в�����Ľ��ֵ����x
**�дӵ�pλ��ʼ��n���������ƣ�λ����Ϊy�����ұ�nλ��ֵ��x������
**��λ���ֲ��䡣
**invert(x, p, n)���ú������ض�xִ�����в�����Ľ��ֵ����x�д�
**��pλ��ʼ��n���������ƣ�λ�󷴣�����1���0��0���1����x������
**��λ���ֲ��䡣
**rightrot(x, n)���ú������ؽ�xѭ�����ƣ��������Ҷ��Ƴ���λ����
**��������룩n�������ƣ�λ�����õ���ֵ��
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