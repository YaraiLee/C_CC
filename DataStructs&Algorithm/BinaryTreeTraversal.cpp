/**
使用栈替代递归，实现二叉树遍历
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef char datatype;  
  
typedef struct BinNode{  
    datatype data;  
    struct BinNode* lchild;  
    struct BinNode* rchild;  
}BinNode;  
  
typedef BinNode* bintree;          //bintree本身是个指向结点的指针  

#define SIZE 100  
typedef struct seqstack{  
    bintree data[SIZE];  
    int tag[SIZE];   //为后续遍历准备的  
    int top;     //top为数组的下标  
}seqstack;  

void push(seqstack *s,bintree t){  
  
    if(s->top == SIZE){  
        printf("the stack is full\n");  
    }else{  
        s->top++;  
        s->data[s->top]=t;  
    }  
}  
  
bintree pop(seqstack *s){  
    if(s->top == -1){  
        return NULL;  
    }else{  
        s->top--;  
        return s->data[s->top+1];  
    }  
}  

void createtree(bintree *t)
{
	datatype c;
	if((c=getchar()) == '#')  /*所有节点通过'#'结束左右孩子指针*/
	{
   		*t = NULL; 
	} 
	else{  
	    *t = (bintree)malloc(sizeof(BinNode));  
	    memset(*t, 0, sizeof(BinNode));

	    (*t)->data = c;  
	    createtree(&(*t)->lchild);  
	    createtree(&(*t)->rchild);  
	} 
}

void postorder_dev(bintree t){  
    seqstack s;  
    s.top = -1;  
    if(!t){  
        printf("the tree is empty!\n");  
    }else{  
        while(t || s.top != -1){    //栈空了的同时t也为空。  
            while(t){  
                push(&s,t);  
                s.tag[s.top] = 0;   //设置访问标记，0为第一次访问，1为第二次访问  
                t= t->lchild;  
            }  
            if(s.tag[s.top] == 0){  //第一次访问时，转向同层右结点  
                t= s.data[s.top];   //左走到底时t是为空的，必须有这步！  
                s.tag[s.top]=1;       
                t=t->rchild;  
            }else {  
                while (s.tag[s.top] == 1){ //找到栈中下一个第一次访问的结点，退出循环时并没有pop所以为其左子结点  
                    t = pop(&s);  
                    printf("%c ",t->data);  
                }  
                t = NULL; //必须将t置空。跳过向左走，直接向右走  
            }  
        }  
    }  
}  

void postorder(bintree root)
{
	if (NULL == root)
		return ;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%c ", root->data);
	return;
}

int main(int argc, char *argv[])
{
	bintree tree;
	createtree(&tree);/*前序输入：abd#e##fg###c## */ 
	postorder_dev(tree);/*后序输出：edgfbca*/
	
	return 0;
} 
