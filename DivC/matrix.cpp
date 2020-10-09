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
	ll x;
	string s;
	cin>>x;
	cin>>s;
	vll v(s.size());
	forn(i,s.size())
	{
		v[i]=s[i]-'0';
	}
	vll sumer;
	map <ll,ll> m;
	forn(i,s.size())
	{
		ll sum=0;
		forn(gap, s.size()-i)
		{
			//cout<<"!"<<endl;
			sum+=v[i+gap];
			sumer.push_back(sum);

		}
	}
	sort(sumer.begin(), sumer.end());
	forn(i,sumer.size())
	{
		ll sum=1;
		//cout<<sumer[i]<<endl;
		while(i<sumer.size()-1&&sumer[i]==sumer[i+1])
		{
			//cout<<"1"<<endl;
			++sum;
			++i;
		}
		//cout<<sum<<endl;
		m.insert(make_pair(sumer[i],sum));


	}
	ll ans=0;

	forn(i,sumer.size())
	{
//cout<<sumer[i]<<" "<<x<<endl;
		if(x==0)
		{
		//	cout<<sumer[i]<<" "<<x<<endl;
			if(sumer[i]!=0)
			{
			/*ll y=x/sumer[i];
		//	cout<<y<<endl;
			std::vector<ll>::iterator indice= lower_bound(sumer.begin()+i, sumer.end(),y);
			if (indice!=sumer.end())
			{

				if(sumer[indice-sumer.begin()]==y&&(indice-sumer.begin())!=i)
				{
					//cout<<y<<" "<<sumer[i]<<endl;
					ans+=2*m.at(y);
				}
				if(sumer[indice-sumer.begin()]==y&&(indice-sumer.begin())==i)
				{
					ans+=1*m.at(y);
				}
			}*/
			}
			else
			{
					//cout<<y<<" "<<sumer[i]<<endl;

					ans+=2*(sumer.size()-i-1);
					if(i==sumer.size()-1)
						ans+=m.at(sumer[i]);
					else if(sumer[i+1]!=sumer[i])
						ans+=m.at(sumer[i]);
					//ans+=1;
					//ans+=1*m.at(0);
				
			}
		}
		if(sumer[i]!=0&&x!=0)
		{
		if(x%sumer[i]==0)
		{
			
			ll y=x/sumer[i];
			std::vector<ll>::iterator indice= lower_bound(sumer.begin()+i, sumer.end(),y);
			if (indice!=sumer.end())
			{

				if(sumer[indice-sumer.begin()]==y&&(indice-sumer.begin())!=i)
				{
					//cout<<y<<" "<<sumer[i]<<endl;
					ans+=2*m.at(y);
				}
				if(sumer[indice-sumer.begin()]==y&&(indice-sumer.begin())==i)
				{
					cout<<m.at(y)<<" "<<y<<sumer[i]<<endl;
					ans+=1*m.at(y);
				}
			}
		}


	
	}
}

	cout<<ans<<endl;

}
