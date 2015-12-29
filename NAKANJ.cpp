/*problem : NAKANJ
  user:kart123
  algo :BFS
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int ht[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int vt[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
int check(pii p) // to check position is in the range
{
	int x = p.first;
	int y = p.second;
	if( (x>=0 && x<8) && (y>=0 && y<8) )
		return 1;
	else
		return 0;
}
int bfs(int x,int y,int xf,int yf)
{	
	int vis[8][8] = {0};
	int flag = 0;
	map <pii ,int> d;
	queue <pii > q;
	q.push(mp(x,y));
	d[q.front()] = 0;
	vis[x][y] = 1;
	pii pair,pi;
	while(!q.empty())
	{	pair  = q.front();
		q.pop();
		for(int z=0;z<8;z++)
		{
			pi = mp(pair.first + ht[z],pair.second + vt[z]);
			if(check(pi))
			if(!vis[pi.first][pi.second])
			{
				if(pi.first == xf && pi.second == yf)
					flag = 1;
				vis[pi.first][pi.second] = 1;
				d[pi] = d[pair] + 1;
				q.push(pi);
			}	
		}

		if(flag)
			break;
	}
	return d[mp(xf,yf)];
}
int main()
{
	int x1,y1,x2,y2,t;
	string s1,s2;
	cin >> t;	
	while(t--)
	{
		cin >> s1 >> s2;
		x1 = s1[0] - 'a';
		x2 = s2[0] - 'a';
		y1 = s1[1] - '1';
		y2 = s2[1] - '1';
		if(x1 == x2 && y1 == y2)
		{
			cout << "0" << endl;
			continue;
		}
		//cout << x1 << x2 << y1 << y2;
		int ans = bfs(x1,y1,x2,y2);
		cout << ans << endl;
	}
	return 0;
}
