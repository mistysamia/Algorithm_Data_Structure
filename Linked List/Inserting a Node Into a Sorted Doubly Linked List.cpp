##############  HackerRank - >Inserting a Node Into a Sorted Doubly Linked List

#include <bits/stdc++.h>
#include <iostream>
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
  struct node *next, *prev;
};
typedef struct node newNode;
newNode *head = NULL, *tail = NULL;

void append(newNode *&head, newNode *&tail, ll value) {

  newNode *current = new newNode();
  current->data = value;
  current->prev = NULL;
  current->next = NULL;

  if (head == NULL) {
    head = current;
    tail = current;
    return;
  } else {
    newNode *recent = head, *temp;
    while (recent != NULL) {
      if (recent->next == NULL) {
        current->prev = recent;
        current->next = NULL;
        recent->next = current;
        tail = current;
        return;
      } else if (recent->data > value) {
        current->next = recent;
        recent->prev = current;
        head = current;
        return;
      } else if (recent->next->data > value) {
        current->prev = recent;
        current->next = recent->next;
        recent->next = current;
        return;
      }
      recent = recent->next;
    }
  }
}

void print(newNode *&head) {
  newNode *current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
    if (current == NULL) {
      cout << endl;
      return;
    }
  }
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
    ll fir = 0, sec = 0, x = 0, y = 0, point, in, temp, prev, next, val;

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> val;
      append(head, tail, val);
      print(head);
    }

    // ll str[n+3];
    // ll len=s.length();
  }
}
