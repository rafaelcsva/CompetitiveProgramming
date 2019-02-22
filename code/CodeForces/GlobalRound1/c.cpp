#include <bits/stdc++.h>

using namespace std;

const int D = 25;

int get_resp(int number){
    int best = -1;

    for(int i = 1 ; i < number ; i++){
        best = max(best, __gcd(number ^ i, number & i));
    }

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int pre[] = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

    // for(int i = 2 ; i <= D ; i++){
    //     cout << get_resp((1 << i) - 1) << ", ";
    // }
    // cout << endl;

    int q;

    cin >> q;

    while(q--){
        int ai;

        cin >> ai;

        int last_step = 0;
        int cnt_step = 0;
        bool have_0 = false;

        while(ai){
            if(ai & 1){
                last_step = cnt_step;
            }else{
                have_0 = true;
            }

            ai /= 2;
            cnt_step++;
        }

        // cout << have_0 << endl;

        if(have_0){
            cout << (1 << cnt_step) - 1 << endl;
        }else{
            cout << pre[last_step - 1] << endl;
        }
    }

    return 0;
}