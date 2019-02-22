//14, 10, 2018, 07:21:44 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

// bool is_palindrome(int i, int j, string s){
//     int md = (i + j) / 2;

//     for(int k = i, l = j ; k <= md ; k++, l--){
//         if(s[k] != s[l])
//             return false;
//     }

//     return true;
// }

// int count_sub(string &s){
//     int cnt = 0;

//     for(int i = 0 ; i < s.length() ; i++){
//         for(int j = i ; j < s.length() ; j++){
//             if(is_palindrome(i, j, s)){
//                 cnt++;
//             }
//         }
//     }

//     return cnt;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;

    cin >> n;
    cin >> s;

    sort(s.begin(), s.end());

    cout << s << endl;

    return 0;
}