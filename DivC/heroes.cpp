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

vvll liking(7);
//vvll teams(3);
vll a(3);
ll ans=INT_MAX;
ll like= -1;
int inddd(string x)
{
	if(x=="Anka")
		return 0;
	if(x=="Chapay")
		return 1;
	if(x=="Cleo")
		return 2;
	if(x=="Troll")
		return 3;
	if(x=="Dracul")
		return 4;
	if(x=="Snowy")
		return 5;
	if(x=="Hexadecimal")
		return 6;



}


void addlike(string s, string t)
{
	int i= inddd(s);
	int j= inddd(t);
	liking[i].pb(j);
	return;
}

void solve(vvll teams)
{
	ll a1= a[0]/teams[0].size();
	ll a2= a[1]/teams[1].size();
	ll a3= a[2]/teams[2].size();

	ll maxi=max(a1,max(a2,a3));
	ll mini= min(a1,min(a2,a3));
	//ans=min(ans,maxi-mini);
	ll likinghere=0;
	forn(i,3)
	{
		//ll lik=0;
		forn(j,teams[i].size())
		{
			forn(op,liking[teams[i][j]].size())
			{
			ll index= liking[teams[i][j]][op];
			forn(k,teams[i].size())
			{
				if(teams[i][k]==index)
					++likinghere;
			}}

		}
		//likinghere=max(likinghere,lik);
	}
	if(ans==maxi-mini)
	{
		//cout<<a1<<" "<<a2<<" "<<a3<<endl;

		like=max(likinghere,like);
	}
	else
	{
		if(ans>maxi-mini)
		{
	
			ans=maxi-mini;
			like=likinghere;
		}
	}
	return;

}


void recur(int root, vvll teams)
{
	for(int i=0;i<3;i++)
	{
		teams[i].pb(root);
		if(root!=6)
		  recur(root+1,teams);
		else
		{
			if(teams[0].size()!=0&&teams[1].size()!=0&&teams[2].size()!=0)
			{
				solve(teams);
			}
		}
		teams[i].pop_back();

	}
}

int main()
{
	ll n;
	cin>>n;
	forn(i,n)
	{
		string s;
		string q;
		string t;
		cin>>s>>q>>t;
		addlike(s,t);
	}
	forn(i,3)
	{
		cin>>a[i];
	}

	vvll teams(3);
	recur(0,teams);
	cout<<ans<<" "<<like<<endl;
}