/************************************************************************/
/*        ������ð������                                                              */
/************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <iostream>

/* ����״̬ȡֵ�� */
typedef enum
{
	SORT_OK,    /* ����ɹ���־ */
	SORT_ERR    /* ����ʧ�ܱ�־ */
}SORTSTATE;

/* �ӵ�ṹ�� */
struct node {
	struct node * pnext;
	unsigned int value;
};

typedef struct node Node;

SORTSTATE sort(Node * * chainhead);
void sortEx(Node** head);
/** @�������ܣ����Ե�������������
* @�����������
* @�������������
*/
int main(void)
{
	Node * head, *p;
	SORTSTATE status;

	/* ������������ */
	p = (Node *)malloc(sizeof(Node));
	head = p;                                    /* ��������ͷ�� */
	p->value = 5;
	p->pnext = (Node *)malloc(sizeof(Node));

	p = p->pnext;
	p->value = 97;
	p->pnext = (Node *)malloc(sizeof(Node));

	p = p->pnext;
	p->value = 7;
	p->pnext = (Node *)malloc(sizeof(Node));

	p = p->pnext;
	p->value = 65;
	p->pnext = (Node *)malloc(sizeof(Node));

	p = p->pnext;
	p->value = 12;
	p->pnext = (Node *)malloc(sizeof(Node));

	p = p->pnext;
	p->value = 1;
	p->pnext = NULL;                            /* ��β��ʼ��Ϊ�� */

												/* ��ӡ��������� */
	p = head;
	while (p != NULL) {
		printf("%4d", p->value);
		p = p->pnext;
	}
	printf("\n");

	/* �������� */
	//status = sort(&head);
	sortEx(&head);
	//if (status == SORT_ERR) {
	//	printf("Chain is wrong!\n");
	//}

	/* ��ӡ��������� */
	p = head;
	while (p != NULL) {
		printf("%4d", p->value);
		p = p->pnext;
	}
	printf("\n");

	system("pause");
	return 0;
}


/** @�������ܣ�������������
* @���������ָ������ͷ����ָ��
*        ע�⣺ָ��ָ���ָ������޸�ָ���ָ��
* @���������SORTSTATE ����ɹ����״̬
*/

SORTSTATE sort(Node * * chainhead)
{
	Node * head,                                    /* ��ǰ�ȽϽӵ����һ���ӵ� */
		*first,                                    /* ��ǰ�ȽϽӵ� */
		*second,                                    /* ��ǰ����Ƚϵ���һ���ӵ� */
		*end;                                        /* ��ǰ�ȽϽӵ���յ�
													 * �յ���ζ�Ŵ��յ㿪ʼ�����
													 * ���������Ѿ�ȷ����ֻ��Ҫ��
													 * �յ�ǰ�����нӵ㰴��ð�ݷ�
													 * ��������ͽ���ɡ�
													 */

	if (*chainhead == NULL)                            /* �����Ƿ�Ϊ�� */
		return SORT_ERR;
	if ((*chainhead)->pnext == NULL)                    /* �����Ƿ��ֻ��һ���ӵ� */
		return SORT_OK;

	end = NULL;                                        /* ��һ��ð��������յ�ӵ�ֵΪNULL */

													   /* ð�ݷ�����,�����кܶ��ִ� */
	while (end != (*chainhead)->pnext) {                /* ���������յ���ڽӵ�ĵڶ�����ַ��
														* Ҳ����˵�ӵڶ����ӵ㿪ʼ���еĽӵ�
														* ���Ѿ����մ�С�����˳��ȷ����λ�á�
														* ��Ȼ��ʣ�µ�Ψһһ������һ�ӵ㡱λ��
														* Ҳ��ȷ���ˡ���������ȫ����ɡ�
														*/

														/* ���ȱȽ�λ��ͷ���������ӵ㣬����λ��ͷ����
														* �������ӵ㲻һ��,��Ҫ����ѭ����ߣ���������
														*/
		first = *chainhead;                        /* ��һ���ȽϽӵ�������ͷ��ָ��Ľӵ� */
		second = first->pnext;                        /* �ڶ����ȽϽӵ��ǽ��ڵĵڶ����ӵ� */

													  /* �Ƿ���Ҫ�������������˳�� */
		if (first->value > second->value) {
			*chainhead = second;                    /* ��������ͷ����ָ�� */
													/* ���������������൱�ڶ��������� */
			first->pnext = second->pnext;
			second->pnext = first;
		}

		/* �ƶ��ȽϽӵ㵽�������ӵ� */
		head = *chainhead;                            /* ��ǰ�ȽϽӵ����һ���ӵ�����ͷ���ӵ� */
		first = head->pnext;                        /* ��ǰ�ȽϽӵ� */
		second = first->pnext;                        /* ��ǰ����Ƚϵ���һ���ӵ� */

		while (second != end)                        /* ���ֵıȽ��Ƿ���� */
		{
			/* �Ƿ���Ҫ�������������˳�� */
			if (first->value > second->value) {
				/* ���������������൱�ڶ��������� */
				head->pnext = second;
				first->pnext = second->pnext;
				second->pnext = first;

			}
			/* �ƶ��ȽϽӵ㵽�������ӵ� */
			head = head->pnext;
			first = head->pnext;
			second = first->pnext;
		}

		end = first;                                /* һ��������ɣ������ӵ�λ������һ�� */
	}

	return SORT_OK;                                    /* ����ɹ� */
}

void sortEx(Node** head) {
	if (NULL == head || NULL == (*head)->pnext) return;

	Node *end = NULL;
	Node *prev = NULL;
	while ((*head)->pnext != end) {
		Node *first = *head;
		Node *second = first->pnext;

		if (first->value > second->value) {
			*head = second;
			first->pnext = second->pnext;
			second->pnext = first;
		}
		prev = *head;
		first = prev->pnext;
		second = first->pnext;

		while (second != end) {
			if (first->value > second->value) {
				prev->pnext = second;
				first->pnext = second->pnext;
				second->pnext = first;
			}
			prev = prev->pnext;
			first = prev->pnext;
			second = first->pnext;
		}
		end = first;
	}
}