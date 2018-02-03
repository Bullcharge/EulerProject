/* list.c */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "list.h"

void list_init(struct list *list){

  list->next = NULL;

}

size_t list_len(struct list *list){

  size_t i;
  list = list->next;
  for(i = 0;list; list = list->next ){

    i+= 1;

  }
  printf("%zu",i);
  return i;

}

int list_is_empty(struct  list *list){

  if (list_len(list) == 0) return 1;
  return 0;

}

void list_push_front(struct list *list, struct list *elm){

  
  struct list *tmp;
  tmp = list->next;
  elm->next = tmp;
  list->next = elm;
  /*
  for(size_t i = 0; i < len; ++i){

    tmp = list;
    list = elm;
    elm = tmp;
    list = list->next;
  }
    
  list->next = elm; 
  free(tmp); */

}

struct list* list_pop_front(struct list *list){

  if (list_is_empty(list)) return NULL;
  list->next = list->next->next;
  return list;

}

struct list* list_find(struct list *list, int value){

  while(list->next != NULL || list->data != value){
      
    list = list->next;

  }

  if (list->next == NULL) return NULL;
  return list;
}

int list_is_sorted(struct list *list){

  while(list->next != NULL){

    if (list->data > list->next->data)
      return 0;

    list = list->next;

  }

  return 1;

}
void list_insert(struct list *list,struct list *elm){

  struct list *tmp;
  tmp = malloc(sizeof(list));
  while(list->next != NULL || list->data < elm->data){

    list = list->next;

  }
  
  tmp = list->next;
  elm->next = tmp;
  list->next = elm;


  /*
  
  for(size_t i = 0; i < len;++i){
      
    tmp = list;
    list = elm;
    elm = tmp;
    list = list->next;

  } */

}

void list_rev(struct list *list){

  struct list *curr = list->next;
  if (curr->next) {
    curr = curr->next;
    struct list *tmp = curr;
    list->next->next = NULL;
    for(;tmp;curr = tmp){
        tmp = curr->next;
        list_push_front(list,tmp);
    }
  }
}


void list_half_split(struct list *list, struct list *second){
    
    size_t n = list_len(list);
    size_t m = n / 2;
    for(size_t i = 0; i < m; ++i){
        
        list_push_front(second,list);
        list_pop_front(list);
        list = list->next;
    }

}


  
