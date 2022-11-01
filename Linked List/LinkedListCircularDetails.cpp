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
  ll data, flag;
  struct node *next, *prev;
};
typedef struct node newNode;
newNode *head = NULL, *tail = NULL;

void append(newNode *&head, newNode *&tail, ll prevValue, ll nextValue,
            ll value) {
  if (prevValue > 0 && nextValue > 0) {
    cout << "Wrong Input" << endl;
    return;
  }
  newNode *current = new newNode();
  current->data = value;
  current->prev = current;
  current->next = current;
  current->flag = 0;
  if (head == NULL) {
    head = current;
    tail = current;
  } else {
    newNode *recent = head, *temp;
    while (recent != NULL) {

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

  while (current != NULL) {
    if (current->data == value) {
      if (current == head && current == tail) {
        head = NULL;
        tail = NULL;
        return;
      } else {
        tempPrev = current->prev;
        tempNext = current->next;

        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
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
  cout << "Invalid Input" << endl;
}

void reverse(newNode *&head, newNode *&tail) {
  newNode *current = head, *temp;
  while (current != NULL) {
    temp = current->next;
    current->prev = current->next;
    if (temp == head) {
      tail = head;
      head = current;
      break;
    }
    current = temp;
  }
  current = tail, temp = head;
  while (current != NULL) {
    current->next = temp;
    temp = current;
    current = current->prev;
    if (current == tail)
      break;
  }
}

void print(newNode *&head) {
  newNode *current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
    if (current == head) {
      cout << endl;
      return;
    }
  }
  cout << "Nothing to Print" << endl;
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
    cout << "Choose an Option (1 Insert) , (2 Delete) , (3 Print)" << endl;
    cin >> n;

    if (n == 1) {
      cin >> prev >> next >> val; // not -1 for which link you want to put
      append(head, tail, prev, next, val);
    } else if (n == 2) {
      cin >> val;
      remove(head, tail, val);
    } else if (n == 3) {
      print(head);
    } else {
      reverse(head, tail);
    }

    // ll str[n+3];
    // ll len=s.length();
  }
}

/*
Input:
1000
1
1 -1 1
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
4
3
1
189 -1 20
3
1
100 -1 44
3
2
100
3
2
44
3
4
3
2
23
4
3

Output:
100 23 90 1 34 33 89 189
189 89 33 34 1 90 23 100
189 20 89 33 34 1 90 23 100  
189 20 89 33 34 1 90 23 100 44 
189 20 89 33 34 1 90 23 44 
189 20 89 33 34 1 90 23
23 90 1 34 33 89 20 189
189 20 89 33 34 1 90
*/
