/*
PROBLEM :EPALIN
User :kart123
Algo : KMP(FAILURE FUNCTION)
HINTS : its give length of longest palindromic sequence in input string...
*/
#include<bits/stdc++.h>
using namespace std;
int psa[1000005];
int failure(string str,int n)
{
	//cout << str << endl;
	int i=1,len=0,l;
	//cout << str.size() << " and n = " << n << endl;
	psa[0]=0;
	while(i<n)
	{
		if(str[len] == str[i])
		 	len++,psa[i]=len,i++;
		else
		{
			if(len!=0)
				len = psa[len-1];
			else
				psa[i]=0,i++;
		}
	}
        return psa[n-1];
}
int main()
{
 string str;
 while(cin >> str)
{
	string str2 = str;
	reverse(str2.begin(),str2.end());
	int n = str.size();
	int p = failure(str2 + '#' + str,2*n+1);
	//cout << p <<endl;
	cout << str;
	for(int i=p;i<n;i++)
	cout << str2[i];
	cout << endl;
}
 return 0;
}
