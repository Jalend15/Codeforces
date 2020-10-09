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




int main()
{
    fast;

    ll n;
    ll len;
    cin>>n>>len;
    vll a(n);
    forn(i,n) cin>>a[i];
    ll k;
    cin>>k;

ll res=0;
for(ll sgn=0;sgn<=1;sgn++){
    if(sgn==1)
    {
        forn(i,n)
        a[i]=-a[i];
    }
    std::multiset<ll> s1,s2;
    std::multiset<ll>::iterator it;
    vll pre(n+1,0);
    forn(i,n)
    {
        pre[i+1]=pre[i]+a[i];
    }
    forn(i,len)
    {
        if(a[i]<0)
        {
            if(s1.size()<k)
             s1.insert(-a[i]);
            else
            {
                s2.insert(-a[i]);
                it= s2.end();
                --it;
                //cout<<(*it);
                if(*it>*(s1.begin()))
                {
                    ll x1= *(s1.begin());
                    s1.erase(s1.find(x1));
                    s1.insert(*it);
                    s2.erase(s2.find(*it));
                    s2.insert(x1);
                }

            }
            
        }
          
    }
    ll negsum=0;

    for(it= s1.begin();it!=s1.end();++it)
    {
        negsum+= *(it);
    }
    ll sum=0;
    ll cc=0;

   // cout<<"11"<<endl;
  // cout<<negsum<<endl;

   
    sum= pre[len]-pre[0]+2*negsum;

 //   cout<<sum<<endl;
    ll ans= sum;
    res=max(ans,res);
    ll i=1;


   while(i+len-1<n)
   {
      // cout<<sum<<endl;
       if(a[i-1]>=0)
        sum-=a[i-1];
        else
        {
            if(s1.find(-a[i-1])!=s1.end())
            {
                sum-=(-a[i-1]);
                s1.erase(s1.find(-a[i-1]));
                if(s2.size()>0)
                {
                    it= s2.end();
                    --it;
                    s1.insert(*it);
                    ll op=*it;
                    s2.erase(s2.find(op));
                    sum+= 2*(op);
                }
 

            }
            else
            {
                sum-= a[i-1];
                if(s2.find(-a[i-1])!=s2.end())
                s2.erase(s2.find(-a[i-1]));
            }
            
        }
        ll ind= i+len-1;
        if(a[ind]>=0)
        {
            sum+=a[ind];
        }
        else
        {
            sum+= a[ind];
            s2.insert(-a[ind]);

            ll flag=1;
            while(s1.size()<k&&s2.size()>0)
            {
                it= s2.end();
                --it;
                ll yyy= *(it);
                sum+= (2*(yyy));
               // cout<<(*it);
                s1.insert(yyy);
                s2.erase(s2.find(yyy));
                flag=0;
                //sum+=
            }
            if(s1.size()==k&&s2.size()>0&&flag==1)
            {
                it= --s2.end();
                ll x1= *(s1.begin());

                ll yy= *(it);
                if(x1<yy)
                {
                sum-= (2*x1);
                sum+= (2*yy);
               // sum+= *(it);
                s1.erase(s1.find(x1));
                s1.insert(yy);
                s2.erase(s2.find(yy));
                s2.insert(x1);
                }
            }
        }
  
        ans=max(ans,sum);
        ++i;


        
   }
   res=max(ans,res);
}
   cout<<res<<endl;



}