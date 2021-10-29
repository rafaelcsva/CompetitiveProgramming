#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int k;

    cin >> s >> k;

    sort(s.begin(), s.end());

    k--;

    do{
        if(!k){
            break;
        }

        k--;
    }while(next_permutation(s.begin(), s.end()));

    cout << s << "\n";

    return 0;
}