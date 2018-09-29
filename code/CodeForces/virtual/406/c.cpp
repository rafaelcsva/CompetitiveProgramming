//23, 07, 2018, 17:09:17 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 100;
string c[N];
vector<string>names, answer;
map<string, bool>mark;
int n, k;

int can_put(string name, int i){
    int st = max(i - k + 1, 0);

    bool have_yes = false;
    
    for(int t = st ; t <= min(n - k, i) ; t++){
        if(c[t] == "YES"){
            for(int j = t ; j <= min(t + k - 1, int(answer.size()) - 1) ; j++){
                if(name == answer[j]){
                    return 0;
                }
            }
        }
    }

    // cout << "r = " << r << endl;

    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    string name = "bcdefghij";
    string f = "A";

    for(char c = 'A' ; c <= 'Z' ; c++){
        names.push_back(f + name);
        next_permutation(name.begin(), name.end());
        names.push_back(f + name);
        next_permutation(name.begin(), name.end());
    }
    
    for(int i = 0 ; i <= n - k ; i++){
        cin >> c[i];
    }    

    for(int i = 0 ; i < n ; i++){
        bool put = false;
        string tmp = "";

        for(int j = 0 ; j < names.size() ; j++){
            int r = can_put(names[j], i);

            if(r == 1){
                put = true;
                answer.push_back(names[j]);
                break;
            }else if(r == 0){
                tmp = names[j];
            }
        }

        if(!put){
            answer.push_back(tmp);
        }
    }

    for(int i = 0 ; i <= n - k ; i++){
        if(c[i] == "NO"){
            bool find = false;

            for(int j = i ; j <= i + k - 1 ; j++){
                
                for(int t = i ; t <= i + k - 1 ; t++){
                    if(t != j && can_put(answer[j], t)){
                        answer[t] = answer[j];
                        find = true;
                        break;
                    }        
                }

                if(find){
                    break;
                }
            }
            
        }
    }

    for(int i = 0 ; i < n ; i++){
        char c = i == n - 1 ? '\n' : ' ';
        cout << answer[i] << c;
    }

    return 0;
}