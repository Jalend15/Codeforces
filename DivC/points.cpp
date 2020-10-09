#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
#define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll a[(ll)1e5+1];
int main()
{
	ll n;
	cin>>n;
	 ll d1=0;
	cin>>d1;
	//vector<ll> a(n);
	forn(i,n)
	{
    	cin>>a[i];
    	//cout<<a[i];
	}
 	unsigned ll ans=0;
 	 ll maxreach=0;
 	forn(i,n-2)
 	{

 		
 		maxreach=a[i]+d1;
 		//cout<<a[i];
 		//cout<<maxreach;
 		ll low=i+1;
 		ll high=n-1;
 		ll mid=low+(high-low)/2;
 		while(low<high)
 		{
 			//cout<<low<<" "<<high<<endl;
 			mid=low+(high-low)/2;
 			if(maxreach>=a[mid])
 			{
 				low=mid+1;
 			}
 			else
 				high=mid;
 			//cout<<low<<" "<<high<<endl;
 		}
 		mid=low+(high-low)/2;
 	if(high==low)
 	{
 		if(mid==n-1)
 		{
 			if(a[mid]<=maxreach)
 				mid=n-1;
 			else
 				mid=n-2;
 		}
 		else
 			mid=mid-1;
 		if(mid-i>=2)
 		{
 			unsigned ll num=mid-i;
 			ans+=((num)*(num-1))/2;
 		}
 	}
 	}	

 	printf("%llu\n",ans );
}