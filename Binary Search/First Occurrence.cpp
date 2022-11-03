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

///searching from array the first occurrence, return index if found, return -1 if not found

ll firstOccurrence(deque<ll> deq, ll key) {

  ll left = 0, right = deq.size() - 1, mid, index = -1;
  while (left <= right) {
    mid = (right + left) / 2;
    if (deq[mid] == key) {
      index = mid;
      right = mid - 1;
    } else if (deq[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return index;
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
    ll fir = 0, sec = 0, x = 0, y = 0, point, in, temp, key;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> a;
      deq.push_back(a);
    }
    // sort(deq.begin(), deq.end());
    cin >> key;
    ans = firstOccurrence(deq, key);

    cout << "Output" << endl;
    cout << ans << endl;
    
    // ll str[n+3];
    // ll len=s.length();
  }
}

/*
Input:
555
8
2 2 3 4 6 8 8 67
8
8
2 2 3 4 6 8 8 67
5
8
2 2 3 4 6 8 8 67
2
8
2 2 3 4 6 8 8 67
67
8
2 2 3 4 6 8 8 67
453

Output:
5
-1
0
7
-1
*/
