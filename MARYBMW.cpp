#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back
#define MAX 50005
using namespace std;
vector< pair<ll,pair<int,int> > > v;
int parent[MAX];
int rank[MAX],n;
void __init__()
{
	for(int i=1;i<=n;i++)
	{
		parent[i] = i;
		rank[i] =0;
	}
}
int find(int x)
{
	while(x != parent[x])
	{
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
} 
void Union(int x1,int y1)
{
	if(rank[x1] > rank[y1])
	{
		parent[y1] = x1;
		rank[x1] = rank[x1] + rank[y1];
	}
	else
	{
		parent[x1] = y1;
		rank[y1] = rank[y1] + rank[x1];
	}
}
bool ok()
{
	int x = find(1);
	int y = find(n);
	if(x==y)
		return true;
	else
		return false;
}
bool check(int m)
{
	__init__();
	for(int i=0;i<m;i++)
	{
		int x = find(v[i].second.first);
		int y = find(v[i].second.second);
		
		if(x==y)
			continue;
		Union(x,y);
		if(ok())
		{
			cout << v[i].first << endl;
			return true;
		}
	}
	return false;
}
int main()
{
	int t,m,a,b;
	ll c;
	scanf("%d",&t);
	while(t--)
	{
		v.clear();
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %lld",&a,&b,&c);
			v.pb(mp(c,mp(a,b)));
		}
		sort(v.rbegin(),v.rend());
		if(!check(m))
			printf("-1\n");
	}
	return 0;
}
