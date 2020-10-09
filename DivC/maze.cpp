#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define forn(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
 ll t;    
 ll visited[501][501];
 char **a;
 int n,m;

 void dfs(int i, int j)
 {
    //cout<<i<<" "<<j<<endl;
    visited[i][j]=1;
    if(i-1>=0){
        if(a[i-1][j]=='.'&&visited[i-1][j]==0)
        {
            dfs(i-1,j);
        }

    }
    if(i+1<n)
    {
        if(a[i+1][j]=='.'&&visited[i+1][j]==0)
        {
            dfs(i+1,j);
        }

    }
    if(j-1>=0)
    {
        if(a[i][j-1]=='.'&&visited[i][j-1]==0)
            dfs(i,j-1);

    }
    if(j+1<m)
    {
        if(a[i][j+1]=='.'&&visited[i][j+1]==0)
            dfs(i,j+1);

    }
    if(t>0)
    {
        a[i][j]='X';
        --t;
    }
    return;
 }
int main()
{
    int k;
    cin>>n>>m>>k;
    
    a=new char*[n];
    forn(i,n)
    a[i]=new char[m];
    forn(i,n)
    {
        forn(j,m)
        {
            cin>>a[i][j];
        }
    }
    t=k;
    forn(i,n)
    {
        forn(j,m)
        {
            if(t<0)
                break;
        if(a[i][j]=='.')

          dfs(i,j);  
        }
        if(t<0)
            break;
    }
    forn(i,n)
    {
        forn(j,m)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
     