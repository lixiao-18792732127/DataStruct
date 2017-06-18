#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int DataType;

typedef struct SeqList
{
	DataType* array;
	size_t size;
	size_t capacity;
}SeqLIst;


void CheckCapacity(SeqList* seq);//���ռ��Ƿ񹻴�
void InitSeqList(SeqList* seq);//��ʼ��˳���
void DestorySeqList(SeqList* seq);//����˳���
//��ɾ�Ĳ�
void PushBack(SeqList* seq, DataType x);//��β������Ԫ��
void Popback(SeqList* seq);//��β��ɾ��Ԫ��

void PushFront(SeqList* seq, DataType x);//��ͷ������Ԫ��
void PopFront(SeqList* seq);//��ͷ��ɾ��Ԫ��

void Insert(SeqList* seq, size_t pos, DataType x);//ָ��λ�ò���Ԫ��
int find(SeqList* seq, DataType x);// Ѱ��Ԫ��
void Erase(SeqList* seq, size_t pos);// ɾ��ָ��λ��Ԫ��
void remove(SeqList* seq, DataType x);//ɾ��Ԫ��X
void removeAll(SeqList* seq, DataType x);//ɾ��˳��������е�X

void BubbleSort(SeqList* seq);//ð������
void SelectSort(SeqList* seq);//ѡ������
void InsertSort(SeqList* seq);//��������
int BinarySearch(SeqList* seq, DataType x);//���ֲ���
int BinarySearchD(SeqList* seq, size_t begin, size_t end, DataType x);//�ݹ飬���ֲ���
void PrintSeqList(SeqList* seq);//����˳���