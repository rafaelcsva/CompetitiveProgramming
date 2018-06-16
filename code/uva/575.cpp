//24, 05, 2018, 10:03:57 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    string s;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> s){
        if(s == "0"){
            break;
        }

        int i = s.length();
        int sum = 0;

        for(int j = 0 ; j < s.length() ; j++, i--){
            sum += ((1 << i) - 1) * (s[j] - '0');
        }

        cout << sum << endl;
    }

    return 0;
}