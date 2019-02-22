//18, 02, 2019, 12:41:41 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e6);
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int best = -1;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        best = max(best, a[i]);
    }

    int carry = 0;
    int resp = 0;

    for(int i = 0 ; i < n ; i++){
        if(a[i] == best){
            carry++;
        }else{
            carry = 0;
        }

        resp = max(resp, carry);
    }

    cout << resp << endl;

    return 0;
}