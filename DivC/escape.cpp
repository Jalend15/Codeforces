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
 	string s;
 	cin>>s;
 	vector<ll> r;
 	vector<ll> l;
 	forn(i,s.size()) 	
 	{
 		if(s[i]=='l')
 			l.push_back(i+1);
 		else
 			r.push_back(i+1);
 	}
 	forn(i,r.size())
 	cout<<r[i]<<endl;
 	forn(i,l.size())
 	{
 		cout<<l[l.size()-i-1]<<endl;
 	}
 	//cout<<endl;
 }