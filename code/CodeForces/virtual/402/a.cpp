//04, 06, 2018, 19:51:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int cnt1[10];
int cnt2[10];

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        cnt1[x]++;
    }    

    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        cnt2[x]++;
    }

    int sum = 0;

    for(int i = 1 ; i <= 5 ; i++){
        int a = cnt1[i];
        int b = cnt2[i];

        if((a + b) % 2 != 0){
            cout << "-1" << endl;
            return 0;
        }

        int m = (a + b) / 2;

        if(m < cnt1[i]){
            sum += abs(cnt1[i] - m);
        }else{
            sum += abs(cnt2[i] - m);
        }
        
    }
    
    cout << sum / 2 << endl;

    return 0;
}