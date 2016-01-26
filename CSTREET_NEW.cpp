/*
problem : CSTREET
user :kart123
algo : kruskal's with union-find Disjoint set to check loops
 with find rank and path-compression.
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
int parent[1005]; // for maintaining sets
int rank[1005];
int find(int i)
{
	if(parent[i] == i)
		return i;
	return find(parent[i]);
}
int Union(int x,int y)
{
	int x1 = find(x);
	int y1 = find(y);
	if(rank[x1] < rank[y1])
		parent[x1] = y1;
	else	
	if(rank[x1] > rank[y1])
		parent[y1] = x1;
	else
	parent[y1] = x1,rank[x1]++;
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
		for(int i=0;i<1005;i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
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
