//19, 04, 2018, 18:41:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = int(1e5 + 100);
vector<ll>f;

ll sum(int i, int j){
    ll x = 0LL;

    for(int k = i ; k <= j ; k++){
        x += f[k];
    }

    return x;
}

ll solve(int start, int end, int flag, ll diff = 0LL){
    
    if(sum(start, end) - diff <= 1){
        return 0LL;
    }

    if(start == end){
        return 0LL;
    }

    int i;
    ll left = f[start] - flag;
    ll right = sum(start + 1, end);

    for(i = start + 1 ; i < end ; i++){
        if(left + f[i] > right - f[i] && left > flag){
            break;
        }

        left += f[i];
        right -= f[i];
    }

    ll r = left;
    ll ndiff = diff;

    if(left < right){
        if(right - left >= ndiff){
            right -= ndiff;
            ndiff = 0;
        }else{
            ndiff -= right - left;
            right = left;
        }
    }else if(left > right){
        if(left - right >= ndiff){
            left -= ndiff;
            ndiff = 0;
        }else{
            ndiff -= left - right;
            left = right;
        }
    }

    left -= (ndiff / 2 + ndiff % 2);
    right -= ndiff / 2;
        
    if(left > right){
        return right;
    }
    
    return left + solve(i, end, 0, diff + left);
    
}

int main(){
    int t;

    cin >> t;

    while(t--){
        for(int i = 0 ; i < 26 ; i++){
            ll x;
            cin >> x;

            if(x > 0LL){
                f.push_back(x);
            }
        }

        ll a = solve(0, f.size() - 1u, 1);

        cout << a << endl;
        
        f.clear();
    }
    
    return 0;
}