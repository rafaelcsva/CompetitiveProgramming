#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int a, b;
        string s;

        cin >> a >> b;
        cin >> s;

        int n = s.length();
        bool ok = true;

        int cnt[2];
        cnt[0] = cnt[1] = 0;

        for(int i = 0, j = n - 1 ; i <= j ; i++, j--){
            if(s[i] != '?' || s[j] != '?'){
                if(s[j] != '?' && s[i] != '?' && s[j] != s[i]){
                    ok = false;
                    break;
                }

                if(s[j] != '?'){
                    s[i] = s[j];
                }else{
                    s[j] = s[i];
                }
            }

            if(s[i] != '?'){
                cnt[s[i] - '0']++;


                if(j != i){
                    cnt[s[j] - '0']++;
                }
            }
        }

        if(!ok){
            cout << "-1\n";
        }else{
            a -= cnt[0];
            b -= cnt[1];

            if(a < 0 || b < 0){
                cout << "-1\n";
                continue;
            }

            for(int i = 0, j = n - 1 ; i <= j ; i++, j--){
                if(s[i] == '?'){
                    int cnt = 1 + (i != j);
                    if(a >= cnt){
                        s[i] = s[j] = '0';
                        a -= cnt;
                    }else if(b >= cnt){
                        s[i] = s[j] = '1';
                        b -= cnt;
                    }
                }
            }

            if(a == 0 && b == 0){
                cout << s << "\n";
            }else{
                cout << "-1\n";
            }
        }
    }

    return 0;
}