#include<bits/stdc++.h>
#define MAX 50003
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
int cnt,len,n;
vector <pair<ll,pair<int,int> > > v;
int parent[MAX];
int rank[MAX];
void __init__()
{
	for(int i=1;i<MAX;i++)
	{
			parent[i] = -1;
			rank[i] = 0;
	}
}
int find(int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent[i]);
}
void Union(int x,int y)
{
	int x1 = find(x);
	int y1 = find(y);
	parent[x1] = y1;
}
bool ok (ll m)
{
	__init__(); // initialising parent
	cnt=0;
	for(int i=0;i<len;i++)
	{	
		if(v[i].first < m)
			continue;
		int x = find(v[i].second.first);
		int y = find(v[i].second.second);
		if(x==y)
			continue;
		Union(x,y);
		cnt++;
	}
	if(cnt == n - 1)
		return true;
	else
		return false;
}
int main()
{
	int m,t,a,b;
	ll dist;
	cin >> t;
	while(t--)
	{	
		ll mdist = 0;
		v.clear();
		cin >> n >> m;
		for(int i=0;i<m;i++)
		{
			cin >> a >> b >> dist;
			v.pb(mp(dist,mp(a,b)));
			if(mdist < dist)
				mdist = dist;
		}
		sort(v.rbegin(),v.rend());
		len = v.size();
		ll low =1;
		ll high=mdist;
		while(low<high)
		{
			ll mid = low +(high-low)/2;
			if(ok(mid))
				low = mid;
			else
				high = mid-1;
		}
		if(cnt != n-1)
			cout << "-1" << endl;
		else
			cout << low << endl;
	}
	return 0;
}