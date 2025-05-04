#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0, dd, aa;
    cin >> n;
    // vector<int> results(n + 1, 0);
    for(int d = 3; d <= n; d++){
        // int temp = result;
        dd = d*d;
        for(int a = 1; a <= d - 1; a++){
            aa = a*a;
            if(a&1){
                for(int b = a + 1; b*b < dd - aa; b += 2){
                    int x = dd - aa - b*b;
                    int root = floor(sqrt(x));
                    if(root*root == x) result++;
                }
            } else {
                for(int b = a; b*b < dd - aa; b++){
                    int x = dd - aa - b*b;
                    int root = floor(sqrt(x));
                    if(root*root == x) result++;
                }
            }
        }
        // results[d] = result - temp;
    }
    // for(int i = 0; i <= n; i++){
    //     cout << i << ": " << results[i] << '\n';
    // }
    cout << result;
    return 0;
}