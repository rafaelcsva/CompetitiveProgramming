//17, 04, 2019, 17:50:20 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int a, b;

        cin >> a >> b;

        if(a < b) {
            cout << "Hamada" << endl;
        }else if(a == b){
            cout << "Iskandar" << endl;
        }else{
            cout << "Bashar" << endl;
        }
    }
    
    return 0;
}