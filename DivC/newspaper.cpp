#include<bits/stdc++.h>
#include<algorithm>
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

vll v(26);
vvll ind(26);
int main()
{
	string a;
	string b;
	cin>>a>>b;
	forn(i,a.size())
	{
		v[a[i]-'a']=1;
		ind[(int)(a[i]-'a')].pb(i);
		//v[a[i]-'a']=1;

	}
	ll act=0;
	ll no=0;
	ll flag=0;
	/*forn(i,26)
	{
		forn(j,ind[i].size())
		{
			cout<<i<<" "<<ind[i][j]<<endl;
		}
	}*/
	forn(i,b.size())
	{
		ll z= b[i]-'a';
		std::vector<ll>:: iterator x = lower_bound(ind[(int)(b[i]-'a')].begin(),ind[(int)(b[i]-'a')].end(),act);
		ll y= x-ind[z].begin();
		//cout<<ind[z][y]<<" "<<y<<" "<<b[i]<<endl;
		//cout<<no<<endl;
		if(v[b[i]-'a']==0)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		if(x==ind[z].end())    //act is greater than all indices
		{
			++no;
			flag=0;

			act=ind[z][0]+1;
			
			if(act>=a.size())
			{
				//++no;
			//	cout<<i<<" "<<b[i]<<endl;
				flag=1;
				act=0;
			}
			continue;
		}
		if(ind[z][y]>=act)
		{

			act=ind[z][y]+1;
			flag=0;
			if(act==a.size())
			{
				++no;
			//	cout<<b[i]<<" "<<i<<endl;
				act=0;
				flag=1;
			}
		}
		/*else
		{
			++no;
			//cout<<b[i]<<" "<<i<<endl;
			act=0;
			flag=1;
		}*/

	}
	//cout<<flag<<endl;
	if(!flag)
		++no;
	cout<<no<<endl;
}