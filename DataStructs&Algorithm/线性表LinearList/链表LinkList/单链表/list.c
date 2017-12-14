/*
**��ͷ���ĵ�������ز������� 
** 
**ע�����м����������������׽ڵ㿪ʼ������ͷ��� 
*/
 
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
�����������������ȣ�ͷ��㲻�������ڣ� 
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
/**
�����������ڵ�����ָ���ڵ�p��������� x 
*/
void InsertAfter_LinkList(LinkList* p, elemtype x)
{
	LinkList* s;
	s = (LinkList*)malloc(sizeof(LinkList));
	s->data = x;
	//������˳���ܵߵ� 
	s->next= p->next; //�½ڵ��������� 
	p->next = s;//�޸�ǰ�����ָ���� 
}
/**
��������:��ָ�����pǰ��������x 
*/
void InsertBefore_LinkList(LinkList* head, LinkList* p, elemtype x)
{
	LinkList* s, *q;
	s = (LinkList*)malloc(sizeof(LinkList));
	s->data = x;
	q = head;
	while (q->next!= p)//��ͷ��㿪ʼ����p���ǰ����㣬����ʹ�ú�壬Ȼ�󽻻�������ʡȥ�������� 
		q = q->next;
	s->next = p;//�޸�ָ���� 
	q->next = s;
} 
/**
���������� ��ָ�����iǰ���� 
*/
int InserNo_LinkList(LinkList* head, elemtype x, int i)
{
	LinkList* p;
	if (i == 0) p = NULL;
	else if(i == 1) p = head;
	else
		p = GetData_LinkList(head, i-1);//��ȡ��i-1�����
	if (NULL == p)
	{
		printf("pos error!\n");
		return -1;
	} 
	else
	{
		InsertAfter_LinkList(p, x);//���ú�� 
		return 0;
	}
}
/**
����������ɾ��ָ�����p�ĺ�̽ڵ� 
*/ 
int DeleteAfter_LinkList(LinkList* p)
{
	LinkList* r;
	if (NULL == p) 
	{
		printf("node is empty!\n")
		return -1;
	}
	r = p->next;
	if (NULL == r)
	{
		printf("no after node!\n");
		return -1;
	}
	p->next= r->next;
	free(r);//�ͷ��ڴ�ռ� 
	r = NULL;
	return 0; 
} 
/**
����������ɾ��ָ�����p 
*/ 
int DeleteNode_LinkList(LinkList* p)
{
	LinkList* r;
	if (NULL != p->next)//���p�к�̽ڵ� 
	{
		p->data = p->next->data;//����p�������� 
		return (DeleteAfter_LinkList(p));//ɾ��p�ĺ�̽ڵ� 
	}
	else
	{
		r = head;
		while(r->next != p)
		{
			r = r->next;
		}
		return (DeleteAfter_LinkList(r));//ɾ��r�ĺ�̽ڵ㣬��p 
	}
}
/**
����������ɾ��ָ������λ�õĽ�� 
*/ 
int DeleteNo_LinkList(LinkList* head, int i)
{
	LinkList *p, *r;
	if (i == 0) p = NULL;
	else if (i == 1) p = head;
	else p = GetData_LinkList(head, i-1);//��ȡǰ����� 
	if (NULL == p)
	{
		printf("the node not exist!\n");
		return -1
	}
	else
	{
		r = p->next;
		p->next = r->next;
		free(r);
		r = NULL;
		return 0;
	}
}
/**
�����������ÿձ�
*/
LinkList *SetNull_LinkList(LinkList *head)
{
	while(NULL != head->next)
		DeleteAfter_LinkList(head);
	return head;
} 