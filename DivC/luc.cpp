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
	 ll x=n/7;
	 ll f=pow(10,9);
	 ll s=pow(10,9);
	 forn(i,x+1)
	 {
	 	ll rest=n-7*i;
	 	if(rest>=0&&rest%4==0)
	 	{
	 		//cout<<s<<" "<<f<<endl;
	 		if((i+(rest)/4)<s+f)
	 		{
	 		s=i;
	 		f=(rest/4);
	 		continue;
	 	}
	 	if((i+(rest)/4)==s+f)
	 	{
	 		if(i<s)
	 		{
	 			s=i;
	 			f=rest/4;

	 		}
	 		//break;
	 	}
	 	}
	 }
	 if(f==pow(10,9)||s==pow(10,9))
	 {
	 	cout<<"-1"<<endl;
	 	
	 }
	 else
	 {
	 //	cout<<s<<" "<<f<<endl;
	 forn(i,f)
	 cout<<"4";
	 forn(i,s)
	 cout<<"7";
	 cout<<endl;

}
}
