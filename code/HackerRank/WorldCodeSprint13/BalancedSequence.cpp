//26, 05, 2018, 18:51:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

stack<char>ct;

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        char c;

        cin >> c;

        if(ct.size() && ct.top() == '(' && c == ')'){
            ct.pop();
        }else{
            ct.push(c);   
        }
        
    }

    int t1 = ct.size() / 2;
    int t2 = ct.size() / 2;
    bool v1 = false;
    int cnt = 0;

    while(t1--){
        char c = ct.top();
        ct.pop();

        if(c == '('){
            if(!v1){
                cnt++;
                v1 = true;
            }
        }else{
            v1 = false;
        }
    }

    bool v2 = false;

    while(t2--){
        char c = ct.top();
        ct.pop();

        if(c == ')'){
            if(!v2){
                cnt++;
                v2 = true;
            }
        }else{
            v2 = false;
        }

    }
    
    cout << cnt << endl;
    
    return 0;
}