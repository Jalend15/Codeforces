#include<bits/stdc++.h>
 #include<string.h>
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
/*struct compare
{
	bool operator()(const string &a, const string &b)
	const{
		return a.compare(b);
	}

};*/
//map<string,ll> m;
int main()
{
	string s;
	cin>>s;
	ll k;
	cin>>k;
	vector<string> v(k);
	
	forn(i,k)
	{
		cin>>v[i];
		//m[v[i]]=1;
		//m[v[1]+v[0]]=1;
	}
	stack<char> st;
	st.push(s[0]);
	ll count1=0;
	ll i=1;
	forn(j,v.size())
	{
		string temp="";
		ll type1=0;
		ll type2=0;

		forn(i,s.size())
		{
			if(s[i]==v[j][0]||s[i]==v[j][1])
			{
				temp+=s[i];
				if(s[i]==v[j][0])
					++type1;
				else
					++type2;
			}
			else
			{
				count1+=min(type1,type2);
				type1=type2=0;
			}
		}
		if(temp!="")
		{
			count1+=min(type1,type2);
		}
	}
	cout<<count1<<endl;
//	cin>>v[i];

}

/*

eo oe 1
st ts 10
oe eo 17
eo oe 21
st ts 33
st ts 50
eo oe 55
ts st 60
ts st 64
gw wg 68
eo oe 76
wg gw 89
gw wg 98
gw wg 104
oe eo 107
eo oe 123
eo oe 124
gw wg 125
wg gw 132
gw wg 138
st ts 139
ts st 147
wg gw 150
st ts 163
eo oe 170
eo oe 173
st ts 174
gw wg 176
wg gw 180
wg gw 181
st ts 182
gw wg 185
wg gw 190
ts st 206
oe eo 207
eo oe 214
oe eo 224
wg gw 226
st ts 229
eo oe 239
wg gw 241
gw wg 248
gw wg 265
eo oe 270
gw wg 280
ts st 283
gw wg 284
eo oe 287
gw wg 290
ts st 295
eo oe 313
oe eo 320
wg gw 323
oe eo 331

**/