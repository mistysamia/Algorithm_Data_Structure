#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005
#define BIG 1000000000000005
#define ff first
#define ss second
typedef pair<ll, ll> pii;

struct edge
{
    ll from, to,weight;

    edge() { }

    edge(ll a,ll b,ll w)
    {
        from= a;
        to= b;
        weight=w;
    }
};

bool comp(const edge& a, const edge& b)
{
    if(a.weight<b.weight)
        return true;
    else
        return false;
}

vector<edge>adj;
vector<pii>save_edge;
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

ll kruskals(ll n)
{
    sort(adj.begin(), adj.end(),comp);
    init_disjoint_set(n);
    ll nodecount=0,cost=0;

    for(int i=0; i<adj.size(); i++)
    {
        ll u=adj[i].from;
        ll v=adj[i].to;
        flag=0;
        Union(u,v);
        if(flag)
        {
            save_edge.push_back({u,v});
            nodecount++;
            cost+= adj[i].weight;
            if(nodecount==n-1)
                break;
        }
    }
    return cost;
}

void clr()
{
    adj.clear();
    save_edge.clear();
}

int main ()
{
    clr();
    ll n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        ll from,to,weight;
        cin>>from>>to>>weight;
        adj.push_back(edge(from,to,weight));
    }
    ll totalcost=kruskals(n);

    cout<<"Total cost of making MST is : "<<totalcost<<endl;

    cout<<"The saved edge to make MST"<<endl;
    for(int i=0;i<save_edge.size();i++)
        cout<<save_edge[i].ff<<" "<<save_edge[i].ss<<endl;

    return 0;
}

/*
Let us create the following graph
          2    3
      (1)--(2)--(3)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (5)-------(4)
            9

5 7
1 2 2
2 3 3
1 5 6
2 5 8
5 4 9
3 4 7
2 4 5

*/
