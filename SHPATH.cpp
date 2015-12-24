/*
Problem: SHPATH OR TSHPATH
user: kart123
Algo : Djisktra shortest-path
*/
#include<bits/stdc++.h>
#define pb push_back
#define psi pair<string,int>
#define pii pair<int,int>
#define mp make_pair
#define INF 10000000
int dist[10005];
bool vis[10005];
using namespace std;
int main()
{
  int t,n,r,p,ocity,tcost,start,end;
  cin >>t;
  //map <string ,int > m[10004];
  char city[100];
  while(t--)
  {
     scanf("%d",&n);
     vector < pii > v[n+9];
     map <string ,int > m;
     map <string ,int > :: iterator it;
     for(int i=1;i<=n;i++)
     {
	scanf("\n%s",city);
	m.insert(mp(city,i));
	scanf("%d",&p);
	for(int j=1;j<=p;j++)
	{
		scanf("%d %d",&ocity,&tcost);
		v[i].pb(mp(tcost,ocity));
	}
     } 
	scanf("%d",&r);
	while(r--)
	{
		priority_queue <pii,vector<pii>,greater<pii> > Q;
		scanf("%s",city);
		it = m.find(city);
		start = (*it).second;
		scanf("%s",city);
		it = m.find(city);
		end = (*it).second;
		for(int i=0;i<=n;i++)
			vis[i]=false,dist[i] = INF;
		dist[start] = 0;
		Q.push(mp(0,start));
		while(!Q.empty())
		{
			int ui = Q.top().first;
			int vi = Q.top().second;
			Q.pop();
			if(vis[vi])
			continue;
			for(int i=0;i<v[vi].size();i++)
			{
				int w = v[vi][i].first;
				int q = v[vi][i].second;
				if(!vis[q] && dist[vi] + w < dist[q]){
					dist[q] = dist[vi] + w;
					Q.push(mp(dist[q],q));
				}	

			}
			vis[vi] = true;
			if(vi == end)
			break;
		}
		printf("%d\n",dist[end]);
	}
  }
		return 0;
}
