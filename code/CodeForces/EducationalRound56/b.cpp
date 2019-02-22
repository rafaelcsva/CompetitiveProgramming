//15, 12, 2018, 12:40:15 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        int n = s.length();
        bool is_palindrome = true;

        for(int i = 0, j = n -1 ; i < n / 2 ; i++, j--){
            if(s[i] != s[j]){
                is_palindrome = false;
                break;
            }
        }

        if(!is_palindrome){
            cout << s << endl;
        }else{
            string resp = "-1";

            for(int i = 1 ; i < n ; i++){
                if(s[i] != s[i - 1]){
                    swap(s[i], s[i - 1]);
                    resp = s;
                    break;
                }
            }

            cout << resp << endl;
        }
    }

    return 0;
}