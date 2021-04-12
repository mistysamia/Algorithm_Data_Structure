#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define llu unsigned long long
#define U unsigned int
#define SIZE 1000002
#define pie 3.14159265358979323
#define minuss 1e-6
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mx 100001


ll arr[mx];
ll tree[mx * 3];


///Building the segment tree from the array
void build(ll node, ll i, ll n)
{
    if (i==n)
    {
        tree[node]=arr[n];
        return;
    }
    ll left,right, mid;

    left = node*2;
    right = node*2+1;
    mid = (i+n)/2;
    build(left, i, mid);
    build(right, mid+1, n);
    tree[node] = tree[left] + tree[right];
}


void update(ll node, ll i, ll n, ll index, ll newvalue)
{
    if (index > n || index < i)
    {
        return; ///out of the given indexes
    }

    if ( i>=index && n<=index) ///relevant segment
    {
        tree[node] = newvalue;
        return;
    }
    ll left,right, mid;

    left = node*2;
    right = node*2+1;
    mid = (i+n)/2;
    update(left,i,mid,index, newvalue);
    update(right,mid+1,n,index, newvalue);
    tree[node] = tree[left] + tree[right];
}

ll sum(ll node, ll i, ll n, ll startIndex, ll endIndex)
{
    if (startIndex>n ||  endIndex<i)
    {
        return 0; ///out of the given indexes
    }

    if (i>=startIndex && n<=endIndex)///relevant segment
    {
        return tree[node];
    }
    ll left,right, mid,sum1,sum2;

    left = node*2;
    right = node*2+1;
    mid = (i+n)/2;
    sum1 = sum(left,i, mid,startIndex,endIndex);
    sum2 = sum(right, mid+1,n,startIndex,endIndex);
    return sum1 + sum2;
}


int main()
{

    ll n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    build(1, 1, n);

    update(1,1,n,2,0);
    cout<<sum(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<sum(1,1,n,2,2)<<endl;

}
