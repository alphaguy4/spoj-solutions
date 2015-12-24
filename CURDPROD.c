//Answer will be btw 1 and max(quality)*T
//Idea is to use binary search btw them
#include<stdio.h>
#define ll long long
int arr[10005]; // to store quality of each machine
ll check(int n,ll max)
{	int i;
	ll temp=0;
	for(i=0;i<n;i++)
	temp += (max/arr[i]);
	return temp;
}
ll binary_search(int n,int amt,ll max)
{
	ll mid,low = 1,high = max;
	while(low < high)
	{
	     	mid = low + (high-low)/2;
		ll tmp = check(n,mid);
		if(tmp < amt)
			low = mid + 1; 
		else
			high = mid;					
	}
	return high;
} 
int main()
{
 int t,n,T,i;
 scanf("%d",&t);
 while(t--)
 {	ll max = -1;
	scanf("%d%d",&n,&T);
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
		if(max < (ll)arr[i])
			max = (ll)arr[i];
	}
	max = max * T;
	//printf("%lld\n",max);
	printf("%lld\n",binary_search(n,T,max));
 }
 return 0;
}
