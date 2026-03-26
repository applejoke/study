#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Stack.h>

// 初始化顺序栈
// 实现思路：将 top 指针设置为 -1，表示栈为空
// 原理：top 指向栈顶元素的下标，-1 表示没有元素
void Init(SeqStack* ps)
{
	// TODO: 将 ps->top 设置为 -1
}

// 入栈操作
// 实现思路：
//   1. 先检查栈是否已满
//   2. 如果未满，先将 top 指针加 1
//   3. 然后将 val 存入 data[top]
// 原理：栈是后进先出（LIFO），新元素放在栈顶
void Push(SeqStack* ps, int val)
{
	// TODO: 检查栈是否已满，如果满则提示错误
	// TODO: top++
	// TODO: data[top] = val
}

// 出栈操作
// 实现思路：
//   1. 先检查栈是否为空
//   2. 如果不为空，先取出 data[top] 的值
//   3. 然后将 top 指针减 1
//   4. 返回取出的值
// 原理：出栈要删除栈顶元素，但数组中的数据可以保留，只需要移动 top 指针
int Pop(SeqStack* ps)
{
	// TODO: 检查栈是否为空，如果空则返回错误值（如 -999）
	// TODO: 取出 data[top] 的值
	// TODO: top--
	// TODO: 返回取出的值
}

// 获取栈顶元素
// 实现思路：
//   1. 先检查栈是否为空
//   2. 如果不为空，返回 data[top] 的值
//   3. 注意：不修改 top 指针，只是查看
// 原理：与 Pop 不同，GetTop 只查看不删除
int GetTop(SeqStack* ps)
{
	// TODO: 检查栈是否为空，如果空则返回错误值（如 -999）
	// TODO: 返回 data[top]
}

// 判断栈是否为空
// 实现思路：直接判断 top 是否等于 -1
// 原理：top == -1 表示栈中没有元素
int IsEmpty(SeqStack* ps)
{
	// TODO: 返回 ps->top == -1 的结果
}

// 判断栈是否已满
// 实现思路：直接判断 top 是否等于 MAX_SIZE - 1
// 原理：top == MAX_SIZE - 1 表示数组已满
int IsFull(SeqStack* ps)
{
	// TODO: 返回 ps->top == MAX_SIZE - 1 的结果
}

// 显示栈内容
// 实现思路：
//   1. 先检查栈是否为空
//   2. 如果不为空，从 top 开始向下遍历到 0
//   3. 打印每个元素
// 原理：栈顶元素在数组的高位，所以从 top 开始向下打印
void Show(SeqStack* ps)
{
	// TODO: 检查栈是否为空，如果空则提示
	// TODO: 使用 for 循环，从 i = ps->top 开始，到 i >= 0 结束
	// TODO: 在循环中打印 data[i]
}
