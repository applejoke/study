#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <Hash.h>

#define LEN_MAX 10
//对LinkHash类型的变量属性赋值
// -> 动态开辟一维数组，每个元素空指针
void Init(LinkHash* ph) {
	ph->len = LEN_MAX;
	ph->table = (Node**)malloc(sizeof(Node*) * ph->len);
	if (ph->table == NULL) {
		printf("Error!");
		return;
	}
	for (int i = 0; i < ph->len; i++) {
		ph->table[i] = NULL;
	}
	return;
}

//哈希函数
static int Hash(int key, int len) {
	int index = key % len;
	if (index < 0) {
		index += len;
	}
	return index;
}

//头插
void HeadInsert(Node* Head, int data) {
	if (Head == NULL) {
		printf("Error!");
		return;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("Error!");
		return;
	}
	Node* temple = Head->next;
	Head->next = p;
	p->data = data;
	p->next = temple;
	return;
}

//存储数据
//1) index = hash();
//2) BuyNode(data); 创建一个新结点，头插到table[index]链表
void InsertVal(LinkHash* ph, int data) {
	if (ph == NULL) {
		printf("Error!");
		return;
	}
	int index = Hash(data, ph->len);
	if (ph->table[index] == NULL) {
		ph->table[index] = (Node*)malloc(sizeof(Node));
		if (ph->table[index] == NULL) {
			printf("Error!");
			return;
		}
		ph->table[index]->data = 0;
		ph->table[index]->next = NULL;
	}
	HeadInsert(ph->table[index], data);
	return;
}

//(根据关键字查找) 返回下标
//1) index = hash();
//2) 定位table[index]位置的链表  链表的遍历 
int SearchByKey(LinkHash* ph, int key) {
	if (ph == NULL) {
		printf("Error!");
		return -1;
	}
	int index = Hash(key, ph->len);
	Node* p = ph->table[index];
	if (p == NULL) {
		printf("搜索失败");
		return -1;
	}
	while (p->next != NULL) {
		if (p->next->data == key) {
			return p->next->data;
		}
		p = p->next;
	}
	printf("搜索失败");
	return -1;
;}

void Destory(LinkHash* ph) {
	if (ph == NULL) {
		printf("Error!");
		return;
	}
	for (int i = 0; i < ph->len; i++) {
		Node* temp = ph->table[i];
		if (temp != NULL) {
			while (temp != NULL) {
				Node* p = temp->next;
				free(temp);
				temp = p;
			}
		}
	}
	free(ph->table);
	ph->table = NULL;
	ph = NULL;
	return;
}

void Show(LinkHash* ph) {
	if (ph == NULL) {
		printf("Error!");
		return;
	}
	for (int i = 0; i < ph->len; i++) {
		Node* p = ph->table[i];
		printf("[%d]: ", i);
		if (p != NULL) {
			while (p->next != NULL) {
				printf("%d ", p->next->data);
				p = p->next;
			}
		}
		printf("\n");
	}
	return;
}
#endif