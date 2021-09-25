#include <bits/stdc++.h>
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
#define b(n) cout << "bug " << n << endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll, ll>
#define fast_cin                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 10000

ll mod = 1e9 + 7;

//GCD=__gcd(n,m);  lcm=(n*m)/GCD;
//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;

ll tra[100006], tra1[100006];

int main()
{
    fast_cin;

    map<ll, ll> track;
    deque<ll> reference, Frame[100];
    string refStr, tempStr;
    ll pageNo, FrameNo, refNo;

    cout << "Number of pages: " << endl;
    cin >> pageNo;
    cout << "Reference String : " << endl;
    cin >> refStr;
    for (int i = 0; i < refStr.length(); i++)
    {
        if (refStr[i] != ',')
            tempStr += refStr[i];
        if (refStr[i] == ',' || i == refStr.length() - 1)
        {
            stringstream geek(tempStr);
            ll x = 0;
            geek >> x;
            reference.push_back(x);
            tempStr.clear();
        }
    }
    refNo = reference.size();
    cout << "Number of Memory Page Frame: " << endl;
    cin >> FrameNo;

    for (int i = 0; i < refNo; i++)
    {
        if (track[reference[i]] == 0)
        {
            track[reference[i]]++;
            if (i == 0)
                Frame[i].push_front(reference[i]);
            else
            {
                for (int j = 0; j < Frame[i - 1].size(); j++)
                    Frame[i].push_back(Frame[i - 1][j]);
                Frame[i].push_back(reference[i]);
                if (Frame[i].size() > FrameNo)
                {
                    track[Frame[i].front()] = 0;
                    Frame[i].pop_front();
                }
            }
        }
        else
        {
            for (int j = 0; j < Frame[i - 1].size(); j++)
            {
                if (Frame[i - 1][j] != reference[i])
                    Frame[i].push_back(Frame[i - 1][j]);
            }
            Frame[i].push_back(reference[i]);
        }
        while (Frame[i].size() != FrameNo)
            Frame[i].push_front(-1);
    }

    cout << endl
         << "Output : " << endl;
    for (int i = FrameNo - 1; i >= 0; i--)
    {
        for (int j = 0; j < refNo; j++)
        {
            if (Frame[j][i] != -1)
                cout << Frame[j][i] << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}


/***********************************************
 * 8
7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1 
3
************************************************/
