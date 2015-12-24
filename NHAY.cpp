//KMP Implementation
#include<iostream>
#include<stdio.h>
using namespace std;
int patr[5000000];
void patt(string pat,int n)
{
  int len =0;
  patr[0]=0;
  int i=1;
  while(i<n)
  {
    if(pat[i] == pat[len])
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
		patr[i] = 0;
		i++;
	}
    }
  }
} 
void kmp(string pat,string text,int n)
{
   int i =0,j=0;
   while(text[i] != '\0')
   {
	if(pat[j] == text[i])
	{
		i++;
		j++;
	}
	if(j == n)
	{
		cout << i-j << endl;
		j = patr[j-1];
	}
	else
	if(text[i]!='\0' && pat[j] != text[i])
	{
		if(j!=0)
		{
			j = patr[j-1];
		}
		else
		 	i++;
	}
	
   }
}
int main()
{
 int t,l;
 string text,pat;
 while(scanf("%d",&l) != EOF)
 {
	cin >> pat;
	cin >> text;
	patt(pat,l);
	kmp(pat,text,l);
	printf("\n");
 }
 return 0;
}
