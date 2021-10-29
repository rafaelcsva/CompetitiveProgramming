#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int val;
    int nxt = -1, bef = -1;
};

const int N = int(2e5) + 10;
Node node[N];

int main(){
    int t;

    scanf("%d", &t);
    
    while(t--){
        int n;

        scanf("%d", &n);

        int cur = -1;
        int sz = 1;

        bool frag = false;

        for(int i = 0 ; i < n ; i++){
            int bi;

            scanf("%d", &bi);
            if(frag) continue;

            if(cur == -1){
                cur = 0;
                node[0].val = bi;
            }else{
                if(bi > node[cur].val){
                    if(node[cur].nxt == -1){
                        node[sz].val = bi;
                        node[sz].bef = cur;
                        node[cur].nxt = sz;
                        cur = sz;
                        sz++;
                    }else if(node[node[cur].nxt].val == bi){
                        cur = node[cur].nxt;
                    }else if(node[node[cur].nxt].val > bi){
                        node[sz].val = bi;
                        node[sz].bef = cur;
                        node[node[cur].nxt].bef = sz;
                        node[sz].nxt = node[cur].nxt;
                        node[cur].nxt = sz;
                        cur = sz;
                        sz++;
                    }else{
                        frag = true;
                    }
                }else if(bi < node[cur].val){
                    if(node[cur].bef == -1){
                        node[sz].val = bi;
                        node[sz].nxt = cur;
                        node[cur].bef = sz;
                        cur = sz;
                        sz++;
                    }else if(node[node[cur].bef].val == bi){
                        cur = node[cur].bef;
                    }else if(node[node[cur].bef].val < bi){
                        node[sz].val = bi;
                        node[sz].nxt = cur;
                        node[node[cur].bef].nxt = sz;
                        node[sz].bef = node[cur].bef;
                        node[cur].bef = sz;
                        cur = sz;
                        sz++;
                    }else{
                        frag = true;
                    }
                }
            }
        }

        if(frag){
            printf("NO\n");
        }else{
            printf("YES\n");
        }

        for(int i = 0 ; i < sz ; i++){
            node[i].nxt = node[i].bef = -1;
        }
    }
}