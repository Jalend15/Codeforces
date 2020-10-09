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

vector<string> ss(4);
ll k1,k2,k3;
ll k;

bool checkvowel(char x)
{
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
	{
		return true;
	}
	return false;
}
string findword(string s)
{
	ll cc=0;
	ll ind=-1;
	for(ll i=s.size()-1;i>=0;i--)
	{
		if(checkvowel(s[i]))
		{
			++cc;
			if(cc==k)
			{

				ind=i;
				break;
			}
		}
	}
	if(ind==-1)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	return s.substr(ind);

}


void checkforaabb()
{
	if((findword(ss[0])==findword(ss[1]))&&(findword(ss[2])==findword(ss[3])))
	{
		k1=1;
	}
}

void checkforabba()
{
	if((findword(ss[0])==findword(ss[3]))&&(findword(ss[2])==findword(ss[1])))
	{
		k2=1;
	}
}

void checkforabab()
{
	if((findword(ss[0])==findword(ss[2]))&&(findword(ss[3])==findword(ss[1])))
	{
		k3=1;
	}
}

void getrhyme()
{
	checkforaabb();
	checkforabba();
	checkforabab();
}


int main()
{
	ll n;
	cin>>n;
	cin>>k;
	vll poem(n);
	forn(i,n)
	{
		k1=0;k2=0;k3=0;
		forn(j,4)
		{
			cin>>ss[j];
		}
		getrhyme();
		if(k1==1&&k2==1&&k3==1)
		{
			poem[i]=3;
			continue;
		}
		if(k1==1)
		{
			poem[i]=0;
		}
		if(k2==1)
		{
			poem[i]=1;
		}
		if(k3==1)
		{
			poem[i]=2;
		}
		if(k1==0&&k2==0&&k3==0)
		{
			cout<<"NO"<<endl;
			exit(0);
		}


	}
	vll ans(4,0);
	forn(i,n)
	{
		//cout<<poem
		++ans[poem[i]];
	}
	if(ans[1]==0&&ans[2]==0&&ans[0]==0)
	{
		cout<<"aaaa"<<endl;
		return 0;
	}
	if(ans[2]==0&&ans[1]==0)
	{	
		cout<<"aabb"<<endl;
		return 0;
	}
	if(ans[2]==0&&ans[0]==0)
	{
		cout<<"abba"<<endl;
		return 0;
	}
	if(ans[0]==0&&ans[1]==0)
	{
		cout<<"abab"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
}
