//16, 10, 2018, 11:21:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin >> s;

    int n = s.length();

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){
        int open = 0, close = 0, quest = 0;
        int copen = 0;

        for(int j = i ; j < n ; j++){
            if(s[j] == ')'){
                if(copen)
                    copen--;

                close++;
            }

            if(s[j] == '('){
                open++;
                copen++;
            }

            if(s[j] == '?'){
                if(copen)
                    copen--;

                quest++;
            }

            if(close > (quest + open))
                break;

            int need = abs(close - open);

            if(need <= quest && !copen){
                int r = quest - need;

                if((r & 1) == 0){
                    // cout << i << " " << j << endl;
                    cnt++;
                }
            }
        }    
    }

    cout << cnt << endl;

    return 0;
}