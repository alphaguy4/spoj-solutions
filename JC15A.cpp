#include<bits/stdc++.h>
#define si(i) scanf("%d",&i)
#define sd(i) scanf("%lf",&i)
#define sch(i) scanf("\n%c",&i)
using namespace std;
int main()
{
  int flag=0;
  double start,end,cspeed,wspeed;
  char direction;
  sd(start);
  sd(end);
  sd(cspeed);
  sd(wspeed);
  sch(direction);
  double ans=0;
  if(direction == 'L')
    wspeed *= -1;
  if(end < start)
    cspeed *= -1;
  double dist = end-start;
  if(dist == 0)
  {
    printf("0.000000\n");
    return 0;
  }
  if(cspeed +wspeed == 0)
    flag=1;
  //cout << (end-start) << " " << (wspeed);
  ans = dist/(cspeed+wspeed);
  if(ans<0 || flag)
    printf("Impossible\n");
  else
    printf("%.6lf\n",abs(ans));
  return 0;
}
