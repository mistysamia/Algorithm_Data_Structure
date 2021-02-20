#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005
#define BIG 1000000000000005
#define ff first
#define ss second
typedef pair<ll, ll> pii;


/// Koitaa set ase check korsi just
struct edge
{
    ll from, to;

    edge() { }

    edge(ll a,ll b)
    {
        from= a;
        to= b;
    }
};


vector<edge>adj;
ll parent[SIZE];
ll flag;



void makeset(ll u)
{
    parent[u]=u;
}

void init_disjoint_set(ll n)
{
    for(ll i=1; i<=n; i++)
        makeset(i);
}

ll FindRepresentative(ll r)
{
    if(parent[r]==r)
        return r;

    parent[r]=FindRepresentative(parent[r]);/// path compression

    return parent[r];
}

void Union(ll a, ll b)
{
    ll u = FindRepresentative(a);
    ll v = FindRepresentative(b);

    if(u!=v)
    {
        parent[u] = v;
        flag = 1;
    }
}

ll DSU(ll n)
{
    init_disjoint_set(n);
    ll cost=0;
    for(int i=0; i<adj.size(); i++)
    {
        ll u=adj[i].from;
        ll v=adj[i].to;
        flag=0;
        Union(u,v);
        if(flag)
            cost++;
    }
    return cost;
}

void clr()
{
    adj.clear();
}

int main ()
{
    clr();
    ll n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        ll from,to;
        cin>>from>>to;
        adj.push_back({from,to});
    }

    ll co=DSU(n);


    cout<<n-co<<endl;

}
