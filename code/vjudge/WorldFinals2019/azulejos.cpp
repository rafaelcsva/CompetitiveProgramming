#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = int(5e5) + 10;
pii p1[N], p2[N];
int id1[N], id2[N];
int ans[N], ans1[N];
int mark[N], mark1[N];
multiset< pii > mst[N], mst1[N];

bool compar1(int a, int b){
    return p1[a] < p1[b];
}

bool compar2(int a, int b){
    return p2[a] < p2[b];
}

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> p1[i].first;
        id1[i] = id2[i] = i;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> p1[i].second;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> p2[i].first;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> p2[i].second;
    }

    sort(id1, id1 + n, compar1);
    sort(id2, id2 + n, compar2);

    int id = 0;

    for(int i = 0 ; i < n ; i++){
        if(i && (p2[id2[i]].first != p2[id2[i - 1]].first)){
            id++;
        }

        mst[id].insert({p2[id2[i]].second, id2[i]});
        ans[i] = id;
    }

    int idd = 0;

    for(int i = 0 ; i < n ; i++){
        if(i && (p1[id1[i]].first != p1[id1[i - 1]].first)){
            idd++;
        }

        mst1[idd].insert({p1[id1[i]].second, id1[i]});
        ans1[i] = idd;
    }

    for(int i = 0 ; i < n ; i++){
        auto l1 = prev(mst1[ans1[i]].end());
        auto l2 = prev(mst[ans[i]].end());
    
        if(l1->first > l2->first){
            auto u = mst1[ans1[i]].upper_bound({l2->first, n});

            mark1[i] = u->second;
            mark[i] = l2->second;

            // if(i == 3){
            //     printf("a: %d, %d\n", i, l2->second);
            // }
            mst1[ans1[i]].erase(u);
            mst[ans[i]].erase(l2);
        }else{
            auto u = mst[ans[i]].lower_bound({l1->first, -1});

            if(u == mst[ans[i]].begin()){
                cout << "impossible\n";
                return 0;
            }

            u = prev(u);

            mark1[i] = l1->second;
            mark[i] = u->second;

            mst1[ans1[i]].erase(l1);
            mst[ans[i]].erase(u);
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << mark1[i] + 1 << " ";
    }
    cout << "\n";

    for(int i = 0 ; i < n ; i++){
        cout << mark[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}