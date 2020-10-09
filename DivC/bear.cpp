
#include "bits/stdc++.h" 
using namespace std; 

#define MAXN 10000001 

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--) 
#define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll spf[MAXN]; 
ll primeq[MAXN];
ll count1[MAXN];


int main() 
{ 
	// precalculating Smallest Prime Factor 
	FASTIO
	ll N=10000001;
	ll n;
	cin>>n;
	vector<ll> x(n);
	vector<bool> pr(N,true);
	
	forn(i,n)
	{
		cin>>x[i]; 
	 ++count1[x[i]]; 
    }



    for(ll i=2;i<=N;i++)
    {
    	if(pr[i])
    	{
    
    	for(ll j=i;j<=(N);j+=i)
    	{
    		primeq[i]+=count1[j];
    		pr[j]=false;
    	}
    }
    }
    ll q;
    cin>>q;
    vector<ll> ans(10000001);
    forn(i,10000001)
    {
    	if(i==0)
    	{
    		ans[i]=0;
    		continue;
    	}
    	ans[i]=ans[i-1]+primeq[i];

    }
    while(q--)
    {
    	ll l,r;
    	cin>>l>>r;
    	if(r>=10000001&&l<=10000001)
    	{
    		cout<<ans[10000000]-ans[l-1]<<endl;
    		continue;
    	}
    	if(r>=10000001&&l>=10000001)
    	{
    		cout<<"0"<<endl;
    		continue;
    	}
    	if(r<=10000001&&l<=10000001)
    	{
    		cout<<ans[r]-ans[l-1]<<endl;
    	}


    }

 
	return 0; 
} 
