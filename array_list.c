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

/*int array_list_get(list l, int index, int *error) {
  *error = 0;
  if (index < 0 || index >= l->used) {
    *error = 1;
    return 0;
  }
  return l->data[index];
}
*/
/*
unsigned int array_list_push_back(list l, int value) {
  if (l->capacity == l->used) {
    if (!increase_memory(l)) 
      return array_list_size(l);
  }
  l->data[l->used] = value;
  l->used++;
  return array_list_size(l);
}
*/

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

