//USING BFS
//Bipartite graph.
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
bool bfs(vector <int> v[],int n)
{
   int visited[2015] = {0};
   int gender[2015] = {0}; // No GENDER assigned INITIALLY
   queue <int> q;
   for(int k=1;k<=n;k++)
 {
   if(visited[k])
   	continue;
   q.push(k);     
   gender[k] = 1;
   while(!q.empty())
   {
      int f = q.front();
      int G = gender[f];
      visited[f] = 1;
      q.pop();
      for(int i=0;i<v[f].size();i++)
      {
	
	if(visited[v[f][i]])
		continue;
	if(gender[v[f][i]] == G)
        	return true;
	else
	{
         q.push(v[f][i]);
	    if(G == 1)
		gender[v[f][i]] = 2;
	    else
		gender[v[f][i]] = 1;
	}
      }
   }
 }
	return false; 
}
int main()
{
 int t,n,m,x,y,c=0;
 cin >> t;
 while(t--)
 {
  scanf("%d%d",&n,&m);
  vector <int> v[2015];
  for(int i = 0;i < m;i++)
  {
	scanf("%d%d",&x,&y);
	v[x].pb(y);
	v[y].pb(x);
  }
  if(bfs(v,n))
  printf("Scenario #%d:\nSuspicious bugs found!\n",++c);
  else
  printf("Scenario #%d:\nNo suspicious bugs found!\n",++c);
 }
 return 0;
}

