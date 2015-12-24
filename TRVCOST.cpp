/*
PROBLEM : TRVCOST
user: kart123
Algo : Djisktra shortest-path
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define INF INT_MAX
int dist[5050];
bool vis[5050];
using namespace std;
int main()
{
	int n,p,q,cost,start,end;
	cin >> n;
	vector < pii > v[505];
	for(int i = 0;i<n;i++)
	{
		scanf("%d%d%d",&p,&q,&cost);
		v[p].pb(mp(cost,q));
		v[q].pb(mp(cost,p));
	}
	scanf("%d",&start);
	priority_queue <pii ,vector<pii >,greater <pii > > Q;
	for(int i = 0;i<1050;i++)
		vis[i] = false,dist[i] = INF;
	dist[start] = 0;
	Q.push(mp(0,start));
	while(!Q.empty())
	{
		int d = Q.top().first;
		int ui = Q.top().second;
		Q.pop();
		for(int i=0;i<v[ui].size();i++)
		{
			int vi = v[ui][i].second;
			int w = v[ui][i].first;
			if(!vis[vi] && w + dist[ui] < dist[vi]){
				dist[vi] = w + dist[ui];
				Q.push(mp(dist[vi],vi));
			}
		}
		vis[ui] = true;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&end);
		if(dist[end] != INF)
			printf("%d\n",dist[end]);
		else
			printf("NO PATH\n");
	}
		return 0;
}

