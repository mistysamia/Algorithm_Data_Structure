#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005
#define BIG 1000000000000005


typedef pair<ll, ll> pii;

vector<pii> adj[SIZE];        /// Graph

ll dis[SIZE];               /// distance array
ll path[SIZE];              /// prev (for path print)

struct Node
{
    ll node;
    ll weight;
    Node() {}

    Node(ll node, ll weight)
    {
        this->node = node;
        this->weight = weight;
    }
    bool operator < (const Node &a)const
    {
        return weight > a.weight;
    }
};
priority_queue<Node>q;

void  dijkstra(ll source)
{
    while(!q.empty())
        q.pop();

    for(int i=0; i<SIZE; i++)
    {
        dis[i] = BIG;
        path[i] = -1;
    }
    Node s(source, 0);
    q.push(s);
    dis[source] = 0;

    while(!q.empty())
    {
        Node curr = q.top();
        q.pop();

        ll source = curr.node;
        ll curr_weight = curr.weight;

        if(curr_weight!=dis[source])
            continue;

        for(int i=0; i<adj[source].size(); i++)
        {
            ll des = adj[source][i].first;
            ll cost = adj[source][i].second;
            if(dis[source]+cost < dis[des])
            {
                dis[des] = dis[source] + cost;
                Node n(des, dis[des]);
                q.push(n);
                path[des] = source;
            }
        }
    }
}

void clr()
{
    for(int i=0; i<SIZE; i++)
        adj[i].clear();
}

int main ()
{
    ll n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        ll a, b, w;
        cin>>a>>b>>w;

        adj[a].push_back(pii(b, w));
       // adj[b].push_back(pii(a, w));
    }

    dijkstra(1);

    if(dis[n]==BIG)
        cout<<"-1"<<endl;
    else
    {
        for(int i=1; i<=n; i++)
        {
            vector<ll> ansVec;
            cout<<"The cost of node "<<i<<" : "<<dis[i]<<endl;
            cout<<"Shortest path root of source to node "<<i<<endl;
            ll curr = i;
            while(curr!=1)
            {
                ansVec.push_back(curr);
                curr = path[curr];
            }
            ansVec.push_back(1);

            for(int i=ansVec.size()-1; i>=0; i--)
            {
                if(i==ansVec.size()-1)
                    cout<<ansVec[i]<<" ";
                else
                    cout<<" "<<ansVec[i]<<" ";
            }
            cout<<endl;
            clr();
        }
    }
    return 0;
}
