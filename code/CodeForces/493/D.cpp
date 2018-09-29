//01, 07, 2018, 12:02:54 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int cnt = 0;
const ll N = 14;
ll resp[] = {4, 10, 20, 35, 56, 83,116, 155, 198, 244, 292, 341, 390, 439};
ll n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n;

    if(n > N){
        cout << resp[N - 1] + (n - 14LL) * 49LL << endl;
    }else{
        cout << resp[n - 1] << endl;
    }

    return 0;
}