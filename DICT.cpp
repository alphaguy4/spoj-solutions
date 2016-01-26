#include<bits/stdc++.h>
#define pool 800000
using namespace std;
int allocation = 1;
struct trie
{
    int flag;
    int next[26];
} array[pool];
// -1 will be return when no prefix found or only prefix is there
int findl(char s[],int l)
{
    int cur =0;
    int al; // last letter's allocation
    for(int i=0; i<l; i++)
    {
        if(array[cur].next[s[i] - 'a'] == 0 )
            return -1;
        cur = array[cur].next[s[i]- 'a'];
        al = cur;
    }
    int i=25;
    while(i>-1)
    {
        if(array[cur].next[i] != 0) // if the prefix only the last one in a branch
            return al;
        i--;
    }
    return -1;
}
void find(char *s,int cur,int l)
{
    if(array[cur].flag == 1)
    {
        printf("%s\n",s);
    }
    for(int i=0; i<26; i++)
    {
        if(array[cur].next[i] != 0)
        {
            char *xx = s; 
            *(xx+l) = (i + 'a');
            *(xx+l+1) = '\0';
            //s += ( i + 'a' );
            find(xx,array[cur].next[i],l+1);
            //s[l]='\0'; //this is not required when using "string class" of c++
        }
    }
}
void insert(char s[])
{
    int cur =0;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(array[cur].next[s[i] - 'a'] == 0)
        {
            array[cur].next[s[i]-'a'] = allocation;
            cur = allocation;
            allocation++;
        }
        else
            cur = array[cur].next[s[i]-'a'];
        if(s[i+1] == '\0')
            array[cur].flag = 1;
    }
    return;
}
int main()
{
    int n,q;
    char s[32];
    scanf("%d",&n);
    memset(array,0,sizeof(array));
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        insert(s);
    }
    scanf("%d",&q);
    for(int i=1; i<=q; i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        int l = findl(s,len);
        printf("Case #%d:\n",i);
        if(l == -1)
            cout << "No match.\n";
        else if(array[l].flag == 1)
        {
            array[l].flag = 0;
            find(s,l,len);
            array[l].flag = 1;
        }
        else
            find(s,l,len);
    }
    return 0;
}
