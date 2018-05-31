#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<assert.h>
typedef struct BitMap
{
	size_t* _bits;
	size_t* _bitV;
	size_t _range;
}BitMap;

void BitMapInit(BitMap* bm, size_t range)
{
	assert(bm);
	//一个字节是8个比特位，size_t是4个字节，所以range要除以32（位移操作符更加精确）
	bm->_bits = (size_t*)malloc(sizeof(size_t)*((range>>5) + 1));
	assert(bm->_bits);
	memset(bm->_bits, 0, sizeof(size_t)*((range >> 5) + 1));
	bm->_range = range;
}

void BitMapSet(BitMap* bm, size_t x)
{
	size_t index,num;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	//位移操作符优先级比较低，所以要时时刻刻记得带括号
	bm->_bits[index] |= (1 << num);
}

//感觉这个功能比较像删除就是将某一位的1(但是也不一定是1还有可能时候0）致为0
void BitMapReset(BitMap* bm, size_t x)
{
	size_t index, num;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	bm->_bits[index] &=( ~(1<<num));
}

// x存在返回非0值，不存在返回0 
int BitMapTest(BitMap* bm, size_t x)
{
	size_t index, num;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	//下面这两种方法都可以
	return bm->_bits[index] & (1 << num);
	//return (bm->_bits[index] >> num) % 2;
}

//附加题 
//1.给定100亿个整数，设计算法找到只出现一次的整数 
void BitMapInitF(BitMap* bm, size_t range)
{
	assert(bm);
	//一个字节是8个比特位，size_t是4个字节，所以range要除以32（位移操作符更加精确）
	bm->_bits = (size_t*)malloc(sizeof(size_t)*((range >> 5) + 1));
	bm->_bitV = (size_t*)malloc(sizeof(size_t)*((range >> 5) + 1));
	assert(bm->_bits);
	assert(bm->_bitV);
	memset(bm->_bits, 0, sizeof(size_t)*((range >> 5) + 1));
	memset(bm->_bitV, 0, sizeof(size_t)*((range >> 5) + 1));
	bm->_range = range;
}

void BitMapSetF(BitMap* bm, size_t x)
{
	size_t index, num,flag,flag1;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	flag1 = 1 << num;
	flag = (bm->_bits[index]) & (1 << num);
	//位移操作符优先级比较低，所以要时时刻刻记得带括号
	if (!flag)
	{
		bm->_bits[index] |= (1 << num);
	}
	else
	{
		bm->_bitV[index] |= (1 << num);
	}
}

//如果是出现一次的就返回该值，如果不是就返回-1
int BitMapTestF(BitMap* bm, int x)
{
	size_t index, num;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	if ((bm->_bits[index] & (1 << num)) && (bm->_bitV[index] & (1 << num)) == 0)
	{
		return x;
	}
	else
	{
		return -1;
	}

}

void BMFindOne()
{
	BitMap bm;
	BitMapInitF(&bm, 100);
	BitMapSetF(&bm, 32); 
	BitMapSetF(&bm, 64);
	
	for (int i = 0; i < bm._range; i++)
	{
		if (BitMapTestF(&bm,i) != -1)
		{
			printf("%d\n", BitMapTestF(&bm,i));
		}
	}

}
//2.给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集
void BMFindInter(BitMap* bm1, BitMap* bm2)
{
	assert(bm1&&bm2);
	for (int i = 0; i < (bm1->_range / 32) + 1; i++)
	{
		bm1->_bits[i] = bm1->_bits[i] & bm2->_bits[i];
	}
	for (int i = 0; i < bm1->_range; i++)
	{
		if (BitMapTest(bm1,i))
		{
			printf("%d\n", i);
		}
	}
}
void BMFindTwo()
{
	BitMap bm1;
	BitMap bm2;
	BitMapInit(&bm1, 100);
	BitMapSet(&bm1, 44);
	BitMapSet(&bm1, 32);
	BitMapSet(&bm1, 32);
	BitMapSet(&bm1, 22);
	BitMapInit(&bm2, 1000);
	BitMapSet(&bm2, 44);
	BitMapSet(&bm2, 33);
	BitMapSet(&bm2, 10);
	BitMapSet(&bm2, 29);
	BMFindInter(&bm1, &bm2);
}

//3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数

void BitMapInitFT(BitMap* bm, size_t range)
{
	assert(bm);
	//一个字节是8个比特位，size_t是4个字节，所以range要除以32（位移操作符更加精确）
	bm->_bits = (size_t*)malloc(sizeof(size_t)*((range >> 5) + 1));
	bm->_bitV = (size_t*)malloc(sizeof(size_t)*((range >> 5) + 1));
	assert(bm->_bits);
	assert(bm->_bitV);
	memset(bm->_bits, 0, sizeof(size_t)*((range >> 5) + 1));
	memset(bm->_bitV, 0, sizeof(size_t)*((range >> 5) + 1));
	bm->_range = range;
}

void BitMapSetFT(BitMap* bm, size_t x)
{
	size_t index, num, flag,flag1;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	flag = (bm->_bits[index]) & (1 << num);
	flag1 = (bm->_bitV[index]) & (1 << num);
	//位移操作符优先级比较低，所以要时时刻刻记得带括号
	if ((flag==0)&&(flag1==0))
	{
		bm->_bits[index] |= (1 << num);
	}
	else
	{
		if (flag1 == 1)
		{
			bm->_bitV[index] &= (~(1 << num));
		}
		else
		{
			bm->_bitV[index] |= (1 << num);
			bm->_bits[index] &= (~(1 << num));
		}
	}
}

//如果是出现一次的就返回该值，如果不是就返回-1
int BitMapTestFT(BitMap* bm, int x)
{
	size_t index, num;
	assert(bm);
	index = x >> 5;
	num = x % 32;
	if ((bm->_bits[index] & (1 << num)) ||(bm->_bitV[index] & (1 << num)))
	{
		return x;
	}
	else
	{
		return -1;
	}

}

void BMFindThree()
{
	BitMap bm;
	BitMapInitFT(&bm, 100);
	BitMapSetFT(&bm, 32);
	BitMapSetFT(&bm, 32);
	BitMapSetFT(&bm, 36);
	BitMapSetFT(&bm, 32);
	BitMapSetFT(&bm, 64);
	BitMapSetFT(&bm, 64);

	for (int i = 0; i < bm._range; i++)
	{
		if (BitMapTestFT(&bm, i) != -1)
		{
			printf("%d\n", BitMapTestFT(&bm, i));
		}
	}

}
//
int main()
{
	//BMFindOne();
	//BMFindTwo();
	BMFindThree();
	/*BitMap bm;
	BitMapInit(&bm, 1000);
	BitMapSet(&bm, 40);
	BitMapSet(&bm, 32);
	BitMapSet(&bm, 31);
	BitMapSet(&bm, 32);*/
	///*BitMapReset(&bm, 32);
	//BitMapReset(&bm, 31);*/
	//if (BitMapTest(&bm, 32))
	//{
	//	printf("存在\n");
	//}
	//else
	//{
	//	printf("不存在\n");
	//}
	system("pause");
	return 0;
}
//附加题 
//1.给定100亿个整数，设计算法找到只出现一次的整数 
//2.给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集 
//3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
//

