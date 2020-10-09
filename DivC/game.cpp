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



vll comp(201);
vll visited(4);
vvll gr(4);
vll yes(4);
bool check()
{
	if(visited[1]==visited[2]&&visited[2]==visited[3]&&visited[1]<=0)
		return false;
	return true;
}

bool check2(vll x)
{
	forn(i,x.size())
	{
		if(x[i]!=0)
			return true;
	}
	return false;
}
int main()
{
	ll n;
	cin>>n;
	vll c(n);
	forn(i,n)
	{
		cin>>c[i];
		comp[i+1]=c[i];
		gr[c[i]].pb(i+1);
		++visited[c[i]];
		yes[c[i]]=1;
	}

	vvll g(n+1);
	forn(i,n)
	{
		ll k;
		cin>>k;
		while(k--)
		{
			ll x;
			cin>>x;
			g[i+1].pb(x);

		}

	}
	ll ans= INT_MAX;
	vll x= c;
	vll xxxx=comp;
	forn(start,3)
	{
		

		ll s= start+1;
		 c= x;
		 comp=xxxx;
		ll y=n;
		while(check2(c))
		{
			//00cout<<s<<endl;
			///cout<<s<<" "<<y<<endl;
			vll selected;
			forn(i,n)
			{
				if(c[i]==s)
				{
					ll S=s;
					
					selected.pb(i+1);
				}

			}
			forn(i,selected.size())
			{
				ll ss=selected[i];
				ll flag=1;
				forn(j,g[ss].size())
				{
					ll sss= g[ss][j];
					if(comp[sss]<=0||comp[sss]==s)
					{

					}
					else
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
				{
					selected.erase(selected.begin()+i);
					--i;
				}
			}
			forn(i,selected.size())
			{
				ll ss= selected[i];
				ll flag=0;
				
				forn(j,g[ss].size())
				{
					flag=0;
					forn(k,selected.size())
					{
						if(g[ss][j]==selected[k]||comp[g[ss][j]]<=0)
							flag=1;
					}
					if(flag==0)
					{
						selected.erase(selected.begin()+i);
						--i;
						break;
					}
				}
			}
			forn(i,selected.size())
			{
				comp[selected[i]]=0;
				//cout<<selected[i]<<" ";
			}
		//	cout<<selected[i]<<' ';
			//cout<<endl;
			forn(i,n)
			{
				forn(j,selected.size())
				{
					if(i+1==selected[j])
					{
						//cout<<i<<endl;
						c[i]=0;
					}
				}
			}
			if(check2(c)==false)
				break;
			++y;
			++s;
			if(s>3)
				s=1;

			//cout<<endl;
		}
		ans=min(y,ans);
		//cout<<ans<<endl<<endl;
	}
	cout<<ans<<endl;



}