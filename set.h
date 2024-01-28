#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define HASHMAP_SIZE 64
#define HASHMAP_SIZE_LIST 1
#define BUFFER_SIZE 20

struct aiv_set_item
{
    const char *key;
    size_t key_len;
};

struct aiv_set
{
    struct aiv_set_item hashmap[HASHMAP_SIZE][HASHMAP_SIZE_LIST];
    int counter;
};


size_t djb33x_hash(const char *key, const size_t keylen);
struct aiv_set_item *aiv_set_insert(struct aiv_set *set, const char *key);