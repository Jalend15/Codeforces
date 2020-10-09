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
vector<string> v;
vector<string> ans;
//vector<string> temp;


void doit(vll x)
{
   /// cout<<"SBSJ"<<endl;
    vector<string> temp;
    string t="";
    forn(i,v[x[1]].size())
    {
    t+="."; 
    }
    forn(i,v[x[4]].size())
    {
        temp.pb(t);
    }
    forn(i,v[x[0]].size())
    temp[0][i]=v[x[0]][i];
    forn(i,v[x[1]].size())
    temp[v[x[3]].size()-1][i]=v[x[1]][i];
    forn(i,v[x[2]].size())
    temp[v[x[4]].size()-1][i+v[x[0]].size()-1]= v[x[2]][i];
   
    forn(i,v[x[3]].size())
    temp[i][0]=v[x[3]][i];
    forn(i,v[x[4]].size())
    temp[i][v[x[0]].size()-1]= v[x[4]][i];
    forn(i,v[x[5]].size())
    temp[i+v[x[3]].size()-1][v[x[1]].size()-1]= v[x[5]][i];

    if(ans.size()==0)
    ans=temp;
    else
    {
        forn(i,ans.size())
        {
            if(i>=temp.size())
            break;
            if(ans[i]<temp[i])
            break;
            if(ans[i]>temp[i])
            {
                ans=temp;
                break;
            }
        }

  
    }
    
}

void helper(string y)
{
    vll x(6);
    ll flag=0;
    
   // cout<<"hai"<<endl;
    forn(i,6)
    {
        x[i]= y[i]-'0';
      //  cout<<x[i];
    }
    if(v[x[3]].size()+v[x[5]].size()-1!=v[x[4]].size())
        return;
   if(v[x[0]][0]!=v[x[3]][0])
        return;
    if(v[x[0]].size()+v[x[2]].size()-1!=v[x[1]].size())
        return;
   if(v[x[3]][v[x[3]].size()-1]!=v[x[1]][0])
    return;


    if(v[x[0]].size()+2>v[x[1]].size())
        return;
   
    if(v[x[3]].size()+2>v[x[4]].size())
        return;

 
    if(v[x[1]][v[x[0]].size()-1]!=v[x[4]][v[x[3]].size()-1])
        return;

  
    if(v[x[4]][v[x[4]].size()-1]!=v[x[2]][0]) return;
  
    if(v[x[5]][0]!=v[x[1]][v[x[1]].size()-1])
         return;
 
    if(v[x[5]][v[x[5]].size()-1]!=v[x[2]][v[x[2]].size()-1])
    return;
    if(v[x[0]][v[x[0]].size()-1]!=v[x[4]][0]) return;


    doit(x);

}

void recur()
{
    string y="012345";
    helper(y);
    while(next_permutation(y.begin(),y.end()))
    {
        helper(y);
    }
}

int main()
{
    //vector<string> v;
    forn(i,6)
    {
        string s;
        cin>>s;
        v.pb(s);
    }
    recur();
    forn(i,ans.size())
    cout<<ans[i]<<endl;
    if(ans.size()==0)
    cout<<"Impossible"<<endl;
}