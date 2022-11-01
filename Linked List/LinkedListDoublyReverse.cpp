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

void reverse(newNode *&head, newNode *&tail) {
  newNode *current = head, *temp;
  while (current != NULL) {
    temp = current->next;
    current->prev = current->next;

    if (temp == NULL) {
      head = current;
      break;
    }
    if (current == head) {
      tail = current;
    }
    current = temp;
  }
  current = tail, temp = NULL;
  while (current != NULL) {
    current->next = temp;
    temp = current;
    current = current->prev;
    if (current == NULL)
      return;
  }
  cout << "Nothing to Reverse" << endl;
}