//20, 07, 2018, 16:52:47 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

string s;
stack< int > st;
const int N = 10000000;
int match[N];
const int ERROR = 1e9 + 7;

void process(){
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(i);
        }else if(s[i] == ')'){
            int f = st.top();

            match[f] = i;
            st.pop();
        }
    }
}

int number(int st, int en){
    int p = 0;
    bool is_negative = false;
    
    for(int i = st ; i <= en ; i++){
        if(s[i] == '-'){
            is_negative = true;
            continue;
        }

        if(s[i] >= '0' && s[i] <= '9'){
            p = p * 10 + int(s[i] - '0');
        }else{
            if(s[i] != '-')
                return ERROR;
        }
    }

    if(is_negative){
        p *= -1;
    }

    return p;
}

ld solve(int st, int en){
    if(en - st > 1){
        if(s[st] == '(' && s[st + 1] == '(' && match[st] == en){
            return solve(st + 1, en - 1);
        }
    }
    
    int r = number(st, en);

    if(r != ERROR){
        return r;
    }

    ld p = 0.0L;
    int j = 0;

    ld pp = 1.0L;
    j = st + 1;
    bool can = false;

    while(s[j] != ' '){
        if(can){
            pp *= 10;
        }
        
        if(s[j] != '.')
            p += int(s[j] - '0') / pp;

        if(s[j] == '.'){
            can = true;
        }

        j++;
    }

    j++;

    int stl = 0, enl = 0, str = 0, enr = 0;

    if(s[j] == '('){
        stl = j;
        enl = match[j];
        j = match[j] + 1;
    }else{
        stl = j;

        while(s[j] != ' '){
            j++;
        }

        enl = j - 1;
    }

    j++;

    if(s[j] == '('){
        str = j;
        enr = match[j];
    }else{
        str = j;

        while(s[j] != ')'){
            j++;
        }

        enr = j - 1;
    }
    
    ld n1 = solve(stl, enl), n2 = solve(str, enr);

    // cout << st << ' ' << en << ' ' << n1 << ' '<< n2 << ' ' <<  p * (n1 + n2) + (1.0L - p) * (n1 - n2) << ' ' << p << endl;

    return p * (n1 + n2) + (1.0L - p) * (n1 - n2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(getline(cin, s)){
        if(s == "()"){
            break;
        }

        process();

        cout << fixed << setprecision(2) << solve(0, int(s.length()) - 1) << endl;
    }

    return 0;
}