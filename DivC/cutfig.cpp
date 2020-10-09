#include<bits/stdc++.h>
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
*/
 
 
using namespace std;
 
/*--------------------------Containers------------------------*/
typedef     long long int           ll;
typedef     unsigned long long int  ull;
typedef     vector < int >          vi;
typedef     vector < ll >           vll;
typedef     vector < vll >           vvll;
typedef     pair< int,int >         pi;
typedef     pair< ll, ll >          pll;
typedef     vector< pi >            vpi;
typedef     vector< pll >           vpll;
/*------------------------------------------------------------*/
 
/*--------------------------Limits & Constants----------------*/
#define     MAX                 200007
#define     MOD                 int(1e9+7)
#define     INF                 ll(8230219982008199610)
#define     MINF                ll(-8230219982008199610)
#define     IL                  INT_MAX
#define     MIL                 INT_MIN
#define     PI                  2*acos(0.0)
/*------------------------------------------------------------*/
 
/*--------------------------Macros----------------------------*/
#define     fast                ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define     pf                  printf
#define     sc                  scanf
#define     all(a)              (a).begin(),(a).end()
#define     sz(x)               int(x.size())
#define     pb                  push_back
#define     eb                  emplace_back
#define     mp                  make_pair
#define     ff                  first
#define     ss                  second
#define     mem(a,n)            memset(a, n, sizeof(a) )
#define     gcd(a,b)            __gcd(a,b)
#define     lcm(a,b)            (a*(b/gcd(a,b)))
#define     forn(i,n)          for(int i=0; i<n; i++)
#define     loop1(i,n)          for(int i=1; i<=n; i++)
#define     rev0(i,n)           for(int i=n-1; i>=0; i--)
#define     rev1(i,n)           for(int i=n; i>0; i--)
/*------------------------------------------------------------*/
 
/*----------------------Scans and Prints----------------------*/
#define     sc1(x)              scanf("%d",&x)
#define     sc2(x,y)            scanf("%d %d",&x,&y)
#define     sc3(x,y,z)          scanf("%d %d %d",&x,&y,&z)
#define     scd1(x)             scanf("%lld",&x)
#define     scd2(x,y)           scanf("%lld %lld",&x,&y)
#define     pf1(x)              printf("%d\n",x)
#define     pf2(x,y)            printf("%d %d\n",x,y)
#define     pfd1(x)             printf("%lld\n",x)
#define     pfd2(x,y)           printf("%lld %lld\n",x,y)
#define     t_case(t)           for(int cs = 1; cs<=t; cs++)
#define     print(a,n)          for(int pr = 0; pr<int(n); pr++)cout<<a[pr]<<" ";cout<<endl
#define     printa(x)           cout<<x<<endl;
#define     debug               cout<<" OK "<<endl
/*------------------------------------------------------------*/


ll visited[51][51];
ll inqueue1[51][51];
ll parentx[51][51];
ll parenty[51][51];
bool isvalid(ll x, ll y, ll n, ll m)
{
	if(x<n&&x>=0&&y>=0&&y<m)
		return true;
	return false;
}
	std::vector<std::vector<char> > v(55,std::vector<char> (55));
ll row[]={1,-1,0,0};
ll col[]={0,0,-1,1};
ll ii;
void dfs( ll n, ll m, ll x, ll y)
{
	visited[x][y]=1;
	//cout<<x<<" "<<y<<endl;
	++ii;
	forn(i,4)
	{
		ll u= x+row[i];
		ll vv= y+col[i];
		if(isvalid(u,vv,n,m))
		{
			if(visited[u][vv]==0)
			{
				if(v[u][vv]=='#')
				dfs(n,m,u,vv);
			}
		}
	}
}

int main()
{
	fast;
	ll n,m;
	cin>>n>>m;

	ll as=0;
	vll s,e;
	forn(i,n)
	{
		forn(j,m)
		{
			parentx[i][j]=-1;
			parenty[i][j]=-1;
			cin>>v[i][j];
			if(v[i][j]=='#')
			{
				s.pb(i);
				e.pb(j);
				++as;
			}
		}
	}
	if(as<=2)
	{
		cout<<"-1"<<endl;
		return 0;
	}

	forn(i,n)
	{
		forn(j,m)
		{
			if(v[i][j]=='#')
			{
				v[i][j]='.';
				ll o1=s[0];
				ll o2=e[0];
				if(i==o1&&j==o2)
				{
					//cout<<"fr"<<endl;
					o1=s[1];
					o2=e[1];
				}
				//cout<<i<<" "<<j<<" "<<o1<<" "<<o2<<endl;
				dfs(n,m,o1,o2);


				forn(k,n)
				{
					forn(l,m)
					{
						if(v[k][l]=='#')
						{
							if(visited[k][l]==0)
							{
								cout<<"1"<<endl;
								exit(0);
							}
						}
					}
				}
				forn(k,n)
				{
					forn(l,m)
					{
						visited[k][l]=0;
					}
				}
				ii=0;
				v[i][j]='#';
			}
		}
	}
	cout<<"2"<<endl;


}