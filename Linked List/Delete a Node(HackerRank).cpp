SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
  SinglyLinkedListNode *current = llist, *prev = llist;

  int count=0;
  while (current != NULL) {
    if (count == position) {
      if (current == llist) {
        llist = llist->next;
      } else {
        if (current->next == NULL) {
          prev->next = NULL;
        } else {
          prev->next = current->next;
        }
      }
      return llist;
    }
    prev = current;
    count++;
    current = current->next;
  }
   return llist;
}
