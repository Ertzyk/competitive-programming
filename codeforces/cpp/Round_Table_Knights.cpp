#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> divisors;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(n/i != i && i > 2){
                divisors.push_back(n/i);
            }
        }
    }
    if(n == 4) divisors.pop_back();
    for(int d: divisors){
        for(int i = 0; i < d; i++){
            bool flag = true;
            for(int j = i; j < n; j += d){
                if(!a[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}