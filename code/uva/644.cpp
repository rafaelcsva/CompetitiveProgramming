//24, 07, 2018, 21:40:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;
map<string, int>mp;
vector<string>v;

bool is_prefix(int j, int i){
    if(v[j].length() > v[i].length()){
        return false;
    }

    int k = 0;

    while(k < v[j].length()){
        if(v[j][k] != v[i][k]){
            return false;
        }

        k++;
    }

    return true;
}

bool is_decodable(){
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v.size() ; j++){
            if(j == i)
                continue;

            if(is_prefix(j, i)){
                return false;
            }
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int set_number = 1;
    bool ok = true;
    
    while(cin >> s){
        if(s == "9"){
            if(is_decodable()){
                cout << "Set " << set_number << " is immediately decodable" << endl; 
            }else{
                cout << "Set " << set_number << " is not immediately decodable" << endl; 
            }

            ok = true;
            set_number++;
            v.clear();
        }else{
            v.push_back(s);
        }
    }

    return 0;
}