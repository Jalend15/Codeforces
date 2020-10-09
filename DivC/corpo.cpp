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
#define     pi                  (2*acos(0.0))
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
#define 	cot(x)				(1.0/tan(x))
/*------------------------------------------------------------*/

string s;
string t="";
vector<string> ss;
vvll gr(10000);
ll x=0;
ll formtree()
{
	ll y=x;
	if(t[x]=='.')
	{

		return -1;
	}
	else if(t[x]==':'||t[x]==',')
	{
		++x;
		return formtree();
	}
	while(t[x]!='.')
	{
		++x;
		gr[t[y]-'0'].pb(formtree());

	}
	++x;
	return t[y]-'0';

}

int main()
{
	///string s;
	cin>>s;
	string temp="";	
	forn(i,s.size())
	{
		if(s[i]==','||s[i]=='.'||s[i]==':')
		{
			if(temp!="")
			{
				ll check=0;
				forn(j,ss.size())
				{
					if(ss[j]==temp)
						check=1;
				}
				if(!check)
					ss.pb(temp);
				temp="";
			}
		}
		else
			temp+=s[i];
	}
	
	//string t="";
	temp="";
	ll xx=0;
	vvll re(ss.size()+1);
	forn(i,s.size())
	{
		if(s[i]==','||s[i]==':'||s[i]=='.')
		{
			if(temp!="")
			{
				forn(j,ss.size())
				{
					if(temp==ss[j])
					{
						//ind=j;
						break;
						//t+=s[i];
					}
				}
				t+=s[i];
			}
			t+=s[i];
			temp="";

		}
		else
			temp+=s[i];
	}

	ll start=formtree();
	cout<<start<<endl;
	forn(i,ss.size())
	{
		forn(j,gr[i].size())
		{
			if (gr[i][j]==-1)
			{
				gr[i].erase(gr[i].begin()+j);
				--j;
			}
			//cout<<gr[i][j]<<" ";
		}
		//cout<<endl;
	}
	forn(i,ss.size())
	{
		forn(j,gr[i].size())
		{

			cout<<gr[i][j]<<" ";
		}
	cout<<endl;
	}


}