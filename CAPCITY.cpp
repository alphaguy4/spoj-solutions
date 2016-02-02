/*user:kart123
  problem:Capcity
  algo : SCC
  */
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MAX 100005
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define si(i) scanf("%d",&i)
using namespace std;
int visited[MAX];
int indeg[MAX];
stack <int> s;
vector <int> graph[MAX];
vector <int> rgraph[MAX];
int comp[MAX];
void __init__(int n)
{
  FOR(i,0,n+1)
    visited[i] = indeg[i] =0;
}
void dfs2(int n,int c)
{
  visited[n] = 0;
  comp[n] =c;
//  cout << n << " ";
  int l = rgraph[n].size();
  FOR(i,0,l)
  {
    if(visited[rgraph[n][i]])
      dfs2(rgraph[n][i],c);
  }
}
void dfs1(int x)
{
  visited[x] = 1;
  int l = graph[x].size();
  FOR(i,0,l)
  {
    if(!visited[graph[x][i]])
      dfs1(graph[x][i]);
  }
  s.push(x);
}
int main()
{
  int n,m,a,b;
  si(n);si(m);
  __init__(n);
  FOR(i,0,m)
  {
    si(a);si(b);
    rgraph[a].pb(b);
    graph[b].pb(a);
  }
  FOR(i,1,n+1)
    if(!visited[i])
      dfs1(i);
  int c=0;
  while(!s.empty())
  {
    if(visited[s.top()])
      {
        dfs2(s.top(),c++);
      }
    s.pop();
  }
  FOR(i,1,n+1)
  {
    FOR(j,0,graph[i].size())
    {
      if(comp[i] != comp[graph[i][j]])
        indeg[comp[graph[i][j]]]++;
    }
  }
  int count=0;
  FOR(i,0,c)
    if(!indeg[i])
      count++;
  if(count>1)
    printf("0\n");
  else
  {
    count=0;
    FOR(i,1,n+1)
      if(!indeg[comp[i]])
        count++;
    cout << count << endl;
    FOR(i,1,n+1)
      if(!indeg[comp[i]])
        cout << i << " ";
    cout << endl;
  }
  return 0;
}
