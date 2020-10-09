#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
 #define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	forn(i,n)
	cin>>a[i];
	ll found=0;
	sort(a.begin(),a.end());
	fore(i,1,n)
	{
		if(a[i]<=i&&a[i]!=1&&a[i]>a[i-1])
		{
			found=i;
		}
	}
	//cout<<found<<endl;
	if(found!=0)
	{
		cout<<a[n-1]<<endl;
	}
	else
	{
		ll add=a[0];
		ll no=a[0]%(n-1);
		vector<ll> a1;
		fore(i,1,n)
		{
			a1.push_back(a[i]-a[0]);

		}
		ll final=a1[n-2];
		forn(i,n-2)
		{
			
			add=add-(final-a1[i]);
			a1[i]=final;
		//	cout<<add<<endl;
		}

		if(add>0)
		{
			add=ceil((add*1.0)/(n-1));
		}
		//forn(i,n-1)
		//cout<<a1[i]<<": ";
		//cout<<a1[n-2];
		//cout<<add<<endl;
		if(add>0)
			a1[n-2]+=add;
		sort(a1.begin(),a1.end());
		cout<<a[0]+a1[n-2]<<endl;

	}
}