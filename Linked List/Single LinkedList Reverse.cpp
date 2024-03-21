#define ll long long

// Approach 1 : 
struct node
{
  ll data;
  struct node *next;
};
typedef struct node newNode;
newNode *head = NULL, *tail = NULL;

void reverse(newNode *&head, newNode *&tail)
{
  newNode *current = head, *temp = NULL, *newNext = NULL;
  tail = head;
  while (current != NULL)
  {
    temp = current->next;
    current->next = newNext;
    newNext = current;
    if (temp == NULL)
    {
      head = current;
      return;
    }
    current = temp;
  }
  cout << "Nothing to reverse" << endl;
}


// Approach 2 : 

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
  ListNode *current = head, *prev = NULL;

  while (current != NULL)
  {
    ListNode *temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
  }
  return prev;
}