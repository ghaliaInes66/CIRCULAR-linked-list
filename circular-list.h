#ifndef CIRCULAR_LIST
#define CIRCULAR_LIST

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}node;


void add_begin(node**s,node**e,int val){
  node *p=(node*) malloc(sizeof(node));
  p->data=val;
  p->next=*s;
  *s=p;
  if(*e==NULL){ *e=*s;}
  node *r=*e;
  r->next=*s;
}

void add_last(node**s,node**e,int val){
  node *p=(node*) malloc(sizeof(node));
  p->data=val;
  p->next=*s;
  node *r=*e;
  if(*s==NULL){
    *s=p;
  *e=*s;
  r->next=*s;
  }else{
   r->next=p;
   *e=p;
  }
}

void delete_begin(node**s,node**e){
  if(*s==NULL){
    printf("empty list");
  }
  else if(*e==*s){
    node *p=*s;
    *s=NULL;*e=NULL;
    free(p);
    
  }
  else{
    node *p=*s;
    *s=p->next;
      node *r=*e;
    r->next=*s;
  }
}

void delete_end(node**s,node**e){
  if(*s==NULL){
    printf("empty list");
  }
  else if(*e==*s){
    node *p=*s;
    *s=NULL;*e=NULL;
    free(p);
  }
  else{
    node *p=*e;
    node *r=*s;
    while(r->next!=*e){
      r=r->next;
    }
    r->next=*s;
    *e=r;
    free(p);
  }
}

void display_nodes(node**s,node**e){
  if(*s==NULL){
    printf("empty list");
  }
  else{
 node *p=*s;
 while(p!=*e){
  printf("%i ",p->data);
  p=p->next;
 }
 printf("%i ",p->data);
  }
}

int length(node**s,node**e){
  if(*s==NULL){
    return 0;
  }
  int count=1;
  node *p=*s;
 while(p!=*e){
  count++;
  p=p->next;
 }
 return count;
}

#endif