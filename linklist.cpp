#include<iostream>
typedef struct Linklist{
    int date;
    struct Linklist* next;
}Lnode,*linklist;
void initlinklist(linklist& linklist)
{
    linklist =new Lnode;
    linklist->next=NULL;
    // for(int i=n;i>0;i--)
    // {
    //     std::cin>>l->date;
    //     l->next=linklist->next;
    //     linklist->next=l;
    // }
}
//销毁链表
void Destorylist(linklist& L)
{
    Lnode *p;
    while(L)
    {
        p=L;
        L=L->next;
        delete p;
    }
}
//判断链表是否为空链表
bool empty(linklist l)
{
    if(l->next)
    {
        return true;
    }else{
        return false;
    }
}
//链表清空操作
void clear(linklist& L)
{
    Lnode* p,* q;
    p=L->next;
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    L->next=nullptr;
}
//求链表表长
int length(linklist &L)
{
    //算法思路 从首元素开始。依次计数所有结点
    linklist p;
    p=L->next;
   int i=0;
   while(p)
   {
    i++;
    p=p->next;
   }
   return i;
}
//链表取值
int getelem_L(linklist l,int i,int e)
{
    linklist p;
    p=l->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
    {
        return -1;
    }
    e=p->date;
    return e;
}
//按值查找
int Locate_date(linklist l,int e)
{
    linklist p;
    p=l->next;
    int j=0;
    if(p->date==e)
    {
        p=p->next;
        j++;
    }
    return j;
}
//插入
// void ListInsert_L(linklist &l,int pos,int e)
// {
//     linklist p; Lnode* s;
//     p=l->next; s->date=e;
//     int j=0;
//     for(int i=0;i<pos-1;i++)
//     {
//         p=p->next;
//     }
//     if(!p||(j>pos-1))
//     std::cout<<"值错误";
//     p->next=s;
//     s->next=l->next;
    
// }
void InsertToList(linklist head, int pos, int data)
{
	Lnode* pnode = head;
	for (int i = 0; i < pos-1; i++)
		pnode = pnode->next;
	Lnode* pNewNode = new Lnode;
	pNewNode->date = data;
	pNewNode->next = pnode->next;
	pnode->next = pNewNode;
	
}
//头插法
void ListInsert_Head(linklist L,int n)
{
        L->next=NULL;
        
        for(int i=n;i>0;i--)
        {
           Lnode* p=new Lnode;
           std::cin>>p->date;
           p->next=L->next;
           L->next=p;
        }
}
void print(linklist l)
{
    Lnode* p=new Lnode;
    p=l->next;
    if(p->next)
    {
        std::cout<<l->date<<"-->";
        p=p->next;
    }
    else{
        std::cout<<"故障";
    }
}
//尾插法
void tail_insert(linklist L,int e)
{
    Lnode* p=new Lnode;
    p->date=e;
    // L->next=NULL;
    while(L->next)
    {
        L=L->next;
    }
    p->next=L->next;
    L->next=p;
}
int main()
{
    linklist l1; int num;
    initlinklist(l1);
    // ListInsert_L(l1,1,1);
  //  InsertToList(l1,1,1);
    // bool flag=empty(l1);
     //ListInsert_Head(l1,3);
     tail_insert(l1,1);
     tail_insert(l1,2);
   // print(l1);
 //   std::cout<<Locate_date(l1,1)<<std::endl;
    // std::cout<<flag<<std::endl;
    // clear(l1);
    // ListInsert_L(l1,1,1);
    // print(l1);
    std::cout<<"该表长为"<<length(l1)<<std::endl;
    // std:: cout<<getelem_L(l1,1,1); 
   std:: cout<<getelem_L(l1,1,num)<<"-->";
   std::cout<<getelem_L(l1,2,num)<<"-->";
//    std::cout<<getelem_L(l1,3,num)<<"-->";
    return 0;
}