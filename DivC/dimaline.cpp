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

int main()
{
	ll n;
	cin>>n;
	vll a(n);
	forn(i,n)
	{
		cin>>a[i];
	}
	ll flag=1;
	forn(i,n-1)
	{
		ll maxi= max(a[i],a[i+1]);
		ll mini=min(a[i],a[i+1]);	
		for(ll j=i+1;j<n-1;j++)
		{
			ll max2=max(a[j],a[j+1]);
			ll min2= min(a[j],a[j+1]);
			//cout<<maxi<<" "<<mini<<" "<<max2<<" "<<min2<<endl;
			if(min2==mini||maxi==max2)
			{
				continue;
				cout<<"yes"<<endl;
				flag=0;
				break;				
			}
			if(min2==maxi)
				continue;
			if(max2==mini)
				continue;
			if((min2>=mini&&min2<=maxi)&&max2>maxi)
			{
				cout<<"yes"<<endl;
				flag=0;
				break;
			}
			if((max2<=maxi&&max2>=mini)&&min2<=mini)
			{
				cout<<"yes"<<endl;
				flag=0;
				break;				
			}

		}
		if(flag==0)
			break;
	}
	if(flag)
	{
		cout<<"no"<<endl;
	}
}