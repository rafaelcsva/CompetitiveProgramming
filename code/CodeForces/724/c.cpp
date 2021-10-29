#include <bits/stdc++.h>

using namespace std;

map< pair< int, int >, int > cnt;

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

        int cntd = 0;
        int cntk = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'D'){
                cntd++;
            }else{
                cntk++;
            }

            int g = __gcd(cntd, cntk);

            cnt[{cntd / g, cntk / g}]++;
        
            cout << cnt[{cntd / g, cntk / g}] << " "; 
        }
        cout << "\n";

        cnt.clear();
    }

    return 0;
}