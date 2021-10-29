#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

vector< vector< int > > pots;

vector< int > get_num(long long x){
    vector< int > ans;

    while(x){
        ans.push_back(x % 10);
        x /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    int t;

    ll d = 1;

    while(d < ll(2e18)){
        pots.push_back(get_num(d));
        d <<= 1LL;
    }

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        vector< int > num = get_num(n);

        int ans = int(1e9);

        for(auto pu: pots){
            int d = 0;
            int tmp = 0;

            for(int i = 0 ; i < num.size() ; i++){
                if(d >= pu.size() || pu[d] != num[i]){
                    tmp++;
                }else{
                    d++;
                }
            }

            tmp += int(pu.size() - d);
            ans = min(ans, tmp);
        }

        printf("%d\n", ans);
    }

    return 0;
}