//20, 07, 2018, 16:25:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

vector< string > statement;
const int N = 1000000;
int match[N];
stack< int > st;

void proccess(){
    for(int i = 0 ; i < statement.size() ; i++){
        if(statement[i] == "IF"){
            st.push(i);
        }

        if(statement[i] == "ELSE"){
            int k = st.top();
            match[k] = i;

            st.pop();
            st.push(i);
        }

        if(statement[i] == "END_IF"){
            int k = st.top();
            match[k] = i;

            st.pop();
        }
    }
}

ll solve(int st, int en){
    if(statement.size() == 0)
        return 1;

    if(st >= en){
        return 1;
    }

    return (solve(st + 1, match[st] - 1) + solve(match[st] + 1, match[match[st]] - 1)) * solve(match[match[st]] + 1, en);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s;

        while(true){
            cin >> s;

            if(s == "ENDPROGRAM"){
                break;
            }

            if(s != "S")
                statement.push_back(s);
        }

        proccess();

        cout << solve(0, int(statement.size()) - 1) << endl;

        statement.clear();
    }    
    
    return 0;
}