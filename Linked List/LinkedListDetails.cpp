#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define b(n) cout << "bug " << n << endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll, ll>
#define fast_cin                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000

ll mod = 1e9 + 7;

// GCD=__gcd(n,m);  lcm=(n*m)/GCD;
// cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006], tra1[100006];

struct node {
  ll data;
  struct node *next;
};
typedef struct node newNode;
newNode *head = NULL, *tail = NULL;

void append(ll value) {
  newNode *current = new newNode();
  current->data = value;
  current->next = NULL;

  if (head == NULL) {
    head = current;
    tail = current;
  } else {
    tail->next = current;
    tail = current;
  }
}

void remove(ll value) {
  newNode *current = head, *prev = head;

  while (current != NULL) {
    if (current->data == value) {
      if (current == head) {
        head = head->next;
      } else {
        if (current->next == NULL) {
          prev->next = NULL;
        } else {
          prev->next = current->next;
        }
      }
      return;
    }
    prev = current;
    current = current->next;
  }
  cout << "Nothing to remove" << endl;
}

void print() {
  newNode *current = head;

  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void search(ll value) {
  newNode *current = head;

  while (current != NULL) {
    if (current->data == value) {
      cout << "Data Found" << endl;
      return;
    }
    current = current->next;
  }
  cout << "Data Not Found" << endl;
}

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

int main() {
  fast_cin;
  ll t, cas = 1;
  cin >> t;
  while (t--) {
    map<ll, ll> mp;
    //  map<ll,ll>::iterator it;
    string s, s1;
    deque<ll> deq;
    ll lock = 0, sum = 0, co = 0, ans = 0, a = 0, b = 0, c = 0, d = 0;
    ll n, m, k, mx = -BIG, mn = BIG;
    ll fir = 0, sec = 0, x = 0, y = 0, point, in, temp;
    cin >> n;
    if (n == 1) // Insertion
    {
      cin >> m;
      append(m);
    } else if (n == 2) // Deletion
    {
      cin >> m;
      remove(m);
    } else if (n == 3) // Print the whole Linked List
    {
      print();
    } else if (n == 4) // Search For a particular Element of a Linked List
    {
      cin >> m;
      search(m);
    }else{
        reverse(head,tail);
    }

    // ll str[n+3];
    // ll len=s.length();
  }
}
