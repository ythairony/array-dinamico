#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

struct array_list{
  int *data,
      capacity,
      used;
};

struct ld_int_node {
  int value;
  struct ld_int_node *next, *prev;
};

struct ld_int{
  struct ld_int_node *head, *tail;
};


/*
struct linked_list_int_node{
  int value;
  struct linked_list_int_node ∗prev;
  struct linked_list_int_node ∗next;
};
struct linked_list_int{
  struct linked_list_int_node ∗first;
  struct linked_list_int_node ∗last;
unsigned int size;
};
*/

typedef struct array_list* list;


list list_create_10();

list list_create_10mil();

list list_create_dobra();

void list_destroy(list l);

int list_get(list l, int index);

void list_append_10(list l, int value);

void list_append_10mil(list l, int value);

void list_append_dobra(list l, int value);

int list_size(list l);

int list_capacity(list l);

int array_list_find(list l, int element);

unsigned int array_list_pop_back(list l);

void append_ldl(struct ld_int *l, int v);

#endif