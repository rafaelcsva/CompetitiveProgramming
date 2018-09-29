//01, 07, 2018, 11:15:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

vector<int>v;
const int N = 1010;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, b;

    cin >> n >> b;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    int sum = 0;

    for(int i = 0 ; i < n ; i++){
        if(a[i] & 1){
            sum -= 1;
        }else{
            sum += 1;
        }

        if(sum == 0){
            if(i != n - 1){
                v.push_back(abs(a[i] - a[i + 1]));
            }
        }
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] > b){
            break;
        }

        cnt++;
        b -= v[i];
    }

    cout << cnt << endl;
    
    return 0;
}