#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
 #define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll n;
ll L;
vector<ll> v(30);

int main()
{
	FASTIO
	cin>>n;
	cin>>L;

	forn(i,n)
	{
		cin>>v[i];
	}
	forn(i,n-1)
	{
		v[i+1]=min(2*v[i],v[i+1]);
	}
	forn(i,n)
	cout<<v[i]<<" ";
	cout<<endl;
	long long ans = (long long) 4e18;
	ll sum=0;
	for(ll i=n-1;i>=0;i--)
	{
		int need=L/(1<<i);
		sum+=(long long)need*v[i];
		cout<<L<<" ";
		L-=need<<i;
		cout<<L<<endl;
		ans=min(ans,sum+(L>0)*v[i]);
		//cout<<L<<" ";
	}
	cout<<ans<<endl;
	return 0;

}

