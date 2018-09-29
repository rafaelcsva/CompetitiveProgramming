//23, 07, 2018, 13:52:15 Rafaelcs cpp
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

    for(int test = 1 ; test <= t ; test++){
        if(test != 1){
            cout << endl;
        }    

        int n, m;

        cin >> n >> m;

        for(int p = 1 ; p <= m ; p++){
            if(p != 1){
                cout << endl;
            }

            for(int i = 1 ; i <= n ; i++){
                for(int j = 1 ; j <= i ; j++){
                    cout << i;
                }
                cout << endl;
            }
            for(int i = n - 1 ; i >= 1 ; i--){
                for(int j = 1 ; j <= i ; j++){
                    cout << i;
                }

                cout << endl;
            }
        }
        
    }

    return 0;
}