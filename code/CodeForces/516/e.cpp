//14, 10, 2018, 08:36:46 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    string first;

    cout << 0 << " " << 0 << endl;

    cin >> first;

    if(n == 1){
        cout << "0 1 1 0" << endl;
        return 0;
    }

    int x = 1;
    string s;
    int lox = 1, hix = 1e9;
    int loy = 1, hiy = 1e9;

    n--;

    while(n){
        int mid = (lox + hix) / 2;

        cout << mid << " 0" << endl;
        cin >> s; 

        n--;

        if(s != first){
            hix = mid - 1;
            break;
        }else{
            lox = mid + 1;
        }
    }

    while(n){
        int mid = (loy + hiy) / 2;

        cout << "0 " << mid << endl;
        cin >> s;

        n--;

        if(s != first){
            hiy = mid - 1;
        }else{
            loy = mid + 1;
        }
    }

    cout << "0 " << (loy + hiy) / 2 << " " << (lox + hix) / 2 << " 0" << endl;

    return 0;
}