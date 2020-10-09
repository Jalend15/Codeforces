#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
 #define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll recur(string s, ll i)
{

}


int main()
{
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	ll flag=0;
	char c= 'a'+p-1;
	ll ii=0;
	ll index=0;
	while(s[n-1-ii]==c&&ii<=n-1)
	{
		++ii;
	}

//cout<<ii<<endl;
	if(ii<=n-1)
	++s[n-1-ii];
	if(ii==n-1)
		flag=1;
	//cout<<s;
	for(ll i=n-1-ii;i>1;i--)
	{
		while(s[i]==s[i-1]||s[i]==s[i-2])
		{
			//cout<<s<<endl;
			if(s[i]==c)
			{
				break;
			}
			else
			{
				++s[i];
			}
		}
		if(s[i]!=s[i-1]&&s[i]!=s[i-2])
		{
			flag=1;
			index=i;
			break;
		}
		else
		{
			ll j=i-1;
			while(s[j]==(c))
			{
				--j;
			}
			//cout<<j;
			if(j==0)
				flag=1;
			++s[j];
			i=j+1;

		}

	}
	if(flag==0&&n>=2)
	{
	for(ll i=1;i>0;i--)
	{
		while(s[i]==s[i-1])
		{
			if(s[i]==c)
				break;
			else
				++s[i];
		}
		if(s[i]!=s[i-1])
		{
			flag=1;
			index=i;
			break;
		}

	}
	if(flag==0)
	{
		++s[0];
	}
}
if(flag==0)
{

//cout<<index<<endl;
	//cout<<s<<endl;
	cout<<"NO"<<endl;
}
else
{
//	cout<<index<<endl;
	if(index==n-1)
	cout<<s<<endl;
else
{
	string temp="";
	char c1;
	if(index>=1)
	c1=s[index-1];
	else
		c1='A';
	char c2='B';
	c2=s[index];
	temp+=c1;
	temp+=c2;
	//sort(temp.begin(), temp.end());
	if(c2=='a')
	{
		temp='a'+temp;
		if(c1=='b')
		{
			temp="cba";
		}
		else
		{
			temp="bca";
		}

	}
	else
	{
		if(c1!='a')
		{

			temp=temp+'a';
			if(c2=='b')
			{
				temp="acb";
			}
			else
			{
				temp="abc";
			}
		}
		else
		{
			if(c2=='b')
			{
				temp="cab";
			}
			else
			{
				temp="bac";
			}
		}
	}
	ll k=0;
	for(ll i=index+1;i<n;i++)
	{
		if(k==3)
		{
			k=0;
		}
		s[i]=temp[k++];
	}
	cout<<s<<endl;



}
}

}