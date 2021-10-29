#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 10;

int main(){
    vector< pair< char, int > > ve;

    string s;

    cin >> s;

    int cnt = 1;

    for(int i = 1 ; i < s.length() ; i++){
        if(s[i] != s[i - 1]){
            ve.push_back({s[i - 1], cnt});
            cnt = 1;
        }else{
            cnt++;
        }
    }

    ve.push_back({s[int(s.length()) - 1], cnt});

    if((ve.size() & 1) == 0){
        cout << "0\n";
        return 0;
    }

    for(int i = 0, j = int(ve.size()) - 1; i < j ; i++, j--){
        if(ve[i].first == ve[j].first && ve[i].second + ve[j].second >= 3){
            continue;
        }

        cout << "0\n";
        return 0;
    }

    int mid = ve[int(ve.size()) / 2].second;

    if(mid + 1 < 3){
        cout << "0\n";
    }else{
        cout << mid + 1 << "\n";
    }

    return 0;
}