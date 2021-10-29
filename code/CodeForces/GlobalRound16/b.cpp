#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        int n = s.length();
        int i = 0;
        int ans = 0;
    
        while(i < n){
            if(s[i] == '0'){
                ans++;
            }

            i++;

            while(i < n && s[i] == s[i - 1]){
                i++;
            }
        }

        printf("%d\n", min(ans, 2));
    }

    return 0;
}