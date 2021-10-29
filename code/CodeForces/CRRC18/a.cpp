#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);

    int suma = 0;
    int sumb = 0;

    for(int i = 0 ; i < n ; i++){
        int a, b;

        scanf("%d %d", &a, &b);
        suma += a;
        sumb += b;
    }

    if(sumb % suma == 0){
        printf("QUALITY\n");
    }else{
        printf("DEFECT\n");
    }

    return 0;
}