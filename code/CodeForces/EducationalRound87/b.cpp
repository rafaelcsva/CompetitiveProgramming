#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        int mark[3];

        memset(mark, -1, sizeof mark);

        // cout << s << endl;
    
        int ans = -1;
    
        for(int i = 0 ; i < s.length() ; i++){
            int u = s[i] - '1';

            mark[u] = i;

            int best = -1;

            for(int d = 0 ; d < 3 ; d++){
                if(d == u) continue;

                if(mark[d] == -1){
                    best = -1;
                    break;
                }

                best = max(best, i - mark[d] + 1);
            }
            // cout << i << " gives " << best << "\n";

            if(best != -1){
                ans = (ans == -1) ? best : min(ans, best);
            }
        }

        cout << max(ans, 0) << "\n";
    }

    return 0;
}