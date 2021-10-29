#include <bits/stdc++.h>

using namespace std;

const int N = 2510;
string s[N];
int k, n;
bool not_equal = false;

bool can(string &f){
    for(int j = 0 ; j < k ; j++){
        vector< int > missid;
        for(int i = 0 ; i < n ; i++){
            if(s[j][i] != f[i]){
                missid.push_back(i);
            }
        }

        if(missid.size() == 0){
            if(!not_equal){
                return false;
            }
            continue;
        }

        if(missid.size() == 2){
            string tmp = s[j];
            swap(tmp[missid[0]], tmp[missid[1]]);

            if(tmp != f){
                // cout << f << " 1fails with " << s[j] << "\n";
                return false;
            }
        }else{
            // cout << f << " 2fails with " << s[j] << " " << missid.size() << "\n";
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> k >> n;

    string f = "-1";

    for(int i = 0 ; i < k ; i++){
        cin >> s[i];
    
        if(s[i] != s[0]){
            f = s[i];
        }
    }

    if(f == "-1"){
        swap(s[0][0], s[0][1]);
        cout << s[0] << "\n";
    }else{
        for(int i = 0 ; i < f.length() ; i++){
            for(int j = i + 1 ; j < f.length() ; j++){
                if(f[i] == f[j]){
                    not_equal = true;
                    break;
                }
            }
            if(not_equal) break;
        }

        vector< int > missid;

        for(int i = 0 ; i < n ; i++){
            if(s[0][i] != f[i]){
                missid.push_back(i);
            }
        }

        if(missid.size() > 4){
            cout << "-1\n";
            return 0;
        }

        if(can(f)){
            cout << f << "\n";
            return 0;
        }

        for(int i = 0 ; i < missid.size() ; i++){
            for(int j = i + 1 ; j < missid.size() ; j++){
                swap(f[missid[i]], f[missid[j]]);

                // cout << "test with " << f << "\n";
                if(can(f)){
                    cout << f << "\n";
                    return 0;
                }

                swap(f[missid[i]], f[missid[j]]);
            }
        }

        cout << "-1\n";
    }

    return 0;
}