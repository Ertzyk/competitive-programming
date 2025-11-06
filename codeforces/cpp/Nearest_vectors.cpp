#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const long double PI = acos(-1);

struct Vector{
    int idx;
    complex<long double> z;
    bool operator<(const Vector& other) const {
        return ((arg(z) >= 0) ? arg(z) : arg(z) + 2*PI) < ((arg(other.z) >= 0) ? arg(other.z) : arg(other.z) + 2*PI);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Vector> vectors;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        complex<long double> p(a, b);
        Vector v;
        v.idx = i;
        v.z = p;
        vectors.push_back(v);
    }
    sort(vectors.begin(), vectors.end());
    long double min_arg = 4;
    int idx_a = 1, idx_b = 2;
    for(int i = 0; i < n - 1; i++){
        long double arg1 = arg(vectors[i + 1].z), arg2 = arg(vectors[i].z);
        if(arg1 < 0) arg1 += 2*PI;
        if(arg2 < 0) arg2 += 2*PI;
        if(arg1 - arg2 < min_arg){
            min_arg = arg1 - arg2;
            idx_a = vectors[i].idx;
            idx_b = vectors[i + 1].idx;
        }
    }
    long double arg1 = arg(vectors[0].z), arg2 = arg(vectors[n - 1].z);
    if(arg1 < 0) arg1 += 2*PI;
    if(arg2 < 0) arg2 += 2*PI;
    if(arg1 - arg2 + 2*PI < min_arg){
        idx_a = vectors[0].idx;
        idx_b = vectors[n - 1].idx;
    }
    cout << idx_a << ' ' << idx_b << '\n';
    return 0;
}