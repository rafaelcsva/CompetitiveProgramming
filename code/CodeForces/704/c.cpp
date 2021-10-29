#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    string s, t;

    cin >> s >> t;

    stack< int > lf, rg;

    int ans = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == t[lf.size()]){
            if(lf.size()){
                ans = max(ans, i - lf.top());
            }
            lf.push(i);
        }
    }

    for(int i = m - 1 ; i >= 0 ; i--){
        lf.pop();
        int st = rg.size() ? rg.top() - 1 : n - 1;

        while(s[st] != t[i]){
            st--;
        }

        if(lf.size()){
            ans = max(ans, st - lf.top());
        }

        if(rg.size()){
            ans = max(ans, rg.top() - st);
        }

        rg.push(st);
    }

    cout << ans << "\n";

    return 0;
}