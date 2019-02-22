//15, 12, 2018, 10:04:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll sum = 0LL;

    string s;

    cin >> s;

    ll carry = 0LL;

    int n = s.length();

    for(int i = n - 1 ; i >= 0 ; i--){
        if(s[i] == 'W'){
            carry++;
        }else{
            sum += carry;
        }
    }

    cout << sum << endl;
    
    return 0;
}