#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
 #define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}
int main()
{
	ll n;
	cin>>n;
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}

	uint64_t prod=n*(n-1);

	uint64_t max1=prod;
	fore(i,1,n-1)
	{
		if(max1<prod*i/(gcd(i,prod)))
		{
			max1=prod*i/(gcd(i,prod));
		}
	}
	 prod=(n-1)*(n-2);
	 //max1=prod;
	fore(i,1,n-2)
	{
		if(max1<prod*i/(gcd(i,prod)))
		{
			max1=prod*i/(gcd(i,prod));
		}
	}
	printf("%"PRId64"",max1);


}