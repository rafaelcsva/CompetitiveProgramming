//03, 06, 2018, 09:58:16 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, int>pipii;

const int N = int(1e5) + 10;
pipii lines[N];
pipii inv[N];
int cat[N];

bool isright(pii u, ll p){
    return u.first > p;
}

bool isInside(pii u, ll p){
    return u.first <= p && p <= u.second;
}

bool compar(pipii x, pipii y){
    pii u = x.first;
    pii v = y.first;

    if(u.second < v.second){
        return true;
    }else if(u.second == v.second){
        return u.first > v.second;
    }

    return false;
}

bool compar1(pipii x, pipii y){
    pii u = x.first;
    pii v = y.first;

    if(u.first > v.first){
        return true;
    }else if(u.first == v.first){
        return u.first > v.second;
    }

    return false;
}

int main(){
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> lines[i].first.first >> lines[i].first.second;
        lines[i].second = i;
        inv[i] = lines[i];
    }

    sort(inv, inv + n, compar);
    sort(lines, lines + n);

    ll pt = 0;
    int left = 0, right = n - 1;
    ll steps = 0;
    
    while(left < n && right >= 0){
        pipii lf = inv[left];
        pipii rg = lines[right];
        
        if(cat[rg.second]){
            right--;
            continue;
        }

        if(cat[lf.second]){
            left++;
            continue;
        }

        ll walkl, walkr;

        if(isright(lf.first, pt)){
            walkl = lf.first.first;
        }else if(isInside(lf.first, pt)){
            walkl = 0;
        }else{
            walkl = lf.first.second;
        }

        if(isright(rg.first, pt)){
            walkr = rg.first.first;
        }else if(isInside(rg.first, pt)){
            walkr = 0;
        }else{
            walkr = rg.first.second;
        }

        if(abs(pt - walkl) > abs(pt - walkr)){
            steps += abs(pt - walkl);
            pt = walkl;
            left++;
            cat[lf.second] = 1;
        }else{
            steps += abs(pt - walkr);
            pt = walkr;
            right--;
            cat[rg.second] = 1;
        }
    }
    
    steps += abs(pt);

    cout << steps << endl;

    return 0;
}