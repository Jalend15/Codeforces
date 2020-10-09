#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--) 

int main()
{
	string s1;
	cin>>s1;
	int b,s,c;
	b=s=c=0;
	forn(i,s1.size())
	{
		if(s1[i]=='B')
			++b;
		if(s1[i]=='C')
			++c;
		if(s1[i]=='S')
			++s;

	}
	int nb,ns,nc;
	cin>>nb>>ns>>nc;
	int pb,pc,ps;
	cin>>pb>>ps>>pc;
	ll r;
	cin>>r;
	int c1,c2,c3;
	c1=c2=c3=1;
	if(b==0)
		c1=0;

	if(s==0)
		c2=0;
	if(c==0)
		c3=0;

	ll maxi=-1;
	for(ll i=0;i<=nb;i++)
	{
		for(ll j=0;j<=ns;j++)
		{
			for(ll k=0;k<=nc;k++)
			{
				ll number=(r+i*pb*c1+j*ps*c2+k*pc*c3)/(pb*b+ps*s+pc*c);
				if(b*number>=c1*i&&s*number>=c2*j&&c*number>=c3*k)
				{
					maxi=max(number,maxi);
				}
			}
		}
	}
	
	cout<<maxi<<endl;
}