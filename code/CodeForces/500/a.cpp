//30, 07, 2018, 05:16:51 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    int sum1 = 0, sum2 = 0;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        sum1 += x;
    }

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        sum2 += x;
    }

    if(sum1 >= sum2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}