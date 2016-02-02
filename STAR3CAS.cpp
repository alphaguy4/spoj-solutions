#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ps push
#define fs first
#define sc second
#define si(i) scanf("%d",&i)
#define FOR(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int n,arr[25],ans;
int visited[100];
bool check(int i)
{
  if(i>0 && i<=n)
    if(!visited[i])
      return true;
  return false;
}
void bfs()
{
  queue<pair<int,int> > q;
  q.ps(mp(1,0));
  while(!q.empty())
  {
    int p = q.front().fs;
    int r = q.front().sc;
    if(p == n)
    {
      if(ans > r)
        ans = r;
    }
    visited[p] = 1;
    q.pop();
    if(check(p+1))
      q.ps(mp(p+1,r+1));
    if(check(arr[p] + p))
      q.ps(mp(arr[p]+p,r+1));
  }
}
int main()
{
  int t;
  si(t);
  while(t--)
  {
    si(n);
    n+=1;
    FOR(i,1,n)
      si(arr[i]);
    memset(visited,0,sizeof(visited));
    ans = INT_MAX;
    bfs();
    cout << ans << endl;
  }
  return 0;
}
