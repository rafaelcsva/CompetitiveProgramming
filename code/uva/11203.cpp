//18, 07, 2018, 08:14:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int count_lasts(string &s, char c){
    int i = s.length() - 1;
    int cnt = 0;

    while(i >= 0){
        if(s[i] != c){
            return cnt;
        }

        cnt++, i--;
    }

    return cnt;
}

int count_start(string &s, char c){
    int i = 0;
    int cnt = 0;

    while(i < s.length()){
        if(s[i] != c){
            return cnt;
        }

        cnt++, i++;
    }

    return cnt;
}

int cnt_middle(string &s, char c){
    int i = 0;

    while(i < s.length() && s[i] != 'M'){
        i++;
    }

    int cnt = 0;
    i++;
    
    while(i < s.length() && s[i] == c){
        cnt++;
        i++;
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string s;

        cin >> s;

        bool ok = true;
        bool M = false, E = false;

        for(int i = 0; i < s.length() ; i++){
            if(s[i] != 'M' && s[i] != '?' && s[i] != 'E'){
                ok = false;
                break;
            }
            if(s[i] == 'M'){
                if(i == 0 || i == int(s.length() - 1) || M){
                    ok = false;
                    break;
                }

                if(s[i + 1] != '?'){
                    ok = false;
                    break;
                }

                M = true;
            }

            if(s[i] == 'E'){
                if(i == 0 || i == int(s.length() - 1) || E || !M){
                    ok = false;
                    break;
                }

                if(s[i + 1] != '?'){
                    ok = false;
                    break;
                }

                E = true;
            }
        }

        int r = count_lasts(s, '?');
        int m = cnt_middle(s, '?');
        int l = count_start(s, '?');

        if(ok && M && E && r >= 2){
            if(l + 1 + m - 1 == r){
                cout << "theorem" << endl;
            }else{
                cout << "no-theorem" << endl;
            }
            
        }else{
            cout << "no-theorem" << endl;
        }
    }
    return 0;
}