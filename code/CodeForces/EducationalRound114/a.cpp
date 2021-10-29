#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            string ans = "";

            for(int j = 0 ; j < i ; j++){
                ans += "()";
            }

            int rest = n - i;

            for(int j = 0 ; j < rest ; j++){
                ans.push_back('(');
            }

            for(int j = 0 ; j < rest ; j++){
                ans.push_back(')');
            }

            cout << ans << "\n";
        }
    }

    return 0;
}