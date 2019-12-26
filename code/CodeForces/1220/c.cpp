#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 10);
bool has[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    for(int i = 0 ; i < s.length() ; i++){
        bool ok = false;

        for(int k = 'a' ; k < s[i] ; k++){
            if(has[k]){
                ok = true;
                break;
            }
        }

        if(ok){
            cout << "Ann\n";
        }else{
            cout << "Mike\n";
        }

        has[s[i]] = true;
    }

    return 0;
}