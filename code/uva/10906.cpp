//19, 07, 2018, 09:28:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
map<string, string>mp;
map<string, bool>is_addition;

bool is_number(char c){
    return c >= '0' && c <= '9';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        int n;

        cin >> n;

        string c, ig, a, op, b;

        for(int i = 1 ; i <= n ; i++){
            cin >> c >> ig >> a >> op >> b;

            if(op == "+"){
                is_addition[c] = true;
            }else{
                is_addition[c] = false;
            }

            string lf, rg;
            
            if(is_number(b[0])){
                rg = b;
            }else{
                if(!is_addition[c] || is_addition[b])
                    rg = "(" + mp[b] + ")";
                else    
                    rg = mp[b];
            }

            if(is_number(a[0])){
                lf = a;
            }else{
                if(!is_addition[c] && is_addition[a]){
                    lf = "(" + mp[a] + ")";
                }else
                    lf = mp[a];
            }
            
            mp[c] = lf + op + rg;
        }    

        cout << "Expression #"<< test << ": " << mp[c] << endl;
    }

    return 0;
}