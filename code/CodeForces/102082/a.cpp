//17, 02, 2019, 15:31:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

struct con{
    string s;
    char c;
};

vector< con > v, tmp;

vector< con > process(string &s){
    string f;
    vector< con > r;
    
    int carry = 0;
    bool have = false;
    int len = s.length();

    for(int i = 0 ; i < len ; i++){
        if('0' <= s[i] && s[i] <= '9'){
            f.push_back(s[i]);
            have = true;
        }else{
            if(have){
                r.push_back({f, 0});
                f = "";
                have = false;
            }

            r.push_back({"", s[i]});
        }
    }

    if(have){
        r.push_back({f, 0});
    }

    return r;
}

int is_str_number_lesser(string &a, string &b){
    
    if(a.length() < b.length()){
        while(a.length() != b.length()){
            a.insert(a.begin(), '0');
        }
    }else{
        while(b.length() != a.length()){
            b.insert(b.begin(), '0');
        }
    }

    int len = a.length();
    // cout << a << " " << b << endl;

    for(int i = 0 ; i < len ; i++){
        if(a[i] < b[i]){
            return 0;
        }else if(a[i] > b[i]){
            return 1;
        }
    }
    // cout << "are equals!" << endl;
    return -1;
}

bool is_lesser(vector< con > &d, vector< con > &f){
    for(int i = 0 ; i < min(d.size(), f.size()) ; i++){
        con a = d[i];
        con b = f[i];

        if(a.c && !(b.c)){
            return false;
        }else if(!(a.c) && b.c){
            return true;
        }else{
            if(a.c){
                if(a.c < b.c){
                    return true;
                }else if(a.c > b.c){
                    return false;   
                }
            }else{
                int val = is_str_number_lesser(a.s, b.s);
                // cout << val << endl;
                if(val == 0){
                    return true;
                }else if(val == 1){
                    return false;
                }
                // cout << "n retornei !!" << endl;
            }
        }
    }
    // cout << d.size() << " " << f.size() << endl;
    return d.size() < f.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    string s0;

    cin >> s0;

    v = process(s0);

    for(int i = 0 ; i < n ; i++){
        string s;

        cin >> s;

        tmp = process(s);

        if(is_lesser(tmp, v)){
            cout << '-' << endl;
        }else{
            cout << '+' << endl;
        }
    }

    return 0;
}