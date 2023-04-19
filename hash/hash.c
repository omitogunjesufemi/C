#include "hash.h"

int main()
{
	HashTable *table;

	table = create_hash_table(CAPACITY);

	insert_hash_item(table, "Tofunmi", "First Child");
	insert_hash_item(table, "Pemi", "Second Child");
	insert_hash_item(table, "Femi", "Third Child");
	insert_hash_item(table, "Hel", "Fourth Child");

	print_table(table);

	printf("\n------------- \n");
	search_hash_item(table, "Pemi");

	printf("\n------------- \n");
	delete_hash_item(table, "Femi");

	printf("\n------------- \n");
	print_table(table);

	printf("\n------------- \n");
	insert_hash_item(table, "Cau", "Fourth Daugther");
	print_table(table);

	printf("\n------------- \n");
	search_hash_item(table, "Cau");

	free_table(table);
}
