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
typedef     vector < vi >           vvi;
typedef     pair< int,int >         pi;
typedef     pair< ll, ll >          pll;
typedef     vector< pi >            vpi;
typedef     vector< pll >           vpll;
/*------------------------------------------------------------*/
 
/*--------------------------Limits & Constants----------------*/
#define     MAX                 200007
#define     MOD                 int(1e9+9)
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

struct Point
{
	double x;
	double y;
};



long  double angle11(Point a)
{
	long double angle1;
	if(a.x!=0)
		angle1=atan(a.y/a.x)/(PI)*180.0;
	else
		angle1=atan(INFINITY)/(PI)*180.0;
	if(a.x<0&&a.y>0)
	{
		angle1= 180+angle1;
	}
	if(a.x<=0&&a.y<=0)
	{
		angle1= 180.0+angle1;
	}
	if(a.x>0&&a.y<0)
	{

		angle1= 360+angle1;
	}
	return angle1;
}
int main()
{
	ll n;
	cin>>n;
	std::vector<Point> v(n);
	std::vector<double> pp;
	forn(i,n)
	{
		cin>>v[i].x>>v[i].y;
		pp.push_back(angle11(v[i]));
	}
	sort(pp.begin(), pp.end());

	/*forn(i,n)
	cout<<pp[i]<<" ";*/
	//cout<<atan(INFINITY)/(PI)*180<<endl;
	if(n==2)
	{
		long double angle1 = angle11(v[0]);
		long double angle2 =angle11(v[1]);
		printf("%0.9lf\n", min(pp[1]-pp[0],360-(pp[1]-pp[0])));
		
		return 0;
	}
	if(n==1)
	{
		double u=0;
		printf("%0.9lf\n", u);
		
		return 0;
	}
	long double maxi=abs(pp[n-1]-pp[0]);
	long double mini=1360.0;
	forn(i,n-1)
	{
		if(maxi>abs(360-pp[i+1]+pp[i]))
			maxi=abs(360-pp[i+1]+pp[i]);
	}
	printf("%0.11Lf\n", maxi);
	
}