#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< pii > v;
vector< int > a;
vector< pii > arestas;
const int N = int(500 + 10);
int d[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nn;

    cin >> nn;

    for(int i = 1 ; i <= nn ; i++){
        cin >> d[i];

        if(d[i] > 1){
            v.push_back(make_pair(d[i], i));
        }else{
            a.push_back(i);
        }
    }

    if(v.size() == 0){
        cout << "NO" << endl;
        return 0;
    }

    sort(v.begin(), v.end());

    int n = v.size();

    if(n >= 2){
        swap(v[0], v[n - 2]);
    }

    for(int i = 1 ; i < n ; i++){
        arestas.push_back({v[i].second, v[i - 1].second});
        v[i].first--;
        v[i - 1].first--;
    }

    int i = 0;
    int m = a.size();
    int add = 0;

    if(m == 1){
        if(v[0].first){
            v[0].first--;
            arestas.push_back({v[0].second, a[0]});
        }else if(v[n - 1].first){
            v[n - 1].first--;
            arestas.push_back({v[n - 1].second, a[0]});
        }else{
            cout << "NO" << endl;
            return 0;
        }

        add = 1;
        i = 1;
    }else if(m >= 2){
        if(v[0].first + v[n - 1].first >= 2){
            bool frag = false;

            if(v[0].first && v[n - 1].first){
                v[0].first--;
                arestas.push_back({v[0].second, a[0]});
                v[n - 1].first--;
                arestas.push_back({v[n - 1].second, a[1]});
                add = 2;
                i = 2;
            }else if(v[0].first){
                v[0].first--;
                arestas.push_back({v[0].second, a[0]});
                v[0].first--;
                arestas.push_back({v[0].second, a[1]});
                add = 1;
                i = 2;
            }else{
                v[n - 1].first--;
                arestas.push_back({v[n - 1].second, a[0]});
                v[n - 1].first--;
                arestas.push_back({v[n - 1].second, a[1]});
                add = 1;
                i = 2;
            }
        }else{
            if(v[0].first){
                v[0].first--;
                arestas.push_back({v[0].second, a[0]});
                i = 1;
                add = 1;
            }else if(v[n - 1].first){
                v[n - 1].first--;
                arestas.push_back({v[n - 1].second, a[0]});
                i = 1;
                add = 1;
            }
        }
    }

    int j = 0;
    bool ok = true;

    for(; i < a.size() ; i++){
        while(j < v.size() && v[j].first == 0){
            j++;
        }

        if(j == v.size()){
            ok = false;
            break;
        }

        arestas.push_back({a[i], v[j].second});
        v[j].first--;
    }

    if(ok){
        cout << "YES " << int(v.size()) + add - 1 << endl;  
        // cout << v.size() << " " << add << endl;

        cout << arestas.size() << endl;

        for(int i = 0 ; i < arestas.size() ; i++){
            cout << arestas[i].first << " " << arestas[i].second << endl;
        }
    }else{
        cout << "NO" << endl;
    }

    return 0;
}