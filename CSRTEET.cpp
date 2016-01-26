/*
problem : CSTREET
user :kart123
algo : kruskal's with union-find Disjoint set to check loops
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
int parent[1005]; // for maintaining sets
int find(int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent[i]);
}
int Union(int x,int y)
{
	int x1 = find(x);
	int y1 = find(y);
	parent[x1] = y1;
}
using namespace std;
int main()
{
	int t,p,n,m,a,b,c;
	cin >> t;
	while(t--)
	{	int l = 0,vt=0;
		vector <pair<int ,pair<int,int> > > v;
		cin >> p >> n >> m;
		for(int i=0;i<m;i++)
		{
			cin >> a >> b >> c;
			v.pb(mp(c,mp(a,b)));
		}
		sort(v.begin(),v.end());
		memset(parent,-1,sizeof(parent));
		for(int i=0;i<m;i++)
		{
			int x = find(v[i].second.first);
			int y = find(v[i].second.second);
			if(x==y)
				continue;
			Union(x,y);
			l += v[i].first;
			vt++;
			if(vt == n-1)
			break;
		}
		cout << l*p << endl;		
	}	

 	return 0;
}
