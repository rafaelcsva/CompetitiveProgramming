
//01, 04, 2019, 17:29:10 Rafaelcs cpp
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

        int words_count = 1;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                words_count++;
            }
        }

        if(words_count > 7){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }

    return 0;
}