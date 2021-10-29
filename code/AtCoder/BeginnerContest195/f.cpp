#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const ll p[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

vector< ll > nums;
ll dp[(1 << 20) + 10][73];

bool can(int i, int msk, int &sub){
    auto num = nums[i];

    for(int i = 0 ; i < 20 ; i++){
        if(num % p[i] == 0){
            int e = 1 << i;
            if(msk & e){
                return false;
            }else{
                sub |= e;
            }
        }
    }

    return true;
}

ll solve(int i, int msk) {
    auto &ans = dp[msk][i];

    if(ans != -1){
        return ans;
    }

    // printf("aqui! %d %lu\n", i, nums.size());
    if(i == nums.size()){
        return ans = 1LL;
    }

    int sub = 0;
    ans = 0;
    if(can(i, msk, sub)){
        ans += solve(i + 1, msk | sub);
    }

    ans += solve(i + 1, msk);

    // printf("%d %lld\n", i, ans);

    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    ll a, b;

    scanf("%lld %lld", &a, &b);

    while(a <= b){
        nums.push_back(a);
        a++;
    }

    printf("%lld\n", solve(0, 0));

    return 0;
}