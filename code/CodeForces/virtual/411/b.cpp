//25, 07, 2018, 16:28:56 Rafaelcs cpp
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

    for(int i = 0 ; i < n / 2 ; i++){
        if(i & 1){
            cout << "aa";
        }else{
            cout << "bb";
        }
    }

    int q = n / 2;

    if(n & 1){
        if(q & 1){
            cout << "a";
        }else{
            cout << "b";
        }
    }
    cout << endl;
    return 0;
}