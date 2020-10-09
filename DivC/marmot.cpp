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
typedef     vector < vll >           vvi;
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
struct Point
{
	ll x;
	ll y;
};

vector<Point> p(4);
vector<Point> o(4);
ll distSq(Point p, Point q) 
{ 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
} 
  
// This function returns true if (p1, p2, p3, p4) form a 
// square, otherwise false 
bool isSquare(Point p1, Point p2, Point p3, Point p4) 
{ 
    ll d2 = distSq(p1, p2); // from p1 to p2 
    ll d3 = distSq(p1, p3); // from p1 to p3 
    ll d4 = distSq(p1, p4); // from p1 to p4 
  
    if (d2 == 0 || d3 == 0 || d4 == 0)     
        return false; 
  
  
    if (d2 == d3 && 2 * d2 == d4 
        && 2 * distSq(p2, p4) == distSq(p2, p3)) { 
        return true; 
    } 
  
    // The below two cases are similar to above case 
    if (d3 == d4 && 2 * d3 == d2 
        && 2 * distSq(p3, p2) == distSq(p3, p4)) { 
        return true; 
    } 
    if (d2 == d4 && 2 * d2 == d3 
        && 2 * distSq(p2, p3) == distSq(p2, p4)) { 
        return true; 
    } 
  
    return false; 
} 
Point rotate(Point p, Point o)
{
	ll xi= p.x-o.x;
	ll yi= p.y-o.y;
	Point q;
	q.x= -yi+o.x;
	q.y= xi+o.y;
	return q;

}
ll min(ll a, ll b)
{
	if(a<b)
		return a;
	else
		return b;
}
ll recur()
{
	ll mini=1e9;
	forn(i,4)
	{
		forn(j,4)
		{
			forn(k,4)
			{
				forn(l,4)
				{
					//cout<<p[3].x<<" "<<p[3].y<<endl;
					//cout<<p[2].x<<" "<<p[2].y<<endl;
					if(isSquare(p[0],p[1],p[2],p[3]))
					{
						mini=min(mini,i+j+k+l);
						//cout<<mini<<endl;
						//cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					}
					p[3]=rotate(p[3],o[3]);
					//cout<<p[3].x<<" "<<p[3].y<<endl;
				}
				//p[3]=rotate(p[3],o[3]);
				p[2]=rotate(p[2],o[2]);
			}
			//p[2]=rotate(p[2],o[2]);
			p[1]=rotate(p[1],o[1]);
		}
		//p[1]=rotate(p[1],o[1]);
		p[0]=rotate(p[0],o[0]);
	}
	return mini;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{

		forn(i,4)
		{
			p[i].x=0;
			p[i].y=0;
			o[i].x=0;
			o[i].y=0;
			cin>>p[i].x>>p[i].y>>o[i].x>>o[i].y;
		}
		ll mini=recur();
		if(mini==1e9)
			cout<<"-1"<<endl;
		else
			cout<<mini<<endl;


	}
}