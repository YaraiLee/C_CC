/**
***单循环链表的操作和单链表操作基本相同
*/

/**
函数描述：将两个用尾指针表示的带头结点的单循环链表ra,rb（尾指针）合并成一个单循环链表，即将rb链接到ra后
单循环链表用尾指针表示，则操作表头/尾都很方便
*/
LinkList* Connect(LinkList* ra, LinkList* rb)
{
	LinkList* p;
	p = ra->next;//p指向ra的头结点
	ra->next = rb->next->next;//ra的指针域指向rb的首节点（跳过rb头结点）
	free(rb->next);//释放rb头结点
	rb->next = p;//尾指针rb指针域指向ra头结点
	return rb;//rb是新单循环链表的尾指针
}