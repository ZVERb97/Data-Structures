#include "set.h"
#include <stdlib.h>

struct dictionary_item
{
    struct aiv_set_item *key;
    char* value;
    
};

typedef struct dictionary_map
{
    struct aiv_set *map;
    struct dictionary_item** items;
}dictionary;


struct dictionary_item *insert_value(struct dictionary_map *dict, char * key, char* value)
{   
    struct dictionary_item *item = malloc(sizeof(struct dictionary_item));
    
    item->key = aiv_set_insert(dict->map,key);
    item->value = value;
    printf("%s,%s\n",item->key->key,item->value);
    
    return item;
}

int main(int argc, char** argv)
{
    dictionary dict;
    memset(&dict,0,sizeof(struct dictionary_map));
    insert_value(&dict,"0","Ciao");

}