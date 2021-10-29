#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;

int main(){
    int t;

    scanf("%d", &t);

    for(int test = 1 ; test <= t ; test++){
        int n;

        scanf("%d", &n);

        int ans = 0;
        int pref = 0;
        int last = 0;
        int hand = -1;

        for(int i = 0 ; i < n ; i++){
            char c;

            scanf("\n%c", &c);

            if(c == 'O'){
                if(hand != -1 && hand != 1){
                    pref += last;
                }

                last = i + 1;
                hand = 1;
            }else if(c == 'X'){
                if(hand != -1 && hand != 0){
                    pref += last;
                    last = i + 1;
                }
                
                last = i + 1;
                hand = 0;
            }

            if(pref >= mod){
                pref -= mod;
            }

            ans += pref;

            if(ans >= mod){
                ans -= mod;
            }
        }

        printf("Case #%d: %d\n", test, ans);
    }

    return 0;
}