#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

int main(){
    list l01 = list_create_dobra();
    int num, i;
    while (scanf("%d",&num), num!=-1){
        list_append_dobra(l01,num); /* l01.append(num) */
    }
    /* Processamento dos dados */
    for (i=0 ; i<list_size(l01) ; ++i)
        printf("%d ",list_get(l01,i));
    printf("\n");
    printf("Used: %d\n",list_size(l01));
    printf("Capa: %d\n",list_capacity(l01));
    //list_destroy(l01);
  
    int e, ind;
    scanf("%d", &e);
    ind = array_list_find(l01, e);
    printf("Índice = %d\n", ind);
    
    return 0;
}