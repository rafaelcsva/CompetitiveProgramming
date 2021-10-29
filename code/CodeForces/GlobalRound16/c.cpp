#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    
    cin >> t;

    while(t--){

        int n;

        cin >> n;
    
        string row1, row2;

        cin >> row1 >> row2;

        int cur = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(cur == 3){
                ans += 2;
                cur = 0;
            }
    
            int a = row1[i] - '0';
            int b = row2[i] - '0';
            int resi = (1 << a) | (1 << b);

            if(cur == 1){
                ans += resi;
                cur = resi == 1 ? 1 : 0;
            }else{
                cur |= resi;
            }
        }

        if(cur == 1){
            ans++;
        }else if(cur == 3){
            ans += 2;
        }

        printf("%d\n", ans);
    }

    return 0;
}