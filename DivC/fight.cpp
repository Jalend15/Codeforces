#include<bits/stdc++.h>
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
*/
 
 
using namespace std;
 
/*--------------------------Containers------------------------*/
typedef      long long int           ll;
typedef      unsigned long long int  ull;
typedef     vector < int >          vi;
typedef     vector < ll >           vll;
typedef     vector < vll >           vvi;
typedef     pair< int,int >         pi;
typedef     pair< ll, ll >          pll;
typedef     vector< pi >            vpi;
typedef     vector< pll >           vpll;
/*------------------------------------------------------------*/
 

/*--------------------------Limits & Constants----------------*/
#define     MAXN                 200007
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
	ll hy, ay, dy;
	cin>>hy>>ay>>dy;

	ll hm, am, dm;
	cin>>hm>>am>>dm;

	ll h,a,d;
	cin>>h>>a>>d;

	ll time1= 1e9;
	if(am>dy)
	{
		time1= ceil(hy*1.0/(am-dy));
	}
	if(am<dy)
	{
		time1=1e9;
	}
	ll time2 = 1e9;
	if(ay>dm)
	{
		time2=ceil(hm*1.0/(ay-dm));
	}
	if(ay<dm)
	{
		time2=1e9;
	}
	//cout<<time1<<" "<<time2<<endl;

int flag=1;
	ll min1=1e9;
		for(ll j=0;j<=200;j++)
		{
			if(ay+j<=dm)
				continue;
			if(ay+j>dm)
			{
				time2=ceil(hm*1.0/(ay+j-dm));
			}

			for(ll k=0;k<=200;k++)
			{

				ll i;
				if(am-dy-k>0)
				 i= (time2)*(am-dy-k)-hy+1;
				if(am<=dy+k)
				{
					i=0;
				}
				if(i<0)
					i=0;

				if(time2!=1e9)
				{
					
				
			    	min1= min(min1,(i)*h+j*a+k*d);
			    	
				
				}
				if(time2==1e9){
						min1=min(min1,j*a+k*d);
				}


						
			}
		}
	//if(min1!=1e9)
	cout<<min1<<endl;



}