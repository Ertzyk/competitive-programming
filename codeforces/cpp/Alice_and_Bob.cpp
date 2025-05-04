#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

int vector_gcd(vector<int> a){
    int result = a[0];
    for(int i = 1; i < a.size(); i++){
        result = gcd(result, a[i]);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    cout << ((*max_element(a.begin(), a.end())/vector_gcd(a) - n)%2 ? "Alice" : "Bob");
    return 0;
}