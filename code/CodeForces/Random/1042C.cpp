//18, 09, 2018, 15:24:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5;
vector< int > bad_guys;
pii a[N];
bool bad[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;    
    }

    sort(a, a + n);

    if(n == 2){
        if(a[0].first > 0 || (a[0].first < 0 && a[1].first < 0)){
            printf("1 1 2\n");
        }
        else{
            printf("2 %d\n", a[0].second + 1);
        }

        return 0;
    }

    int cnt_neg = 0;
    int last_neg = -1;

    for(int i = 0 ; i < n ; i++){
        if(a[i].first < 0){
            cnt_neg++;
            last_neg = a[i].second;
        }else if(a[i].first == 0){
            bad[a[i].second] = true;
            bad_guys.push_back(a[i].second);
        }
    }

    if(cnt_neg & 1){
        bad[last_neg] = true;
        bad_guys.push_back(last_neg);
    }

    for(int i = 1 ; i < bad_guys.size() ; i++){
        printf("%d %d %d\n", 1, bad_guys[i] + 1, bad_guys[0] + 1);
    }

    if(bad_guys.size() != n && bad_guys.size())
        printf("2 %d\n", bad_guys[0] + 1);

    int fi = -1;

    for(int i = 0 ; i < n ; i++){
        if(!bad[i]){
            if(fi != -1){
                printf("1 %d %d\n", i + 1, fi + 1);
            }else{
                fi = i;
            }
        }
    }

    return 0;
}