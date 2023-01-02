#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

struct array_list{
  int *data,
      capacity,
      used;
};

typedef struct array_list* list;


list list_create_10();

list list_create_10mil();

list list_create_dobra();

void list_destroy(list l);

int list_get(list l, int index);

void list_append(list l, int value);

void list_append_dobra(list l, int value);

int list_size(list l);

int list_capacity(list l);

#endif