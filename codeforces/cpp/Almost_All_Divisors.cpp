#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> d(n);
        for (long long &x: d) cin >> x;
        sort(d.begin(), d.end());
        long long res = (d.size()%2) ? pow(d[d.size()/2], 2) : d[d.size()/2]*d[d.size()/2 - 1];
        bool flag = true;
        for(int i = 0; i < (d.size() - 1)/2; i++){
            if(res != d[i]*d[d.size() - 1 - i]){
                cout << -1 << "\n";
                flag = false;
                break;
            }
        }
        if(flag){
            long long copy = res;
            int k = 2, num_of_div = 1;
            while(copy > 1){
                int alpha = 0;
                while(copy%k == 0){
                    copy /= k;
                    alpha++;
                }
                num_of_div *= (alpha + 1);
                k++;
            }
            if(d.size() != num_of_div - 2){
                cout << -1 << "\n";
            } else {
                cout << res << "\n";
            }
        }
    }
    return 0;
}