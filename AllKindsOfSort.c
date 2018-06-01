#define _CRT_SECURE_NO_WARNINGS 
//1.实现插入、希尔、选择、堆排、冒泡、快排、归并排序 
//2.总结各个排序的性能、稳定性等优缺点。
#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>

void Print(int* a, size_t n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


//插入排序（升序）
//基本思想：
//当插入第i(i<=1)个元素时，前面的a[0],a[1]....a[i-1]已经排好序，此时将a[i]与a[i-1],a[i-2]...的顺序进行比较，
//找到插入位置即将a[i]插入,原来位置上的元素按顺序后移
void InsertSort(int* a, size_t n)
{
	assert(a);
	//i表示要插的数
	for (int i = 1; i < n; i++)
	{
		int tmp = a[i],j=i;
		//将j插入到以j-1为结束的有序区间
		for ( j = i; j >0; j--)
		{
			if (tmp < a[j-1])
			{
				a[j] = a[j-1];
			}
			else
			{
				break;
			}
		}
		a[j] = tmp;
	}

}


//希尔排序
//又称缩小增量排序，是对直接插入排序的优化
//先预排序，再直接排序
void ShellSort(int* a, size_t n)
{
	size_t gap = n;
	assert(a);
	while (gap>1)
	{
		gap = gap / 3+1;
		for (int j = gap; j < n; j = j + gap)
		{
			int tmp = a[j],k=j;
			for (k = j; k>0; k = k - gap)
			{
				if (a[k-gap]>tmp)
				{
					a[k] = a[k - gap];
				}
				else
				{
					break;
				}
			}
			a[k] = tmp;
		}
		/*printf("第%d趟排序->", i);
		i++;
		Print(a, n);*/
	}
}


//直接选择排序（优化版，一次选两个，选出最大值和最小值）
//void sawp(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
void SelectSort(int* a, size_t n)
{
	size_t begin = 0, end = n - 1;
	while (begin < end)
	{
		size_t k = begin + 1,max=begin,min=begin;
		while (k <= end)
		{
			if (a[min] > a[k])
			{
				min = k;
			}
			if (a[max] < a[k])
			{
				max = k;
			}
			k++;
		}
		//最大的数在begin的位置，最小的数在end的位置，这个时候如果交换两次的话就会回到原来的位置（相当于没有交换）
		if ((min == end)&&(max==begin))
		{
			//sawp(&a[min], &a[begin]);
			continue;
		}
		/*sawp(&a[min], &a[begin]);
		sawp(&a[max], &a[end]);
		begin++;*/
		end--;
		printf("第%d趟排序->", begin);
		Print(a, n);
	}
}

//堆排序
void sawp(int* c, int* b)
{
	int tmp = *c;
	*c = *b;
	*b = tmp;
}
void AdjustBwon(int* a, size_t n,size_t m)
{
	size_t parent = m, child = 2 * parent + 1;
	while (child < n)
	{
		//防止数组越界，并且找到左右孩子结点中的最大值
		if (child + 1 < n&&a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			sawp(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, size_t n)
{
	int j = 1;
	assert(a);
	//建堆（大堆）
	for (int i = n / 2; i >= 0; i--)
	{
		//向下调整
		AdjustBwon(a,n, i);
	}
	//排序
	for (int i = n-1; i>0; i--)
	{
		sawp(&a[i], &a[0]);
		AdjustBwon(a, i, 0);
		printf("第%d趟排序->", j++);
		Print(a, n);
	}
}

//冒泡排序

void BubbleSort(int* a, size_t n)
{
	assert(a);
	int k=1;
	for (int i = n-1; i>0; i--)
	{
		//哨兵，优化作用，一旦排好顺序，就会跳出循环
		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j]>a[j + 1])
			{
				flag = 1;
				sawp(&a[j], &a[j + 1]);
			}
		}
		printf("第%d趟排序->", k++);
		Print(a, n);
		if (flag == 0)
		{
			break;
		}
	}
}

//快速排序
//找最右边的元素做key
void QuickSort1(int *a, int _left,int _right)
{
	int left = _left, right = _right;
	if (left < right)
	{
		int key = a[_right];
		while (left < right)
		{
			//left找大
			while (left < right&&a[left] <= key)
			{
				left++;
			}
			a[right] = a[left];
			//right找小
			while (left < right&&a[right] >= key)
			{
				right--;
			}
			a[left] = a[right];
		}
		a[left] = key;
		QuickSortPart1(a, _left, left - 1);
		QuickSortPart1(a, left + 1, _right);
	}
}
//找中间数
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

//挖矿法
//找最右边的元素做key
int QuickSortPart2(int *a, int _left, int _right)
{
	int left = _left, right = _right;
     int key = a[_right];
		while (left < right)
		{
			//left找大
			while (left < right&&a[left] <= key)
			{
				left++;
			}
			a[right] = a[left];
			//right找小
			while (left < right&&a[right] >= key)
			{
				right--;
			}
			a[left] = a[right];
		}
		a[left] = key;
	return left;
}
//前后指针法
int QuickSortPart3(int *a, int left, int right)
{
	//自己的代码有点繁琐
	int cur = left, prev = left-1,key;
	key = a[right];
	while (cur <= right)
	{
	    //如果a[cur]比key大，cur就走prev不动
		if (a[cur]> key)
		{
			cur++;
		}
		else
		{
		    //如果a[cur]比key小，就比较a[cur]和 a[++prev]是否相等，相等cur就往前走，否则两个值交换
			if (a[cur] == a[++prev])
			{
				cur++;
			}
			else
			{
				sawp(&a[cur], &a[prev]);
			}
		}

	}
	return prev;
	/*int key = a[right];
	int prev = left - 1, cur = left;
	while (cur < right)
	{
		if ((a[cur] <= key)&&(++prev != cur))
		{
			sawp(&a[cur], &a[prev]);
		}
		cur++;
	}
	sawp(&a[++prev], &a[right]);
	return prev;*/
}
void QuickSort(int* a, int left,int right)
{
	//自己的代码有点繁琐
	/*int div = QuickSortPart1(a, left, right);
	int begin1 = left, end1 = div - 1;
	int begin2 = div + 1, end2 = right;
	assert(a);
	if (begin1 < end1)
	{
		QuickSort(a, begin1, end1);
	}
	if (begin2 < end2)
	{
		QuickSort(a, begin2, end2);
	}*/
	int div;
	assert(a);
	if (left >= right)
	{
		return;
	}
	//div = QuickSortPart1(a, left, right);
	//div = QuickSortPart2(a, left, right);
	div = QuickSortPart3(a, left, right);
	printf("div->%d\n", div);
	QuickSort(a, left,div-1);
	QuickSort(a, div+1, right);
}

//归并排序
//递归
void Merge(int* a,size_t left,size_t right)
{
	int mid=(right-left)>>1;
	int begin1, end1, begin2, end2,i=0;
	int *tmp = (int*)malloc(sizeof(int)* 100);
	memset(tmp, 0, sizeof(a[0])*100);
	assert(a&&tmp);
	if (left >= right)
	{
		return;
	}
	//划分
	Merge(a,left,left+mid);
	Merge(a, left + mid+1, right);
	//归并
	begin1 = left, end1 = mid+left;
	begin2 =left+ mid + 1, end2 = right;
	while ((begin1 <= end1)&&(begin2 <= end2))
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1];
			begin1++;
		}
		else
		{
			tmp[i++] = a[begin2];
			begin2++;
		}
	}
	while (begin1 <=end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (i = left; i <= right; i++)
	{
		a[i] = tmp[i-left];
	}
	free(tmp);
}
//归并排序（非递归）
//二路归并
void MergeR(int* a,int begin,int mid,int end)
{
	int i=0;
	int *tmp = (int*)malloc(sizeof(int)* 100);
	int begin1 = begin, end1 =mid;
	int begin2 =mid + 1, end2 = end;
	memset(tmp, 0, sizeof(a[0])*100);
	assert(a&&tmp);
	while ((begin1 <= end1) && (begin2 <= end2))
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1];
			begin1++;
		}
		else
		{
			tmp[i++] = a[begin2];
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (int k = begin; k <= end; k++)
	{
		a[k] = tmp[k - begin];
	}
	free(tmp);
}
//一趟二路归并
void MergePass(int*a,size_t n,int length)
{
	int i = 0;
	assert(a);
	//归并时两个区间的划分
	for (i = 0; i+2*length-1 < n; i += length * 2)
	{
		MergeR(a, i,i+length-1,i+2*length-1);
	}
	//这一步主要是解决当长度很大时，不足以构成俩个完整的归并区间时（此时就只能划分为两个区间），就把两个不完整的区间合并
	if (i + length - 1 <n - 1)
	{
		MergeR(a, i, i + length - 1, n-1);
	}
}
//归并
void MergeSortR(int* a, int n)
{
	assert(a);
	//每次划分的长度length=1,2,4,6,8.....
	for (int length = 1; length < n; length *= 2)
	{
		MergePass(a, n, length);
		printf("长度：%d->", length);
		Print(a, n);
	}
}


//计数排序
void CountSort(int* a, size_t n)
{
	int max = a[0], min = a[0],range,*tmp,index=0;
	assert(a);
	//找最大值最小值用来确定开数组的范围
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min>a[i])
		{
			min = a[i];
		}
	}
	range = max - min + 1;
	tmp = (int *)malloc(sizeof(int)*range);
	memset(tmp, 0, sizeof(a[0])*range);
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[index++] = i + min;
		}
	}
	free(tmp);
}
void Test()
{
    int a[] = { 9, 8, 7, 6, 5, 4,5, 3, 2, 1, 0 };
    //int a[] = { 2, 5, 4, 9, 3, 6, 8, 7,1, 0 };
	//int a[] = { 21, 25, 49, 25, 16, 8, 31, 41 };
	size_t n= sizeof(a) / sizeof(a[0]);
	int tmp[20] = { 0 };
	printf("原始数据:");
	Print(a, n);
	/*InsertSort(a, n);
	ShellSort(a, n);
	printf("最终排序：");
	Print(a, n);
	SelectSort(a, n);*/
	//HeapSort(a, n);
	//BubbleSort(a, n);
	//Merge(a, 0, n - 1, tmp);
	//MergeSortR(a, n);
	//CountSort(a, n);
	//QuickSortPart1(a, 0, n - 1);
	QuickSort(a, 0, n - 1);
	Print(a, n);
}
int main()
{

	Test();
	system("pause");
	return 0;
}