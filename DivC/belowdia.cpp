#include <bits/stdc++.h>
using namespace std;
#define sz size()
#define fi first
#define se second
#define mp make_pair
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
#define pb push_back
#define all(v) v.begin(),v.end()
#define EPS 1e-9
#define MOD 1000000007
#define MAX 1005
typedef pair<int,int> pii;
typedef long long ll;

int n;
int col[MAX];
int row[MAX];
int last[MAX];
bool mt[MAX][MAX];

vector<int> op,e1,e2;

int main()
{
    scanf("%d",&n);

    for(int i=1; i<n ; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        x--; y--;
        row[x]++;
        col[y]++;
        mt[x][y] = 1;
    }

    int m = 0;
    for(int i=0; i<n; i++)
    {
        m = i;
        for(int j = i + 1; j<n; j++)
            if(col[j] > col[m]) m = j;
        if(m != i)
        {
            op.pb(2);
            e1.pb(i);
            e2.pb(m);
            swap(col[i],col[m]);
            for(int j=0; j<n; j++)
                swap(mt[j][i],mt[j][m]);
        }
    }

    memset(last,-1,sizeof last);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(mt[i][j])
                last[i] = j;
    }

    for(int i=n - 1; i>=0; i--)
    {
        int m = i;
        for(int j=i-1; j>=0; j--)
            if(last[j] > last[m]) m = j;
        if(m != i)
        {
            op.pb(1);
            e1.pb(i);
            e2.pb(m);
            swap(last[i],last[m]);
        }
    }

    printf("%d\n",op.sz);
    for(int i=0; i<op.sz; i++)
        printf("%d %d %d\n",op[i],e1[i] + 1,e2[i] + 1);

}
