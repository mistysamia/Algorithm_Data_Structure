#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define b(n) cout<<"bug "<<n<<endl;
#define en cout<<endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 100000
ll mod=10000007;


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;
vector<ll>weight[N];
ll dp[100006];

ll shortest(ll i,ll n)
{
    if(dp[i]!=-1)
        return dp[i];

    ll child=-BIG;
    for(int j=0; j<weight[i].size(); j++)
        child=max(child,shortest(weight[i][j],n)+1);

    if(child==-BIG)
        return dp[i]=0;

    return dp[i]=child;
}

int main()
{
    fast_cin;


    ll lock=0,sum=0,co=0,ans=-BIG,a=0,b=0,c=0;
    ll n,m,k,mx=-BIG,mn=BIG;
    ll fir=0,sec=0;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        weight[a].push_back(b);
    }
    for(int i=0;i<=n;i++)
    {
        if(dp[i]==-1)
            ans=max(ans,shortest(i,n));
    }

    cout<<ans<<endl;

}
/*

4 5
1 2
1 3
3 2
2 4
3 4


6 3
2 3
4 5
5 6

5 8
5 3
2 3
2 4
5 2
5 1
1 4
4 3
1 3



*/


