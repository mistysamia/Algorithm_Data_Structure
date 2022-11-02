////////////////Hackerrank - > Insert a node at a specific position in a linked list

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
      SinglyLinkedListNode *current = new SinglyLinkedListNode(data);
  current->data = data;
  current->next = NULL;

  int count = 1;
  SinglyLinkedListNode *recent = llist;
  if(recent==NULL){
    llist=current;
    return llist;
  }
  while (recent != NULL) {
    if(count==position){
        current->next=recent->next;
        recent->next=current;
        return llist;
    }
    count++;
    recent = recent->next;
  }
  return llist;

}
