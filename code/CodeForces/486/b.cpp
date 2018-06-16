//01, 06, 2018, 11:41:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 110;
string s[N];

bool compar(string a, string b){
    return a.length() < b.length();
}

bool isSub(string a, string b){
    bool have = false;
    
    for(int i = 0 ; i <= int(a.length() - b.length()) ; i++){
        bool ok = true;

        for(int j = 0 ; j < b.length() ; j++){
            if(a[i + j] != b[j]){
                ok = false;
                break;
            }
        }

        have |= ok;
    }

    return have;
}

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }

    sort(s, s + n, compar);

    bool ok = true;

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(!isSub(s[i], s[j])){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    for(int i = 0 ; i < n ; i++){
        cout << s[i] << endl;
    }

    return 0;
}