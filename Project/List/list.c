#include "list.h"
/*接口函数*/
/*把链表设置为空链表*/
LinkList InitializeList(LinkList *plist)
{
  *plist = (LinkList)malloc(sizeof(Node));
  if((*plist)==NULL)
  {
      puts("Memory allocation failed.Goodbye!");
      exit(EXIT_FAILURE);
  }
  (*plist)->next =NULL;
  return *plist;
}
/*如果链表为空则返回真*/
bool ListIsEmpty(const LinkList *plist)
{
    if(*plist == NULL)
     return true;
    else
     return false; 
}
/*返回节点数*/
unsigned int ListItemCount(const LinkList *plist)
{
    unsigned int count=0;
    Node *pnode = *plist;
    while(pnode != NULL)
    {
        count++;
        pnode = pnode->next;
     }
     return count;
}

/*在链表中查找某一元素*/
/*找到则返回元素指针，否则返回NULL*/
LinkList FindX(LinkList L,Item item,char str)
{
    LinkList p;
    p = L ->next;
    while(p!=NULL && p->item.club != str)
    {
        p = p ->next;
    }
    return p;
}

/*查找链表中某元素前面一个元素*/
LinkList PreviousFindX(LinkList L,Item item,char str)
{
    LinkList p;
    p = L ->next;
    while(p->next!=NULL && p->next->item.club != str)
    {
        p = p ->next;
    }
    return p;
}

/*单链表的删除*/
Status ListDeletePlayer(LinkList *plist,char str,Item item)
{
    LinkList p,q;
    q = FindX(*plist,item,str);
    p = PreviousFindX(*plist,item,str);
    if(q == NULL)
    {
        return Error;
    }
    q = p->next;
    p ->next = q ->next;
    free(q);
    return Ok;
}






