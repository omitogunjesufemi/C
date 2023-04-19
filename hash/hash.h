#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50000
unsigned long hash_function(char *str);

typedef struct HashItem
{
	char *key;
	char *value;
} HashItem;

typedef struct LinkedList
{
	HashItem* item;
	struct LinkedList *next;
} LinkedList;

typedef struct HashTable
{
	HashItem** items;
	LinkedList** overflow_buckets;
	int size;
	int count;
} HashTable;

HashItem *create_hash_item(char *key, char *value);
HashTable *create_hash_table(int size);
void free_item(HashItem *item);
void free_table(HashTable *table);
void print_table(HashTable *table);

void insert_hash_item(HashTable *table, char *key, char *value);
void search_hash_item(HashTable *table, char *key);
void delete_hash_item(HashTable *table, char *key);

LinkedList *create_node(HashItem *item);
LinkedList *insert_node(LinkedList *list, HashItem *item);
LinkedList *delete_head_node(LinkedList *list, HashItem *item);
void free_linkedlist(LinkedList *list);

void handle_collision(HashTable *table, unsigned long index, HashItem *item);

#endif
