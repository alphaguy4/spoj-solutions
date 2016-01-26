//SPOJ TOPOSORT
#include<bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define pb(x) push_back(x)
const int MAX = 111111;
int M, N, indeg[MAX];
set< int >  s;
vector<int>g[MAX];
vector< int > order;
int cnt;
void topology() {
  int u, v;cnt=0;
  while(!s.empty()) {
    u = *s.begin();
    s.erase(s.begin());
    order.PB(u);
    cnt++;
    for(int i=0; i!=g[u].size(); i++) {
      v = g[u][i];
      indeg[v]--;
      if(!indeg[v]) s.insert(v);
    }
  }
}

int main() {
  int i, j, k, u, v;
  scanf("%d%d", &N, &M);
  for(i=0; i<M; i++) 
  {
    scanf("%d%d", &u, &v);
    g[u].pb(v);
    indeg[v] += 1;
  }
  for(i=1; i<=N; i++)
    if(!indeg[i])
      s.insert(i);
  topology();
  if(cnt!=N)
  {
    cout << "Sandro fails.";
    return  0;
  }
  printf("%d", order[0]);
  for(i=1; i<N; i++)
    printf(" %d", order[i]);
  printf("\n");
  return 0;
}