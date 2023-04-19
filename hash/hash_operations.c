#include "hash.h"

void insert_hash_item(HashTable *table, char *key, char *value)
{
	HashItem *item;
	unsigned long index;

	index = hash_function(key);

	if (table->items[index] == NULL)
	{
		item = create_hash_item(key, value);
		table->items[index] = item;
	}
	else
	{
		if (strcmp(table->items[index]->key, key) == 0)
		{
			strcpy(table->items[index]->value, value);
		}
		else
		{
			//There is collision
			item = create_hash_item(key, value);
			handle_collision(table, index, item);
		}
	}
}


void search_hash_item(HashTable *table, char *key)
{
	HashItem *item;
	unsigned long index;
	LinkedList *head;

	index = hash_function(key);
	item = table->items[index];
	head = table->overflow_buckets[index];

	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
		{
			printf("Search complete!\n");
			printf("Index: %ld  Key: %s  Value: %s\n",
			       index, item->key, item->value);
		}

		if (head != NULL)
		{
			item = head->item;
			printf("Search complete!\n");
			printf("Index: %ld  Key: %s  Value: %s\n",
			       index, item->key, item->value);
		}
	}
}


void delete_hash_item(HashTable *table, char *key)
{
	HashItem *item;
	unsigned long index;

	index = hash_function(key);
	item = table->items[index];

	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
		{
			printf("Removing Item!\n");
			printf("Index: %ld  Key: %s  Value: %s\n",
			       index, item->key, item->value);
			free_item(item);
			table->items[index] = NULL;
		}
	}
}
