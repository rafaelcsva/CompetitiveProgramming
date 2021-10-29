#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, k;

    cin >> a >> b >> k;

    if(b == 1 || a == 0 || k == 0){
        if(k){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(int i = 0 ; i < b ; i++){
                cout << 1;
            }

            for(int i = 0 ; i < a ; i++){
                cout << 0;
            }
            cout << "\n";

            for(int i = 0 ; i < b ; i++){
                cout << 1;
            }

            for(int i = 0 ; i < a ; i++){
                cout << 0;
            }
            cout << "\n";
        }

        return 0;
    }
    string s = "", t = "";

    for(int i = 0 ; i < b ; i++){
        s.push_back('1');
    }

    for(int i = 0 ; i < a ; i++){
        s.push_back('0');
    }

    for(int i = 0 ; i < b - 1 ; i++){
        t.push_back('1');
    }
    a--;
    int poa = t.length();
    t.push_back('0');

    k--;
    while(k && a){
        if(!a){
            cout << "NO\n";
            return 0;
        }

        t.push_back('0');
        a--;
        k--;
    }

    t.push_back('1');

    while(a){
        t.push_back('0');
        a--;
    }

    while(k && poa - 1 > 0){
        swap(t[poa], t[poa - 1]);
        k--;
        poa--;
    }

    if(k){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << s << "\n" << t << "\n";

    return 0;
}