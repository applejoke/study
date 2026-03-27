#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include "Stack.h"

void test_basic_operations()
{
	printf("========== 测试1: 基本操作测试 ==========\n");
	SeqStack stack;
	Init(&stack);

	Push(&stack, 10);
	Push(&stack, 20);
	Push(&stack, 30);

	printf("栈内容:\n");
	Show(&stack);

	printf("\n");
}

void test_push_and_pop()
{
	printf("========== 测试2: 入栈和出栈测试 ==========\n");
	SeqStack stack;
	Init(&stack);

	for (int i = 1; i <= 5; i++)
	{
		Push(&stack, i * 10);
	}

	printf("入栈后的栈:\n");
	Show(&stack);

	printf("\n出栈操作:\n");
	while (!IsEmpty(&stack))
	{
		int val = Pop(&stack);
		printf("出栈: %d\n", val);
	}

	printf("\n");
}

void test_get_top()
{
	printf("========== 测试3: 获取栈顶元素测试 ==========\n");
	SeqStack stack;
	Init(&stack);

	Push(&stack, 100);
	Push(&stack, 200);
	Push(&stack, 300);

	int top = GetTop(&stack);
	printf("栈顶元素: %d\n", top);

	printf("\n");
}

void test_empty_and_full()
{
	printf("========== 测试4: 空栈和满栈测试 ==========\n");
	SeqStack stack;
	Init(&stack);

	printf("栈是否为空: %s\n", IsEmpty(&stack) ? "是" : "否");

	for (int i = 0; i < MAX_SIZE; i++)
	{
		Push(&stack, i);
	}

	printf("栈是否已满: %s\n", IsFull(&stack) ? "是" : "否");

	printf("\n");
}

void test_edge_cases()
{
	printf("========== 测试5: 边界情况测试 ==========\n");
	SeqStack stack;
	Init(&stack);

	printf("空栈时获取栈顶:\n");
	int top = GetTop(&stack);

	printf("空栈时出栈:\n");
	int val = Pop(&stack);

	printf("满栈时入栈:\n");
	for (int i = 0; i < MAX_SIZE + 1; i++)
	{
		Push(&stack, i);
	}

	printf("\n");
}

int main()
{
	printf("=======================================\n");
	printf("         顺序栈全面测试程序           \n");
	printf("=======================================\n\n");

	test_basic_operations();
	test_push_and_pop();
	test_get_top();
	test_empty_and_full();
	test_edge_cases();

	printf("=======================================\n");
	printf("         所有测试完成!                 \n");
	printf("=======================================\n");

	return 0;
}
