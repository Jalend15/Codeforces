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
#define     MOD                 int(1e9+9)
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

vector<ll> count1(10,0);
vector<ll> ans(7,0);

void recur(string a, ll l, ll r)
{
	if(l==r)
	{
		ll num=0;
		forn(i,4)
		{
			num=num*10+(a[3-i]-'0');
		}
		ans[num%7]=num;
	}
	else
	{
		for(ll i=l;i<=r;i++)
		{
			swap(a[l],a[i]);
			recur(a,l+1,r);
			swap(a[l],a[i]);
		}
	}
}

int main()
{
	string s;
	cin>>s;
	count1[1]=count1[6]=count1[8]=count1[9]=-1;
	forn(i,s.size())
		++count1[s[i]-'0'];
	ll rem =0;
	forn(i,9)
	{
		while(count1[i+1]>0)
		{
			rem=(rem*10+(i+1))%7;
			cout<<(i+1);
			--count1[i+1];
		}
	}	
	rem= rem%7;
	ll num=0;
	recur("1689",0,3);
	forn(i,10)
	{
		if((rem*10000+i)%7==0)
		{
			num=ans[i];
			break;
		}
	}

	cout<<num;
	while(count1[0]>0)
	{
		--count1[0];
		cout<<"0";
	}



}