
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
	return (head);
} 