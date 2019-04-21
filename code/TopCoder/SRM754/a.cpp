//30, 03, 2019, 08:05:50 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

set< pii > points;

void print(pii u, string s){
    printf("+ (%d, %d) in ", u.first, u.second);
    cout << s << endl;
}

class MoreSquares{
    public:
    int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix){
        for(int i = 0 ; i < Xprefix.size() ; i++){
            points.insert({Xprefix[i], Yprefix[i]});
        }

        int x = Xprefix[int(Xprefix.size()) - 1];
        int y = Yprefix[int(Yprefix.size()) - 1];

        for(int i = Xprefix.size() ; i < N ; i++){
            x = (x * 47 + 42) % SX;
            y = (y * 47 + 42) % SY;

            points.insert({x, y});
        }

        set< pii >P;

        for(set< pii >::iterator it = points.begin() ; it != points.end() ; it++){
            printf("%d, %d\n", it->first, it->second);

            for(set< pii >::iterator itj = next(it) ; itj != points.end() ; itj++){
                pii a = *it;
                pii b = *itj;
                assert(a != b);

                if(a.first == b.first){
                    int len = b.second - a.second;

                    pii tr = {b.first + len, b.second};
                    pii br = {a.first + len, a.second};

                    int fnd1 = 0;
                    int fnd2 = 0;

                    if(points.find(tr) != points.end()){
                        fnd1 = 1;
                    }

                    if(points.find(br) != points.end()){
                        fnd2 = 1;
                    }

                    if(!fnd1 && fnd2){
                        P.insert(tr);
                        print(tr, "3");
                    }else if(fnd1 && !fnd2){
                        P.insert(br);
                        print(br, "4");
                    }

                    pii tl = {b.first - len, b.second};
                    pii bl = {a.first - len, a.second};

                    fnd1 = fnd2 = 0;

                    if(points.find(tl) != points.end()){
                        fnd1 = 1;
                    }

                    if(points.find(bl) != points.end()){
                        fnd2 = 1;
                    }

                    if(fnd1 && !fnd2){
                        P.insert(bl);
                        print(bl, "5");
                    }else if(!fnd1 && fnd2){
                        P.insert(tl);
                        print(tl, "6");
                    }

                }else if(a.second == b.second){
                    int len = b.first - a.first;

                    pii tr = {b.first , b.second + len};
                    pii br = {a.first, a.second + len};

                    int fnd1 = 0;
                    int fnd2 = 0;

                    if(points.find(tr) != points.end()){
                        fnd1 = 1;
                    }

                    if(points.find(br) != points.end()){
                        fnd2 = 1;
                    }

                    if(!fnd1 && fnd2){
                        P.insert(tr);
                        print(tr, "7");
                    }else if(fnd1 && !fnd2){
                        P.insert(br);
                        print(br, "8");
                    }

                    pii tl = {b.first , b.second - len};
                    pii bl = {a.first , a.second - len};

                    fnd1 = fnd2 = 0;

                    if(points.find(tl) != points.end()){
                        fnd1 = 1;
                    }

                    if(points.find(bl) != points.end()){
                        fnd2 = 1;
                    }

                    if(fnd1 && !fnd2){
                        P.insert(bl);
                        print(bl, "9");
                    }else if(!fnd1 && fnd2){
                        P.insert(tl);
                        print(tl, "10");
                    }
                }else{
                    int len = b.first - a.first;

                    if(len == abs(b.second - a.second)){
                        pii tl = {b.first - len, b.second};
                        pii tr = {a.first + len, a.second};

                        int fnd1 = 0, fnd2 = 0;

                        if(points.find(tl) != points.end()){
                            fnd1 = 1;
                        }

                        if(points.find(tr) != points.end()){
                            fnd2 = 1;
                        }

                        if(fnd1 && !fnd2){
                            P.insert(tr);
                            print(tr, "11");
                        }

                        if(!fnd1 && fnd2){
                            P.insert(tl);
                            print(tl, "12");
                        }
                    }

                    if(b.second < a.second){
                        int dx = b.first - a.first;
                        int dy = a.second - b.second;

                        pii tl = {a.first - dy, a.second - dx};
                        pii bl = {b.first - dy, b.second - dx};

                        int fnd1 = 0;
                        int fnd2 = 0;

                        if(points.find(tl) != points.end()){
                            fnd1 = 1;
                        }

                        if(points.find(bl) != points.end()){
                            fnd2 = 1;
                        }

                        if(!fnd1 && fnd2){
                            P.insert(tl);
                            print(tl, "13");
                        }

                        if(fnd1 && !fnd2){
                            P.insert(bl);
                            print(bl, "14");
                        }

                        tl = {a.first + dy, a.second + dx};
                        bl = {b.first + dy, b.second + dx};
                        fnd1 = fnd2 = 0;

                        if(points.find(tl) != points.end()){
                            fnd1 = 1;
                        }

                        if(points.find(bl) != points.end()){
                            fnd2 = 1;
                        }

                        if(!fnd1 && fnd2){
                            P.insert(tl);
                            print(tl, "15");
                        }

                        if(fnd1 && !fnd2){
                            P.insert(bl);
                            print(bl, "16");
                        }
                    }else{
                        int dx = abs(a.first - b.first);
                        int dy = abs(a.second - b.second);
                        // swap(dx, dy);
                        pii tl = {a.first + dy, a.second - dx};
                        pii bl = {b.first + dy, b.second - dx};

                        int fnd1, fnd2;
                        fnd1 = fnd2 = 0;

                        if(points.find(tl) != points.end()){
                            fnd1 = 1;
                        }

                        if(points.find(bl) != points.end()){
                            fnd2 = 1;
                        }

                        if(!fnd1 && fnd2){
                            P.insert(tl);
                            print(tl, "17");
                        }

                        if(fnd1 && !fnd2){
                            P.insert(bl);
                            print(bl, "18");
                        }

                        tl = {a.first - dy, a.second + dx};
                        bl = {b.first - dy, b.second + dx};

                        fnd1 = fnd2 = 0;

                        if(points.find(tl) != points.end()){
                            fnd1 = 1;
                        }

                        if(points.find(bl) != points.end()){
                            fnd2 = 1;
                        }

                        if(!fnd1 && fnd2){
                            P.insert(tl);
                            printf("%d %d | %d %d | %d %d | %d %d\n", a.first, a.second, b.first, b.second, bl.first, bl.second, dx, dy);
                            print(tl, "19");
                        }

                        if(fnd1 && !fnd2){
                            P.insert(bl);
                            print(bl, "20");
                        }
                    }
                }
            }
        }

        return P.size();
    }
};

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    MoreSquares test;


    printf("r: %d\n", test.countLocations( 23,
11,
13,
{7},
{0}
));

    return 0;
}