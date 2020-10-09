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

struct si
{
	ll a;
	ll b;
};

map<ll,si> m;
void addEdge(ll x,ll y)
{
	if(m[x].a==-1)
	{
		m[x].a=y;

	}
	else
	{
		m[x].b=y;
	}
	if(m[y].a==-1)
	{
		m[y].a=x;
	}
	else
	{
		m[y].b=x;
	}
	//cout<<m[x].a<<endl;
	//return next;
	return;
}
int main()
{
	ll n;
	cin>>n;
	vll a(n);
	vll b(n);
	map< ll,ll > vis;
	
	//vll s;
	vll s;
	forn(i,n)
	{
		cin>>a[i];
		cin>>b[i];
		m[a[i]].a=-1;
		m[b[i]].b=-1;
		m[b[i]].a=-1;
		m[a[i]].b=-1;
		s.pb(a[i]);
		s.pb(b[i]);

		///vis.insert({a[i],0});
		//vis.insert({b[i],0});
	}

	forn(i,n)
	{
		addEdge(a[i],b[i]);
	}
	ll k=0;
	ll found=-1;
	forn(i,n)
	{
		//cout<<next[a[i]].a<<" "<<next[a[i]].b<<endl;
		if(m[a[i]].a==-1||m[a[i]].b==-1)
		{
			found=a[i];
			break;
		}
	}
	forn(i,n)
	{
		//cout<<next[b[i]].a<<" "<<next[b[i]].b<<endl;
		if(m[b[i]].a==-1||m[b[i]].b==-1)
		{
			found=b[i];
			break;
		}
	}
	//cout<<found<<endl;
	while(m[found].a!=-1||m[found].b!=-1)
	{
		cout<<found<<" ";
		ll x= found;
		if(m[found].a!=-1)
		{
			x= m[found].a;
			if(m[x].a==found)
					m[x].a=-1;
			if(m[x].b==found)
				m[x].b=-1;
		}
		else if(m[found].b!=-1)
		{
			x= m[found].b;
			if(m[x].a==found)
					m[x].a=-1;
			if(m[x].b==found)
				m[x].b=-1;			
		}
		if(found==x)
			break;
		found=x;


	}
	cout<<found<<" ";



}
