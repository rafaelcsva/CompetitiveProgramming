//14, 07, 2018, 09:32:30 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

map<ll, int>mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        ull a, b, c, d;

        cin >> a >> b >> c >> d;

        if(a < b || b > d){
            cout << "No" << endl;
            continue;
        }
        
        if(abs(c - b) <= 1 || c > b){
            cout << "Yes" << endl;
        }else{
            a = a % b;
            d = d % b;

            if(d){
                ull x = (c - a + d) / d;

                if((a + d * x) % b > c){
                    cout << "No" << endl;
                }else{
                    cout << "Yes" << endl;
                }
            }else{
                if(a > c){
                    cout << "No" << endl;
                }else{
                    cout << "Yes" << endl;
                }
            }
        }
    }   

    return 0;
}