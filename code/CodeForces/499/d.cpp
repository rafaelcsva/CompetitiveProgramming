//26, 07, 2018, 13:47:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 30;
bool is_liar[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> m >> n;

    for(int i = 0 ; i < n ; i++){
        cout << 1 << endl;
        int r;

        cin >> r;

        if(r == 0){
            return 0;
        }
        
        if(r == 2){
            exit(0);
        }
        
        if(r != 1){
            is_liar[i] = true;
        }
    }

    int st = 1, en = m;
    int p = 0;
    
    while(st <= en){
        int mid = (st + en) / 2;
        int r;

        cout << mid << endl;

        cin >> r;

        if(r == 2){
            exit(0);
        }

        if(r == 0){
            return 0;
        }

        if(r == 1){
            if(is_liar[p]){
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{
            if(is_liar[p]){
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }

        p = (p + 1) % n;
    }  

    return 0;
}