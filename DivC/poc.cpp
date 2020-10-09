#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--) 

int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 ll n,m;
	 cin>>n>>m;
	 vector<string> v(n);
	 forn(i,n)
	 cin>>v[i];
	 vector<ll> vis(27);
	 forn(i,27)
	  vis[i]=0;
	 ll prod=1;

	 forn(i,m)
	 {
	 	ll sum=0;
	 	forn(j,n)
	 	{
	 		if(vis[v[j][i]-'A']==0)
	 		{
	 			vis[v[j][i]-'A']=1;
	 			++sum;
	 			//cout<<sum;
	 		}
	 	}
	 	prod=(prod*sum)%((ll)pow(10,9)+7);
	 		 forn(i,27)
	           vis[i]=0;
	 }
	 cout<<prod<<endl;

}