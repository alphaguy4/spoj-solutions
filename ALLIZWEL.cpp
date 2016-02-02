#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define si(i) scanf("%d",&i)
#define sch(c) scanf("%c",&c);
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define fs first
#define sc second
using namespace std;
int n,m;
char arr[104][105];
int visited[104][104];
vector <pair<int,int> > va; // contains position of A's
int xi[8] = {-1,-1,-1,0,0,+1,+1,+1};
int yi[8] = {0,+1,-1,-1,+1,0,-1,+1};
char pat[10]= {'A','L','L','I','Z','Z','W','E','L','L'};
bool flag;
bool valid(int x,int y)
{
  if( x > -1 && x<n && y >-1 && y < m)
  {
    if(!visited[x][y])
      return true;
  }
  return false;
}
void dfs(int x,int y,int start)
{
  if(start>9)
  {
    flag = true;
    return;
  }
  FOR(i,0,8)
  {
    //cout << pat[start] << " " << X << " " << Y << endl;
    int X = xi[i] + x;
    int Y = yi[i] + y;
    if(valid(X,Y))
    {
      if(arr[X][Y] == pat[start])
      {
          visited[X][Y] = 1;
          dfs(X,Y,start+1);
          visited[X][Y] =0;
  //        cout << pat[start] << " " << X << " " << Y << endl;
      }
    }
  }
}
void well()
{
  int l = va.size();
  FOR(i,0,l)
  {
    if(!visited[va[i].fs][va[i].sc])
      dfs(va[i].fs,va[i].sc,1);
    if(flag)
      break;
  }
}
int main()
{
  int t;
  si(t);
  while(t--)
  {
    va.clear();
    si(n);si(m);
    flag = false;
    memset(visited,0,sizeof(visited));
    FOR(i,0,n)
    {
      FOR(j,0,m)
      {
        cin >> arr[i][j];
        if(arr[i][j] == 'A')
          va.pb(mp(i,j));
      }
    }
    well();
    if(!flag)
    cout << "NO" << endl;
    else
    cout << "YES" << endl;
  }
  return 0;
}
