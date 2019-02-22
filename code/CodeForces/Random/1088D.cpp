//06, 12, 2018, 11:25:55 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int a, b;

void solve(int &resp, int &i){
    if(resp == 0){
        for(; i >= 0 ; i--){
            int e = 1 << i;
            int x;

            cout << "? " << (a | e) << " " << b << endl;

            cin >> x;
            assert(x != -2);

            if(x == -1){
                a |= e;
                b |= e;
            }
        }

        return;
    }

    for(; i >= 0 ; i--){
        int e = 1 << i;
        cout << "? " << (a | e) << " " << (b | e) << endl;

        int x;

        cin >> x;
        assert(x != -2);

        if(x != resp){
            if(resp == 1){
                a |= e;
            }else{
                b |= e;
            }
            break;
        }else{
            if(resp == 1){
                cout << "? " << a << " " << (b | e) << endl;
                cin >> x;
                assert(x != -2);

                if(x == 1){
                    a |= e;
                    b |= e;
                }
            }else{
                cout << "? " << (a | e) << " " << b << endl;
                cin >> x;   
                assert(x != -2);
                
                if(x == -1){
                    a |= e;
                    b |= e;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "? 0 0" << endl;

    int resp;

    cin >> resp;

    assert(resp != -2);

    int i = 29;

    while(i >= 0){
        solve(resp, i);

        if(i >= 0){
            cout << "? " << a << " " << b << endl;
            cin >> resp;
            assert(resp != -2);
            i--;
        }
    }

    cout << "! " << a << " " << b << endl;

    return 0;
}