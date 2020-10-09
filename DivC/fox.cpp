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
	 vector<ll> v(n);
	 ll cnt[101];
	 forn(i,101)
	  cnt[i]=0;
	 forn(i,n)
	 {

	 	cin>>v[i];
	 	++cnt[v[i]];
	 	} 
	 sort(v.begin(),v.end());
	 ll count=cnt[v[0]];
	 ll num=v[0];
	 priority_queue<ll> q;

	 priority_queue<ll> q1;
	 for(ll i=0;i<n;i++)
	 {
	 	int flag=0;

	 	while(q.empty()!=true)
	 	{
	 		if(flag==0&&q.top()<=v[i])
	 		{
	 			ll y=q.top()+1;
	 			q.pop();
	 			q1.push(y);
	 			flag=1;
	 		}
	 		else
	 		{
	 			ll y=q.top();
	 			q1.push(y);
	 			//q1.push(1);
	 			q.pop();
	 		}
	 	}
	 	if(flag==0)
	 		q1.push(1);
	 	q=q1;
	 	while(q1.empty()!=true)
	 		q1.pop();
	 }
	 cout<<q.size()<<endl;
	/* while(q.empty()!=true)
	 {
	 	cout<<q.top()<<" ";
	 	q.pop(); 
	 }*/
}