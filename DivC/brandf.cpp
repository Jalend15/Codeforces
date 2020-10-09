#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <set>
using namespace std;
 
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 7;
 
set<int>pre,ans;
int a[maxn];
     
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) 
    {
        cin>>a[i];
    }

     for(int i=1;i<=n;i++)
        {
        	set<int>temp;
            for(auto it:pre)
            {
                int f=it;
                ans.insert(f|a[i]);
                temp.insert(f|a[i]);
            }
           ans.insert(a[i]);
           temp.insert(a[i]);
           pre=temp;
        }
    cout<<ans.size();

	}