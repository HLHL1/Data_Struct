#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Heap.h"
void HeapInit(Heap* hp, HeapDateType* a, size_t n)
{
	assert(hp);
	hp->_a = (HeapDateType*)malloc(n*sizeof(HeapDateType));
	hp->_size = n;
	hp->_capacity = n;
	for (size_t i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
}
void Swap(HeapDateType* x, HeapDateType* y)
{
	HeapDateType tmp = *x;
	*x = *y;
	*y = tmp;
}
void HeapAdjustDown(Heap* hp, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < hp->_size)
	{
		if (child+1<hp->_size&&hp->_a[child + 1]>hp->_a[child])//·ÀÖ¹Ô½½ç
		{
			child++;
		}
		if (hp->_a[child]>hp->_a[parent])
		{
			Swap(&(hp->_a[child]), &(hp->_a[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapMake(Heap* hp)
{
	assert(hp);
	for (int i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		HeapAdjustDown(hp, i);
	}
}
void HeapAdjustUp(Heap *hp, int root)
{
	int child = root;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp->_a[child] > hp->_a[parent])
		{
			Swap(&(hp->_a[child]), &(hp->_a[parent]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}
}
void CheckCapacity(Heap* hp)
{
	HeapDateType* newbase = (HeapDateType*)realloc(hp->_a, sizeof(HeapDateType)*hp->_capacity * 2);
	hp->_a = newbase;
	hp->_capacity += hp->_capacity;
}
void HeapPush(Heap* hp, HeapDateType x)
{
	assert(hp);
	CheckCapacity(hp);
	hp->_size++;
	hp->_a[hp->_size - 1] = x;
	HeapAdjustUp(hp, hp->_size - 1);
	
}
void HeapPop(Heap* hp)
{
	if (hp->_size > 0)
	{
		Swap(&(hp->_a[0]), &(hp->_a[hp->_size - 1]));
		hp->_size--;
	    HeapAdjustDown(hp, 0);
		
	}
}
size_t HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
size_t HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
HeapDateType HeapTop(Heap* hp)
{
	assert(hp&&hp->_size>0);
	return hp->_a[0];
}
void HeapSort(Heap* hp)
{
	if (hp->_size > 0)
	{
		int flag = hp->_size;
		while (hp->_size>0)
		{
			Swap(&(hp->_a[0]), &(hp->_a[hp->_size - 1]));
			hp->_size--;
			HeapAdjustDown(hp, 0);
		}
		hp->_size = flag;
	}
}
void HeapPrint(Heap *hp)
{
	assert(hp);
	for (size_t i=0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	HeapDateType arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	HeapInit(&hp, arr, sizeof(arr) / sizeof(HeapDateType));
	HeapMake(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 100);
	HeapPrint(&hp);
	HeapSort(&hp);
	HeapPrint(&hp);
}

