//07, 02, 2019, 18:53:42 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

stack< pii > parser;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while(cin >> s){
        s.push_back('-');
        int n = s.length();

        int resp = -1;

        for(int i = 0 ; i < n - 1 ; i++){
            if(s[i] == '('){
                if(s[i + 1] == '*'){
                    parser.push({5, i});
                }else{
                    parser.push({1, i});
                }
            }else if(s[i] == '['){
                parser.push({2, i});
            }else if(s[i] == '{'){
                parser.push({3, i});
            }else if(s[i] == '<'){
                parser.push({4, i});
            }else if(s[i] == ')'){
                if(s[i + 1] == '*'){
                    if(parser.empty() || parser.top().first != 5){
                        resp = parser.top().second;
                        break;
                    }else{
                        parser.pop();
                    }
                }else{
                    if(parser.empty() || parser.top().first != 1){
                        resp = parser.top().second;
                        break;
                    }else{
                        parser.pop();
                    }
                }
            }else if(s[i] == ']'){
                if(parser.empty() || parser.top().first != 2){
                    resp = parser.top().second;
                    break;
                }else{
                    parser.pop();
                }
            }else if(s[i] == '}'){
                if(parser.empty() || parser.top().first != 3){
                    resp = parser.top().second;
                    break;
                }else{
                    parser.pop();
                }
            }else if(s[i] == '>'){
                if(parser.empty() || parser.top().first != 4){
                    resp = parser.top().second;
                    break;
                }else{
                    parser.pop();
                }
            }
        }
    }   

    return 0;
}