#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
#include<assert.h>
typedef struct TwoBitSet
{
	size_t* _bits;
	size_t _rang;
}TwoBitSet;
//初始化
void TBSInit(TwoBitSet* tbs, size_t rang)
{
	assert(tbs);
	//用两个比特位来表示一个值的状态，所以4个字节可以表示16个数的状态
	tbs->_bits = (size_t*)malloc(sizeof(size_t)*((rang >> 4) + 1));
	assert(tbs->_bits);
	//数组初始化
	memset(tbs->_bits, 0, sizeof(size_t)*((rang >> 4) + 1));
	tbs->_rang = rang;
}

int TBSGetValue(TwoBitSet* tbs, size_t x)
{
	size_t index, num;
	assert(tbs);
	index = x >> 4;
	num = x % 16;
	num *= 2;

	int value = tbs->_bits[index];
	value >>= num;
	return value&3;
}
void TBSSetValue(TwoBitSet* tbs, size_t x, int state)
{
	size_t index,num;
	assert(tbs);
	index = x >> 4;
	num = x % 16;
	num *= 2;
	//当状态为0的时候，我们要将对应位置（0或1）置为00
	if (state == 0)
	{
		//两种方法都可以
		//方法一
		tbs->_bits[index] &= ~(3 << num);
		//方法二
		/*tbs->_bits[index] &= ~(1 << num);
		tbs->_bits[index] &= ~(1 << (num+1));*/
	}
	else
	{
		//当状态为1的时候，我们要将对应位置（0或1）置为01
		if (state == 1)
		{

			tbs->_bits[index] |= (1 << num);
			tbs->_bits[index] &= ~(1 << (num + 1));
		}
		else
		{
			//当状态为2的时候，我们要将对应位置（0或1）置为10
			if (state == 2)
			{

				tbs->_bits[index] &= ~(1 << num);
				tbs->_bits[index] |= (1 << (num+1));
			}
			else
			{
				//当状态为3的时候，我们要将对应位置（0或1）置为11
				if (state == 3)
				{
					tbs->_bits[index] |= (3 << num);
					/*tbs->_bits[index] |= (1 << num);
					tbs->_bits[index] |= (1 << (num+1));*/
				}
				else
				{
					assert(1);
				}
			}
		}
	}

}
void TBSDestory(TwoBitSet* tbs)
{
	free(tbs->_bits);
}
//哈希位图
//给定100亿个整数，设计算法找到只出现一次的整数 
void Test1()
{
	TwoBitSet tbs;
	int value, a[] = { 0, 1, 1, 2, 2, 3, 4, 5, 5 };
	TBSInit(&tbs, 10);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		value = TBSGetValue(&tbs, a[i]);
		if (value <= 1)
		{
			TBSSetValue(&tbs, a[i], value + 1);
		}
	}
	//在这里遍历的时候举例子用的是0~10的数字范围，如果真得要100亿个数的话就要遍历所有整型数字0~2^32（有一个小技巧(size_t)-1）
	for (size_t i = 0; i <10/*(size_t)-1*/; i++)
	{
		if (TBSGetValue(&tbs, i) == 1)
		{
			printf("%d\n", i);
		}
	}
	TBSDestory(&tbs);
}
//哈希变形
//1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
void Test2()
{
	TwoBitSet tbs;
	int value, a[] = { 0, 1, 1, 2, 2,2, 3, 4, 5, 5 ,5,6,6,32,32,31};
	TBSInit(&tbs, 100);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		value = TBSGetValue(&tbs, a[i]);
		if (value <= 2)
		{
			TBSSetValue(&tbs, a[i], value + 1);
		}
	}
	
	for (size_t i = 0; i <100/*(size_t)-1*/; i++)
	{
		if (TBSGetValue(&tbs, i) <= 2 && TBSGetValue(&tbs, i)>0)
		{
			printf("%d\n", i);
		}
	}
	TBSDestory(&tbs);
}
int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}
//布隆过滤器 + 哈希切分 
//给两个文件，分别有100亿个query，我们只有1G内存，如何找到两个文件交集？分别给出精确算法和近似算法 
//如何扩展BloomFilter使得它支持删除元素的操作 
//如何扩展BloomFilter使得它支持计数操作 
//
//倒排索引 
//给上千个文件，每个文件大小为1K—100M。给n个设计算法对每个词找到所有包含它的文件，你只有100K内存
//
//
//
//
