#pragma once

#define MAX_SIZE 100

typedef struct SeqStack
{
	int data[MAX_SIZE];
	int top;
}SeqStack;

void Init(SeqStack* ps);

void Push(SeqStack* ps, int val);

int Pop(SeqStack* ps);

int GetTop(SeqStack* ps);

int IsEmpty(SeqStack* ps);

int IsFull(SeqStack* ps);

void Show(SeqStack* ps);
