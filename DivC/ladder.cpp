#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
#define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
std::vector<ll> vi(1000000);
int main()
{
	FASTIO
	ll n;
	ll m;
	cin>>n>>m;
	vector<ll> v(n);
	forn(i,n)
	cin>>v[i];
	vector<ll> r(n+1);
	vector<ll> l(n+1);
	//dp[0]=0;
	l[0]=0;

	for(ll i=1;i<n;i++)
	{
		if(v[i]<=v[i-1])
			l[i]=l[i-1];
		else
			l[i]=i;
	}
	r[n]=n;
	for(ll i=n-1;i>=0;i--)
	{
		if(v[i]<=v[i+1])
			r[i]=r[i+1];
		else
			r[i]=i;
	}
	
	while(m--)
	{
		ll l1,r1;
		cin>>l1>>r1;
		if(r[l1-1]>=l[r1-1])
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
}