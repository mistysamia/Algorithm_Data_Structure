#define ll long long
struct node {
  ll data;
  struct node *next;
};
typedef struct node newNode;
newNode *head = NULL, *tail = NULL;

void reverse(newNode *&head, newNode *&tail) {
  newNode *current = head, *temp = NULL, *newNext = NULL;
  tail=head;
  while (current != NULL) {
    temp = current->next;
    current->next = newNext;
    newNext = current;
    if(temp==NULL){
        head=current;
        return;
    }
    current = temp;
  }
  cout<<"Nothing to reverse"<<endl;
}
