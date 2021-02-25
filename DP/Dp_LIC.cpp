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
ll mod=1000000007;


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll save_cost[100006];
ll save_data[100006];

ll LIC(ll i,ll n,ll str[])
{
    ll ans=0;
    for(int j=i+1; j<=n; j++)
    {
        if(str[j]>str[i])
        {
            ll val=LIC(j,n,str);
            if(val>ans)
            {
                ans=val;
                save_data[i]=j;
            }
        }
    }
    return save_cost[i]=ans+1;
}


int main()
{
    fast_cin;
    ll t;
    cin>>t;
    while(t--)
    {
        memset(save_data,-1,sizeof save_data);
        ll n,ans=0,start_index=-1;
        cin>>n;

        ll str[n+3];
        for(int i=1; i<=n; i++)
            cin>>str[i];

        for(int i=1; i<=n; i++)
        {
            memset(save_cost,-1,sizeof save_cost);
            ll temp=LIC(i,n,str);
            if(ans<temp)
            {
                ans=temp;
                start_index=i;
            }
        }
        cout<<ans<<endl;

        ///printing the elements
        while(start_index != -1)
        {
            cout<<str[start_index]<<" ";
            start_index = save_data[start_index];
        }
        cout<<endl;
    }
}

/*
6
7
5 0 9 2 7 3 4
*/
