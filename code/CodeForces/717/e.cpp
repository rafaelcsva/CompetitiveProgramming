#include <bits/stdc++.h>

using namespace std;

map< vector< int >, bool > mp;

void brute(vector< int > &v, int op, int &ans){
    if(op == 0){
        if(!mp[v]){
            ans++;
            mp[v] = true;
        }
        return;
    }

    for(int i = 0 ; i < v.size() ; i++){
        for(int j = i + 1 ; j < v.size() ; j++){
            swap(v[i], v[j]);
            brute(v, op - 1, ans);
            swap(v[i], v[j]);
        }
    }
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    vector< int > v;

    for(int i = 0 ; i < n ; i++){
        v.push_back(i);
    }

    for(int i = 1 ; i <= k ; i++){
        int ans = 0;
        brute(v, i, ans);
        mp.clear();
        printf("%d %d\n", i, ans);
    }

    return 0;
}