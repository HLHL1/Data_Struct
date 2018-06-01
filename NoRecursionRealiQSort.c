#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"Stack.h"
#include<assert.h>

void Print(int* a, size_t n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//找中间数
void sawp(int* c, int* b)
{
	int tmp = *c;
	*c = *b;
	*b = tmp;
}
int GetMidIndex(int*a, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else
		{
			if (a[left] < a[right])
			{
				return right;
			}
			else
			{
				return left;
			}
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else
		{
			if (a[left] < a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
	}
}
//三数取中法(快排的优化）(左右指针法)
int QuickSortPart1(int *a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	int key, begin, end;
	sawp(&a[mid], &a[right]);
	key = a[right];
	begin = left, end = right;
	while (begin < end)
	{
		//begin找大
		while (begin < end&&a[begin] <= key)
		{
			begin++;
		}
		//end找小
		while (begin < end&&a[end] >= key)
		{
			end--;
		}
		if (begin < end)
		{
			sawp(&a[begin], &a[end]);
		}
	}
	sawp(&a[begin], &a[right]);
	return begin;
}

void QuickSortR(int* a, int left, int right)
{
	int div,topl,topr;
	Stack s;
	assert(a);
	if (left >= right)
	{
		return 0;
	}
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		topr = StackTop(&s);
		StackPop(&s);
		topl = StackTop(&s);
		StackPop(&s);
		div = QuickSortPart1(a, topl, topr);
		if (topl < div - 1)
		{
			StackPush(&s, topl);
			StackPush(&s, div-1);
		}
		if (div + 1 < topr)
		{
			StackPush(&s, div+1);
			StackPush(&s, topr);
		}
	}
}
int main()
{

	//int a[] = { 9, 8, 7, 6, 5, 4, 5, 3, 2, 1, 0 };
	//int a[] = { 2, 5, 4, 9, 3, 6, 8, 7,1, 0 };
	int a[] = { 21, 25, 49, 25, 16, 8, 31, 41 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSortR(a, 0, n - 1);
	Print(a, n);
	system("pause");
	return 0;

}
