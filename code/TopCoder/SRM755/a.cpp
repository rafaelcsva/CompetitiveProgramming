//15, 04, 2019, 12:08:42 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class OneHandSort{
    public:
    vector <int> sortShelf(vector <int> target){
        int n = target.size();
        vector< int > commands;

        for(int i = 0 ; i < target.size() ; i++){
            if(target[i] == i){
                continue;
            }

            for(int j = i + 1 ; j < target.size() ; j++){
                int u = target[j];

                if(u == i){
                    commands.push_back(i);
                    commands.push_back(j);
                    commands.push_back(n);

                    swap(target[i], target[j]);
                    break;
                }
            }
        }

        return commands;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    OneHandSort test;

    auto t = test.sortShelf({1, 0, 3, 2});

    for(int i = 0 ; i < t.size() ; i++){
        cout << t[i] << " ";
    }
    // cout << test.sortShelf({0, 1, 2, 3}) << endl;

    return 0;
}