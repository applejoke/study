#pragma once

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct LinkHash
{
	Node** table; //哈希表 --> 哈希表扩容-重新哈希
	int len; //容量大小
}LinkHash;

//对LinkHash类型的变量属性赋值
// -> 动态开辟一维数组，每个元素空指针
void Init(LinkHash* ph);

//存储数据
//1) index = hash();
//2) BuyNode(data); 创建一个新结点，头插到table[index]链表
void InsertVal(LinkHash* ph, int data);

//(根据关键字查找) 返回下标
//1) index = hash();
//2) 定位table[index]位置的链表  链表的遍历 
int SearchByKey(LinkHash* ph, int key);

void Destory(LinkHash* ph);

void Show(LinkHash* ph);