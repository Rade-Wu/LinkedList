#ifndef  LIST_H_
#define  LIST_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Ok 1
#define Error 0
#define PlayerSize 20
#define ClubSize 20
#define SeasonSize 10
typedef int Status;
typedef int Elemtype;
typedef struct 
{
    Elemtype number;/*球员号码*/
    Elemtype age;/*球员年龄*/
    char player[PlayerSize];/*球员名字*/
    char club[ClubSize];/*俱乐部名字*/
    char season[SeasonSize];/*赛季*/
}Item;

typedef struct Node
{
    Item item;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

LinkList InitializeList(LinkList *plist);
bool ListIsEmpty(const LinkList *plist);
unsigned int ListItemCount(const LinkList *plist);
LinkList FindX(LinkList L,Item item,char str);
LinkList PreviousFindX(LinkList L,Item item,char str);
Status ListDeletePlayer(LinkList *plist,char str,Item item);
bool AddItem(Item item,LinkList *plist);
void Traverse(const LinkList *plist,void(*pfun)(Item item));
Status ClearList(LinkList *plist);

#endif 