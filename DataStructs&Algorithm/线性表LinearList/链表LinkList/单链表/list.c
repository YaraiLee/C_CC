
typedef int elemtype;

typedef struct node
{
	elemtype data;//����������
	struct node * next;//����ָ���� 
}LinkList;

/**
����������ͷ�巨��������ͷ���ĵ����� 
*/
LinkList * Create_LinkListF()
{
	elemtype ix;
	LinkList* head, *p;
	head = (LinkList*)malloc(sizoef(LinkList));//����ͷ��� 
	head->next = NULL;
	printf("input data end with 0:\n");
	scanf("%d", &ix);
	while(0 != ix)
	{
		p = (LinkList*)malloc(sizoef(LinkList));
		p->data = ix;
		p->next = head->next;//�޸��½���ָ���� 
		head->next = p;//�޸�ͷ����ָ���� 
		scanf("%d", &ix);
	}
	return (head);//����ͷ��� 
} 
/**
����������β�巨��������ͷ���ĵ�����  
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
		tail->next = p;//�޸�βָ���ָ���� 
		tail = p;//�޸�βָ�� 
		scanf("%d", &ix);
	}
	return(head);
}

/**
������������������� 
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
������������������ 
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
���������������������� 
*/
LinkList* GetData_LinkList(LinkList* head, int index)
{
	LinkList *p;
	int j = 0;
	if (index <= 0) return NULL;
	p = head;
	while(NULL != p->next && j < index)//����Ŀ�굫��̻��н�� 
	{
		p = p->next;
		j++;
	}
	if (i == j) return p;
	else return NULL;
}

/**
������������ֵ������� 
*/
LinkList* Search_LinkList(LinkList* head, elemtype key)
{
	LinkList *p = head->next;
	while (NULL != p)
	{
		if (p->data == key)//�ҵ����� 
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