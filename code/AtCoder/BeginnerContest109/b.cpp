//08, 09, 2018, 09:05:59 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

set< string > st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    char last;
    
    for(int i = 0 ; i < n ; i++){
        string s;

        cin >> s;

        if(st.find(s) != st.end()){
            cout << "No" << endl;
            return 0;
        }

        if(i != 0){
            if(s[0] != last){
                cout << "No" << endl;
                return 0;
            }
        }

        last = s[s.length() - 1];
        st.insert(s);
    }    

    cout << "Yes" << endl;
    
    return 0;
}