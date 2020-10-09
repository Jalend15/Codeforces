#include<bits/stdc++.h>
#include<algorithm>
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
/*------------------------------------------------------------*/

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vll a(n);
        vll b(n);
        vector<pair<ll,ll> > x;
        forn(i,n) cin>>a[i];
        forn(i,n)
        {
            cin>>b[i];
            x.pb(make_pair(a[i],1));
            x.pb(make_pair(b[i],2));
        }
        sort(x.begin(),x.end());
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll flag=1;
        vll xx;
       /* forn(i,2*n)
        {
            if(x[i].ff!=x[i+1].ff)
            {
                    flag=0;
                    break;
            }
            else
            {
                if(x[i].ss==x[i+1].ss)                {
                    xx.pb(x[i].ff);
                }
            }
            ++i;
       }*/

        ll k=0;

       while(k<2*n)
       {
           if(x[k].ff!=x[k+1].ff)
           {
               flag=0;
               break;
           }
           else
           {
               vll cc(2,0);
               ll tt=x[k].ff;
               while(k<2*n&&tt==x[k].ff&&x[k+1].ff==x[k].ff)
               {
                   ++cc[x[k].ss-1];
                   ++cc[x[k+1].ss-1];
                   k+=2;
               }
             //  cout<<tt<<" "<<cc[0]<<" "<<cc[1]<<endl;
               ll oo= abs(cc[0]-cc[1])/2;
               while(oo--)
               {
                   xx.pb(tt);
               }
           }
       }

       sort(xx.begin(),xx.end());
     /*  forn(i,xx.size())
       {
           cout<<xx[i]<<" ";
       }
       cout<<endl;*/
       if(flag)
       {
           ll hh= min(a[0],b[0]);
           ll sum=0;
            ll ind=0;
            while((ind<xx.size()/2)&&xx[ind]<=2*hh)
            {
                sum+=xx[ind];
                ++ind;
            }
            while(ind<xx.size()/2)
            {
                ++ind;
                sum+= 2*hh;
            }
           // ans+=(ind)*hh;
            
           cout<<sum<<endl;
       }
       else
       {
           ll sum=-1;
           cout<<sum<<endl;
       }
       
    }
}