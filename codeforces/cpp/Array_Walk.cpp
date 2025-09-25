#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        for(int i = 0; i < n - k - 1; i++) a.pop_back();
        int sum_a = accumulate(a.begin(), a.end(), 0);
        int result = sum_a;
        for(int i = 1; i <= min(z, k/2); i++){
            sum_a -= a[k - 2*i + 2] + a[k - 2*i + 1];
            int max_pair = 0;
            for(int j = 0; j <= k - 2*i; j++){
                max_pair = max(max_pair, a[j] + a[j + 1]);
            }
            result = max(result, sum_a + i*max_pair);
        }
        cout << result << '\n';
    }
    return 0;
}