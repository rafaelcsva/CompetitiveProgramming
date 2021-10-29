#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

const int N = 110;
int n;
pii a[N];
pii b[N];

bool equals(vector< pii > &r){
    sort(r.begin(), r.end());
    for(int i = 0 ; i < r.size() ; i++){
        if(r[i] != b[i]){
            return false;
        }
    }

    return true;
}

bool can1(vector< pair< int, int > > v){
    for(int x = -10 ; x <= 10 ; x++){
        for(int y = -10 ; y <= 10 ; y++){
            vector< pii > r;

            for(int i = 0 ; i < n ; i++){
                r.push_back({v[i].first + x, v[i].second + y});
            }

            if(equals(r)){
                return true;
            }
        }
    }

    return false;
}

bool can(){
    for(int x = -10 ; x <= 10 ; x++){
        for(int y = -10 ; y <= 10 ; y++){
            vector< pii > r;

            for(int i = 0 ; i < n ; i++){
                r.push_back({a[i].first + x, a[i].second + y});
            }

            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j < n ; j++){
                    int x = r[j].first;
                    int y = r[j].second;
                    r[j].first = -y;
                    r[j].second = x;
                }

                if(can1(r)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &a[i].first, &a[i].second);
    }

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &b[i].first, &b[i].second);
    }

    sort(b, b + n);

    if(can()){
        printf("Yes\n");
        return 0;
    }
    printf("No\n");

    return 0;
}