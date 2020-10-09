#include<bits/stdc++.h>
 #include<string.h>
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
/*----------------------------------
--------------------------*/
 
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

	vvll a(1000+1);
	vvll d(1000+1,vll(1000+1,0));
	vll vis(1000+1,0);
	vll parent(1001);
	ll count2=0;
	vll from;
	vll to;
	vll via;

void dfs(ll u, ll dia)
{
	vis[u]=1;
	forn(i,a[u].size())
	{
		if(vis[a[u][i]]==0)
		{
			parent[a[u][i]]=u;
			ll x=min(dia,d[u][a[u][i]]);
		   dfs(a[u][i],x);
		}

	}
	if(a[u].size()==0)
	{
		ll x=u;
		while(parent[x]!=0)
		{
			 x=parent[x];

		}
		from.pb(x);
		to.pb(u);
		via.pb(dia);
		//cout<<x<<" "<<u<<" "<<dia<<endl;
		++count2;
	}
}
vll exist(1001);
int main()
{
	ll n,p;
	cin>>n>>p;

	forn(i,p)
	{
		ll u,v;
		cin>>u>>v;
		ll dia;
		cin>>dia;
		a[u].pb(v);
		parent[v]=u;
		d[u][v]=dia;
		exist[u]=1;
		exist[v]=1;	
	}
	forn(i,n)
	{
		if(parent[i+1]==0&& p>0&&exist[i+1]==1)
		{
			parent[i+1]=0;
			dfs(i+1,1000000);
		}
	}
	cout<<count2<<endl;
	forn(i,from.size())
		{
		cout<<from[i]<<" "<<to[i]<<" "<<via[i]<<endl;
	}


}