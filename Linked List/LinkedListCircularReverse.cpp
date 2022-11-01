/***********************
************************
Only For one Directional 
************************
************************/



#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long

struct node {
  ll data, flag;
  struct node *next, *prev;
};
typedef struct node newNode;
newNode *head = NULL, *tail = NULL;

void reverse(newNode *&head,newNode *&tail) {

  newNode *current = head, *next = NULL, *prev = NULL;

  while (current != NULL) {
    next=current->next;
    current->next=current->prev;
    current=next;

    if(current==head){
      head=current->prev;
      tail=current;
      current=head;
      return ;
    }
  }
  cout<<"Nothing to reverse"<<endl;
}