//25, 06, 2018, 16:04:07 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int cnt[30];
int cnt2[30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;

    while(cin >> n){
        ll tn = n;

        if(tn == 0)
            cnt[0]++;

        while(tn){
            cnt[tn % 10LL]++;
            cnt2[tn % 10LL]++;
            tn /= 10LL;
        }    

        ll number = 0LL;

        for(int i = 9 ; i >= 0 ; i--){
            while(cnt[i]){
                number = number * 10LL + i;
                cnt[i]--;
            }
        }

        ll number2 = 0LL;
        
        for(int i = 1 ; i <= 9 ; i++){
            if(cnt2[i]){
                number2 = i;
                cnt2[i]--;
                break;
            }
        }

        for(int i = 0 ; i <= 9 ; i++){
            while(cnt2[i]){
                number2 = number2 * 10LL + i;
                cnt2[i]--;
            }
        }

        ll diff = number - number2;

        cout << number << " - " << number2 << " = " << diff << " = 9 * " << diff / 9LL << endl;
    }

    return 0;
}