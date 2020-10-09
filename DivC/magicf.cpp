
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
 #define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
	FASTIO
	ll n;
	cin>>n;
	vector<ll> a(n,0);
	forn(i,n)
	cin>>a[i];
	ll xora=0;
	forn(i,n)
	xora^=a[i];
	vector<ll> dora(n+1,0);
	dora[0]=0;
	dora[1]=1;
	for(ll i=2;i<=n;i++)
	{
		dora[i]=dora[i-1]^(i);
		//cout<<dora[i]<<" ";
	}
	//cout<<endl;




	forn(i,n)
	{
		//cout<<n/(i+1)<<endl;
		//cout<<xora<<" ";


		if((n/(i+1))%2==1)
		{
			////cout<<dora[i]<<" ";
			xora^=(dora[i]);
		}

		xora=xora^(dora[n%(i+1)]);
		//cout<<dora[n%(i+1)]<<endl;
		
	}
	cout<<xora<<endl;

}