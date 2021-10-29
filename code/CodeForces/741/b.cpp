#include <bits/stdc++.h>

using namespace std;

set< int > non_prime;
const int N = 10100;
bool composite[N];

void sieve(){
    composite[1] = true;
    for(int i = 2 ;i < N ; i++){
        if(!composite[i]){
            for(int j = i + i ; j < N ; j += i){
                composite[j] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    int t;

    cin >> t;

    while(t--){
        int n;
        string s;

        cin >> n;
        cin >> s;

        int ans = -1;

        for(int i = 0 ; i < n ; i++){
            int d = s[i] - '0';

            if(composite[d]){
                ans = d;
                break;
            }
        }

        if(ans != -1){
            cout << "1\n" << ans << "\n";
            continue;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int l = s[i] - '0';
                int r = s[j] - '0';

                int num = l * 10 + r;

                if(composite[num]){
                    ans = num;
                    break;
                }
            }
            if(ans != -1) break;
        }

        if(ans != -1){
            cout << "2\n" << ans << "\n";
            continue;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    int l = s[i] - '0';
                    int m = s[j] - '0';
                    int r = s[k] - '0';
                
                    int num = l * 100 + m * 10 + r;

                    if(composite[num]){
                        ans = num;
                        break;
                    }
                }
                if(ans != -1){
                    break;
                }
            }
            if(ans != -1) break;
        }

        assert(ans != -1);
        if(ans != -1){
            cout << "3\n" << ans << "\n";
            continue;
        }
    }

    return 0;
}