#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
 #define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
vector<ll> bit_tree(2*1e6);
vector<ll> bit_tree2(2*1e6);
void add(ll value, ll idx)
{
	while(idx<bit_tree.size())
	{
		bit_tree[idx]+=value;
		bit_tree2[idx]+=value;
		idx+=(idx&(-idx));
	}
}

ll sum(ll which,ll idx)
{
	if(which==1)
	{
		ll sum=0;
		while(idx)
		{
			sum+=bit_tree[idx];
			idx-=(idx&(-idx));
		}
		return sum;
	}
	if(which==2)
	{
		ll sum=0;
		while(idx)
		{
			sum+=bit_tree2[idx];
			idx-=(idx&(-idx));
		}
		return sum;
	}

}


void add(ll which, ll idx, ll value)
{
	if(which==1)
	{
		while(idx<bit_tree.size())
		{
			bit_tree[idx]+=value;
			idx+=(idx&(-idx));
		}		
	}
	if(which==2)
	{
		while(idx<bit_tree2.size())
		{
			bit_tree2[idx]+=value;
			idx+=(idx&(-idx));
		}		
	}
}

ll pre_sum(ll k)
{
	return sum(1,k)*k-sum(2,k);
}

ll range_sum(ll l, ll r)
{
	return pre_sum(r)-pre_sum(l-1);
}

void update(ll val, ll l, ll r)
{
	add(1,l,val);
	add(1,r+1, -val);
	add(2,l,val*(l-1));
	add(2,r+1,-val*(r));
}
int main()
{
	ll n;
	cin>>n;

	vector<ll> v;
	v.push_back(0);
	//vector<ll> pre(4*1e5+1,0);
	//Fenwick_Tree_Sum(v) ;
	add(0,1);

	//n=1;
	ll currentidx=1;
	forn(i,n)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll a;
			ll x;
			cin>>a>>x;
			update(x,1,a);
		    double ans=pre_sum(currentidx)*1.0;
			//cout<<<<endl;
			ans=ans/(v.size()*1.0);
			printf("%0.9lf\n",ans );
		}
		if(t==2)
		{
			ll k;
			cin>>k;
			++currentidx;
			//add(k,currentidx);
			update(k,currentidx,currentidx);
			v.push_back(k);
		    double ans=pre_sum(currentidx)*1.0;
			//cout<<<<endl;
			ans=ans/(v.size()*1.0);
			//cout<<v.size();
			printf("%0.9lf\n",ans );

		}
		if(currentidx>=2)
		{
		if(t==3)
		{
			
			ll ki=pre_sum(currentidx)-pre_sum(currentidx-1);
			//add(-ki,currentidx);
			update(-ki,currentidx,currentidx);
			--currentidx;
			v.pop_back();
			double ans=pre_sum(currentidx+1)*1.0;
			//cout<<<<endl;
			ans=ans/(v.size()*1.0);
			printf("%0.9lf\n",ans );
		}
	}
		//forn(i,currentidx+2)
		//cout<<bit_tree[i]<<" ";

	}
}