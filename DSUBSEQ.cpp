/*
problem : DSUBEQ
user : kart123
algo : bruteforce / dynamic-programming
*/
#include<bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
using namespace std;
int main()
{
  int t;
  char s[100005];
  ll dp[100005];
  cin >> t;
  while(t--)
  {	
	int last[256] = {0};  // to check the last occurence
	scanf("%s",s);
	int l =strlen(s);
	dp[0] = 1;
 	for(int i=0;i<l;i++)
	{
		dp[i+1] = (dp[i] * 2);
		if(last[s[i]]!=0)
			dp[i+1] = (dp[i+1] - dp[last[s[i]]-1] + MOD);
		dp[i+1] %= MOD;
		last[s[i]] = i+1;
  	//	cout << dp[i] << endl;
	}	
	cout << dp[l] << endl;
  } 
	return 0;
}
