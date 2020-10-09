//Link : https://codeforces.com/problemset/problem/1327/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

int a[N];

struct myq{
  set<pair<int,int> > waitQueue;
  set<pair<int,int> > workerQueue;
  ll sum = 0;
  void push(pair<int,int> r,int k) {
    waitQueue.insert(r);
    while(workerQueue.size()<k && waitQueue.size()>0) {
      pair<int,int> u = *prev(waitQueue.end());
      waitQueue.erase(u);
      workerQueue.insert(u);
      sum += u.first;
    }
    while(workerQueue.size() >0 && workerQueue.size()==k && waitQueue.size()>0) {
      pair<int,int> maxWait = *prev(waitQueue.end());
      pair<int,int> minWork = *workerQueue.begin();
      if(minWork.first< maxWait.first) {
        waitQueue.erase(maxWait);
        workerQueue.erase(minWork);
        waitQueue.insert(minWork);
        workerQueue.insert(maxWait);
        sum += maxWait.first;
        sum -= minWork.first;
      } else {
        break;
      }
    }
  }
  void erase(pair<int,int> r,int k) {
    if(waitQueue.count(r)) {
      waitQueue.erase(r);
    }
    else if(workerQueue.count(r)) {
      workerQueue.erase(r);
      sum -= r.first;
    } else {
      assert(0);
    }
    while(workerQueue.size()<k && waitQueue.size()>0) {
      pair<int,int> u = *prev(waitQueue.end());
      waitQueue.erase(u);
      workerQueue.insert(u);
      sum += u.first;
    }
  }
};
void solve() {
  int n,len;
  scanf("%d %d", &n,&len);
  for(int i=0;i<n;++i) {
    scanf("%d ", &a[i]);
  }
  int k;scanf("%d ", &k);
  myq q[2];
  k = min(k,len);
  q[0].sum = q[1].sum = 0;
  ll curSum = 0;
  ll ret = 0;
  for(int i=0;i<len;++i) {
    curSum += a[i];
    if(a[i]<0) {
      q[0].push(make_pair(-a[i],i),k);
    } else if(a[i]>0) {
      q[1].push(make_pair(a[i],i),k);
    }
  }
  for(int i=0;i+len-1<n;++i) {
    //query
    ret = max(ret, abs(curSum));
    ret = max(ret, abs(curSum + 2*q[0].sum));
    ret = max(ret, abs(curSum - 2*q[1].sum));

    if(i+len==n) {
      break;
    }
    curSum -= a[i];
    if(a[i]<0) {
      q[0].erase(make_pair(-a[i],i),k);
    } else if(a[i]>0) {
      q[1].erase(make_pair(a[i],i),k);
    }
    if(i+len<n) {
      curSum += a[i+len];
      if(a[i+len]<0) {
        q[0].push(make_pair(-a[i+len],i+len),k);
      } else if(a[i+len]>0) {
        q[1].push(make_pair(a[i+len],i+len),k);
      }
    }
  }
  printf("%lld\n", ret);
}

int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
  using namespace std;
  int main()
  {
      int n,l;
      scanf("%d%d",&n,&l);int a[100000];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int k;scanf("%d",&k);
    long long m=-1e18;
    for(int sgn=0;sgn<=1;sgn++)
    {
        if(sgn==1)
            for(int i=0;i<n;i++)
            a[i]=-a[i];
            long long s=0;
            multiset<int>ps,ns;
            for(int i=0;i<n;i++)
            {
                if(a[i]>=0)s+=a[i];
                else if(ps.size()<k)
                {
                    ps.insert(a[i]);
                     s+=-a[i];
                }
                else if(k!=0&&a[i]<*(--ps.end()))
                {
                    ps.insert(a[i]);s+=-a[i];
                     int v=*(--ps.end());ps.erase(ps.find(v));
                     ns.insert(v);s-=-v;s+=v;
                }
                else
                {
                    ns.insert(a[i]);s+=a[i];
                }
                int j=i-l;
                if(j>=0)
                    if(a[j]>=0)
                    s-=a[j];
                    else if(ps.find(a[j])!=ps.end())
                    {
                    ps.erase(ps.find(a[j]));s-=-a[j];
                     if(!ns.empty()){
                     int v=*ns.begin();ns.erase(ns.find(v));
                      ps.insert(v);s-=v;s+=-v;}
                      }
                    else{ns.erase(ns.find(a[j]));
                          s-=a[j];
                          }
    
                      if(j>=-1&&s>m)m=s;}
                      }printf("%I64d\n",m);
    
    return 0;}