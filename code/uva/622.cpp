//20, 07, 2018, 15:12:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 10000;
stack<int>pill;
int match[N];

bool is_forbidden(char c){
    return !((c >= '0' && c <= '9') || (c == '(' || c == ')') || (c == '+' || c == '*'));
}
void clear_pill(){
    while(!pill.empty()){
        pill.pop();
    }
}

bool try_parse(string &s){
    for(int i = 0 ; i < s.length() ; i++){
        if(is_forbidden(s[i])){
            clear_pill();

            return false;
        }

        if(s[i] == '('){
            pill.push(i);
        }else if(s[i] == ')'){
            if(pill.empty()){
                return false;
            }

            int f = pill.top();

            match[f] = i;
            pill.pop();
        }
    }

    return true;
}

ll getnumber(int st, int en, string &s){
    ll num = 0;

    for(int i = st ; i <= en ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + int(s[i] - '0');
        }else{
            return -1LL;
        }
    }

    return num;
}

int solve(int st, int en, string &s){
    if(st > en){
        return -1;
    }
    
    int open = 0;
    int pos = -1;

    for(int i = st ; i <= en ; i++){
        if(s[i] == '('){
            open++;
        }else if(s[i] == ')'){
            open--;
        }

        if(s[i] == '+' || s[i] == '*'){
            if(!open){
                if(pos == -1 || s[i] == '+')
                    pos = i;
            }
        }
    }

    if(pos != -1){
        ll lef = solve(st, pos - 1, s);
        ll rig = solve(pos + 1, en, s);
        
        if(lef == -1 || rig == -1){
            return -1;
        }

        if(s[pos] == '+'){
            return lef + rig;
        }else{
            return lef * rig;
        }
    }else{
        ll r = getnumber(st, en, s);

        if(r != -1){
            return r;
        }
        
        if(s[st] != '(' || match[st] != en){
            return -1;
        }

        return solve(st + 1, en - 1, s);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    
    cin >> t;

    while(t--){
        string s;

        cin >> s;

        if(try_parse(s)){
            ll r = solve(0, int(s.length()) - 1, s);

            if(r == -1LL){
                cout << "ERROR" << endl;
            }else{
                cout << r << endl;
            }
        }else{
            cout << "ERROR" << endl;
        }
    }

    return 0;
}