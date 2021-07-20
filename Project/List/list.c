#include "list.h"
static void CopyToNode(Item item,LinkList pnode);
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

/*创建存放项目的节点，并把它添加到*/
/*由plist指向的链表尾部(尾插法)*/
bool AddItem(Item item,LinkList *plist)
{
    LinkList pnew;
    LinkList scan = *plist;
    pnew = (LinkList)malloc(sizeof(Node));
    if(pnew == NULL)
    return false;
    CopyToNode(item,pnew);
    pnew ->next = NULL;             /*pnew指向链表尾部*/
    if(scan == NULL)
    {
        *plist = pnew;
    }
    else
    {
        while(scan ->next!=NULL)
        {
            scan = scan -> next;
        }
        scan->next = pnew;
    }
    return true;
}

/*访问每个节点并对它们分别执行由pfun指向的函数*/
void Traverse(const LinkList *plist,void(*pfun)(Item item))
{
    LinkList pnode;
    pnode = *plist;
    while(pnode != NULL)
    {
      (*pfun)(pnode->item);
      pnode = pnode ->next;
    }    
}

/*单链表的整表删除*/
Status ClearList(LinkList *plist)
{
 LinkList psave;
 while(*plist != NULL)
 {
     psave = (*plist)->next;   /*保存下一个节点的地址*/
     free(*plist);             /*释放当前节点*/
     *plist = psave;           /*前进到下一个节点*/
 }

}

/*把一个项目复制到一个节点中*/
static void CopyToNode(Item item,LinkList pnode)
{
    pnode ->item = item;
}




