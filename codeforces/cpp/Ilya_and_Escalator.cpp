#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    double p, res = 0;
    cin >> n >> p >> t;
    for(int i = 1; i <= t; i++){
        double cur = min((double)i, (double)n);
        int i_prim = min(i, t - i);
        int p_cnt = 0, one_minus_p_cnt = 0, numerator_cnt = t - i_prim + 1, denominator_cnt = 2;
        while(denominator_cnt <= i_prim && numerator_cnt <= t){
            if(cur > 1){
                if(p_cnt < i){
                    cur *= p;
                    p_cnt++;
                } else if(one_minus_p_cnt < t - i){
                    cur *= 1 - p;
                    one_minus_p_cnt++;
                } else {
                    cur /= (double)denominator_cnt;
                    denominator_cnt++;
                }
            } else {
                cur *= (double)numerator_cnt;
                numerator_cnt++;
            }
        }
        while(p_cnt < i){
            cur *= p;
            p_cnt++;
        }
        while(one_minus_p_cnt < t - i){
            cur *= 1 - p;
            one_minus_p_cnt++;
        }
        while(denominator_cnt <= i_prim){
            cur /= (double)denominator_cnt;
            denominator_cnt++;
        }
        while(numerator_cnt <= t){
            cur *= (double)numerator_cnt;
            numerator_cnt++;
        }
        res += cur;
    }
    cout << fixed << setprecision(10) << res << '\n';
    return 0;
}