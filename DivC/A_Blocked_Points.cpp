#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n; 
void mainp()
{
    cin>>n;
    if(n==0) {cout<<1<<endl; return;}
    long long ans=0ll;
    int y=n, prev=n;
    for(int x=1; x<=n; x++)
    {
        while(x*1ll*x+y*1ll*y>n*1ll*n) y--;
        ans++;
        ans+=max(0, prev-y-1);
        prev=y;
    }
    
    cout<<ans*4<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mainp();
    return 0;
}