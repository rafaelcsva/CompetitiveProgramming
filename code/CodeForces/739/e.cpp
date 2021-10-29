#include <bits/stdc++.h>

using namespace std;

int cnt[300];
int cnt_ans[300];

bool gen(string ans, vector< char > &del_seq, string &s){
    string r = ans;

    for(auto u: del_seq){
        string tmp = "";

        for(auto e: ans){
            if(e != u){
                tmp.push_back(e);
            }
        }

        r += tmp;
        ans = tmp;
    }

    // cout << r << " " << s << "\n";

    return r == s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        set< char > mark;
        vector< char > del_seq;

        for(int i = int(s.length()) - 1 ; i >= 0 ; i--){
            if(mark.find(s[i]) == mark.end()){
                del_seq.push_back(s[i]);
                mark.insert(s[i]);
            }

            cnt[s[i]]++;
        }

        int j = del_seq.size();
        bool frag = false;

        for(int i = 0 ; i < del_seq.size() ; i++){
            if(cnt[del_seq[i]] % j){
                frag = true;
            }
            cnt_ans[del_seq[i]] = cnt[del_seq[i]] / j;
            j--; 
        }

        string ans = "";

        for(int i = 0 ; i < s.length() ; i++){
            if(cnt_ans[s[i]]){
                ans.push_back(s[i]);
                cnt_ans[s[i]]--;
            }
        }

        reverse(del_seq.begin(), del_seq.end());

        if(!frag && gen(ans, del_seq, s)){
            cout << ans << " ";

            for(auto u: del_seq){
                cout << u;
            }
            cout << "\n";
        }else{
            cout << "-1\n";
        }

        memset(cnt, 0, sizeof cnt);

        memset(cnt_ans, 0, sizeof cnt_ans);
    }

    return 0;
}