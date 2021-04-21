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
#define N 1000
ll mod=10000007;


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;
vector<ll>weight[N];
ll dp[100006];
ll indx;

ll longest(ll i,ll n)
{
    if(dp[i]!=-1)
        return dp[i];

    ll child=-BIG;
    for(int j=0; j<weight[i].size(); j++)
        child=max(child,longest(weight[i][j],n)+1);

    if(child==-BIG)
        return dp[i]=0;

    return dp[i]=child;
}

void path(ll source,ll val)
{
    if(val==0)
    {
        for(int i=0; i<weight[source].size(); i++)
            if(val==dp[weight[source][i]])
                indx=min(indx,weight[source][i]);
         return;
    }

    for(int i=0; i<weight[source].size(); i++)
    {
        if(val==dp[weight[source][i]])
            path(weight[source][i],val-1);
    }

}

void clr()
{
    memset(dp,-1,sizeof dp);
    for(int i=0; i<N; i++)
        weight[i].clear();
    indx=BIG;
}
int main()
{
    ll cas=1;
    while(1)
    {
        fast_cin;
        ll lock=0,sum=0,co=0,ans=BIG,a=0,b=0,c=0;
        ll n,m,k,mx=-BIG,mn=BIG,source,in=-1;
        ll fir=0,sec=0;
        cin>>n;
        if(n==0)
            break;
        clr();
        cin>>source;
        while(1)
        {
            cin>>a>>b;
            if(a+b==0)
                break;
            weight[a].push_back(b);
        }
        ans=longest(source,n);
        in=ans-1;
        path(source,in);
        cout<<"Case "<<cas++<<": The longest path from "<<source;
        cout<<" has length "<<ans<<", finishing at ";
        cout<<indx<<"."<<endl<<endl;
    }
}
