//12, 10, 2018, 18:27:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 300;
bool is_semi_prime[N];

bool is_prime(int x){
    if(x == 1)
        return false;

    for(int i = 2 ; i < x ; i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    for(int i = 2 ; i < N ; i++){
        for(int j = 2 ; j < i ; j++){
            if(i % j == 0){
                if(is_prime(j) && is_prime(i / j) && j != (i / j)){
                    is_semi_prime[i] = true;
                    break;
                }else{
                    break;
                }
            }
        }
    }

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        bool ok = false;

        for(int i = 2 ; i < n ; i++){
            int a = n - i;

            if(is_semi_prime[a] && is_semi_prime[i]){
                ok = true;
                break;
            }
        }

        if(ok){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}