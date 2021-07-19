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

#endif 