#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--) 

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
	return (abs(a.first)+abs(a.second))<(abs(b.first)+abs(b.second));
}

int main()
{

	ll n;
	cin>>n;
	vector< pair<ll ,ll > > v(n);
	forn(i,n)
	{
		ll x;
		ll y;
		scanf("%lld %lld",&x,&y);
		v[i].first=x;
		v[i].second=y;
	}
	sort(v.begin(),v.end(),comp);

	//cout<<v[1].second;
	ll move=0;
	forn(i,n)
	{
		if(v[i].first!=0)
			move+=2;
		if(v[i].second!=0)
			move+=2;
		move+=2;
	}
	printf("%lld\n",move );
	forn(i,n)
	{
		ll x=v[i].first;
		ll y=v[i].second;
		if(abs(x)) printf("1 %lld %c\n", abs(x), x>0?'R':'L');
		if(abs(y)) printf("1 %lld %c\n", abs(y), y>0?'U':'D');
		printf("2\n");
		if(abs(x)) printf("1 %lld %c\n", abs(x), x>0?'L':'R');
		if(abs(y)) printf("1 %lld %c\n", abs(y), y>0?'D':'U');
		printf("3\n");


	}

}	