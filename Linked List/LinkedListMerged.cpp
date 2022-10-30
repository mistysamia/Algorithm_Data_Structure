/////////////2 sorted linked list merged by ascending order




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
newNode *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL,
        *finalHead = NULL, *finalTail = NULL;

void append(ll value, newNode *&head, newNode *&tail) {

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

void print(newNode *head) {
  newNode *current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void merged() {
  newNode *current1, *current2;
  current1 = head1;
  current2 = head2;
  while (current1 != NULL && current2 != NULL) {

    if (current1->data < current2->data) {
      if (finalHead == NULL) {
        finalHead = current1;
        finalTail = current1;
      } else {
        finalTail->next = current1;
        finalTail = current1;
      }
      current1 = current1->next;
    } else {
      if (finalHead == NULL) {
        finalHead = current2;
        finalTail = current2;
      } else {
        finalTail->next = current2;
        finalTail = current2;
      }
      current2 = current2->next;
    }
  }

  while (current1 != NULL) {
    if (finalHead == NULL) {
      finalHead = current1;
      finalTail = current1;
    } else {
      finalTail->next = current1;
      finalTail = current1;
    }
    current1 = current1->next;
  }

  while (current2 != NULL) {
    if (finalHead == NULL) {
      finalHead = current2;
      finalTail = current2;
    } else {
      finalTail->next = current2;
      finalTail = current2;
    }
    current2 = current2->next;
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
    ll fir = 0, sec = 0, x = 0, y = 0, point, in, temp;

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a;
      append(a, head1, tail1);
      // cout<<head1->data<<endl;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> a;
      append(a, head2, tail2);
    }
    print(head1);
    print(head2);
    merged();
    print(finalHead);
    // ll str[n+3];
    // ll len=s.length();
  }
}



/*

Input:
1
5
1 3 4 6 7
4
3 4 6 8 

Output:
1 3 3 4 4 6 6 7 8
*/
