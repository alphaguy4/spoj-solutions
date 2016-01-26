#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define si(a) scanf("%d",&a)
using namespace std;
struct node
{
  int num;
  int f;
}array[100004];
int arr[100005];
int max(int a,int b)
{
  return a > b ? a : b;
}
void construct(int ss ,int s,int e)
{
  if(s==e)
  {
    array[ss].f =1;
    array[ss].num = arr[s];
    return;
  }
  int m = (s+e)/2;
  construct(2*ss,s,m);
  construct(2*ss+1,m+1,e);
  if(array[2*ss].num == array[2*ss+1].num)
  {
    array[ss].f = array[2*ss].f + array[2*ss+1].f;
    array[ss].num = array[2*ss].num;
  }
  else
  {
    if(array[2*ss].f > array[2*ss+1].f)
    {
      array[ss].f = array[2*ss].f;
      array[ss].num = array[2*ss].num;
    }
    else
    {
      array[ss].f = array[2*ss+1].f;
      array[ss].num = array[2*ss+1].num;
    }
  }
}
int  query(int p,int qs,int qe,int ss,int se)
{
  if( qs > se || qe < ss )
      //cout << "1 " << ss << " " << se << endl;
      return -1;
  if(qs <= ss && qe >= se)
    {
      //cout << "2 " << ss << " " << se << endl;
      return array[p].f;
    }
  int m = (ss+se)/2;
  return max(query(2*p,qs,qe,ss,m),query(2*p+1,qs,qe,m+1,se));
}
int main()
{
  int n,q,a,b;
  while(1)
  {
    si(n);
    if(n==0)
      break;
    si(q);
    FOR(i,1,n+1)
    si(arr[i]);
    construct(1,1,n);
  //  FOR(i,1,10)
    //	cout<< array[i].num << array[i].f << endl;
    while(q--)
    {
      si(a);si(b);
      int ans = query(1,a,b,1,n);
      cout << ans << endl;
    }
  }
  return 0;
}
