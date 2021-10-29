#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
        }

        bool ver = false;
    
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j){
                    ver |= (a[i] == a[j]);
                }

                for(int k = 0 ; k < n ; k++){
                    ver |= ((a[i] - a[j]) == a[k]);
                }
            }
        }

        if(ver){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }   

    return 0;
}