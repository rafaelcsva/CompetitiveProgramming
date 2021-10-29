#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        vector< int > odd;
        int ans = 0;
        int tn = n - 1;
    
        for(int i = 0 ; i < n ; i++){
            int ai;

            scanf("%d", &ai);

            if(ai & 1){
                odd.push_back(ai);
            }else{
                // printf("+%d\n", tn);
                ans += tn;
                tn--;
            }
        }

        for(int i = 0 ; i < odd.size() ; i++){
            for(int j = i + 1 ; j < odd.size() ; j++){
                if(__gcd(odd[i], odd[j]) > 1){
                    // printf("%d-%d\n", odd[i], odd[j]);
                    ans++;
                }
            }
        }

        odd.clear();

        printf("%d\n", ans);
    }

    return 0;
}