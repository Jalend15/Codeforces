#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
int flag=0;
int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 ll n,cursor;
	 string s;
	 cin>>n>>cursor>>s;
	 --cursor;
	 if(cursor>=n/2)
	 {
	 	cursor=n-1-cursor;
	 	reverse(s.begin(),s.end());
	 }
	// cout<<s<<endl;
	 vector<int> v(n);
	 ll ind=-1;
	 ll count=0;
	 int flag=1;
	 if(n%2==1)
	 	v[n/2]=0;
	 ll sum=0;
	 forn(i,n/2)
	 {
	 	if(s[i]!=s[n-i-1])
	 	{
	 		int diff=s[i]-s[n-i-1];
	 		if(diff<0)
	 			diff=-diff;
	 		
	 		v[i]=v[n-i-1]=min(diff,26-diff);
	 		sum=sum+v[i];
	 	}
	 	else
	 		v[i]=v[n-i-1]=0;
	 }
	 //forn(i,n)
	// cout<<v[i]<<" ";
	 //cout<<endl;
	 ll l=cursor;
	 ll r=cursor;
	 forn(i,cursor)
	 {
	 	if(v[i]!=0)
	 	{
	 		l=i;
	 		break;
	 	}
	 }
	// cout<<r<<endl;
	 for(ll i=n/2-1;i>cursor;i--)
	 {
	 //	cout<<r<<endl;
	 	if(i==n/2)
	 		continue;
	 	if(v[i]!=0)
	 	{
	 		r=i;
	 		break;
	 	}

	 }
	// cout<<l<<" "<<r<<endl;
//
	 count=min(cursor-l+2*(r-cursor),(r-cursor)+2*(cursor-l));
	//cout<<count<<" "<<sum<<endl;
	 cout<<count+sum<<endl;

}