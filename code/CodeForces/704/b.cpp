#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 10;
int a[N];

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        set< int > srt;

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]);
            srt.insert(a[i]);
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            stack< int > st;

            int j = i;
            // printf("r: %d\n", *srt.rbegin());
            while(a[j] != *srt.rbegin()){
                st.push(a[j]);
                j--;
            }
            st.push(a[j]);
            i = j;

            while(!st.empty()){
                srt.erase(st.top());
                printf("%d ", st.top());
                st.pop();
            }
        }

        printf("\n");
    }
    
    return 0;
}