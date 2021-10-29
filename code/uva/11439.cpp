#include <bits/stdc++.h>

using namespace std;

const int M=500;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
struct_edge pool[M*M*2];
edge top=pool,adj[M];
int V,E,match[M],qh,qt,q[M],father[M],base[M];
bool inq[M],inb[M],ed[M][M];
int a[M][M];
int n;

void add_edge(int u,int v){
  top->v=v,top->n=adj[u],adj[u]=top++;
  top->v=u,top->n=adj[v],adj[v]=top++;
}

int LCA(int root,int u,int v){
  static bool inp[M];
  memset(inp,0,sizeof(inp));

  while(1){
    inp[u=base[u]]=true;
    if (u==root) break;
    u=father[match[u]];
  }
  while(1){
    if (inp[v=base[v]]) return v;
    else v=father[match[v]];
  }
}

void mark_blossom(int lca,int u)
{
  while (base[u]!=lca)
    {
      int v=match[u];
      inb[base[u]]=inb[base[v]]=true;
      u=father[v];
      if (base[u]!=lca) father[u]=v;
    }
}
void blossom_contraction(int s,int u,int v){
  int lca=LCA(s,u,v);
  memset(inb,0,sizeof(inb));
  mark_blossom(lca,u);
  mark_blossom(lca,v);
  if (base[u]!=lca)
    father[u]=v;
  if (base[v]!=lca)
    father[v]=u;
  for (int u=0;u<V;u++){
    if (inb[base[u]]){
      base[u]=lca;
      if (!inq[u])
        inq[q[++qt]=u] = true;
    }
  }
}
int find_augmenting_path(int s)
{
  memset(inq,0,sizeof(inq));
  memset(father,-1,sizeof(father));

  for (int i=0;i<V;i++) base[i]=i;
  inq[q[qh=qt=0]=s]=true;

  while (qh<=qt){
    int u = q[qh++];
    for (edge e=adj[u];e;e=e->n){
      int v = e->v;
      if (base[u]!=base[v]&&match[u]!=v){
        if ((v==s) || (match[v]!=-1 && father[match[v]]!=-1)){
          blossom_contraction(s,u,v);
        }else if (father[v]==-1){
          father[v] = u;
          if (match[v]==-1){
            return v;
          }
          else if (!inq[match[v]]){
            inq[q[++qt] = match[v]]=true;
          }
        }
      }
    }
  }
  return -1;
}

int augment_path(int s,int t)
{
  int u=t,v,w;
  while (u!=-1){
    v=father[u];
    w=match[v];
    match[v]=u;
    match[u]=v;
    u=w;
  }
  return t!=-1;
}

int edmonds()
{
    int matchc=0;
    memset(match,-1,sizeof(match));
    for (int u=0;u<V;u++){
      if (match[u]==-1){
        matchc+=augment_path(u,find_augmenting_path(u));
      }
    }

    top = pool;
    memset(adj, 0, sizeof adj);

    return matchc;
}

bool can(int mid){
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(a[i][j] >= mid){
                add_edge(i, j);
                // printf("edge(%d, %d)\n", i, j);
            }
        }
    }

    int r = edmonds();

    // printf("para %d temos %d\n", mid, r);

    return r == (n / 2);
}

int main(){
    int t;
    int cs = 1;

    scanf("%d", &t);

    while(t--){
      scanf("%d", &n);
      n = 1 << n;
      V = n;

      for(int i = 0 ; i < n ; i++){
          for(int j = i + 1 ; j < n ; j++){
              scanf("%d", &a[i][j]);
              a[j][i] = a[i][j];
          }
      }

      int lo = 0, hi = 1e9;
      int r = -1;

      while(lo <= hi){
          int mid = (lo + hi) >> 1;

          if(can(mid)){
              lo = mid + 1;
              r = mid;
          }else{  
              // printf("nao consegue!\n");
              hi = mid - 1;
          }
      }

      printf("Case %d: %d\n", cs++, r);
    }

    return 0;
}