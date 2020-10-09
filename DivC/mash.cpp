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
	ll n;
	ll k;
	cin>>n>>k;
	if(n==1)
	{
		if(k==0)
			cout<<"1"<<endl;
		else
			cout<<"-1"<<endl;
		return 0;
	}
	if(k<n/2)
	{
		cout<<"-1"<<endl;
		return 0;
	}

	ll x=k-(n-2)/2;
	cout<<x<<" "<<2*x<<" ";
	ll y=1;

	forn(i,(n-2)/2)
	{
		if(y!=x&&y+1!=2*x&&y!=2*x&&y!=x-1)
		{
			cout<<y<<" "<<y+1<<" ";
		}
		else
			--i;
		y+=2;
	}

	if(n%2!=0)
		cout<<"1000000000";


}