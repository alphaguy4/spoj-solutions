/* 
	problem :PARTY
	user :kart123
	algo:knapsack
*/
#include<bits/stdc++.h>
using namespace std;
int bal;
int max(int a,int b)
{
	return a > b ? a : b;
}
int knpsack(int W, int wt[], int val[], int n)
{
	int i, w;
	int dp[n+1][W+1];
	bal = 0;
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				dp[i][w] = 0;
			else 
			if (wt[i-1] <= w)
				dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
			else
				dp[i][w] = dp[i-1][w];
		}
	}
	int k = dp[n][W];
	for(int i=1;i<W;i++)
	{
		if(dp[n][i] == k)
		{
			bal = i;
			break;
		}
	}

return dp[n][W];
}
int main()
{
	int w,n;
	while(1)
	{
		cin >> w >> n;
		if(n==0 && w == 0)
			break;
		int wt[1000],val[1000];
		for(int i=0;i<n;i++)
		{
			cin >> wt[i] >> val[i];
		}
	//	sort(wt,val,n);
		int fun = knpsack(w,wt,val,n);
		cout << bal << " " << fun << endl;
	}
	return 0;
}