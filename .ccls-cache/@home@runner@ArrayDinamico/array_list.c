#include "array_list.h"
#include <stdlib.h>

list list_create_10(){
    list l;
    l = (list)malloc(sizeof(struct array_list));
    l->capacity = 10;
    l->used=0;
    l->data = (int*)malloc(sizeof(int)*(l->capacity));
    return l;
}

list list_create_10mil(){
    list l;
    l = (list)malloc(sizeof(struct array_list));
    l->capacity = 10000;
    l->used=0;
    l->data = (int*)malloc(sizeof(int)*(l->capacity));
    return l;
}

list list_create_dobra(){
    list l;
    l = (list)malloc(sizeof(struct array_list));
    l->capacity = 8;
    l->used=0;
    l->data = (int*)malloc(sizeof(int)*(l->capacity*2));
    return l;
}

void list_destroy(list l){
    free(l->data);
    free(l);
}

int list_get(list l, int index){
    return l->data[index];
}

void list_append_10(list l, int value){
    if (l->used==l->capacity){
        int j,*new_data = (int*)malloc(sizeof(int)*(l->capacity+10));
        l->capacity+=10;
        for (j=0 ; j<l->used ; ++j)
            new_data[j]=l->data[j];
        int *old_data = l->data;
        l->data = new_data;
        free(old_data);
    }
    l->data[l->used++] = value;
}

void list_append_10mil(list l, int value){
    if (l->used==l->capacity){
        int j,*new_data = (int*)malloc(sizeof(int)*(l->capacity+10000));
        l->capacity+=10000;
        for (j=0 ; j<l->used ; ++j)
            new_data[j]=l->data[j];
        int *old_data = l->data;
        l->data = new_data;
        free(old_data);
    }
    l->data[l->used++] = value;
}

void list_append_dobra(list l, int value){
    if (l->used==l->capacity){
        int j,*new_data = (int*)malloc(sizeof(int)*(l->capacity*2));
        l->capacity*=2;
        for (j=0 ; j<l->used ; ++j)
            new_data[j]=l->data[j];
        int *old_data = l->data;
        l->data = new_data;
        free(old_data);
    }
    l->data[l->used++] = value;
}

int list_size(list l){
    return l->used;
}

int list_capacity(list l){
    return l->capacity;
}


int array_list_find(list l, int element) {
  int i, x, ind = -1;
  for (i = 0; i < list_size(l); i++) {
    x = list_get(l, i);
    if (x == element) {
      ind = i;
      break;
    }
  }
  
  return ind;
}

unsigned int array_list_pop_back(list l) {
  if (l->used == 0) return -1;
  int j,*new_data = (int*)malloc(sizeof(int)*(l->capacity));
  for (j=0 ; j<(l->used - 1) ; ++j)
    new_data[j]=l->data[j];
  int *old_data = l->data;
  l->data = new_data;
  free(old_data);
  return *new_data;
} 


void append_ldl(struct ld_int *l, int v) {
  struct ld_int_node * new_node = (struct ld_int_node *) malloc(sizeof(struct ld_int_node));
  new_node->value = v;
  new_node->next = l->head;
  new_node->prev = 0;
  l->head = new_node;
  if (new_node->next == 0) {
    l->tail = new_node;
  } else {
    new_node->next->prev = new_node;
  }
}

void inserir_inicio(struct ld_int *l, int v) {
struct ld_int_node * new_node = (struct ld_int_node *) malloc(sizeof(struct ld_int_node));
new_node->value = v;
new_node->next = l->head;
new_node->prev = 0;
l->head = new_node;
if (new_node->next == 0) {
l->tail = new_node;
} else {
new_node->next->prev = new_node;
}
}

/* métodos que não implementados

void inserir_fim(ll_int l, int v) {
struct ll_int_node * new_node;
new_node = (struct ll_int_node*) malloc(sizeof(struct ll_int_node));
new_node->value = v;
new_node->next = 0;
if (l->last == 0)
	l->first = new_node;
else
	l->last->next = new_node;
l->last=new_node;
}

int remover_inicio(ll_int l) {
if (l->first == 0)
	return -1;
int r = l->first->value;
struct ll_int_node *old_node = l->first;
l->first = l->first->next;
free(old_node);
return r;
}

int remove_fim(ll_int l ){
if (l->first==0) return -1;
if (l->first!=0 && l->next==0) {
free(l->first);
return -1;
}
int r = l->last->value;
struct ll_int_node *new_last = l->first;
while (new_last->next != l->last)
	new_last = new_last->next;
new_last->next=0;
free(l->last);
l->last = new_last;
return;
}
*/