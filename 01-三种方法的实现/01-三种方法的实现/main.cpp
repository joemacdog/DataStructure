//
//  main.cpp
//  01-三种方法的实现
//
//  Created by wangju on 15/10/8.
//  Copyright © 2015年 wangju. All rights reserved.
//

#include<iostream>
#include<string>
#include<list>

using namespace std;

int ListLength(list<int> );
void GetElem(list<int> lis, int i, int &e);//取出lis中的第i个元素，赋值给e
bool LocateElem(list<int> ,int ,string);
void ListInsert(list<int> &,int ,int );
void Union(list<int> &la, list<int> lb);//相同的元素不合并

void Union2(list<int> &la, list<int> lb);//习题例2-2


void Union(list<int> &la,list<int> lb)//相同的元素不合并
{
    int la_len = ListLength(la);
    int lb_len = ListLength(lb);
    int e;
    for (int i = 1;i <= lb_len;i++)
    {
        GetElem(lb,i,e);
        if (!LocateElem(la,e, "equal"))
        {
            ListInsert(la,++la_len,e);
        }
    }
}

void Union2(list<int> &la, list<int> lb)//相同的元素也合并
{
    int la_len = ListLength(la);
    int lb_len = ListLength(lb);
    int e;
    for (int i = 1;i <= lb_len;i++)
    {
        GetElem(lb, i, e);
        ListInsert(la, ++la_len, e);
    }
}


bool LocateElem(list<int> lis, int e ,string str)
{
    if ( lis.empty() && str != "equal")
        return false;
    
    int len = ListLength(lis);
    for (int i = 0;i < len;i++)
    {
        if (lis.front() == e)
            return true;
        lis.pop_front();
    }
    return false;
}


void GetElem(list<int> lis, int i, int &e)//取出lis中的第i个元素，赋值给e(首元素为第0个元素)
{
    
    if (lis.empty())
        return;
    
    for (auto x = 1;x < i;x++)
    {
        lis.pop_front();
    }
    e = lis.front();
}

int ListLength(list<int> lis)//求线性表的长度
{
    int length = 0;
    for (auto i = lis.begin(); i != lis.end(); i++)
    {
        length ++;
    }
    
    return length;
}

void ListInsert(list<int> &lis, int len, int e)
{
    //len 在list内部已经实现，这里不需要对len操作，只是保持函数原型和原书相同
    lis.push_back(e);
    lis.sort();
}


int main()
{
    list<int> la = {3,5,8,11};
    list<int> lb = {2,6,8,9,11,15,20};
    
    Union(la,lb);
    
    
    for (auto i = la.begin(); i != la.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}