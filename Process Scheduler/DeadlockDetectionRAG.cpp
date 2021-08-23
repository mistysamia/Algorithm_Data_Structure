///DeadlockDetectionUsingResourceAllocationGraph(RAG)

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
#define fast_cin                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000

ll mod = 1e9 + 7;

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006], tra1[100006];

ll n, m, cas = 1;
deque<ll> path;
vector<ll> adj[SIZE]; /// number of node, number of edges
ll visited[SIZE];     /// visited arrray
ll recStack[SIZE];    /// recursion stack (1 if it is in the recursion stack)
ll lastCir = -1;
map<char, ll> mp1;
map<ll, char> mp2;

void printPath()
{
    cout << cas++ << " - Deadlock Detected Among nodes: ";
    for (int j = 0; j < path.size(); j++)
        cout << mp2[path[j]] << " ";
    
    cout << endl;
    path.clear();
}

bool isCyclic(ll curr)
{
    if (!visited[curr])
    {
        visited[curr] = 1;
        recStack[curr] = 1;

        for (int i = 0; i < adj[curr].size(); i++)
        {
            ll next = adj[curr][i];

            if (!visited[next] && isCyclic(next)) /// found a back edge in the child's subtree
            {
                path.push_front(curr);
                if (lastCir == curr)
                    printPath();
                return true;
            }
            else if (recStack[next]) /// if it is in the recursion stack, it found a back edge
            {
                path.push_front(curr);
                lastCir = next;
                return true;
            }
        }
    }
    recStack[curr] = 0;
    return false;
}

void clr()
{
    for (int i = 0; i < SIZE; i++)
    {
        adj[i].clear();
        visited[i] = 0;
        recStack[i] = 0;
    }
    mp1.clear();
    mp2.clear();
}

int main()
{
    fast_cin;
    clr();
    cout << "Number of nodes & edges :" << endl;
    cin >> n >> m;
    cout << "Node names :" << endl;
    ll indx = 1;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        mp1[ch] = indx;
        mp2[indx++] = ch;
    }

    cout << "Edges : " << endl;
    for (int i = 0; i < m; i++)
    {
        char from, to;
        cin >> from >> to;
        adj[mp1[from]].push_back(mp1[to]);
    }

    for (int i = 0; i < n; i++) /// handles for disconnected graph (DFS forest)
        isCyclic(i);
    return 0;
}