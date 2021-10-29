#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        string s;

        cin >> s;

        int lst = 0;
        vector< int > v;

        for(int i = 0 ; i < n ; i++){
            int d = s[i] - '0';
            int r = 0;

            if(lst == 1){
                if(d == 0){
                    r = 0;
                }else{
                    r = 1;
                }
            }else if(lst == 2){
                if(d == 0){
                    r = 1;
                }else{
                    r = 0;
                }
            }else{
                r = 1;
            }

            v.push_back(r);
            lst = (r + d);
        }

        // reverse(v.begin(), v.end());
        for(auto u: v){
            printf("%d", u);
        }
        printf("\n");
    }

    return 0;
}