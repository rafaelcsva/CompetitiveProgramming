#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > sols;

void gen_alls(int d, int n, int l, int r, vector< int > v){
    if(d > n){
        sols.push_back(v);
        return;
    }

    for(int k = l ; k <= r ; k++){
        if(k == d) continue;

        v.push_back(k);
        gen_alls(d + 1, n, l, r, v);
        v.pop_back();
    }
}

void print_arr(vector< int > arr){
    for(auto u: arr){
        printf("%d ", u);
    }
}

int get_val(vector< int > arr){
    int ans = 0;

    for(int i = 1 ; i <= arr.size() ; i++){
        for(int j = i + 1 ; j <= arr.size() ; j++){
            if(arr[i - 1] + arr[j - 1] == i + j){
                ans++;
            }
        }
    }

    return ans;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n, l, r;

        scanf("%d %d %d", &n, &l, &r);
    
        vector< int > v;
        gen_alls(1, n, l, r, v);

        int mx = 0;
        for(auto u: sols){
            mx = max(mx, get_val(u));    
        }

        int tot = 0;

        for(auto u: sols){
            if(mx == get_val(u)){
                print_arr(u);
                printf(" has %d\n", get_val(u));
                tot++;
            }
        }

        printf("in total %d\n", tot);

        sols.clear();
    }

    return 0;
}