#include "hash.h"

unsigned long hash_function(char *str)
{
	unsigned long i = 0;
	int j;

	for (j = 0; str[j]; j++)
		i += str[j];

	return i % CAPACITY;
}

HashItem *create_hash_item(char *key, char *value)
{
	HashItem *item;

	item = malloc(sizeof(HashItem));
	if (item == NULL)
	{
		return NULL;
	}

	item->key = malloc(strlen(key) + 1);
	item->value = malloc(strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);

	return item;
}

HashTable *create_hash_table(int size)
{
	HashTable *table;
	int i;

	table = malloc(sizeof(HashTable));
	if (table == NULL)
	{
		return NULL;
	}
	table->size = size;
	table->count = 0;
	table->items = calloc(size, sizeof(HashItem *));

	for (i = 0; i < size; i++)
	{
		table->items[i] = NULL;
	}

	table->overflow_buckets = calloc(size, sizeof(LinkedList *));

	for (i = 0; i < size; i++)
	{
		table->overflow_buckets[i] = NULL;
	}

	return table;
}

void free_item(HashItem *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void free_table(HashTable *table)
{
	int i;

	for (i = 0; i < table->size; i++)
	{
		if (table->items[i] != NULL)
		{
			free_item(table->items[i]);
		}
	}
	free(table->items);

	for (i = 0; i < table->size; i++)
	{
		if (table->overflow_buckets[i] != NULL)
		{
			free_linkedlist(table->overflow_buckets[i]);
		}
	}
	free(table->overflow_buckets);

	free(table);
}

void print_table(HashTable *table)
{
	int i;

	for (i = 0; i < table->size; i++)
	{
		if (table->items[i] != NULL)
		{
			printf("Index: %d  Key: %s  Value: %s\n",
			       i, table->items[i]->key,
			       table->items[i]->value);
		}
	}
}

void handle_collision(HashTable *table, unsigned long index, HashItem *item)
{
	LinkedList *head = table->overflow_buckets[index];

	if (head == NULL)
	{
		head = create_node(item);
		table->overflow_buckets[index] = head;
	}
	else
	{
		table->overflow_buckets[index] = insert_node(head, item);
	}
}
