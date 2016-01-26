#include<bits/stdc++.h>
using namespace std;
int prime[10005];
void sieve()
{
  for(int i=3;i*i<10005;i+=2)
  {
      if(!prime[i])
      for(int j=i*i;j<10005;j+=(i<<1))
        prime[i] = 1;
  }
}
void bfs(int a,int b)
{
  queue<int>q;
  for(int j=1;j<4;j++)
  {
    if(c)
    for(int i =0;i<10;i++)
    {

    }
  }
}
int main()
{
  int a,b,t;
  sieve();
  cin >> t;
  while(t--)
  {
    cin >> a >> b;
    bfs(a,b);
  }
  return 0;
}
