//10, 06, 2018, 07:13:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(2e5 + 100);
int a[N];

int binary_search(int start, int end, int v){
    int r = -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(a[mid] > v){
            end = mid - 1;
        }else{
            r = a[mid];
            start = mid + 1;
        }
    }

    return r;
}

int main(){
    int n, k;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }   

    sort(a, a + n);

    int rmv = 0;

    for(int i = 0 ; i < n ; i++){
        int ind = binary_search(i + 1, n - 1, a[i] + k);

        if(ind > a[i]){
            rmv++;
        }
    }

    cout << n - rmv << endl;

    return 0;
}