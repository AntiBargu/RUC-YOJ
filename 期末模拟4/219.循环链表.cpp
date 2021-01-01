#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <memory.h> 

using namespace std;

struct node
{
    int data;
    node *next;
};

//该函数的输入head 是一个链表的头部和一个插入值val
//编写该函数实现把val值插入链表并保持该函数从大到小有序
//返回插入后链表的头指针
node* Insert(node *head,int val)
{
   //此函数代码隐藏
}

void release(node *head)
{
//此函数代码隐藏
}

node* CreateList(node *head)
{
//此函数代码隐藏
}

//这是你需要完成的函数
//给定循环链表的头指针，请返回该循环链表的节点数
int getLength(node* head); 

int getLength(node* head)
{
	int cnt;
	node *ptr;

	if(!head)
		return 0;

	for(cnt = 1, ptr = head->next; ptr != head; ++cnt, ptr = ptr->next)
		;

	return cnt;
}

int main()
{
    node *head = NULL;

    head = CreateList(head);    //创建链表 
    cout << getLength(head) << endl; //输出链表的节点数目 
    
    release(head);

    return 0;

}
