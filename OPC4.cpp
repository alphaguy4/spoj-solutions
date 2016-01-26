#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
vector<int> v[10005];
int visited[100005],n;
int bfs(int a)
{
	queue<pair<int,int> > q;
	q.push(a,0);
	int l;
	while(!q.empty())
	{
		int t = q.front().first;
		    l = q.front().second;
		q.pop();
		visited[t] = 1;
		for(int i=0;i<v[t].size();i++)
		{
			if(!visited[v[t][i]])
			{
				q.push(v[t][t],l+1);
			}
		}
	}
	return l;
	
}
int main()
{
	int t,a;
	cin >> t;
	while(t--)
	{
		v.clear();
		memset(visited,0,sizeof(visited));
		for(int i=1;i<=n;i++)
		{
			cin >> a;
			v[i].pb(a);
		}
		int a = bfs(1);
		int ans = bfs(a);
		printf("%d\n",ans);
	}
	return 0;
}