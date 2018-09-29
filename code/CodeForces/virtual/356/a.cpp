//17, 07, 2018, 12:41:01 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
const int N = 1000;
int cnt[N];
int a[N];
int n = 5;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        cnt[a[i]]++;
        sum += a[i];
    }    

    int best = sum;

    for(int i = 0; i < n ; i++){
        if(cnt[a[i]] > 1){
            best = min(best, sum - min(3, cnt[a[i]]) * a[i]);
        }
    }

    cout << best << endl;

    return 0;
}