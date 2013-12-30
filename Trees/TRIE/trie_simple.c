#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPH_SIZE 26

typedef enum { false, true } bool;

struct trie_node{
	int value;
	struct trie_node *children[ALPH_SIZE];
};
typedef struct trie_node trie_node_t;

/*
This is the root node. It contains a pointer to the
top most trie node and the count.

Eg: ROOT ---> TRIE_NODE1
	     /          \
	TRIE_NODE2   TRIE_NODE3

and so on
*/
struct trie{
	trie_node_t *root_node;
	int count;
};
typedef struct trie trie_t;

void insert(trie_t *root, char *key){
	int level;
	int index;
	int length = strlen(key);
	trie_node_t *crawl;

	root->count++;
	crawl = root->root_node;

	for(level = 0; level < length; level++){
		index = key[level]-'a';
		
		if( !crawl->children[index] ){
			trie_node_t *temp = (trie_node_t*)malloc(sizeof(trie_node_t));
			memset(temp, 0, sizeof(trie_node_t));
			crawl->children[index] = temp;
		}
		
		crawl = crawl->children[index];
	}
	// Mark this node as the leaf
	crawl->value = root->count;
}

bool search(trie_t *root, char *key){
	int level;
	int length = strlen(key);
	int i;
	int index;
	trie_node_t *crawl = root->root_node;

	for(i=0; i<length; i++){
		index = key[i]-'a';
		if( !crawl->children[index] )
			return 0;
		crawl = crawl->children[index];
	}
	return ((crawl != NULL) && crawl->value);

}


int main(){
	trie_t *proot;
	trie_node_t *first_node;
	proot = (trie_t*)malloc(sizeof(trie_t));
	first_node = (trie_node_t*)malloc(sizeof(trie_node_t));
	memset(first_node, 0, sizeof(trie_node_t));
	proot->root_node = first_node;

	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

	insert(proot, keys[0]);
	insert(proot, keys[1]);
	printf("\n key %s key[1] Found? %d \n",keys[1], search(proot, "hello"));
	return 0;
}
