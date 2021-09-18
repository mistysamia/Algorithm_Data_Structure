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
    deque<ll> holes[100], memoryReq[100], BestFit[100], FirstFit[100], WorstFit[100];
    ll holesNo, memoryReqNo, cross;
    cout << "Number of Holes : " << endl;
    cin >> holesNo;
    cout << "Memory Holes: " << endl;
    for (int i = 0; i < holesNo; i++)
    {
        cin >> holes[0][i];
        WorstFit[i + 1][0] = FirstFit[i + 1][0] = BestFit[i + 1][0] = holes[0][i];
    }

    cout << "Number of Memory Request : " << endl;
    cin >> memoryReqNo;
    for (int i = 0; i < memoryReqNo; i++)
    {
        cin >> memoryReq[0][i];
        WorstFit[0][i] = FirstFit[0][i] = BestFit[0][i] = memoryReq[0][i];
    }

    /***************************
 *********First Fit*********
 ***************************/
    cout <<endl<< "***************************************" << endl;
    cout << "First Fit" << endl;
    cout << "Step by Step memory allocation situation in First Fit" << endl
         << endl;

    cout << "First Fit:" << endl;
    ll firstFitSum = 0;
    for (int i = 0; i < memoryReqNo; i++)
    {
        ll flag = 0, sum = 0;
        for (int j = 1; j <= holesNo; j++)
        {
            if (FirstFit[j][i] >= FirstFit[0][i])
            {
                FirstFit[j][i] -= FirstFit[0][i];
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            for (int j = 1; j <= holesNo; j++)
            {
                FirstFit[j][i + 1] = FirstFit[j][i];
                sum += FirstFit[j][i];
            }
            firstFitSum = sum;
        }
        else
        {
            cross = i;
            for (int j = 1; j <= holesNo; j++)
                FirstFit[j][i] = -1;

            break;
        }
    }

     for (int i = 0; i <= holesNo; i++)
    {
        for (int j = 0; j < memoryReqNo; j++)
        {
            if (cross <= j && cross != -1 && i!=0)
                cout << "X\t";
            else
                cout << FirstFit[i][j] << "\t";
        }
        cout << endl;
    }

    if (cross == -1)
        cout << endl
             << "No External Fragmentation" << endl
             << endl;
    else
        cout << endl
             << "External Fragmentation: " << firstFitSum << endl
             << endl;


    /***************************
 *********Best Fit*********
 ***************************/
    cout << "***************************************" << endl;
    cout << "Best Fit" << endl;
    cout << "Step by Step memory allocation situation in Best Fit" << endl
         << endl;

    ll bestFitSum = 0;
    cross = -1;
    for (int i = 0; i < memoryReqNo; i++)
    {
        ll flag = 0, sum = 0, indx = -1, mn = BIG;
        for (int j = 1; j <= holesNo; j++)
        {
            if (BestFit[j][i] >= BestFit[0][i])
            {
                if ((BestFit[j][i] - BestFit[0][i]) < mn)
                {
                    mn = BestFit[j][i] - BestFit[0][i];
                    indx = j;
                }
            }
        }
        if (indx != -1)
        {
            BestFit[indx][i] -= BestFit[0][i];
            for (int j = 1; j <= holesNo; j++)
            {
                BestFit[j][i + 1] = BestFit[j][i];
                sum += BestFit[j][i];
            }
            bestFitSum = sum;
        }
        else
        {
            cross = i;
            for (int j = 1; j <= holesNo; j++)
                BestFit[j][i] = -1;

            break;
        }
    }
    for (int i = 0; i <= holesNo; i++)
    {
        for (int j = 0; j < memoryReqNo; j++)
        {
            if (cross <= j && cross != -1 && i!=0)
                cout << "X\t";
            else
                cout << BestFit[i][j] << "\t";
        }
        cout << endl;
    }

    if (cross == -1)
        cout << endl
             << "No External Fragmentation" << endl
             << endl;
    else
        cout << endl
             << "External Fragmentation: " << bestFitSum << endl
             << endl;

    /***************************
 *********Worst Fit*********
 ***************************/
    cout << "***************************************" << endl;
    cout << "Worst Fit" << endl;
    cout << "Step by Step memory allocation situation in Worst Fit" << endl
         << endl;

    ll worstFitSum = 0;
    cross = -1;
    for (int i = 0; i < memoryReqNo; i++)
    {
        ll flag = 0, sum = 0, indx = -1, mn = -BIG;
        for (int j = 1; j <= holesNo; j++)
        {
            if (WorstFit[j][i] >= WorstFit[0][i])
            {
                if ((WorstFit[j][i] - WorstFit[0][i]) > mn)
                {
                    mn = WorstFit[j][i] - WorstFit[0][i];
                    indx = j;
                }
            }
        }
        if (indx != -1)
        {
            WorstFit[indx][i] -= WorstFit[0][i];
            for (int j = 1; j <= holesNo; j++)
            {
                WorstFit[j][i + 1] = WorstFit[j][i];
                sum += WorstFit[j][i];
            }
            worstFitSum = sum;
        }
        else
        {
            cross = i;
            for (int j = 1; j <= holesNo; j++)
                WorstFit[j][i] = -1;

            break;
        }
    }
    for (int i = 0; i <= holesNo; i++)
    {
        for (int j = 0; j < memoryReqNo; j++)
        {
            if (cross <= j && cross != -1 && i!=0)
                cout << "X\t";
            else
                cout << WorstFit[i][j] << "\t";
        }
        cout << endl;
    }

    if (cross == -1)
        cout << endl
             << "No External Fragmentation" << endl
             << endl;
    else
        cout << endl
             << "External Fragmentation: "
             << worstFitSum << endl
             << endl;
}


/*
5
50 200 70 115 15
10
100 10 35 15 23 6 25 55 88 40
*/