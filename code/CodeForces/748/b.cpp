#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        string num;

        cin >> num;

        reverse(num.begin(), num.end());

        bool f0 = false;
        bool f5 = false;

        int ans = int(1e9);
        
        for(int i = 0 ; i < num.length() ; i++){
            for(int j = i + 1 ; j < num.length() ; j++){
                int x = num[i] - '0' + (num[j] - '0') * 10;
            
                if(x % 25 == 0){
                    ans = min(ans, j - 1);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}