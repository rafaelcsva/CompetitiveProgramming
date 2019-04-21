//17, 04, 2019, 17:57:05 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int b1, p1, b2, p2;

        cin >> b1 >> p1 >> b2 >> p2;

        if(b2 == 0 && b1 != 0){
            cout << "HaHa" << endl;
            continue;
        }else if(b1 == 0 && b2 != 0){
            cout << "Congrats" << endl;
            continue;
        }else if(b1 == 0 && b2 == 0){
            cout << "Lazy" << endl;
            continue;
        }

        double a = p1 * log(b1);
        double b = p2 * log(b2);

        if(fabs(a - b) < eps){
            cout << "Lazy" << endl;
        }else if(a - b > eps){
            cout << "HaHa" << endl;
        }else{
            cout << "Congrats" << endl;
        }
    }
    
    return 0;
}