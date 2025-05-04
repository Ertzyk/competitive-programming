#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    int g = gcd(a, b);
    set<int> divisors;
    for(int i = 1; i*i <= g; i++){
        if(g%i == 0){
            divisors.insert(i);
            divisors.insert(g/i);
        }
    }
    vector<int> div(divisors.begin(), divisors.end());
    while(n--){
        int cur_max = INT_MAX, l = 0, r = div.size() - 1, low, high;
        cin >> low >> high;
        while(l <= r){
            int m = l + (r - l)/2;
            if(div[m] > high){
                r = m - 1;
            } else {
                l = m + 1;
            }
            if(div[m] <= high && div[m] >= low){
                cur_max = div[m];
            }
        }
        cout << ((cur_max == INT_MAX) ? -1 : cur_max) << '\n';
    }
    return 0;
}