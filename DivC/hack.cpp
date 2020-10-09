#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--) 

ll rem[1000007];

ll remainder(ll a,ll b)
{
	
}
int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	
	 char c;
	// cin>>c;
	 string s;
	 cin>>s;
	  vector<int> num(s.size());
	 for(ll i=0;i<s.size();i++)
	 {
	 	num[i]=(s[i]-'0');

	 }
	 ll n=num.size();
	 ll a,b;
	 cin>>a>>b;
	 int flag=0;
	 vector<ll> rema(n);
	 vector<ll> remb(n);
	 rema[0]=num[0]%a;
	 rem[0]=1;
	 for(ll i=1;i<=1000001;i++)
	 {
		 rem[i]= (rem[i-1]*10)%b;
		 
	 }
	// cout<<rem[2]<<endl;
	 fore(i,0,n-1)
	 {
	 	rema[i+1]=((rema[i]*10)+num[i+1])%a;
	 	
	 }
	 remb[n-1]=num[n-1]%b;
	 
	// cout<<remb[n-1];
	 for(ll i=n-2;i>=0;i--)
	 {
	 	unsigned ll y=((num[i])*rem[n-i-1]) %b;
	 	remb[i]=(remb[i+1]+y)%b;
	//	 cout<<rem[n-i-1]<<" ";
	 //	cout<<remb[i]<<endl;

	 }
	 ll ind=0;
	/* forn(i,n)
	 cout<<rema[i]<<" "; cout<<endl;
	 forn(i,n) cout<<remb[i]<<" ";cout<<endl;*/
	 fore(i,0,n-1)
	 {
	 	//cout<<rema[i]<<" "<<remb[i+1]<<endl;
	 	if(rema[i]==0&&remb[i+1]==0)
	 	{
	 		if(num[i+1]!=0)
	 		{
	 			flag=1;
	 			ind=i;
	 			break;
	 		}
	 	}
	 }
	 if(flag)
	 {
	 	cout<<"YES"<<endl;
	 	forn(i,ind+1)
	 	cout<<s[i];
	 	cout<<endl;
	 	for(ll i=ind+1;i<n;i++)
	 		cout<<s[i];
	 	cout<<endl;
	 }
	 else
	 	cout<<"NO"<<endl;

}