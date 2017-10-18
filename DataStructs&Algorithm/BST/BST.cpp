//
//  main.cpp
//  BST
//
//  Created by 李亚雷 on 2017/9/17.
//  Copyright © 2017年 李亚雷. All rights reserved.
//

#include <iostream>

#define NULL 0

typedef struct Node
{
    int key;
    struct Node *pLeft;
    struct Node *pRight;
}Node;

/**
 描述：二叉排序树搜索算法
 输入参数：pRoot：子树中的根节点     key：被查找的关键字
 返回值：查找成功返回1，失败返回0
 */
int SearchBST(Node *pRoot, int key)
{
    /*节点为空，则表示搜索到叶子结点仍未找到，返回0*/
    if (NULL == pRoot)
    {
        return 0;
    }
    /* 成功找到返回1 */
    if (key == pRoot->key)
    {
        return 1;
    }
    /*关键字小于pRoot节点的关键字，则在左子树查找*/
    else if (key < pRoot->key) SearchBST(pRoot->pLeft, key);
    /*反之大于，在右子树查找*/
    else SearchBST(pRoot->pRight, key);
    return 0;
}

/**
 描述：改进二叉排序树搜索算法
 输入参数：pRoot：子树中根节点指针    key：被查找的关键字     pParentNode：pRoot的父节点，初始时pRoot指向根节点，其父节点为NULL
 输出参数：pKeyNode：查找成功时返回关键字所在节点的指针，不成功时，返回查找路径上不为空的最后一个节点，当pKeyNode返回NULL时，表示此时二叉排序树为一空树
 返回：查找成功，返回1；查找失败，返回0
 */
int SearchBST(Node *pRoot, int key, Node **pKeyNode, Node **pParentNode)
{
    *pKeyNode = pRoot;
    while (*pKeyNode)
    {
        if (key > (*pKeyNode)->key)
        {
            *pParentNode = *pKeyNode;
            *pKeyNode = (*pKeyNode)->pRight;
        }
        else if (key < (*pKeyNode)->key)
        {
            *pParentNode = *pKeyNode;
            *pKeyNode = (*pKeyNode)->pLeft;
        }
        else
        {
            return 1;
        }
    }
    
    *pKeyNode = *pParentNode;
    
    return 0;
}

/**
 描述：二叉排序树插入算法
 输入参数：key：被插入的关键字
 输出参数：pRoot：插入后新的二叉排序树的根节点指针
 返回：插入成功返回1，插入失败返回0
 */
int InsertBST(Node **pRoot, int key)
{
    Node *pNewNode = NULL;/*定义存放新的关键字节点*/
    Node *pKeyNode = NULL;
    Node *pParentNode = NULL;
    
    /*如果该关键字已存在树中，则插入失败*/
    if (SearchBST(*pRoot, key, &pKeyNode, &pParentNode)) return 0;
    /*若不存在，则首先为新的节点分配空间*/
    pNewNode = (Node *)malloc(sizeof(Node));
    pNewNode->key = key;
    pNewNode->pRight = pNewNode->pLeft = NULL;
    /*若树为空树，则新节点为树的根节点*/
    if (NULL == pKeyNode)   (*pRoot) = pNewNode;
    /*比节点关键字小，插入到左孩子*/
    else if (key < pKeyNode->key) pKeyNode->pLeft = pNewNode;
    else pKeyNode->pRight = pNewNode;
    
    return 1;
}

/**
 描述：二叉排序树删除算法
 输入参数：pRoot：子树中的根节点     key：被删除的关键字
 返回：查找成功返回1，失败返回0
 */
int DeleteBST(Node *pRoot, int key)
{
    Node *pParentNode = NULL;
    Node *pNode = pRoot;
    Node *pKeyNode;
    Node **pTempNode;
    
    /*如果找到*/
    if (SearchBST(pRoot, key, &pKeyNode, &pParentNode))
    {
        if (pParentNode == NULL)    pTempNode = &pRoot;
        /*找到节点为其父节点的左孩子*/
        else if (pKeyNode == pParentNode->pLeft)    pTempNode = &pParentNode->pLeft;
        /*找到节点为父节点的右孩子*/
        else pTempNode = &pParentNode->pRight;
        /*若被删除的节点左子树为空，则直接删除*/
        if (NULL == pKeyNode->pLeft)
        {
            *pTempNode = pKeyNode->pRight;
            free(pKeyNode);
        }
        /*若被删除的节点右子树为空，直接删除*/
        if (NULL == pKeyNode->pRight)
        {
            *pTempNode = pKeyNode->pLeft;
            free(pKeyNode);
        }
        else
        {
            pNode = pKeyNode->pLeft;/*pNode肯定不为空*/
            pTempNode = &pKeyNode->pLeft;
            while (NULL != pNode->pRight)/*查找被删除节点左孩子的最右孩子节点，用于替换被删除节点*/
            {
                pTempNode = &pNode->pRight;
                pNode = pNode->pRight;
            }
            /*替换被删除节点*/
            pKeyNode->key = pNode->key;
            *pTempNode = pNode->pLeft;/*最右节点不一定是叶子节点，最右子节点的父节点右孩子指针指向最右节点的左孩子节点*/
            free(pNode);
        }
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

