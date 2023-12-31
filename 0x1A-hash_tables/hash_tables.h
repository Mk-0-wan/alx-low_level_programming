#ifndef __HASH_TABLES__
#define __HASH_TABLES__

/* C standard library */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h> /* for printf */
#include <stdlib.h> /* for malloc */
#include <string.h> /* for strcpy */

/*aliases*/
typedef unsigned long int ul;
typedef unsigned char uc;
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* Advanced task */
/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

/* PHP */
void shash_table_print(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
void free_shash_nodes(shash_node_t *head);
char *shash_table_get(const shash_table_t *ht, const char *key);
shash_node_t *sbuckets(const char *key, const char *value);

/* Function prototypes */
void hash_table_delete(hash_table_t *ht);
hash_table_t *hash_table_create(ul size);
ul hash_djb2(const uc *str);
ul key_index(const uc *key, ul size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
hash_node_t *buckets(const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void free_hash_table(hash_table_t *ht);
void hash_table_print(const hash_table_t *ht);
void free_node_items(hash_node_t *bucket);
void hash_table_delete(hash_table_t *ht);
void free_hash_nodes(hash_node_t *head);
#endif
