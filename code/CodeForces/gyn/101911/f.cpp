//30, 11, 2018, 15:11:06 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10;
vector< pii > numbers;
int resp[N];
int BIT[N * 10];

int LSOne(int x){
    return x & (-x);
}

int query(int x){
    int sum = 0;

    while(x > 0){
        sum += BIT[x];
        x -= LSOne(x);
    }

    return sum;
}

int rsq(int l, int r){
    return query(r) - query(l - 1);
}

void update(int x){
    while(x < N){
        BIT[x]++;
        x += LSOne(x);
    }
}

int get(int x){
    int digits[6];
    memset(digits, 0, sizeof digits);
    int i = 5;

    while(x){
        digits[i] = x % 10;
        i--;
        x /= 10;
    }

    int sum1 = digits[0] + digits[1] + digits[2];
    int sum2 = digits[3] + digits[4] + digits[5];

    return abs(sum1 - sum2);
}

char s[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("\n%s", s);

        int number = 0;

        for(int j = 0 ; j < 6 ; j++){
            number = number * 10 + (s[j] - '0');
        }

        numbers.push_back({number, i});
    }

    sort(numbers.begin(), numbers.end());

    int last = 0;

    for(int i = 0 ; i < numbers.size() ; i++){
        if(numbers[i].first > last){
            for(int j = last ; j < numbers[i].first ; j++){
                update(get(j) + 1);
            }

            last = numbers[i].first;
        }

        int pos = numbers[i].second;
        resp[pos] = rsq(1, get(numbers[i].first));
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d%c", resp[i], '\n');
    }

    return 0;
}