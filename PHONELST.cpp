/*
problem:DICT
user :kart123
algo:TRIE'd hard  + dfs make it easy
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int flag;
	int next[27];
}array[500005];
int allocated=1,visited[500005];
void insert(char s[])
{
	int i,cur=0;
	int l = strlen(s);
	for(i=0;i<l;i++)
	{
		if(array[cur].next[s[i] - 'a'] == 0)
		{
			array[cur].next[s[i] - 'a'] = allocated;
			cur = allocated;
			allocated++;
		}
		else
			cur = array[cur].next[s[i] - 'a'];
		if(i == l-1)
			array[cur].flag = 1;
	}
	return;
}
int findl(string s)
{
	int l = s.length();
	int al;
	int cur=0;
	for(int i=0;i<l;i++)
	{
		if(!array[cur].next[s[i]-'a'])
			return -1;
		cur = array[cur].next[s[i]-'a'];
		al = cur;
	}
	return al;
}
void find(string s,int cur)
{
	if(array[cur].flag == 1 && !visited[cur])
	{
		cout << s << endl;
		visited[cur] = 1;
		//printf("%s\n",s);
	}
	for(int i=0;i<26;i++)
	{
		if(array[cur].next[i] != 0)
		{
			s += (i+'a');
			find(s,array[cur].next[i]); // dfs
			s.resize(s.length() - 1);
			//s[-1]='\0';
		}
	}

	return;
}
int main()
{
	char word[100];
	int n,i,k;
	scanf("%d",&n);//cin >> n;
	memset(array,0,sizeof(array));
	memset(visited,0,sizeof(visited));
	for(i=0;i<n;i++)
	{
		scanf("\n%s",word);
		insert(word);
	}
	scanf("%d",&k);
	string word1;
	for(int i=1;i<=k;i++)
	{

		cin >> word1;
		printf("Case #%d\n",i);
		int last = findl(word1); // last -> last word allocations
		if(last == -1)
			printf("No match.\n");
		else
		find(word1,last);
	//	printf("%d\n",last);
	}
	return 0;
}