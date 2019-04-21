//27, 03, 2019, 18:02:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 13 * 13;
int go_to[N];
vector< vector< double > > a;
vector< double > ans;
const double EPS = 1e-9;
const int INF = 1e9;

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS){
            // cout << "linha " << i << " falha " << sum << " " << a[i][m]  << endl;
            return 0;
        }
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int norm(int x, int n){
    if(x > n){
        return n - (x - n);
    }

    return x;
}

void show(vector< vector< double > > a){
    for(int i = 0 ; i < a.size() ; i++){
        for(int j = 0 ; j < a[i].size() ; j++){
            printf("%.2lf\t", a[i][j]);
        }
        printf("\n");
        fflush(stdout);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, s;

    while(cin >> w >> h >> s){
        for(int i = 0 ; i < s ; i++){
            int ui, vi;

            cin >> ui >> vi;

            go_to[ui] = vi;
        }

        int n = w * h;

        a.resize(n);

        for(int i = 1 ; i <= w * h ; i++){
            a[i - 1].resize(n + 1, 0);
            a[i - 1][i - 1] = 1.0;
            
            if(i != n){
                for(int j = 1 ; j <= 6 ; j++){
                    int u = norm(i + j, n);

                    if(go_to[u]){
                        u = go_to[u];
                    }
                    
                    a[i - 1][u - 1] -= 1.0 / 6.0;
                }

                a[i - 1][n] = 1.0;
            }
        }
        
        // show(a);

        int d = gauss(a, ans);
        assert(d == 1);

        cout << setprecision(8) << fixed << ans[0] << endl;

        memset(go_to, 0, sizeof go_to);
        ans.clear();
        a.clear();
    }
    
    return 0;
}