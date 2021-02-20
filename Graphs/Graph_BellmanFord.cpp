#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1005
#define BIG 1000000000000005


ll path_save[SIZE];/// to save the path
ll path_cost[SIZE];///to save the cost
typedef pair<pair<ll, ll>,ll>pii;
vector<pii>adj;


bool bellmanFord(ll source,ll n,ll m)
{
    path_cost[source] = 0;
    for(int i=1; i<=n-1; i++)
    {
        bool update=false;
        for(int j=0; j<m; j++)
        {
            ll sour = adj[j].first.first;
            ll des = adj[j].first.second;
            ll cost = adj[j].second;
            if(path_cost[sour]+cost<path_cost[des] && path_cost[sour]!=BIG  )
            {
                path_cost[des] = path_cost[sour]+cost;
                path_save[des]=sour;
                update=true;
            }
        }
        if(!update)
            break;

    }
    for(int j=0; j<m; j++)
    {
        ll sour = adj[j].first.first;
        ll des = adj[j].first.second;
        ll cost = adj[j].second;
        if(path_cost[sour]+cost<path_cost[des] && path_cost[sour]!=BIG  )
        {
            path_cost[des] = -BIG;///If I want to detect which node has the negative cycle.
            //return false;
        }

    }
    return true;
}
void clr()
{
    for(int i=0; i<SIZE; i++)
    {
        adj.clear();
        path_cost[i] = BIG;
        path_save[i]=0;
    }
}
int main()
{
    clr();
    ll m,n,source;
    cout<<"Enter the number of node and edge"<<endl;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        ll from,to, weight;
        cin>>from>>to>>weight;
        adj.push_back({{from, to},weight});
    }
    cout<<"Enter the Source node"<<endl;
    cin>>source;

    if(bellmanFord(source,n,m))
    {
        for(int i=1; i<=n; i++)
        {
            if(path_cost[i]!=BIG && path_cost[i]!=-BIG)
                cout<<"Path["<<i<<"] = "<<path_cost[i]<<endl;
            else if(path_cost[i]==-BIG)
                cout<<"Path["<<i<<"] = "<<"This node has a negative cycle "<<endl;
            else
                cout<<"Path["<<i<<"] = inf"<<endl;
        }
        cout<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<"Path of "<<i<<endl;

            if(path_cost[i]==BIG)
                cout<<"Invalid"<<endl;
            else if(path_cost[i]==-BIG)
                cout<<"This node has a negative cycle "<<endl;
            else
            {
                vector<ll> path;
                ll des = i;
                while(des!=source)
                {
                    path.push_back(des);
                    des = path_save[des];
                }

                cout<<des<<" ";
                for(int j=path.size()-1; j>=0; j--)
                    cout<<path[j]<<" ";

                cout<<endl;
            }
        }
    }
    else
        cout<<"Negative cycle detected"<<endl;

    return 0;
}

/*

11 10
2 1 2
1 3 3
10 3 -20
3 11 5
3 4 6
4 11 -10
11 5 7
5 7 7
7 8 -100
8 5 10



5 9
1 2 2
1 3 6
2 3 3
3 2 2
5 3 1
3 4 4
2 4 8
4 2 -2
4 5 -4
*/
