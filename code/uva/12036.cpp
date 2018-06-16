//30, 05, 2018, 13:30:10 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 110;
int qtd[N];

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        int n;

        cin >> n;
        
        bool ok = true;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int x;

                cin >> x;

                qtd[x]++;

                if(qtd[x] > n){
                    ok = false;
                }
            }
        }

        cout << "Case " << test << ": ";

        if(ok){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        memset(qtd, 0, sizeof qtd);
        
    }

    return 0;
}