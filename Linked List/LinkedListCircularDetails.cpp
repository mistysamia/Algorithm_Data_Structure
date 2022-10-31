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

void append(newNode *&head, newNode *&tail, ll prevValue, ll nextValue,
            ll value) {
  newNode *current = new newNode();
  current->data = value;
  current->prev = current;
  current->next = current;
  if (head == NULL) {
    head = current;
    tail = current;
  } else {
    newNode *recent = head, *temp;
    while (1) {

      if (recent->data == prevValue) {
        temp = recent->next;
        current->prev = recent;
        current->next = temp;
        recent->next = current;
        temp->prev = current;

        if (current->next == head) {
          tail = current;
          head->prev = tail;
        }
        return;
      }
      if (recent->data == nextValue) {
        temp = recent->prev;
        current->prev = temp;
        current->next = recent;
        recent->prev = current;
        temp->next = current;

        if (current->prev == tail) {
          head = current;
          tail->next = head;
        }
        return;
      }
      recent = recent->next;
      if (recent == head) {
        cout << "Wrong Input" << endl;
        break;
      }
    }
  }
}

void remove(newNode *&head, newNode *&tail, ll value) {
  newNode *current = head, *tempPrev = NULL, *tempNext = NULL;

  while (1) {
    if (current->data == value) {
      if (current == head && current == tail) {
        head = NULL;
        tail = NULL;
        return;
      } else {
        tempPrev = current->prev;
        tempNext = current->next;

        tempPrev->next = tempNext;
        tempNext->prev=tempPrev;
        if (current == head) {
          head = tempNext;
        } else if (current == tail) {
          tail = tempPrev;
        }
        return;
      }
    }
    current = current->next;
    if (current == head) {
      cout << "Invalid Input" << endl;
      break;
    }
  }
}

void print(newNode *head) {
  newNode *current = head;
  while (1) {
    cout << current->data << " ";
    current = current->next;
    if (current == head)
      break;
  }
  cout << endl;
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

    if (n == 1) {
      cin >> prev >> next >> val; // not -1 for which link you want to put
      append(head, tail, prev, next, val);
    } else if (n == 2) {
      cin >> val;
      remove(head, tail, val);
    } else if (n == 3) {
      print(head);
    }

    // ll str[n+3];
    // ll len=s.length();
  }
}

/*
Input:
1000
1
1 1 1
1
1 -1 33
1
1 -1 34
1
33 -1 89
1
-1 1 23
1
-1 1 90
1 
-1 23 100
1
89 -1 189
3
2
100
3
2
189
3
2
1
3
2
23
3

Output:
100 23 90 1 34 33 89 189
23 90 1 34 33 89 189 
23 90 1 34 33 89 
23 90 34 33 89
90 34 33 89
*/