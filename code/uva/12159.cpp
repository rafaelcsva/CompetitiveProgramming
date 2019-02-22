#include <bits/stdc++.h>
 
using namespace std;
  
struct line{
	double a, b;	
};
 
struct tower{
	int x, y, p;	
};

const int N = 500;
vector< tower > line_pt;
vector< tower > towers, group1, group2;
vector< int > adj[N];
int match[N];
int vis[N];
const double EPS = 1e-9;

int take_dir(tower &t, line &l){
	double mpos = t.y;
	double posl = l.a * t.x + l.b;
 
	if(mpos - posl > EPS){
		return 1;
	}else{
		return 2;
	}
}

bool dfs(int u){
	if(vis[u]){
		return 0;
	}
 
	vis[u] = 1;
 
	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i];
 
		if(match[v] == -1 || dfs(match[v])){
			match[v] = u;
			return 1;
		}
	}
 
	return 0;
}
 
int main(){
	int n;
	int test = 1;
 
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			break;
		}
 
		for(int i = 0 ; i < n ; i++){
			int xi, yi, p;
 
			scanf("%d %d %d", &xi, &yi, &p);
 
			towers.push_back({xi, yi, p});
		}

		int a, b, r;
 
		scanf("%d %d %d", &a, &b, &r);
        a--, b--;

        line_pt.push_back(towers[a]);
        line_pt.push_back(towers[b]);

        if(line_pt[0].x > line_pt[1].x){
            swap(line_pt[0], line_pt[1]);
        }

		line l;
 
		int dx = line_pt[1].x - line_pt[0].x;
		int dy = line_pt[1].y - line_pt[0].y;
        bool ver_x = false;

        if(dx != 0){
            l.a = double(dy) / double(dx);
            l.b = line_pt[0].y - l.a * line_pt[0].x;
        }else{
            ver_x = true;
        }
        
		//printf("%lf %lf\n", l.a, l.b);
		for(int i = 0 ; i < towers.size() ; i++){
            if(i == a || i == b){
                continue;
            }

            int dir;

            if(ver_x){
                // assert(false);
                if(line_pt[0].x > towers[i].x){
                    dir = 1;
                }else{
                    dir = 2;
                }
            }else{
			    dir = take_dir(towers[i], l);
            }

			if(dir == 1){
				group1.push_back(towers[i]);
			}else{
				group2.push_back(towers[i]);
			}
		}
 
		if(group1.size() > group2.size()){
		//	printf("eh o de baixo!\n");
			swap(group1, group2);
		}
		// printf("%lu %lu\n", group1.size(), group2.size());
 
		for(int i = 0 ; i < group1.size() ; i++){
			for(int j = 0 ; j < group2.size() ; j++){
				int disx = abs(group1[i].x - group2[j].x);
				int disy = abs(group1[i].y - group2[j].y);
				int dis = disx * disx + disy * disy;

                if(group2[j].p == 0){
                    continue;
                }

				if(group1[i].p > group2[j].p && dis <= (r * r)){
                    // assert(group2[j].p != 0);
					adj[i].push_back(j);
					// printf("%d %d\n", i, j);
				}
			}
		}
 
		int mcbm = 0;
		memset(match, -1, sizeof match);
 
		for(int i = 0 ; i < group1.size() ; i++){
			memset(vis, 0, sizeof vis);
 
			if(dfs(i)){
				mcbm++;
			}
		}
 
		printf("Case %d: %d\n", test++, mcbm);
 
		for(int i = 0 ; i < group1.size() ; i++){
			adj[i].clear();
		}
 
		group1.clear();
		group2.clear();
		towers.clear();
		line_pt.clear();
	}
 
	return 0;
}