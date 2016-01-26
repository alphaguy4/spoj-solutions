//AC CODE
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define si(i) scanf("%d",&i)
#define sd(j) scanf("%lf",&j)
using namespace std;
vector<pair<double,pair<double,double> > > v; // topheight and bottom and vol unit height
bool ok(int n,double v1,double l)
{
	double tl,bl,vl;
	double vol = 0.0;
	for(int i=0;i<n;i++)
	{
		tl = v[i].first;
		bl = v[i].second.first;
		vl = v[i].second.second;
		if(l<bl)
			continue;
		else
		if(l >= tl)
			vol+=((tl-bl)*vl);
		else
			vol+=((l-bl)*vl);

	}
	if(vol < v1)
		return false;
	else
		return true;
}
int main()
{
	int t,n;
	double v1,a,b,c,d;
	si(t);
	while(t--)
	{
		si(n);
		double low=0,high=0;
		double vol = 0;
		v.clear();
		for(int i=0;i<n;i++)
		{
			sd(a);sd(b);sd(c);sd(d);
			v.pb(mp(a+b,mp(a,c*d)));
			if(high < a+b)
				high = a+b;
			vol += (b*c*d); 
		}
		sd(v1);
		//cout << vol << " " << v1 << endl;
		if(vol < v1)
		{
			printf("OVERFLOW\n");
			continue;
		}
		double mid;
		int i = 64;
		while(i--)
		{
			mid = low + (high-low)/2.0;
			if(ok(n,v1,mid))
				high = mid;
			else
				low = mid; 
		}
		printf("%.2lf\n",mid);
	}
	return 0;
}
