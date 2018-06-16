//02, 06, 2018, 07:13:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while(t--){
        ll n;

        cin >> n;
        
        bitset<40>bst(n);

        int l1 = -1, l2 = -1;
        
        
        for(int i = 0 ; i < 40; i++){
            if(bst.test(i)){
                l1 = i;
                break;
            }
        }

        if(l2 == -1){
            int cnt = 1;
            
            for(int k = l1 - 1 ; k >= 0 ; k--){
                if(!bst.test(k)){
                    cnt++;
                }
            }

            cout << cnt << endl;
            
        }else{
            int cnt = 1;
        
            for(int k = l2 - 1 ; k >= 0 ; k--){
                if(!bst.test(k)){
                    cnt++;
                }
            }

            cout << cnt << endl;
        }

    }


    return 0;
}