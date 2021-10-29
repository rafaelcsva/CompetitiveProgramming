#include <bits/stdc++.h>
 
using namespace std;
 
vector< vector< int > > v;
 
bool solve(vector< int > a){
	for(auto e: v){
		int cnt = 0;
		for(int i = 0 ; i < e.size() ; i++){
			cnt += e[i] != a[i];
		}
		
		if(cnt > 2) return false;
	}
	
	return true;
}
 
int main(){
	int n, m;
 
	scanf("%d %d", &n, &m);
 
	for(int i = 0 ; i < n ; i++){
		vector< int > tmp;
		for(int j = 0 ; j < m ; j++){
			int sij;
 
			scanf("%d", &sij);
	
			tmp.push_back(sij);
		}
 
		v.push_back(tmp);
	}
 
    set< pair< int, int > > st;

	for(int i = 1 ; i < n ; i++){
        set< pair< int, int > > difs;
 
		for(int j = 0 ; j < m ; j++){
			if(v[0][j] != v[i][j]){
                difs.insert({j, v[i][j]});
			}
		}
 
		if(difs.size() >= 5){
			printf("No\n");
			return 0;
		}
 
		if(difs.size() >= 3){
            for(auto u: difs){
                st.insert(u);
            }
		}

        if(st.size() > 3){
            break;
        }
	}

    vector< pair< int, int > > difs;

    for(auto u: st){
        difs.push_back(u);
    }
	
    if(difs.size() > 0){
        for(int m = 0 ; m < (1 << (difs.size())) ; m++){
            vector< int > ti = v[0];

            for(int j = 0 ; j < difs.size() ; j++){
                int e = 1 << j;
                if(m & e){
                    ti[difs[j].first] = difs[j].second;
                }
            }
            
            if(solve(ti)){
                printf("Yes\n");
                for(auto u: ti){
                    printf("%d ", u);
                }
                printf("\n");
                return 0;
            }
        }

        printf("No\n");

        return 0;
    }
    
	printf("Yes\n");
	
	for(auto u: v[0]){
		printf("%d ", u);
	}
	printf("\n");
 
	return 0;
}