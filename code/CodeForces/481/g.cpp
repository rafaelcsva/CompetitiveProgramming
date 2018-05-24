//13, 05, 2018, 08:04:40 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef struct{
    int s, d, c;
}Exam;

vector<vector<int> >days;
const int N = 110;
Exam exams[N];

bool operator > (Exam a, Exam b){
    if(a.d < b.d){
        return true;
    }else if(a.d > b.d){
        return false;
    }

    if(a.s > b.s){
        return true;
    }else if(a.s < b.s){
        return false;
    }

    return a.c < b.c;
}

bool operator < (Exam a, Exam b){

    return !(a > b);
}

priority_queue<Exam>pq;
vector<int>schedule;
map<int, int>mp;
bool is_ready[N];

int main(){
    int n, m;

    cin >> n >> m;

    days.resize(n + 1);

    for(int i = 0 ; i < m ; i++){
        cin >> exams[i].s >> exams[i].d >> exams[i].c;
        
        days[exams[i].s].push_back(i);
        mp[exams[i].d] = i + 1;
    }
    
    bool ok = true;
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < days[i].size() ; j++){
            int u = days[i][j];

            pq.push({exams[u].s, exams[u].d, exams[u].c});
        }

        if(mp[i] != 0){
            if(is_ready[mp[i]]){
                schedule.push_back(m + 1);
                continue;
            }else{
                ok = false;
                break;
            }
        }
        
        if(pq.empty()){
            schedule.push_back(0);
        }else{
            Exam a = pq.top();
            pq.pop();

            a.c--;
            schedule.push_back(mp[a.d]);

            if(a.c){
                pq.push(a);
            }else{
                is_ready[mp[a.d]] = true;
            }
        }
    }

    if(ok){
        for(int i = 0 ; i < schedule.size() ; i++){
            char c = i == schedule.size() - 1 ? '\n' : ' ';

            cout << schedule[i] << c;
        }
    }else{
        cout << "-1" << endl;
    }

    return 0;
}