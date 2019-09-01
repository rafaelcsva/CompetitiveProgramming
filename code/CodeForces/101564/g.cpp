#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 500;
 
set<pair<int,int> >graph[maxn];
 
struct dsu
{
    int rep[maxn];
    long long sz[maxn];
 
    void init(int n)
    {
        for(int i = 1 ; i <= n; i++)
        {
            rep[i] = i;
            sz[i] = 1;
        }
    }
 
    int find(int x)
    {
        return rep[x] = (rep[x] == x ? x : find(rep[x]));
    }
 
    void unio(int x, int y)
    {
        x = find(x);
        y = find(y);
 
        if(x != y)
        {
            if(sz[x] < sz[y])
                swap(x,y);
            rep[y] = x;
            sz[x] += sz[y];
        }
    }
}d;
 
struct edge
{
    int u,v,c;
    edge(int u , int v, int c) : u(u), v(v), c(c){}
 
    bool operator < (edge &e)
    {
        return c < e.c ;
    }
};
 
typedef long long ll;
 
ll min_edge;
pair<int,int>min_edge_ed;
ll mi_ed;

void dfs(int u, int target, int p, ll val, pair<int,int>ed)
{
    if(target == u)
    {
        min_edge = val;
        min_edge_ed = ed;
    }

    for(auto &v : graph[u])
    {
        mi_ed = min(mi_ed, ll(v.second));

        if(v.first == p)
            continue;
        if(val > v.second)
        {
            pair<int,int>p1;
            p1.first = u;
            p1.second = v.first;
            dfs(v.first, target, u, v.second, p1);
        }
        else
        {
            dfs(v.first, target, u, val, ed);   
        }
    }
}
 
vector<edge>edges;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        int m;
        scanf("%d",&m);
        for(int i = 0; i < maxn; i++)
            graph[i].clear();
        edges.clear();
        for(int i = 0; i < m; i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            u++,v++;
            edges.push_back(edge(u,v,c));

        }
        
        sort(edges.begin(),edges.end());
        d.init(n);
        ll ans = 1LL << 60;
        ll at = 0;
        int count = 0;
        ll mi = edges[0].c;
        for(int i = 0 ; i < edges.size(); i++)
        {
            if(d.find(edges[i].u) == d.find(edges[i].v))
            {   
                mi_ed = LLONG_MAX;
                min_edge = LLONG_MAX;
                pair<int,int>p(-1,-1);
                dfs(edges[i].u, edges[i].v, -1, (1LL << 60), p);
                assert(min_edge_ed.first != -1);

                auto d = graph[min_edge_ed.first].lower_bound({min_edge_ed.second, -1});
                graph[min_edge_ed.first].erase(d);

                d = graph[min_edge_ed.second].lower_bound({min_edge_ed.first, -1});
                graph[min_edge_ed.second].erase(d);
 
                graph[edges[i].u].insert({edges[i].v,edges[i].c});
                graph[edges[i].v].insert({edges[i].u,edges[i].c});
                mi = mi_ed;
            }
            else
            {
                d.unio(edges[i].u,edges[i].v);
                graph[edges[i].u].insert({edges[i].v,edges[i].c});
                graph[edges[i].v].insert({edges[i].u,edges[i].c});
                count++;
            }
            if(count >= n-1){
                mi_ed = LLONG_MAX;
                min_edge = LLONG_MAX;
                pair<int,int>p(-1,-1);
                dfs(edges[i].u, -1, -1, (1LL << 60), p);
                mi = mi_ed;
                ans = min(ans, abs(edges[i].c - mi));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}