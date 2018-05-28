#define _CRT_SECURE_NO_WARNINGS
#include"Hash.h"


size_t GetNextPrimeNum(size_t x)
{
	//const在C语言中修饰变量使变量具有常属性变量
	//但是在c++中相当于常量
	const int _PrimeSize = 28;
	static const unsigned long _PrimeList[28/*_PrimeSize*/] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul, 1543ul, 3079ul, 6151ul, 12289ul, 24593ul, 49157ul, 98317ul, 196613ul, 393241ul, \
		786433ul, 1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul, 50331653ul, 100663319ul, 201326611ul, 4026531889ul, \
		805306457ul, 1610612741ul, 3221225473ul, 4294967291ul

	};
	for (int i = 0; i<_PrimeSize; i++)
	{
		if (x<_PrimeList[i])
		{
			return _PrimeList[i];
		}
	}
}
void HashTableInit(HashTable* ht,size_t capacity)
{
	assert(ht&&capacity>0);//解决下面增容有除0的bug
	ht->_tables = (HashNode*)malloc(sizeof(HashNode)*capacity);
	assert(ht->_tables);//预判内存分配失败

	//初始化申请的数组（状态必须初始化）关键字最好不要初始化，因为如果改变关键字类型就会出现问题
	for (size_t  i = 0; i < capacity; i++)
	{
		ht->_tables[i]._status = EMPTY;
	}
	ht->_size = 0;
	ht->_capacity = capacity;
}


void CheckCapacity(HashTable* ht)
{
	//增容realloc不可以用,因为realloc是在原先内存的基础上再在后面增加空间但是哈希表的建立实在容量基础上计算的
	//但是哈希表的建立是在容量基础上计算的,这样会倒置有的值会被覆盖掉
	if (ht->_size * 10 / ht->_capacity >=7)
	{
		HashTable newht;
		HashTableInit(&newht, GetNextPrimeNum(ht->_capacity));
		//复用
		for (size_t i=0; i < ht->_capacity; i++)
		{
			if (ht->_tables[i]._status == EXITS)
			{
				HashTableInsert(&newht, ht->_tables[i]._key);
				newht._size++;
			}
		}
		HashTableDestory(ht);
		ht->_tables = newht._tables;
		ht->_size = newht._size;
		ht->_capacity = newht._capacity;
	}
}


size_t HashFunc(HashTable* ht, KeyType key)
{
	return key%ht->_capacity;
}

//成功：0  失败：-1
int HashTableInsert(HashTable* ht, KeyType key)
{
	size_t index = 0,i=1;
	assert(ht);
	CheckCapacity(ht);
	index = HashFunc(ht, key);
	//结点状态只有为空的时候，才会插入数据
	while (ht->_tables[index]._status != EMPTY)
	{
		if (ht->_tables[index]._key == key)
		{
			return -1;
		}
		index += i*i;
		index %= ht->_capacity;
		++i;
		/*++index;
		if (index == ht->_capacity)
		{
			index = 0;
		}*/
	}
	ht->_tables[index]._key = key;
	ht->_tables[index]._status = EXITS;
	ht->_size += 1;
	return 0;

}

//隐患1：如果表里的值满了，就会死循环---上面增容会解决这个问题
//隐患2：如果一个数已经被删除了,但是还是会表示存在——问题已解决
HashNode*  HashTableFind(HashTable* ht, KeyType key)
{
	size_t index,i = 1;;
	assert(ht);
	index = HashFunc(ht, key);
	while (ht->_tables[index]._status != EMPTY)
	{
		//防止一个数已经被删除了, 但是还是会表示存在
		if (ht->_tables[index]._key == key)
		{
			if (ht->_tables[index]._status == EXITS)
			{
				return &ht->_tables[index];
			}
			else
			{
				return NULL;
			}
		}
		//二次探测
		index += i*i;
		index %= ht->_capacity;
		++i;
		//线性探测
		/*index++;
		if (index == ht->_capacity)
		{
			index = 0;
		}*/
	}
	return NULL;
}

//删除结点就是将其状态设置为删除状态
int HashTableRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	HashNode* node = HashTableFind(ht, key);
	if (node)
	{
		node->_status = DELETE;
		ht->_size--;
		return 0;
	}
	else
	{
		return -1;
	}
}

void HTPrin(HashTable* ht)
{
	assert(ht);
	for (size_t i = 0; i < ht->_capacity; i++)
	{
		if (ht->_tables[i]._status == EXITS)
		{
			printf("%d->[EX:%d]\n",i, ht->_tables[i]._key);
		}
		else
		{
			if (ht->_tables[i]._status == DELETE)
			{
				printf("%d->[DE:%d]\n",i, ht->_tables[i]._key);
			}
			else
			{
				printf("%d->[EM:]\n",i);
			}
		}
	}
}
int HashTableDestory(HashTable* ht)
{
	assert(ht);
	free(ht->_tables);
	ht->_tables = NULL;
	ht->_size = ht->_capacity = 0;
}
void HashTest()
{
	HashTable ht;
	HashTableInit(&ht, GetNextPrimeNum(0));
	HashTableInsert(&ht,5);
	HashTableInsert(&ht, 15);
	HashTableInsert(&ht, 7);
	HashTableInsert(&ht, 25);
	HashTableInsert(&ht, 35);
	HashTableInsert(&ht, 27);
	HashTableInsert(&ht, 53);
	HashTableInsert(&ht, 0);
	HashTableInsert(&ht, 106);
	HTPrin(&ht);
	if (HashTableFind(&ht, 106))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没有找到\n");
	}
	HashTableRemove(&ht,7);
	HashTableRemove(&ht, 25);
	HashTableRemove(&ht, 35);
	HashTableRemove(&ht, 27);
	HashTableRemove(&ht, 5);
	HTPrin(&ht);
	HashTableDestory(&ht);
}
int main()
{
	HashTest();
	system("pause");
	return 0;
}

