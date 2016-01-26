#include<stdio.h>
#include<string.h>
int patr[100004];
char arr[100005];
void failure(int l)
{
    int i=1;
    int len=0;
    patr[0]=0;
    while(i<l)
    {
      if(arr[i] == arr[len])
      {
        len++;
        patr[i++]=len;
      }
      else
      {
        if(len != 0)
        {
          len = patr[len-1];
        }
        else
        {
          patr[i++]=0;
        }
      }
    }
}
int main()
{
  while(1)
  {
    scanf("\n%s",arr);
    if(arr[0] == '*')
      break;
    int l = strlen(arr);
    failure(l);
    //cout << patr[l-1] << " " <<l<<endl   ;
    if(l % (l-patr[l-1])==0)
    {
      printf("%d\n",l/(l-patr[l-1]));
    }
    else
      printf("1\n");
  }
  return 0;
}
