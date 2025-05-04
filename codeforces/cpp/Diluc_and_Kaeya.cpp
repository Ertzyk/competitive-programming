#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>
using namespace std;

int gcd(int a, int b){
    return ((b == 0) ? a : gcd(b, a%b));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, d = 0, k = 0;
        string s;
        cin >> n >> s;
        unordered_map<string, int> hashmap;
        for(int i = 0; i < n; i++){
            if(s[i] == 'D') d++;
            else k++;
            int g = gcd(d, k);
            hashmap[to_string(d/g) + ':' + to_string(k/g)]++;
            cout << hashmap[to_string(d/g) + ':' + to_string(k/g)] << " \n"[i == n - 1];
        }
    }
    return 0;
}