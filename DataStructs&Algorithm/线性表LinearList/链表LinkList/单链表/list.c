
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
	return (head);
} 