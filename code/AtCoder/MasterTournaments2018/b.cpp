//07, 07, 2018, 09:04:38 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int w;

    cin >> s >> w;

    string r = "";

    for(int i = 0 ; i < s.length() ; i++){
        if(i % w == 0){
            cout << s[i];
        }
    }

    cout << endl;
    
    return 0;
}