//28, 11, 2018, 08:58:49 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< int > prod;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        int n, k;

        cin >> n >> k;

        for(int i = 0 ; i < n ; i++){
            vector< int > tmp;

            for(int j = 0 ; j < 3 ; j++){
                int xi;

                cin >> xi;

                tmp.push_back(xi);
            }

            sort(tmp.begin(), tmp.end());
            prod.push_back(tmp[0]);
            prod.push_back(tmp[1]);
        }

        sort(prod.begin(), prod.end());

        int sum = 0;

        for(int i = 0 ; i < k ; i++){
            sum += prod[i];
        }

        cout << sum << endl;

        prod.clear();
    }

    return 0;
}