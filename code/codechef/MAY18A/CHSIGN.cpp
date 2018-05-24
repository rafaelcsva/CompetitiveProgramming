#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
typedef pair<int, int> pii;
const int N = int(1e5 + 100);
const ll INF = ll(1e17);
ll a[N];
ll sum[N];
ll dp[N];
int used[N];
int isGood[N];
int test;
vector<int>v;
int n;
    
ll solve(int x){
    if(x > n){
        return dp[x] = 0LL;
    }
    
    if(used[x] == test){
        return dp[x];
    }
    
    used[x] = test;
    
    ll tmp = 0LL;
    dp[x] = INF;
    
    if(isGood[x] == test){
        dp[x] = -a[x];
        
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
        
        if(idx == v.size() - 1){
            return dp[x] = dp[x] + sum[x + 1];
        }
    
        int dd = idx;
        idx = v[idx + 1];
    
        if(idx == x + 2){
            if(a[x + 1] - a[x] > a[x + 2]){
                dp[x] += a[x + 1] + solve(x + 2);
            }else{
                if(dd == v.size() - 2){
                    dp[x] += sum[x + 1];
                }else{
                    idx = v[dd + 2];
    
                    dp[x] += sum[x + 1] - sum[idx] + solve(idx);
                }
            }
        }else{
            dp[x] += sum[x + 1] - sum[idx] + solve(idx);
        }
    }
    
    dp[x] = min(dp[x], a[x] + solve(x + 1));
    
    return dp[x];
}
    
void printDP(int x){
    if(x > n){
        return;
    }
    
    if(isGood[x] == test){
        //cout << "x is here = " << x << endl;
    
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
        
        if(idx == v.size() - 1){
            if(x != 1){
                cout << " ";
            }
    
            cout << -a[x];
    
            for(int i = x + 1 ; i <= n ; i++){
                char c = i == n ? '\n' : ' ';
                
                cout << " " << a[i];
            }
    
            return;
        }
    
        int dd = idx;
        
        idx = v[idx + 1];
        //cout << idx << ' ' << x + 2 << " is equals ? " << endl;
    
        if(idx == x + 2){
            if(a[x + 1] - a[x] > a[x + 2]){
                if(dp[x] == a[x + 1] + solve(x + 2) - a[x]){
                    if(x != 1){
                        cout << " ";
                    }
    
                    cout << -a[x] << " " << a[x + 1];
                    printDP(x + 2);
    
                    return;
                }
            }else{
                if(dd == v.size() - 2){
                    if(dp[x] == sum[x + 1] - a[x]){
                        if(x != 1)
                            cout << " ";
    
                        cout << -a[x];
    
                        for(int i = x + 1 ; i <= n ; i++){
                            cout << " " << a[i] ;
                        }
                        return;
                    }
                }else{
                    idx = v[dd + 2];
    
                    if(dp[x] == sum[x + 1] - sum[idx] + solve(idx) - a[x]){
                        if(x != 1)
                            cout << " ";
    
                        cout << -a[x];
    
                        for(int i = x + 1 ; i < idx ; i++){
                            cout << " " << a[i];
                        }                     
                        
                        printDP(idx);
                        return;
                    }
                }
            }
        }else{
            //cout << " but them are ? " << sum[x + 1] - sum[idx] + solve(idx) - a[x] << " " << dp[x] << " ?" << endl;
    
            if(dp[x] == sum[x + 1] - sum[idx] + solve(idx) - a[x]){
                //cout << x << " leaved here" << endl;
    
                if(x != 1)
                    cout << " ";
    
                cout << -a[x];
    
                for(int i = x + 1 ; i < idx ; i++){
                    cout << " " << a[i];
                }                     
                
                printDP(idx);
                return;
            }
        }
    }
    
    if(x != 1){
        cout << " ";
    }
    
    cout << a[x];
    printDP(x + 1);
}
    
int main(){
    int t;
    
    cin >> t;
    
    for(test = 1 ; test <= t ; test++){
        cin >> n;
    
        a[0] = a[n + 1] = INF;
    
        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }
    
        for(int i = 1 ; i <= n ; i++){
    
            if(a[i] < a[i - 1] && a[i] < a[i + 1]){
                v.push_back(i);
                isGood[i] = test;
            }
        }
    
        a[n + 1] = a[0] = 0LL;
        sum[n + 1] = 0LL;

        for(int i = n ; i >= 1 ; i--){
            sum[i] = sum[i + 1] + a[i];
        }
    
        //cout << solve(1) << " is the min" << endl;
        solve(1);
        printDP(1);
    
        cout << endl;
        
        //memset(isGood, 0, sizeof isGood);
        //memset(sum, 0, sizeof sum);
        v.clear();
    }
    
    return 0;
} 