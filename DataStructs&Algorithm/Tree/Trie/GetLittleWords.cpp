#include <iostream>
#include <cstring>

using namespace std;
#define MAX	26	//�ַ�����С
 
typedef struct Trie_node
{
	int count;	//ͳ�Ƶ���ǰ׺���ִ���
 	struct Trie_node* next[MAX];	//ָ�����������ָ�� 
 	bool exist;	//��Ǹýڵ��Ƿ񹹳ɵ��� 
} TrieNode, *Trie;

TrieNode* createTrieNode()
{
	TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
	node->count = 0;
	node->exist = false;
	memset(node->next, 0, sizeof(node->next));	//��ʼ����ָ�� 
	return node;
}

void Trie_insert(Trie root, char* word)
{
	Trie node = root;
	char *p = word;
	int id;
	while (*p)
	{
		id = *p - 'a';
		if (NULL == node->next[id])
		{
			node->next[id] = createTrieNode();
		}
		node = node->next[id];	//ÿ����һ�����൱����һ���´�������ָ�������ƶ� 
		++p;
		node->count += 1;	//ͳ�Ƶ���ǰ׺���ֵĴ�����Ҳ����ÿ�����ʳ��ֵĴ����� 
	}
	node->exist = true;	//���ʽ������ 
} 

int Trie_search(Trie root, char* word)
{
	Trie node = root;
	char *p = word;
	int id;
	while (*p)
	{
		id = *p - 'a';
		node = node->next[id];
		++p;
		if (NULL == node)
			return 0;
	}
	return node->count;
} 