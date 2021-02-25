///print the Length and the String

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1000


ll save_datarec[SIZE][SIZE];
ll save_datait[SIZE][SIZE];
string s1,s2;
ll length;


///recursive way
ll length_recursive(ll len1,ll len2)
{
    if(len1==s1.size()||len2==s2.size())
        return 0;

    if(save_datarec[len1][len2] != -1)
        return save_datarec[len1][len2];

    if(s1[len1]==s2[len2])
        length =length_recursive(len1+1,len2+1)+1;
    else
        length=max(length_recursive(len1+1,len2),length_recursive(len1,len2+1));

    return save_datarec[len1][len2]=length;
}


///iterative way
ll length_iterative(ll n, ll m)
{
    for (int i =1; i <=n; i++)
    {
        for (int j =1; j<=m; j++)
        {
            if (s1[i-1] == s2[j-1])
                save_datait[i][j] = save_datait[i-1][j-1]+1;
            else
                save_datait[i][j]=max(save_datait[i-1][j],save_datait[i][j-1]);
        }
    }
    return save_datait[n][m];
}


void print(ll save_data[][SIZE],ll len1,ll len2)
{
    if(len1==s1.size() || len2==s2.size())
        return;

    if(s1[len1]==s2[len2])
    {
        cout<<s1[len1];
        print(save_data,len1+1,len2+1);
    }
    else  if(save_datarec[len1][len2+1]>=save_datarec[len1+1][len2])
        print(save_data,len1,len2+1);
    else
        print(save_data,len1+1,len2);
}

void clr()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            save_datait[i][j]=0;
            save_datarec[i][j]=-1;
        }
    }
    s1.clear();
    s2.clear();
}

int main()
{
    clr();
    cout<<"Enter the two string :"<<endl;
    cin>>s1>>s2;
    ll len1=s1.length();
    ll len2=s2.length();
    length=0;

    ///Recursive way
    cout<<endl<<"Recursive way"<<endl;
    cout<<"Length of the LCS  : "<<length_recursive(0,0)<<endl;
    cout<<"Printing the LCS   : ";
    print(save_datarec,0,0);

    ///Iterative way
    cout<<endl<<endl<<"Iterative way "<<endl;
    cout<<"Length of the LCS  : "<<length_iterative(len1,len2)<<endl;
    cout<<"Printing the LCS   : ";
    print(save_datait,0,0);
    cout<<endl;
}


///print the grid

#include<bits/stdc++.h>
using namespace std;
#define FastIO ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read(in) freopen("Input.txt","r",stdin)
#define write(out) freopen("Ouput.txt","w",stdout)
#define pf printf
#define sf scanf
#define fr0(i,n) for(int i=0 ; i<n ; i++)
#define fr1(i,n) for(int i=1 ; i<=n ; i++)
#define fr2(i,n) for(int i=n ; i>=1 ; i--)
#define frx(i,x,n) for(int i=x ; i<=n ; i++)
#define sf1(val) scanf("%lld",&val)
#define sf2(val1,val2) scanf("%lld %lld",&val1,&val2)
#define INF 999999999999999999
#define Pi 2*acos(0.0)
#define len 200000

typedef long long int lli;

lli a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum=0,total=0,res=0,ans=0;

string ar,br,cr;
lli LCS_Length[100][100];
char LCS_Direction[100][100];


int main()
{
    cout<<"Enter Two Strings : \n\n";

    cin>>ar>>br;

    lli len_1 = ar.size(), len_2 = br.size();

    for(i=0 ; i<=len_1 ; i++)
    {
        LCS_Length[i][0]=0;
    }

    for(j=0 ; j<=len_2 ; j++)
    {
        LCS_Length[0][j]=0;
    }

    for(i=1 ; i<=len_1 ; i++)
    {
        for(j=1 ; j<=len_2 ; j++)
        {
            if(ar[i-1] == br[j-1])
            {
                LCS_Length[i][j] = LCS_Length[i-1][j-1]+1;

                LCS_Direction[i][j] = '*';                                  // * means letter came from the previous immediate diagonal corner cell
            }
            else if(LCS_Length[i-1][j] >= LCS_Length[i][j-1])
            {
                LCS_Length[i][j] = LCS_Length[i-1][j];
                LCS_Direction[i][j] = '^';                                   // ^ means letter came from the previous immediate row cell
            }
            else
            {
                LCS_Length[i][j] = LCS_Length[i][j-1];
                LCS_Direction[i][j] = '<';                                    // < means letter came from the previous immediate previous column cell
            }
        }
    }

    cout<<"\n\n";
    cout<<"The Longest Common Subsequence Length : "<<LCS_Length[len_1][len_2];
    cout<<"\n\n";

    cout<<"  ";
    for(j=0 ; j<len_2 ; j++)
        cout<<br[j]<<" ";
    cout<<"\n";

    for(i=1 ; i<=len_1 ; i++)
    {
        cout<<ar[i-1]<<" ";

        for(j=1 ; j<=len_2 ; j++)
        {
            cout<<LCS_Length[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n\n";
    cout<<"The Longest Common Subsequence Direction : ";
    cout<<"\n\n";

    cout<<"  ";
    for(j=0 ; j<len_2 ; j++)
        cout<<br[j]<<" ";
    cout<<"\n";

    for(i=1 ; i<=len_1 ; i++)
    {
        cout<<ar[i-1]<<" ";

        for(j=1 ; j<=len_2 ; j++)
        {
            cout<<LCS_Direction[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    cout<<"The Longest Common Subsequence is : ";

    x=0;

    for(i=len_1 ; i>=1 ; )
    {
        for(j=len_2 ; j>=1 ; )
        {
            if(LCS_Direction[i][j] == '*')
                cr+=ar[i-1],    i--, j--,x++;

            else if(LCS_Direction[i][j] == '^')
                i--;

            else if(LCS_Direction[i][j] == '<')
                j--;

            if(x==LCS_Length[len_1][len_2])
            {
                j=-7;
                break;
            }
        }
        if(j==-7)
            break;
    }



    for(i=cr.size()-1 ; i>=0 ; i--)
        cout<<cr[i];
    cout<<"\n\n";
}

/*ABCBDAB
BDCABA*/


/*
sjkdfjsldkfjskldjfk
sdkjfskdljfskdljfksdjfksdjfksj
*/
