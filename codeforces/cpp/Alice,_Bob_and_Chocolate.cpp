#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int &x : t) cin >> x;
    int pa = 0, pb = n - 1, sum_a = 0, sum_b = 0;
    while (pa != pb){
        if (sum_a <= sum_b){
            sum_a += t[pa];
            pa++;
        } else {
            sum_b += t[pb];
            pb--;
        }
    }
    if (sum_a <= sum_b){
        pa++;
    }
    cout << pa << " " << n - pa;
    return 0;
}