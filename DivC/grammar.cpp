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

struct word
{
	string m;
	string f;
};
ll a=0;
ll n=0;
ll v=0;
ll male=0;
ll female=0;
word adj;
word noun;
word verb;



string s;

map<string, ll> indice, count1;

ll max(ll a, ll b)
{
	if(a>b)
		return a;
	return b;
}

void checks(ll cc)
{
	ll n= s.size();

	if(n>=6)
	indice[s.substr(max(0,n-6),n)]=  min(cc,indice[s.substr(max(0,n-6),n)]);
	
	if(n>=4&&s.substr(max(0,n-4),n)=="etra")
		indice[s.substr(max(0,n-4),n)]=  max(cc,indice[s.substr(max(0,n-4),n)]);
	else
		indice[s.substr(max(0,n-4),n)]=  max(cc,indice[s.substr(max(0,n-4),n)]);
	if(n>=3)
	indice[s.substr(max(0,n-3),n)]=  max(cc,indice[s.substr(max(0,n-3),n)]);
	if(n>=5)
	indice[s.substr(max(0,n-5),n)]=  max(cc,indice[s.substr(max(0,n-5),n)]);
	if(n>=6)
	++count1[s.substr(max(0,n-6),n)];
if(n>=4)
	++count1[s.substr(max(0,n-4),n)];
if(n>=3)
	++count1[s.substr(max(0,n-3),n)];
if(n>=5)
	++count1[s.substr(max(0,n-5),n)];
	//cout<<s.substr(max(0,n-5),n)<<endl;



}

void checkcount()
{
	if(count1[noun.m]==0&&count1[noun.f]==0&&count1[adj.m]==0&&count1[adj.f]==0&&count1[verb.m]==0&&count1[verb.f]==0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	if(count1[noun.m]>1||count1[noun.f]>1)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
}


void printcheck()
{
	cout<<indice[adj.m]<<" "<<indice[adj.f]<<endl;
	cout<<count1[adj.m]<<" "<<count1[adj.f]<<endl;
	cout<<indice[noun.m]<<" "<<indice[noun.f]<<endl;
	cout<<count1[noun.m]<<" "<<count1[noun.f]<<endl;
	cout<<indice[verb.m]<<" "<<indice[verb.f]<<endl;
	cout<<count1[verb.m]<<" "<<count1[verb.f]<<endl;
}
int main()
{
	adj.m="lios";
adj.f="liala";

noun.m="etr";
noun.f="etra";

verb.m="initis";
verb.f= "inites";
	ll cc=1;
	indice[adj.m]=indice[adj.f]=0;
	 indice[noun.m]= indice[noun.f]= 0;
	indice[verb.m]= indice[verb.f]=100000000000;
	ll prev1=0;
	ll prev2=0;
	ll prev3=0;
	ll prev4=0;
	ll prev5=0;
	ll prev6=0;
    count1[adj.m]=0;
    count1[adj.f]=0;
    count1[noun.m]=0;
    count1[noun.f]=0;
    count1[verb.m]=0;
    count1[verb.f]=0;
	while((cin>>s))
	{
		string r;
		checks(cc);
		++cc;
		checkcount();
		if(prev1==count1[adj.m]&&prev2==count1[adj.f]&&prev3==count1[noun.m]&&prev4==count1[noun.f]&&prev5==count1[verb.m]&&prev6==count1[verb.f])
		{
			cout<<"NO"<<endl;
			return 0;
		}

		prev1=count1[adj.m];
		prev2=count1[adj.f];
		prev3=count1[noun.m];
		prev4=count1[noun.f];
		prev5=count1[verb.m];
		prev6=count1[verb.f];
		//printcheck();
		//cout<<endl;
		if(count1[adj.m]>0||count1[verb.m]>0||count1[noun.m]>0)
			male=1;
		if(count1[adj.f]>0||count1[verb.f]>0||count1[noun.f]>0)
			female=1;
		if(male&female)
		{
			cout<<"NO"<<endl;
			exit(0);
		}
		//cout<<male<<" "<<count1[noun.m]<<endl<<endl;
		s=r;

	}
	checkcount();

	
	if(male==1)
	{
		ll x= count1[verb.m]+count1[noun.m]+count1[adj.m];
		if(x==1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		else
		{
			if(count1[noun.m]==0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else
			{
				if((indice[verb.m]<indice[noun.m])||(indice[adj.m]>indice[noun.m]))
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	
	}
	if(female==1)
	{
		ll x= count1[verb.f]+count1[noun.f]+count1[adj.f];
		if(x==1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		else
		{
			if(count1[noun.f]==0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else
			{
				if((indice[verb.f]<indice[noun.f])||(indice[adj.f]>indice[noun.f]))
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	
	}
	cout<<"YES"<<endl;
}