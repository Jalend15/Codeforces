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
	 priority_queue <ll,vector<ll>,greater<ll> > q;
	 q.push(1);
	 ll count=0;
	 while(1)
	 {
	 	ll y=q.top();
	 	if(y>n)
	 		break;
	 	++count;

	 	q.pop();
	 	if(y%10==0)
	 	{
	 	//	cout<<y+1<<endl;
	 		q.push(y+1);
	 	}
	 	q.push(y*10);
	 	//cout<<y<<endl;

	 }

	 cout<<count<<endl;
}
