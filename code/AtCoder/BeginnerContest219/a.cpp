#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;

    cin >> x;

    if(x < 40){
        cout << 40 - x << "\n";
    }else if(x < 70){
        cout << 70 - x << "\n";
    }else if(x < 90){
        cout << 90 - x << "\n";
    }else{
        cout << "expert\n";
    }

    return 0;
}