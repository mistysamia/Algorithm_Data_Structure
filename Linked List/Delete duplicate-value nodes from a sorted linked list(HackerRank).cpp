SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
  SinglyLinkedListNode *current = llist, *prev = NULL;
  int check = -100000;

  while (current != NULL) {
    if (current->data > check) {
      check = current->data;
      prev=current;
    }else{
        prev->next=current->next;
    }

    current = current->next;
  }
  return llist ;
}
