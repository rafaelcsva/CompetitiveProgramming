//19, 07, 2018, 10:48:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<char, int>sig;

vector< string > break_conjuctions(string &s){
    vector<string>r;
    string tmp = "";

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '|'){
            r.push_back(tmp);
            tmp = "";
        }else if(s[i] != ')' && s[i] != '('){
            tmp += s[i];
        }
    }

    r.push_back(tmp);

    return r;
}

bool ok(string &s){
    int i = 0;

    while(i < s.length()){
        char c = s[i];
        
        if(c == '&'){
            i++;
            continue;
        }

        if(c == '~'){
            c = s[i + 1];

            if(sig[c] == 1){
                return false;
            }

            i = i + 2;
            sig[c] = -1;
        }else{
            if(sig[c] == -1){
                return false;
            }
            
            i++;
            sig[c] = 1;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;
    int now = 1;

    while(t--){
        string s;

        cin >> s;

        vector<string>conjuction = break_conjuctions(s);      

        bool flag = false;

        sig.clear();

        for(int i = 0 ; i < conjuction.size() ; i++){
            
            if(ok(conjuction[i])){
                cout << "YES" << endl;
                flag = true;
                break;
            }

            sig.clear();
        }

        if(!flag){
            cout << "NO" << endl;
        }
    }
    return 0;
}