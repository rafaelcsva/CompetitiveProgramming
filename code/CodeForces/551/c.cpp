//13, 04, 2019, 11:28:23 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
int mark[N];
vector< int > idx;
stack< int > st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

    cin >> n;
    cin >> s;

    int open = 0;
    int close = 0;

    if((n & 1) || s[0] == ')' || s[n - 1] == '('){
        cout << ":(" << endl;
    }else{
        s[0] = '(';
        s[n - 1] = ')';

        for(int i = 1 ; i < n - 1 ; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    continue;
                }

                int u = st.top();
                st.pop();

                s[u] = '(';
                mark[u] = 1;
                mark[i] = 1;
            }
        }
        
        while(!st.empty()){
            st.pop();
        }

        for(int i = 1 ; i < n - 1 ; i++){
            if(!mark[i]){
                idx.push_back(i);
            }
        }   

        if((idx.size()) & 1){
            cout << ":(" << endl;
        }else{
            int closed = 0;

            for(int i = 0 ; i < idx.size() ; i ++){
                int u = idx[i];

                if(s[u] == ')'){
                    closed++;
                }
            }
            
            int sum = 0;

            for(int i = 0 ; i < idx.size() ; i++){
                int u = idx[i];

                if(s[u] == '('){
                    sum++;
                }else if(s[u] == ')'){
                    sum--;
                    closed--;
                }else{
                    if(sum - closed <= 0){
                        s[u] = '(';
                        sum++;
                    }else{
                        s[u] = ')';
                        sum--;
                    }
                }

                if(sum < 0){
                    cout << ":(" << endl;
                    return 0;
                }
            }

            if(sum == 0)
                cout << s << endl;
            else
                cout << ":(" << endl;
        }
    }

    return 0;
}