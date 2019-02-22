//24, 11, 2018, 07:27:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

double EPS = 1e-13;
const int N = 100;
ll cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        ll n, k;

        cin >> n >> k;

        ll squares = 1LL;

        while(k && n){
            if(squares > k){
                break;
            }

            k -= squares;
            n--;

            squares *= 4LL;
        }

        if(!k){
            cout << "YES" << " ";
            cout << n << endl;
            continue;
        }

        if(!n){
            cout << "NO" << endl;
            continue;
        }
        
        if(squares == 4LL){
            if(k == 2LL){
                if(n > 1){
                    cout << "YES" << " ";
                    cout << n << endl;
                }else{
                    cout << "NO" << endl;
                }
            }else if(k == 3LL){
                cout << "YES" << " ";
                cout << n - 1 << endl;
            }else{
                cout << "YES" << " ";
                cout << n << endl;
            }

            continue;
        }

        ll tn = n;
        ll have = squares - 7LL;

        while(k && n){
            if(have > k){
                break;
            }

            k -= have;
            have *= 4LL;

            n--;
        }

        if(n == 0LL && k != 0LL){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << " ";
        cout << tn << endl;
    }

    return 0;
}