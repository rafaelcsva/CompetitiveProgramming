#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

void gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
    for(int i = 0 ; i < m ; i++){
        if(where[i] != -1){
            ans[i] = a[where[i]][m];
            // cout << "found on " << i << endl;
        }
    }
}

int cnt[N];
int a[N][N], b[N][N], mt[N][N];
vector< bitset<N> > v;

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int n;

        scanf("%d", &n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                char c;

                scanf("\n%c", &c);
                a[i][j] = c - '0';
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                char c;

                scanf("\n%c", &c);
                b[i][j] = c - '0';
            }
        }
        for(int i = 0 ; i < n * n ; i ++){
            bitset< N > tmp;
            int l = i / n;
            int j = i % n;

            if(cnt[l] > 1 && cnt[n + j] > 1) continue;
            cnt[l]++;
            cnt[n + j]++;
            tmp[l] = 1;
            tmp[n + j] = 1;

            tmp[2 * n] = (a[l][j] != b[l][j]);
            // cout << tmp << endl;
        
            v.push_back(tmp);
        }
        memset(cnt, 0, sizeof cnt);
        bitset< N > ans;
        // cout << ans << endl;
        gauss(v,v.size(), 2 * n, ans);
        // cout << "ans\n";
        // cout << ans << endl;
        bool ok = true;
        for(int i = 0 ; i < n * n ; i++){
            int l = i / n;
            int j = i % n;

            int val = ans[l] ^ ans[n + j];
            if(val != (a[l][j] != b[l][j])){
                ok = false;
                break;
            }
        }

        if(ok){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

        v.clear();
    }

    return 0;
}