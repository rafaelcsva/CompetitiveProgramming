//04, 06, 2018, 19:59:39 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    string n;
    int k;

    cin >> n >> k;

    int c0 = 0;
    int rmv = 0;

    reverse(n.begin(), n.end());
    
    int i;

    for(i = 0 ; i < n.length() ; i++){
        if(c0 >= k){
            break;
        }

        if(n[i] != '0'){
            rmv++;
        }else{
            c0++;
        }
    }

    if(i == n.length()){
        cout << n.length() - 1 << endl;
        return 0;
    }

    cout << rmv << endl;
    
    return 0;
}