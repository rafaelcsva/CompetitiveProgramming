#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6;
queue<int>a, b;

int main (){
    int n;

    cin >> n;

    int k1, k2;

    cin >> k1;

    for(int i = 0 ; i < k1 ; i++){
        int x;

        cin >> x;

        a.push(x);
    }

    cin >> k2;

    for(int i = 0 ; i < k2 ; i++){
        int x;

        cin >> x;

        b.push(x);
    }

    for(int g = 0 ; g < N ; g++){
        int xa = a.front();
        a.pop();
        int xb = b.front();
        b.pop();

        if(xa > xb){
            a.push(xb);
            a.push(xa);
        }else{
            b.push(xa);
            b.push(xb);
        }

        if(a.size() == 0){
            cout << g + 1 << ' ' << 2 << '\n';
            return 0;
        }else if(b.size() == 0){
            cout << g + 1 << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}