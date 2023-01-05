#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"
#include <time.h>

int main(){
    clock_t inicio, fim;
    list l01 = list_create_10mil();
    int num, i;
    inicio = clock();
    while (scanf("%d",&num), num!=-1){
        list_append_dobra(l01,num); 
    }
    fim = clock();
    double tempo = (fim - inicio)/(CLOCKS_PER_SEC/1000.0);
  
    /* Processamento dos dados */
    /*for (i=0 ; i<list_size(l01) ; ++i)
        printf("%d ",list_get(l01,i));*/
    printf("\n");
    printf("Used: %d\n",list_size(l01));
    printf("Capa: %d\n",list_capacity(l01));
    printf("Tempo decorrido: %lf ms\n", tempo);
    //list_destroy(l01);


    // Pegando índice de algum elemento  
    /*
    int e, ind;
    scanf("%d", &e);
    ind = array_list_find(l01, e);
    printf("Índice = %d\n", ind);
    */

    
    return 0;
}