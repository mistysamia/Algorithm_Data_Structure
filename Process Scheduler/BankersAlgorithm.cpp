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

int main()
{
    fast_cin;
    map<ll, ll> finish;
    ll lock = 0,n,m,in = 1;
    cout << "Enter the no. of processes: " << endl;
    cin >> n;
    cout << "Enter the no. of resources: " << endl;
    cin >> m;
    deque<ll> allocation[n + m], maximum[n + m], need[n + m], available[n + m];
    deque<ll> resources, InitialSum, track, process;
    for (int i = 1; i <= n; i++)
    {
        cout << "Process " << i << endl;
        for (int j = 1; j <= m; j++)
        {
            cout << "Maximum value for resource " << j << ": " << endl;
            cin >> maximum[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            cout << "Allocation from resource " << j << ": " << endl;
            cin >> allocation[i][j];
            need[i][j] = maximum[i][j] - allocation[i][j];
            InitialSum[j] += allocation[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << "Enter total value of resource " << i << ": " << endl;
        cin >> resources[i];
        available[1][i] = resources[i] - InitialSum[i];
    }

    track.push_back(in++);
    while (!track.empty())
    {
        ll indx = track.front();
        track.pop_front();
        for (int i = 1; i <= n; i++)
        {
            lock = 0;
            if (finish[i] == 0)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (need[i][j] > available[indx][j])
                    {
                        lock = 1;
                        break;
                    }
                }
                if (!lock)
                {
                    for (int j = 1; j <= m; j++)
                        available[in][j] = allocation[i][j] + available[indx][j];
                    
                    track.push_back(in++);
                    finish[i] = 1;
                    process.push_back(i);
                }
            }
        }
    }
    if (process.size() != n)
        cout << "The system is currently not in safe state." << endl;
    else
    {
        cout << "The system is currently in safe state and < ";
        for (int i = 0; i < process.size(); i++)
            cout <<"P"<< process[i] << " ";
        
        cout << "> is the safe sequence." << endl;
    }

}
