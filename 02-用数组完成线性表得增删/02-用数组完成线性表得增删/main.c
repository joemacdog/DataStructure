//
//  main.c
//  02-用数组完成线性表得增删
//
//用数组的方式完成（有序）线性表特定元素的增加和删减
//
//  Created by wangju on 15/10/9.
//  Copyright © 2015年 wangju. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

//预留内存空间
#define RESERVE 20
#define ERROR -1




void addElement(int);

//输出list的所有元素 -1表示失败 1表示成功
int deleteElement(int);

void printList();
void initList();


//向新内存空间拷贝旧内存空间的数据，并释放旧内存空间
void ElementTransfer(int *,int *);

void ResetList();


struct list
{
    int* data;//指向数组的指针
    int length;//元素的长度
    int trueLength;//实际长度
}arrayList;


void addElement(int Element)
{
    int* oldData = NULL;
    if (arrayList.data == NULL)//当数据为空时长度重置为零
    {
        arrayList.length = 0;
        arrayList.trueLength = 0;
        
    }
    

    if (arrayList.length >= arrayList.trueLength)
    {
        arrayList.trueLength = arrayList.length + RESERVE;
      
        if(arrayList.data != NULL)
          oldData = arrayList.data;
  
        arrayList.data = (int *)malloc(sizeof(int) * arrayList.trueLength);
        if (arrayList.data == NULL) {
            return exit(-1);
        }
        
        
        ElementTransfer(arrayList.data,oldData);
    }
    
    arrayList.data[arrayList.length] = Element;
    
    arrayList.length++;
}

int deleteElement(int Element)
{

    if(arrayList.length == 0)
    {
        return -1;
    }

    for (int i = 0; i < arrayList.length; i ++) {
        if (arrayList.data[i] == Element)
        {
            
            for (int j = i; j < arrayList.length - 1; j++)
            {
                arrayList.data[j] = arrayList.data[j+1];
            }
            arrayList.length--;
            return 1;
            
        }
    }
    
    return -1;
    
}


void ElementTransfer(int* newData,int* oldData)
{

    if (oldData == NULL)
    {
        return;
    }
    
    for (int i = 0; i < arrayList.length; i++)
    {
       newData[i]= oldData[i];
    }

    free(oldData);
}
void initList()
{
    arrayList.data = NULL;
    arrayList.length = 0;
    arrayList.trueLength = 0;
}

void printList()
{
    
    for (int i = 0; i < arrayList.length; i++)
    {
        printf("%3d",arrayList.data[i]);
    }
    printf("\n");
    
}

void ResetList()
{
    free(arrayList.data);
    arrayList.data = NULL;
    arrayList.length = 0;
    arrayList.trueLength = 0;
}



int main(int argc, const char * argv[])
{

    
    
    initList();
    
    for (int i =0; i < 50; i++)
    {
        addElement(i);
    }
    
    
    
    printList();
    
    printf("------------------华丽的分割线-----------------------\n");
    
    deleteElement(40);
    deleteElement(0);
    deleteElement(49);
    addElement(80);
    
    printList();
    
    
    
    return 0;
}
