//24, 05, 2018, 10:10:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
string s = "";

int main(){
    int n;

    while(cin >> n){
        if(n == 0)
            break;

        int sum = 0;
        int tn = n;
        s = "";
        
        while(n){
            s += char(n % 2 + '0');
            sum += n % 2;
            n /= 2;
        }

        reverse(s.begin(), s.end());

        cout << "The parity of "<< s <<" is " << sum << " (mod 2)." << endl; 
    }

    return 0;
}