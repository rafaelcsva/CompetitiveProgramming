//12, 11, 2018, 12:36:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    string s;

    cin >> s;

    int r = n - 1;

    for(int i = 0 ; i < n - 1 ; i++){
        if(s[i] > s[i + 1]){
            r = i;
            break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(i != r){
            cout << s[i];
        }
    }

    cout << endl;

    return 0;
}