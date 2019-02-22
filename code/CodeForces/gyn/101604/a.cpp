#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< char > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin >> s;

    int n = s.length();

    for(int i = 0, j = n - 1 ; i < n / 2 ; i++, j--){
        if(s[i] != s[j]){
            v.push_back(s[i]);
            v.push_back(s[j]);
        }
    }

    sort(v.begin(), v.end());

    if(v.size() > 4){
        cout << "NO" << endl;
        return 0;
    }

    if(v.size() == 2){
        if((n & 1) && (v[0] == s[n / 2] || v[1] == s[n / 2])){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

        return 0;
    }

    if(v.size() == 0){
        cout << "YES" << endl;
        return 0;
    }

    if(v[0] == v[1] && v[2] == v[3]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}