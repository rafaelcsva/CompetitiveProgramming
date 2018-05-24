//21, 05, 2018, 20:04:18 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

vector<ll>pol;
string s;

ll fastPow(ll num, int n){
    if(n == 0LL){
        return 1LL;
    }

    if(n == 1LL){
        return num;
    }

    ll r = fastPow(num, n / 2LL);
    r *= r;

    if(n % 2){
        r *= num;
    }

    return r;
}

void generate_pol(){
    ll pot = 1;
    ll num = 0;
    bool flag = false;

    for(int i = 0 ; i < s.length() ; i++){
        
        if(s[i] == '-'){
            
            flag = true;
            continue;
        }
        if(s[i] == ' '){
            if(flag){
                num *= -1LL;
            }
            pol.push_back(num);

            num = 0;
            pot = 1;
            flag = false;
        }else{
            num = num * 10LL + ll(s[i] - '0');
            pot *= 10LL;
        }
    }

    if(flag){
        num *= -1LL;
    }
    pol.push_back(num);
}

ll calc(ll num){
    ll r = 0LL;

    for(int i = 0 ; i < pol.size() ; i++){
        r += pol[i] * fastPow(num, int(pol.size() - i - 1));    
        // cout << num << "^" << int(pol.size() - i - 1) << " = " << fastPow(num, int(pol.size() - i - 1)) << endl;
    }

    return r;
}

int main(){
    
    while(getline(cin, s) && s.length()){
        generate_pol();

        string v;

        getline(cin, v);

        ll num = 0LL;
        ll pot = 1LL;

        bool flag = false;

        for(int i = 0 ; i < v.length() ; i++){
            if(v[i] == '-'){
                flag = true;
                continue;
            }

            if(v[i] == ' '){
                if(flag)
                    num *= -1LL;
                    
                cout << calc(num) << ' ';
                num = 0;
                pot = 1LL;
                flag = false;
            }else{
                num = num * 10LL + v[i] - '0';
                pot *= 10LL;
            }
        }

        if(flag){
            num *= -1LL;
        }
        
        cout << calc(num) << endl;
        pol.clear();
    }

    return 0;
}