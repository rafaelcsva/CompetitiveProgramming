//06, 05, 2018, 11:08:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

map<string, int>mp;

int main(){
    int n;
    string s;

    cin >> n >> s;

    int ans = 0;
    string r;

    for(int i = 0 ; i < n - 1 ;i++){
        string a = s.substr(i, 2);
        
        mp[a]++;

        if(mp[a] > ans){
            ans = mp[a];
            r = a;
        }
    }

    cout << r << endl;

    return 0;
}