//28, 07, 2018, 16:46:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
const int MASK = (1 << 17);
const int N = 17;
int dp[N][MASK];
int grid[N][N];
int n;
vector<int>masks;

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

int sum_masks(int mask, int l){
    int all_e = 1 << n;

    int best = 0;
    
    for(int mask_1 : masks){
        if(mask_1 >= all_e){
            break;
        }
        
        int tmp = 0;
        
        for(int j = 0 ; j < n ; j++){
            int e = 1 << j;
            int lf = 1 << (j - 1);
            int rg = 1 << (j + 1);
            
            if(mask_1 & e){
                if(mask & e){
                    tmp = -1;
                    break;
                }

                if(j){
                    if(mask & lf){
                        tmp = -1;
                        break;
                    }
                }
            
                if(mask & rg){
                    tmp = -1;
                    break;
                }
            }
        }

        if(tmp != -1){
            // if(best < dp[l][mask_1]){
            //     bitset<5>bs(mask), bs1(mask_1);

            //     cout << bs1 << " fit on " << bs << " adding " << dp[l][mask_1] << " on line (" << l << "," << l + 1 << ")" << endl;
            // }
            best = max(best, dp[l][mask_1]);
        }
            
    }

    return best;
}

bool test_mask(int mask){
    for(int i = 1 ; i < N ; i++){
        int e = 1 << i;
        int el = 1 << (i - 1);

        if((mask & e) && (mask & el)){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    int last = (1 << N);

    for(int i = 0 ; i < last ; i++){
        if(test_mask(i)){
            masks.push_back(i);
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
            for(int mask : masks){
                if(mask >= all_e){
                    break;
                }

                dp[l][mask] = sum_mask(mask, l);
                
                if(l != 0){
                    dp[l][mask] += sum_masks(mask, l - 1);
                }

                if(l == n - 1){
                    // if(dp[l][mask] == 49){
                    //     bitset<5>bs(mask);

                    //     cout << bs << " is the winner " << bs << endl; 
                    // }
                    best = max(best, dp[l][mask]);
                }
            }
        }

        cout << best << endl;
    }
    
    return 0;
}