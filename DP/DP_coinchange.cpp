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
#define N 10000
ll mod=10000007;


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll coin[N],dp[N][N],check[N],n,k;
vector<ll>save;


///If you're allowed to take an element only one times
ll coinchange(ll i,ll w)
{
    if(w<0)
        return INF;

    if(n==i)
    {
        if(w==0)
            return 0;
        return INF;
    }

    if(dp[i][w]!=INF)
        return dp[i][w];

    ll a=1+coinchange(i+1,w-coin[i]);
    ll b=coinchange(i+1,w);

    ll ans=min(a,b);

    return dp[i][w]=ans;

}


///If you're allowed to take an element more than one times
ll coinchange(ll j,ll w)
{
    if (w < 0)
        return INF;
    if (w == 0)
        return 0;
    if (dp[j][w] !=-1)
        return dp[j][w];


    ll ans = INF;
    for (int i = 0; i < n; i++)
    {
        ans=min(ans,1+coinchange(0,w-coin[i]));
    }

    dp[j][w] = ans;
    return dp[j][w];
}


///If you're allowed to take an element K times

ll coinchange(ll j,ll w,ll val)
{
    if(val>k)
        return INF;
    if (w < 0)
        return INF;

    if (w == 0)
        return 0;
    if (dp[j][w] !=-1)
        return dp[j][w];


    ll ans = INF;
    for (int i = 0; i < n; i++)
    {
        ans=min(ans,1+coinchange(0,w-coin[i],check[i]+1));
    }

    dp[j][w] = ans;
    return dp[j][w];
}



void clr()
{
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=N; j++)
            dp[i][j]=-1;
    }
    memset(check,0,sizeof check);
    save.clear();

}

int main()
{
    fast_cin;
    ll t,cas=1;
    cin>>t;
    while(t--)
    {
        clr();
        ll w;
        cin>>n>>w>>k;

        for(int i=0; i<n; i++)
            cin>>coin[i];

        ll sol=coinchange(0,w,0);
        if(sol==INF)
            cout<<"NOT FOUND"<<endl;
        else
            cout<<sol<<endl;
    }
}
/*
5
5 1 2
2 5 9 13 15
8 22 1
1 1 6 9 6 6 15 12
*/
