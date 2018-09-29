//03, 08, 2018, 11:49:25 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    scanf("%d %d", &n, &m);

    int carry = 0;

    for(int i = 0 ; i < n ; i++){
        int a;
        int r = 0;

        scanf("%d", &a);

        if(carry){
            if(carry > a){
                carry -= a;
                a = 0;
            }else{
                a -= carry;
                r++;
                carry = 0;
            }
        }

        if(a){
            int need = a / m;
            r += need;
            carry = m - a % m;

            if(carry == m){
                carry = 0;
            }
        }
        
        printf("%d ", r);
    }    
    printf("\n");
    
    return 0;
}