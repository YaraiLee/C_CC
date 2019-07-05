/************************************************************************/
/*        单链表冒泡排序                                                              */
/************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <iostream>

/* 排序状态取值表 */
typedef enum
{
	SORT_OK,    /* 排序成功标志 */
	SORT_ERR    /* 排序失败标志 */
}SORTSTATE;

/* 接点结构体 */
struct node {
	struct node * pnext;
	unsigned int value;
};

typedef struct node Node;

SORTSTATE sort(Node * * chainhead);
void sortEx(Node** head);
/** @函数功能：测试单向链表排序功能
* @输入参数：无
* @输出参数：无用
*/
int main(void)
{
	Node * head, *p;
	SORTSTATE status;

	/* 构建单向链表 */
	p = (Node *)malloc(sizeof(Node));
	head = p;                                    /* 保存链表头部 */
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
	p->pnext = NULL;                            /* 链尾初始化为空 */

												/* 打印链表的内容 */
	p = head;
	while (p != NULL) {
		printf("%4d", p->value);
		p = p->pnext;
	}
	printf("\n");

	/* 链表排序 */
	//status = sort(&head);
	sortEx(&head);
	//if (status == SORT_ERR) {
	//	printf("Chain is wrong!\n");
	//}

	/* 打印链表的内容 */
	p = head;
	while (p != NULL) {
		printf("%4d", p->value);
		p = p->pnext;
	}
	printf("\n");

	system("pause");
	return 0;
}


/** @函数功能：单向链表排序
* @输入参数：指向链表头部的指针
*        注意：指向指针的指针可以修改指针的指向
* @输出参数：SORTSTATE 排序成功与否状态
*/

SORTSTATE sort(Node * * chainhead)
{
	Node * head,                                    /* 当前比较接点的上一个接点 */
		*first,                                    /* 当前比较接点 */
		*second,                                    /* 当前参与比较的另一个接点 */
		*end;                                        /* 当前比较接点的终点
													 * 终点意味着从终点开始往后的
													 * 链表排序已经确定，只需要将
													 * 终点前的所有接点按照冒泡法
													 * 排序，排序就将完成。
													 */

	if (*chainhead == NULL)                            /* 链表是否为空 */
		return SORT_ERR;
	if ((*chainhead)->pnext == NULL)                    /* 链表是否就只有一个接点 */
		return SORT_OK;

	end = NULL;                                        /* 第一轮冒泡排序的终点接点值为NULL */

													   /* 冒泡法排序,可能有很多轮次 */
	while (end != (*chainhead)->pnext) {                /* 如果排序的终点等于接点的第二个地址，
														* 也就是说从第二个接点开始所有的接点
														* 都已经按照从小到大的顺序确定了位置。
														* 显然，剩下的唯一一个“第一接点”位置
														* 也就确定了。所有排序全部完成。
														*/

														/* 首先比较位于头部的两个接点，由于位于头部，
														* 与其他接点不一样,需要放在循环外边，单独处理。
														*/
		first = *chainhead;                        /* 第一个比较接点是链表头部指向的接点 */
		second = first->pnext;                        /* 第二个比较接点是紧邻的第二个接点 */

													  /* 是否需要更改链表的连接顺序 */
		if (first->value > second->value) {
			*chainhead = second;                    /* 更改链表头部的指向 */
													/* 重新连接链表，就相当于对链表排序 */
			first->pnext = second->pnext;
			second->pnext = first;
		}

		/* 移动比较接点到下两个接点 */
		head = *chainhead;                            /* 当前比较接点的上一个接点则是头部接点 */
		first = head->pnext;                        /* 当前比较接点 */
		second = first->pnext;                        /* 当前参与比较的另一个接点 */

		while (second != end)                        /* 此轮的比较是否结束 */
		{
			/* 是否需要更改链表的连接顺序 */
			if (first->value > second->value) {
				/* 重新连接链表，就相当于对链表排序 */
				head->pnext = second;
				first->pnext = second->pnext;
				second->pnext = first;

			}
			/* 移动比较接点到下两个接点 */
			head = head->pnext;
			first = head->pnext;
			second = first->pnext;
		}

		end = first;                                /* 一轮排序完成，结束接点位置上移一个 */
	}

	return SORT_OK;                                    /* 排序成功 */
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