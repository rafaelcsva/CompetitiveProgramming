#include <bits/stdc++.h>

using namespace std;

bool check(string &s){
    int cnt = 0;

    for(auto u: s){
        if(u == ')'){
            cnt--;
        }else{
            cnt++;
        }

        if(cnt < 0){
            return false;
        }
    }

    return cnt == 0;
}

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;
        string s;
    
        cin >> n;
        cin >> s;

        if(s[0] != '1'){
            cout << "NO\n";
            continue;
        }
    
        string t(n, '.'), p(n, '.');
    
        int lt = 0;
        vector< int > idx;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                if(lt){
                    t[i] = ')';
                    p[i] = '(';
                }else{
                    p[i] = ')';
                    t[i] = '(';
                }

                lt = !lt;
            }else{
                idx.push_back(i);
            }
        }

        // cout << p << " " << t << endl;

        for(int i = 0, j = int(idx.size()) - 1 ; i <= j ; i++, j--){
            p[idx[i]] = t[idx[i]] = '(';
            p[idx[j]] = t[idx[j]] = ')';
        }
        // cout << p << " " << t << endl;

        if(check(p) && check(t)){
            cout << "YES\n";
            cout << p << endl;
            cout << t << endl;
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}