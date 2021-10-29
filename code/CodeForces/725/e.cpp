#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

map< string, pair< string, ll> > mp;

ll get_num(string val){
    ll cnt = 0LL;
    // cout << "in " << val << " found " << ": ";
    for(int i = 0 ; i <= int(val.length()) - 4 ; i++){
        if(val.substr(i, 4) == "haha"){
            cnt++;
        }
    }
    // cout << cnt << "\n";
    return cnt;
}

void insert(string var, string val){
    ll cnt = get_num(val);

    mp[var] = {val, cnt};
}

string get_merge(string v1, string v2){
    string p1 = "", p2 = "";

    if(v1.length() < 3){
        p1 = v1;
    }else{
        p1 = v1.substr(int(v1.length()) - 3);
    }

    if(v2.length() < 3){
        p2 = v2;
    }else{
        p2 = v2.substr(0, 3);
    }

    // cout << "bec " << p1 << " " << p2 << "\n";
    return p1 + p2;
}

string get_merge1(string v1, string v2){
    string p1 = "", p2 = "";

    if(v1.length() < 3){
        p1 = v1;
    }else{
        p1 = v1.substr(0, 3);
    }

    if(v2.length() < 3){
        p2 = v2;
    }else{
        p2 = v2.substr(int(v2.length()) - 3);
    }

    // cout << "bec " << p1 << " " << p2 << "\n";
    return p1 + p2;
}

void merge(string var, string v1, string v2){
    string res = get_merge(mp[v1].first, mp[v2].first);
    auto cnt = get_num(res) + mp[v1].second + mp[v2].second;

    mp[var] = {get_merge1(mp[v1].first, mp[v2].first), cnt};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;
        
        cin >> n;

        string last = "-1";

        for(int i = 0 ; i < n ; i++){
            string var;
            string attr;

            cin >> var >> attr;

            last = var;

            if(attr == ":="){
                string val;

                cin >> val;

                insert(var, val);
            }else{
                string var1, var2;
                string op;

                cin >> var1 >> op >> var2;

                merge(var, var1, var2);

                // cout << var << " becomes " << mp[var].first << " w/ " << mp[var].second << "\n";
            }
        }

        cout << mp[last].second << "\n";
        mp.clear();
    }

    return 0;
}