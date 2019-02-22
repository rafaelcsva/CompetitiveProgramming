//09, 01, 2019, 12:51:48 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 4e5, D = 3;
char s[N];
set< int > st[D];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("\n%c", &s[i]);

        s[i] -= '0';

        st[s[i]].insert(i);
    }

    int target = n / 3;

    //fix 0
    while(st[0].size() < target){
        int fi = 1e9;
        int se = 1e9;

        if(st[2].size() > target){
            fi = *st[2].begin();
        }

        if(st[1].size() > target){
            se = *st[1].begin();
        }

        if(fi < se){
            st[0].insert(fi);
            st[2].erase(fi);
        }else{ 
            assert(se != 1e9);

            st[0].insert(se);
            st[1].erase(se);
        }
    }

    //fix 2
    while(st[2].size() < target){
        int fi = -1;
        int se = -1;

        if(st[1].size() > target){
            fi = *st[1].rbegin();
        }

        if(st[0].size() > target){
            se = *st[0].rbegin();
        }

        if(fi > se){
            st[2].insert(fi);
            st[1].erase(fi);
        }else{
            assert(se != -1);
            st[2].insert(se);
            st[0].erase(se);
        }
    }
    
    //fix 1
    while(st[1].size() < target){
        int fi = -1;
        int se = -1;

        if(st[2].size() > target){
            fi = *st[2].begin();
        }

        if(st[0].size() > target){
            se = *st[0].rbegin();
        }

        if(fi != -1){
            st[1].insert(fi);
            st[2].erase(fi);
        }else{
            assert(se != -1);
            st[1].insert(se);
            st[0].erase(se);
        }
    }

    for(int i = 0 ; i < D ; i++){
        for(set< int >::iterator it = st[i].begin() ; it != st[i].end() ; it++){
            s[*it] = i;
        }
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d", s[i]);
    }

    printf("\n");

    return 0;
}