//25, 06, 2018, 15:57:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

bool test(int divisor, string &number){
    int r = 0;

    for(int i = 0 ; i < number.length() ; i++){
        int digit = number[i] - '0';

        r = (r * 10 + digit) % divisor;
    }

    return r == 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    string s;

    cin >> t;

    while(t--){
        cin >> s;

        int n;

        cin >> n;

        bool is_wonderfull = true;
        
        for(int i = 0 ; i < n ; i++){
            int x;

            cin >> x;

            is_wonderfull &= test(x, s);
        }

        cout << s << " - ";

        if(is_wonderfull){
            cout << "Wonderful." << endl;
        }else{
            cout << "Simple." << endl;
        }

    }

    return 0;
}