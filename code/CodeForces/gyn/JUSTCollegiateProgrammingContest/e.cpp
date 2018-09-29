//28, 07, 2018, 16:46:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
const int MASK = (1 << 17);
const int N = 16;
int dp[N + 10][MASK];
int grid[N + 10][N + 10];
int n;
vector<pii>masks;

int sum_mask(int mask, int l){
    int sum = 0;

    for(int j = 0 ; j < n ; j++){
        int e = 1 << j;

        if(mask & e){
            sum += grid[l][j];
        }
    }

    return sum;
}

int sum_masks(int anti_mask, int mask, int l){
    int all_e = 1 << n;

    int best = 0;
    
    for(pii u : masks){
        int mask_1 = u.first;
        
        if(mask_1 >= all_e){
            break;
        }

        if((anti_mask & mask_1) == 0){
            best = max(best, dp[l][mask_1]);
        }
            
    }

    return best;
}

int test_mask(int mask){
    int anti_mask = 0;

    for(int i = 1 ; i < N ; i++){
        int e = 1 << i;
        int el = 1 << (i - 1);

        if((mask & e) && (mask & el)){
            return -1;
        }
    }

    for(int i = 0 ; i < N ; i++){
        int e = 1 << i;
        int rg = 1 << (i + 1);
        int lf = 1 << (i - 1);
        
        if(mask & e){   
            anti_mask |= e;

            if(i != N - 1){
                anti_mask |= rg;
            }

            if(i != 0){
                anti_mask |= lf;
            }
        }
    }

    return anti_mask;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    int last = (1 << N);

    for(int i = 0 ; i < last ; i++){
        int anti_mask = test_mask(i);
        
        if(anti_mask != -1){
            masks.push_back({i, anti_mask});
        }
    }
    
    while(t--){
        cin >> n;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> grid[i][j];
            }
        }

        int all_e = 1 << n;
        int best = 0;

        for(int l = 0 ; l < n ; l++){
            for(pii u : masks){
                int mask = u.first;
                int anti_mask = u.second;
                
                if(mask >= all_e){
                    break;
                }

                dp[l][mask] = sum_mask(mask, l);
                
                if(l != 0){
                    dp[l][mask] += sum_masks(anti_mask, mask, l - 1);
                }

                if(l == n - 1){
                    best = max(best, dp[l][mask]);
                }
            }
        }

        cout << best << endl;
    }
    
    return 0;
}