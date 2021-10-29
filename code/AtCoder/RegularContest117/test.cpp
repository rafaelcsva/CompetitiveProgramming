#include <bits/stdc++.h>

using namespace std;

char cho[3] = {'R', 'B', 'W'};

int main(){
    srand(time(NULL));
    int n = 100;

    cout << n << "\n";

    for(int i = 0 ; i < n ; i++){
        cout << cho[rand() % 3];
    }

    cout << "\n";

    return 0;
}