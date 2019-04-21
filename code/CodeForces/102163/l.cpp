//17, 04, 2019, 17:55:20 Rafaelcs cpp
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
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            int xi;

            cin >> xi;

            cout << __builtin_popcount(xi) << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}