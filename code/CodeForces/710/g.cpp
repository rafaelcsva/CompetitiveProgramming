#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int cnt[N];
string s;
string t;

bool can(char u, int sz){
    int tmp[N];
    memset(tmp, 0, sizeof tmp);
    int i = 0;

    for(auto d: s){
        if(d == '-'){
            i++;
            continue;
        }

        if(d == u){
            break;
        }else{
            tmp[d - 'a']++;

            if(tmp[d - 'a'] == cnt[d - 'a']){
                // cout << u << ' ' << d << endl;
                return false;
            }
        }
        i++;
    }

    for(int j = 0 ; j < i ; j++){
        if(s[j] != '-'){
            cnt[s[j] - 'a']--;
            t[j] = s[j] = '-';
            // cout << "aqui!\n";
        }
    }

    s[i] = '-';

    for(int j = i + 1 ; j < s.length() ; j++){
        if(s[j] == u){
            cnt[s[j] - 'a']--;
            t[j] = s[j] = '-';
            // cout << " aqui!\n";
        }
    }

    return true;
}

int main(){
    int te;

    cin >> te;

    while(te--){
        cin >> s;

        t  = s;
    
        for(int i = 0 ; i < s.length() ; i++){
            cnt[s[i] - 'a']++;
        }

        set< char, greater< char > > st;

        for(int i = 0 ; i < s.length() ; i++){
            // t.push_back(s[i]);
            st.insert(s[i]);
        }

        while(!st.empty()){
            for(auto u: st){
                // cout << u << endl;

                if(can(u, st.size())){
                    // cout << u << " " << "taked" << endl;
                    st.erase(u);
                    break;
                }
            }
        }

        for(auto u: t){
            if(u != '-'){
                cout << u;
            }
        }
        cout << endl;
        memset(cnt, 0, sizeof cnt);
        // cout << s << " " << t << endl;
    }

    return 0;
}