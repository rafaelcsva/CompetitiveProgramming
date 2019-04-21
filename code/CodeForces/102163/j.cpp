//17, 04, 2019, 18:35:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(3e5 + 100);
int cnt[N];
int a[N], x[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        for(int i = 1 ; i <= m ; i++){
            cin >> a[i];
        }

        for(int i = 1 ; i <= m ; i++){
            cin >> x[i];
        }

        for(int i = 1 ; i <= m ; i++){
            if(x[i] < 0){
                x[i] *= -1;

                if(a[i] - x[i] <= 0){
                    cnt[1]++;
                    cnt[a[i] + 1]--;
                    cnt[(a[i] - x[i]) + n]++;
                    cnt[n + 1]--;
                }else{
                    cnt[a[i] + 1]--;
                    cnt[a[i] - x[i]]++;
                }
            }else{
                if(a[i] + x[i] > n){
                    cnt[a[i]]++;
                    cnt[n + 1]--;
                    cnt[1]++;
                    cnt[a[i] + x[i] - n + 1]--;

                    // cout << a[i] << " -> " << n + 1 << " + ";
                    // cout << 1 << " -> " << a[i] + x[i] - n + 1 << endl;
                }else{
                    cnt[a[i]]++;
                    cnt[a[i] + x[i] + 1]--;

                    // cout << a[i] << " -> " << a[i] + x[i] + 1 << endl;
                }
            }
        }

        int carry = 0;

        for(int i = 1 ; i <= n ; i++){
            carry += cnt[i];
            // cout << i << " = " << carry << " | " << cnt[i] << " | " << a[i] << endl;
            a[i] = carry;
        }

        int best = 0;
        int best_i = -1;

        for(int i = 1 ; i <= n + 1 ; i++){
            // cout << "c " << i << " = " << a[i] << endl;
            if(a[i] > best){
                best_i = i;
                best = a[i];
            }

            cnt[i] = 0;
        }

        cout << best_i << " " << best << endl;
    }
    
    return 0;
}