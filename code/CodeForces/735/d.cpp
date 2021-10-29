#include <bits/stdc++.h>

using namespace std;

int cnt[30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    // cout << 'z' - 'a' << "\n";
    while(t--){
        int n;

        cin >> n;

        if(n <= 26){
            for(int i = 0 ; i < n ; i++){
                cout << char('a' + i);
            }
            cout << "\n";
            continue;
        }
    
        string ans = "";
        int letter = 0;

        memset(cnt, 0, sizeof cnt);

        while(true){
            if(letter >= 3 && __builtin_popcount(n - letter) <= letter && (((n - letter) & 1) == 0)){
                break;
            }

            // printf("inc on %d\n", letter);
            cnt[letter]++;
            letter++;
        }

        int e = 0;
        // printf("has %d\n", n - letter);
        for(int j = 0 ; j < 20 ; j++){
            if((n - letter) & (1 << j)){
                // printf("add %d on %d, %d\n", 1 << j, cnt[e], e);
                cnt[e] += (1 << j);
                e++;
            }
        }

        for(int i = 0 ; i < letter ; i++){
            for(int j = 0 ; j < (cnt[i] + 1) / 2 ; j++){
                ans.push_back(char('a' + i));
            }
        }

        for(int i = 0, j = letter - 2 ; i < letter ; i++,j--){
            int lt = ((j % letter) + letter) % letter;
            for(int j = 0 ; j < cnt[lt] / 2 ; j++){
                ans.push_back(char('a' + lt));
            }
        }
        assert(ans.length() == n);

        cout << ans << "\n";
    }

    return 0;
}
