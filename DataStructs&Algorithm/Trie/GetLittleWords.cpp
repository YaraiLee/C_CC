#include <iostream>
#include <cstring>

using namespace std;
#define MAX	26	//字符集大小
 
typedef struct Trie_node
{
	int count;	//统计单词前缀出现次数
 	struct Trie_node* next[MAX];	//指向各个子树的指针 
 	bool exist;	//标记该节点是否构成单词 
} TrieNode, *Trie;

TrieNode* createTrieNode()
{
	TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
	node->count = 0;
	node->exist = false;
	memset(node->next, 0, sizeof(node->next));	//初始化空指针 
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
		node = node->next[id];	//每插入一部，相当于有一个新串经过，指针向下移动 
		++p;
		node->count += 1;	//统计单词前缀出现的次数（也包括每个单词出现的次数） 
	}
	node->exist = true;	//单词结束标记 
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