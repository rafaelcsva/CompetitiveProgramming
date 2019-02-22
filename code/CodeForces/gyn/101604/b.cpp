#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< pii > comm[2];

bool compar(pii &a, pii &b){
    int val1 = a.first - a.second;
    int val2 = b.first - b.second;

    return val1 > val2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        int ti, xi, yi;

        scanf("%d %d %d", &ti, &xi, &yi);

        comm[ti - 1].push_back({xi, yi});
    }

    sort(comm[0].begin(), comm[0].end(), compar);
    sort(comm[1].begin(), comm[1].end(), compar);
    
    bool ok = true;
    int si = 1, sj = 1;

    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < comm[i].size() ; j++){
            if(i){
                sj += comm[i][j].first;

                // if(sj <= 0){
                //     ok = false;
                //     break;
                // }

                sj -= comm[i][j].second;

                if(sj <= 0){
                    ok = false;
                    break;
                }
            }else{
                si += comm[i][j].first;

                // if(si <= 0){
                //     ok = false;
                //     break;
                // }

                si -= comm[i][j].second;

                if(si <= 0){
                    ok = false;
                    break;
                }
            }
        }

        if(!ok){
            break;
        }
    }

    if(ok){
        printf("YES\n(%d, %d)\n", si, sj);
    }else{
        printf("NO\n");
    }

    return 0;
}