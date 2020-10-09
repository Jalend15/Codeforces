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
	 ll n;
	 cin>>n;
	 vector< vector<ll> > v(n,vector<ll> (n));
	 vector<ll> d1(2*n+1);
	 vector<ll> d2(2*n+1);
	 forn(i,2*n+1)
	 {
	 	d1[i]=0;
	 	d2[i]=0;
	 }
	 forn(i,n)
	 {
	 	forn(j,n)
	 	{
	 		cin>>v[i][j];
	 		d1[i+j]+=v[i][j];
	 		d2[j-i+n]+=v[i][j];
	 	}
	 }
	 vector< vector<ll> > d(n,vector<ll> (n));
	 ll sol1=-1;
	 ll sol2=-1;
	 ll i1=-1;
	 ll i2=-1;
	 ll j1=-1;
	 ll j2=-1;

	 forn(i,n)
	 {
	 	forn(j,n)
	 	{
	 		ll val=d1[i+j]+d2[j-i+n]-v[i][j];
	 		if((i+j)%2==0)
	 		{
	 			if(val>sol1)
	 			{
	 				i1=i;
	 				j1=j;
	 				sol1=val;
	 			}
	 		}
	 		else
	 		{
	 			if(val>sol2)
	 			{
	 				i2=i;
	 				j2=j;
	 				sol2=val;
	 			}
	 		}
	 		
	 	}
	 }

	 cout<<sol1+sol2<<endl;
	 cout<<i1+1<<" "<<j1+1<<" "<<i2+1<<" "<<j2+1<<endl;
}