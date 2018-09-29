//03, 08, 2018, 12:41:29 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(3e5 + 100);
ll crec[2][N], des[2][N], sum[2][N];
ll a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;

    scanf("%lld", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &b[i]);
    }

    ll coef = 0LL;
    
    for(int i = 1 ; i <= n ; i++){
        crec[0][i] = coef * a[i];
        des[0][i] = (n - coef) * a[i];
        crec[1][i] = coef * b[i];
        des[1][i] = (n - coef) * b[i];
        sum[0][i] += a[i];
        sum[1][i] += b[i];

        if(i){
            crec[0][i] += crec[0][i - 1];
            des[0][i] += des[0][i - 1];
            sum[0][i] += sum[0][i - 1];
            crec[1][i] += crec[1][i - 1];
            des[1][i] += des[1][i - 1];
            sum[1][i] += sum[1][i - 1];
        }
        
        coef++;
    }

    int i = 1, j = 1;
    ll best = 0LL;
    ll takedu = 0LL, takedd = 0LL;
    ll add = 0LL;
    ll tim = 0;
    ll carry = 0LL;
    ll add_up = -1LL, add_down = -1LL;
    
    while((takedu + takedd) != 2LL * n){
        if(i == 1){
            takedu++;

            add_up = add * (sum[0][n] - sum[0][takedu]);
            add_down = (add + n - takedu) * (sum[1][n] - sum[1][takedd]);
            
            if(add){
                add_up -= (sum[0][n] - sum[0][takedu]);
            }
        
            carry += tim * a[takedu];
            best = max(best, carry + crec[0][n] - crec[0][takedu] + des[1][n] - des[1][takedd] + add_up + add_down);
            printf("%10d %10d %10lld %10lld %10lld %10lld %10lld %10lld %10lld %10lld %10lld\n", i, j, add_up, add_down, carry + crec[0][n] - crec[0][takedu] + des[1][n] - des[1][takedd] + add_up + add_down, add, takedd, crec[1][n] - crec[1][takedd], des[0][n] - des[0][takedu], des[0][n], des[0][takedu]);
            
            tim++;
            add++;
            takedu++;
            carry += tim * a[takedu];
            
            i++;
            if(j != 1){
                j++;
            }
        }else{
            takedd++;

            if(add_up == -1LL){
                add_up = (add + n - takedd) * (sum[0][n] - sum[0][takedu]);
                add_down = (add - 1LL) * (sum[1][n] - sum[1][takedd]);
            }
            
            carry += tim * b[takedd];
            best = max(best, carry + crec[1][n] - crec[1][takedd] + des[0][n] - des[0][takedu] + add_up + add_down);
            printf("%10d %10d %10lld %10lld %10lld %10lld %10lld %10lld %10lld %10lld %10lld\n", i, j, add_up, add_down, carry + crec[1][n] - crec[1][takedd] + des[0][n] - des[0][takedu] + add_up + add_down, add, takedd, crec[1][n] - crec[1][takedd], des[0][n] - des[0][takedu], des[0][n], des[0][takedu]);
            
            tim++, takedd++;
            add++;
            carry += tim * b[takedd];
            
            j++, i--;
        }

        add++;
        tim++;
    }

    printf("%lld\n", best);
 
    return 0;
}