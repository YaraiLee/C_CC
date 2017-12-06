
typedef int elemtype;

typedef struct node
{
	elemtype data;//结点的数据域
	struct node * next;//结点的指针域 
}LinkList;

/**
函数描述：头插法，建立带头结点的单链表 
*/
LinkList * Create_LinkListF()
{
	elemtype ix;
	LinkList* head, *p;
	head = (LinkList*)malloc(sizoef(LinkList));//生成头结点 
	head->next = NULL;
	printf("input data end with 0:\n");
	scanf("%d", &ix);
	while(0 != ix)
	{
		p = (LinkList*)malloc(sizoef(LinkList));
		p->data = ix;
		p->next = head->next;//修改新结点的指针域 
		head->next = p;//修改头结点的指针域 
		scanf("%d", &ix);
	}
	return (head);//返回头结点 
} 
/**
函数描述：尾插法，建立带头结点的单链表  
*/ 
LinkList * Create_LinkListR()
{
	elemtype ix;
	LinkList *head, *p, *tail;
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next= NULL;
	tail = head;
	printf("input data end with 0:\n");
	scanf("%d", &ix);
	while(ix != 0)
	{
		p = (LinkList*)malloc(sizeof(LinkList));
		p->data= ix;
		p->next = NULL;
		tail->next = p;//修改尾指针的指针域 
		tail = p;//修改尾指针 
		scanf("%d", &ix);
	}
	return(head);
}

/**
函数描述：单链表遍历 
*/ 
void Print_LinkList(LinkList * head)
{
	LinkList* p = head->next;
	while(NUU != p)
	{
		printf("\t%d", p->data);
		p = p->next;
	}
}
/**
函数描述：单链表长度 
*/
int LinkList_Length(LinkList* head)
{
	LinkList* p = head;
	int count = 0;
	while(NULL != p->next)
	{
		count++;
		p = p->next;
	}
	return count;
}
/**
函数描述：按序号链表查找 
*/
LinkList* GetData_LinkList(LinkList* head, int index)
{
	LinkList *p;
	int j = 0;
	if (index <= 0) return NULL;
	p = head;
	while(NULL != p->next && j < index)//不是目标但后继还有结点 
	{
		p = p->next;
		j++;
	}
	if (i == j) return p;
	else return NULL;
}

/**
函数描述：按值链表查找 
*/
LinkList* Search_LinkList(LinkList* head, elemtype key)
{
	LinkList *p = head->next;
	while (NULL != p)
	{
		if (p->data == key)//找到结束 
		{
			break;
		}
		else
		{
			p = p->next;
		}
	}
	return p;
}
/**
函数描述：在单链表指定节点p后插入数据 x 
*/
void InsertAfter_LinkList(LinkList* p, elemtype x)
{
	LinkList* s;
	s = (LinkList*)malloc(sizeof(LinkList));
	s->data = x;
	//后两行顺序不能颠倒 
	s->next= p->next; //新节点连入链表 
	p->next = s;//修改前驱结点指针域 
}
/**
函数描述:在指定结点p前插入数据x 
*/
void InsertBefore_LinkList(LinkList* head, LinkList* p, elemtype x)
{
	LinkList* s, *q;
	s = (LinkList*)malloc(sizeof(LinkList));
	s->data = x;
	q = head;
	while (q->next!= p)//从头结点开始查找p结点前驱结点，可以使用后插，然后交换数据域，省去遍历操作 
		q = q->next;
	s->next = p;//修改指针域 
	q->next = s;
} 
/**
函数描述： 在指定序号i前插入 
*/
int InserNo_LinkList(LinkList* head, elemtype x, int i)
{
	LinkList* p;
	if (i == 0) p = NULL;
	else if(i == 1) p = head;
	else
		p = GetData_LinkList(head, i-1);//获取第i-1个结点
	if (NULL == p)
	{
		printf("pos error!\n");
		return -1;
	} 
	else
	{
		InsertAfter_LinkList(p, x);//调用后插 
		return 0;
	}
}
/**
函数描述：删除指定结点的后继节点 
*/ 
int DeleteAfter_LinkList(LinkList* p)
{
	LinkList* r;
	if (NULL == p) 
	{
		printf("node is empty!\n")
		return -1;
	}
	r = q->next;
	if (NULL == r)
	{
		printf("no after node!\n");
		return -1;
	}
	p->next= r->next;
	free(r);//释放内存空间 
	r = NULL;
	return 0; 
} 