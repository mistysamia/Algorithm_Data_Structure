///uva biocoloring

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> adj[100000];
ll level[100000];
ll check[100000];
ll lockk=0;
ll color[100000];

void BFS(ll source,ll n)
{
    queue<ll> q;
    memset(check,-1,sizeof(check));
    memset(level,-1,sizeof(level));
    q.push(source);
    level[source]=0;
    check[source]=0;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0; i<adj[u].size(); i++)
        {
            if(level[adj[u][i]]==-1)
            {
                level[adj[u][i]]=0;
                q.push(adj[u][i]);
                if(check[adj[u][i]]==-1 )
                {
                    if(check[u]==0)
                        check[adj[u][i]]=1;
                    else
                        check[adj[u][i]]=0;
                }
            }
            else if(check[adj[u][i]]==check[u])
            {
                lockk=1;
                break;
            }
        }
    }

}
int main()
{
    ll n;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;

        ll edge;
        cin>>edge;
        ll a,b;
        while(edge--)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        lockk=0;
        BFS(0,n);

        if(lockk==1)
            cout<<"NOT BICOLORABLE."<<endl;
        else
            cout<<"BICOLORABLE."<<endl;

        for(int i=0; i<n; i++)
            adj[i].clear();


    }
    return 0;
}
