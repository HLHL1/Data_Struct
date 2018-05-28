#define _CRT_SECURE_NO_WARNINGS
#include"Hash.h"


size_t GetNextPrimeNum(size_t x)
{
	//const��C���������α���ʹ�������г����Ա���
	//������c++���൱�ڳ���
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
	assert(ht&&capacity>0);//������������г�0��bug
	ht->_tables = (HashNode*)malloc(sizeof(HashNode)*capacity);
	assert(ht->_tables);//Ԥ���ڴ����ʧ��

	//��ʼ����������飨״̬�����ʼ�����ؼ�����ò�Ҫ��ʼ������Ϊ����ı�ؼ������;ͻ��������
	for (size_t  i = 0; i < capacity; i++)
	{
		ht->_tables[i]._status = EMPTY;
	}
	ht->_size = 0;
	ht->_capacity = capacity;
}


void CheckCapacity(HashTable* ht)
{
	//����realloc��������,��Ϊrealloc����ԭ���ڴ�Ļ��������ں������ӿռ䵫�ǹ�ϣ��Ľ���ʵ�����������ϼ����
	//���ǹ�ϣ��Ľ����������������ϼ����,�����ᵹ���е�ֵ�ᱻ���ǵ�
	if (ht->_size * 10 / ht->_capacity >=7)
	{
		HashTable newht;
		HashTableInit(&newht, GetNextPrimeNum(ht->_capacity));
		//����
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

//�ɹ���0  ʧ�ܣ�-1
int HashTableInsert(HashTable* ht, KeyType key)
{
	size_t index = 0,i=1;
	assert(ht);
	CheckCapacity(ht);
	index = HashFunc(ht, key);
	//���״ֻ̬��Ϊ�յ�ʱ�򣬲Ż��������
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

//����1����������ֵ���ˣ��ͻ���ѭ��---�������ݻ����������
//����2�����һ�����Ѿ���ɾ����,���ǻ��ǻ��ʾ���ڡ��������ѽ��
HashNode*  HashTableFind(HashTable* ht, KeyType key)
{
	size_t index,i = 1;;
	assert(ht);
	index = HashFunc(ht, key);
	while (ht->_tables[index]._status != EMPTY)
	{
		//��ֹһ�����Ѿ���ɾ����, ���ǻ��ǻ��ʾ����
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
		//����̽��
		index += i*i;
		index %= ht->_capacity;
		++i;
		//����̽��
		/*index++;
		if (index == ht->_capacity)
		{
			index = 0;
		}*/
	}
	return NULL;
}

//ɾ�������ǽ���״̬����Ϊɾ��״̬
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
		printf("�ҵ���\n");
	}
	else
	{
		printf("û���ҵ�\n");
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

