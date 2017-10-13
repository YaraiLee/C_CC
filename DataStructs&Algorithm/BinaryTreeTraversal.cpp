/**
ʹ��ջ����ݹ飬ʵ�ֶ���������
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
  
typedef BinNode* bintree;          //bintree�����Ǹ�ָ�����ָ��  

#define SIZE 100  
typedef struct seqstack{  
    bintree data[SIZE];  
    int tag[SIZE];   //Ϊ��������׼����  
    int top;     //topΪ������±�  
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
	if((c=getchar()) == '#')  /*���нڵ�ͨ��'#'�������Һ���ָ��*/
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
        while(t || s.top != -1){    //ջ���˵�ͬʱtҲΪ�ա�  
            while(t){  
                push(&s,t);  
                s.tag[s.top] = 0;   //���÷��ʱ�ǣ�0Ϊ��һ�η��ʣ�1Ϊ�ڶ��η���  
                t= t->lchild;  
            }  
            if(s.tag[s.top] == 0){  //��һ�η���ʱ��ת��ͬ���ҽ��  
                t= s.data[s.top];   //���ߵ���ʱt��Ϊ�յģ��������ⲽ��  
                s.tag[s.top]=1;       
                t=t->rchild;  
            }else {  
                while (s.tag[s.top] == 1){ //�ҵ�ջ����һ����һ�η��ʵĽ�㣬�˳�ѭ��ʱ��û��pop����Ϊ�����ӽ��  
                    t = pop(&s);  
                    printf("%c ",t->data);  
                }  
                t = NULL; //���뽫t�ÿա����������ߣ�ֱ��������  
            }  
        }  
    }  
}  

int main(int argc, char *argv[])
{
	bintree tree;
	createtree(&tree);/*ǰ�����룺abd#e##fg###c## */ 
	postorder_dev(tree);/*���������edgfbca*/
	
	return 0;
} 