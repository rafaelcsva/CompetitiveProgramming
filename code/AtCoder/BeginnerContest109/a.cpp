#include <bits/stdc++.h>
    
using namespace std;
    
int main(){
    int a, b;
    cin >> a >> b;
    
    for(int i = 1 ; i <= 3 ; i++){
        if((a * b * i) & 1){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No\n";
    
}