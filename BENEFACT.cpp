/*
problem : BENEFACT
user: kart123
algo : simple bfs 
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
int dist[50005];
int bfs(vector <pii > v[],int n)
{
	int vis[50005] = {0},ans,d=0;
	queue <int > q;
	q.push(n);
	dist[n] = 0;
	while(!q.empty())
	{
		int m = q.front();
		vis[m] = 1;
		q.pop();
		for(int i = 0;i < v[m].size();i++)
		{
			int h = v[m][i].first;
			int w = v[m][i].second;
			if(!vis[h])
			{
				dist[h] = dist[m] + w;
				q.push(h);
			}
					
		}
		if (d < dist[m])
		{
			d = dist[m];
			ans = m;
		}
	}
	return ans;
}
int main()
{
 int t,n,a,b,c;
 cin >> t;
 while(t--)
 {
    cin >> n;
    vector <pair<int,int> > v[n+9];
    for(int i=0;i<n-1;i++)
    {
	cin >> a >> b >> c;
	v[a].pb(mp(b,c));
	v[b].pb(mp(a,c));
    }
  //  memset(dist,0,sizeof(dist));
    int start =  bfs(v,1);
    int end = bfs(v,start);
    cout << dist[end] << endl;	
 }
 return 0;
}

