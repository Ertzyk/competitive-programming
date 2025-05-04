#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, result = 0, carry = 0, x;
        cin >> n >> x;
        map<int, int> hashmap;
        while(n--){
            int a;
            cin >> a;
            hashmap[(x - 1)/a + 1]++;
        }
        for(auto key: hashmap){
            result += (key.second + carry)/key.first;
            carry = (key.second + carry)%key.first;
        }
        cout << result << '\n';
    }
    return 0;
}