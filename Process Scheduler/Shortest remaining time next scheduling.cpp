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
#define all(v) (v).begin(), (v).end()
#define b(n) cout<<"bug "<<n<<endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<pair<pair<ll,ll>,ll>,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000

ll mod=1e9+7;

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006],tra1[100006];


bool sortbysec(const pair<pair<pair<ll,ll>,ll>,ll>&a,const pair<pair<pair<ll,ll>,ll>,ll> &b)
{
    if(a.ff.ff.ff==b.ff.ff.ff)
        return a.ff.ff.second<b.ff.ff.second;
    else
        return a.ff.ff.first<b.ff.ff.first;
}
bool sortbyIndx(const pair<pair<ll,ll>,ll>&a,const pair<pair<ll,ll>,ll> &b)
{
    return a.ss<b.ss;
}


int main()
{
    fast_cin;
    ll t,cas=1;
    string s,s1;
    deque<pii>process;
    deque<pair<pair<ll,ll>,ll>>save;
    ll lock=0,sum=0,co=0,ans=0,a=0,b=0,c=0,d=0;
    ll n,m,k,mx=-BIG,mn=BIG;
    ll fir=0,sec=0,x=0,y=0,point,indx,flag=0;
    ll waitTime=0,turnTime=0,avgWait=0,avgTurn=0,curTime=0;

    cout<<"Enter the number of process: "<<endl;
    cin>>n;

    ll cpu[n+5],arrival[n+5];
    cout<<"Enter the CPU times"<<endl;
    for(int i=0; i<n; i++)
        cin>>cpu[i];

    cout<<"Enter the arrival times"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arrival[i];
        process.push_back({{{arrival[i],cpu[i]},cpu[i]},i});
    }

    stable_sort(process.begin(),process.end(),sortbysec);
    while(!process.empty())
    {
        ll nextProc=mn;
        for(int i=0; i<process.size(); i++)
        {
            pii secTime=process[i];
            if(curTime<secTime.ff.ff.ff)
                break;
            if(secTime.ff.ss<nextProc)
            {
                indx=i;
                nextProc=secTime.ff.ss;
            }
        }
        curTime++;
        if(nextProc!=mn)
        {
            process[indx].ff.ss--;
            if(process[indx].ff.ss==0)
            {
                pii doneProc=process[indx];
                process.erase (process.begin()+indx);
                turnTime=curTime-doneProc.ff.ff.ff;
                waitTime=turnTime-doneProc.ff.ff.ss;
                avgTurn+=turnTime;
                avgWait+=waitTime;
                save.push_front({{waitTime,turnTime},doneProc.ss});
            }
        }
    }
    sort(save.begin(),save.end(),sortbyIndx);
    for(int i=0; i<save.size(); i++)
    {
        cout<<"Process "<<cas++<<": Waiting Time: "<<save[i].ff.ff;
        cout<<" Turnaround Time :"<<save[i].ff.ss<<endl;
    }
    cout<<fixed<<setprecision(2)<<"Average Waiting Time: "<<double(avgWait)/n<<endl;
    cout<<fixed<<setprecision(2)<<"Average Turnaround Time: "<<double(avgTurn)/n<<endl;

}




