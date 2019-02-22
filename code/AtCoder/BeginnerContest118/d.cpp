//16, 02, 2019, 10:20:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5);
int dp[N];
int cost[] = {2,5,5,4,5,6,3,7,6};
int n, m;
int a[N];

int solve(int number_sticks){
    if(number_sticks == 0){
        return 0;
    }

    if(number_sticks < 0){
        return -1e9;
    }

    int &ans = dp[number_sticks];

    if(ans != -1){
        return ans;
    }

    for(int i = 0 ; i < m ; i++){
        ans = max(ans, solve(number_sticks - cost[a[i] - 1]) + 1);
    }

    return ans;
}

void print(int number_sticks){
    if(number_sticks == 0){
        return;
    }

    int &ans = dp[number_sticks];

    for(int i = 0 ; i < m ; i++){
        if(ans == solve(number_sticks - cost[a[i] - 1]) + 1){
            cout << a[i];
            print(number_sticks - cost[a[i] - 1]);
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> a[i];
    }

    sort(a, a + m, greater< int >());

    solve(n);
    print(n);
    cout << endl;

    return 0;
}