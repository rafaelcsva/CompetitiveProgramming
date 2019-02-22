//08, 01, 2019, 13:52:13 Rafaelcs cpp
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
        string s, t;

        cin >> s >> t;

        int n = s.length();

        bool ok = true;
        int swaps = 0;
        int state = 0;
        int j = n - 1;

        for(int i = 0 ; i < n / 2 ; i++){
            char f = s[i];
            char se = s[j];

            if(state){
                swap(f, se);
            }

            if(t[i] == f && t[j] == se){
                j--;
                continue;
            }

            if(t[i] != f && t[i] != se || t[j] != f && t[j] != se){
                // cout << i << " " << j << endl;
                ok = false;
                break;
            }

            swaps++;
            state = !state;

            j--;
        }

        if(s[n / 2] != t[n / 2]){
            ok = false;
        }

        if(!ok){
            cout << -1 << endl;
        }else{
            cout << swaps << endl;
        }
    }   

    return 0;
}