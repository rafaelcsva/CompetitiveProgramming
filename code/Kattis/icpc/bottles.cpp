#include <bits/stdc++.h>

using namespace std;

const int N = 22;
const int D = 30;
const double eps = double(1e-3);
double a[N];
double b[N];

double calc(double x, int n){
    double ans = 0.0;

    for(int i = 0 ; i <= n ; i++){
        ans += a[i] * (pow(x, i + 1) / double(i + 1));
    }

    return ans * acos(-1.0);
}

int main(){
    int n;

    int test = 1;

    while(scanf("%d", &n) != EOF){
        for(int i = 0 ; i <= n ; i++){
            scanf("%lf", &b[i]);
        }

        for(int i = 0 ; i <= 2 * n ; i++){
            a[i] = 0.0;
        }

        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= n ; j++){
                a[i + j] += b[i] * b[j];
            }
        }

        n *= 2;

        double xlo, xhi;

        int inc;

        scanf("%lf %lf %d", &xlo, &xhi, &inc);

        double vol = calc(xhi, n) - calc(xlo, n);

        double tlo = xlo;

        printf("Case %d: %.2lf\n", test++, vol);

        if(vol < inc){
            printf("insufficient volume\n");
        }else{
            vector< double > marks;

            while(marks.size() < 8 && vol >= inc){
                double lo = xlo, hi = xhi;

                for(int i = 0 ; i < D ; i++){
                    double mid = (lo + hi) / 2.0;
                    double cvol = calc(mid, n) - calc(xlo, n);
                    // printf("%lf\n", cvol);
                    
                    if(fabs(cvol - inc) < eps){
                        // printf("pushado!\n");
                        marks.push_back(mid);
                        break;
                    }

                    if(cvol > inc){
                        hi = mid;
                    }else if(cvol < inc){
                        lo = mid;
                    }
                }

                xlo = marks[marks.size() - 1];
                vol = calc(xhi, n) - calc(xlo, n);
            }

            for(auto u: marks){
                printf("%.2lf ", u - tlo);
            }
            printf("\n");
        }
    }

    return 0;
}