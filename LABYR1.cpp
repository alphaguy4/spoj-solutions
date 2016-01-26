//dfs
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define si(i) scanf("%d",&i)
#define sch(ch) scanf("\n%c",&ch)
#define FOR(i,j,k) for(int i=j;i<k;i++)
using namespace std;
vector < string > v;
int visited[1003][1003];
char arr[1003][1003];
int xi[4]={-1,1,0,0};
int yi[4]={0,0,-1,1};
int x,y,r,c;
bool check(int x,int y)
{
  if(x<r && y<c && x>=0 && y>=0)
  {
    if(arr[x][y] == '.' && visited[x][y] ==0)
      return true;
  }
  return false;
}
int dfs(int i,int j)
{
  if(visited[i][j])
    return 0;
  int ans=0;
  visited[i][j]=1;
  int bestx= i,besty =j;
  FOR(k,0,4)
  {
    int x2 = i + xi[k];
    int y2 = j + yi[k];
    if(check(x2,y2))
    {
      int base = dfs(x2,y2);
      if(ans < base)
        {
          ans = base;
          bestx = x;
          besty = y;
        }
    }
    x = bestx;
    y = besty;
  }
  return ans + 1;
}
int main()
{
  int t;
  string s;
  si(t);
  char ch;
  while(t--)
  {
    memset(visited,0,sizeof(visited));
    x=y=-1;
    si(c);si(r);
    FOR(i,0,r)
      FOR(j,0,c)
      {
        cin >> ch;
        if(ch == '.')
          {
          	arr[i][j]='.';
              x=i;
              y=j;
          }
        else
          arr[i][j] ='#';
      }
      int l = dfs(x,y);
      memset(visited,0,sizeof(visited));
    //  cout << x << " " << y;
          l = dfs(x,y)-1;
    cout << "Maximum rope length is " << l << "." << endl;
  }
  return 0;
}
