#include <bits/stdc++.h>

using namespace std;

int main(){
    for(int i = 0 ; i < 26 ; i++){
        int pi;

        cin >> pi;

        pi--;
        cout << char('a' + pi);
    }
    cout << "\n";
    return 0;
}