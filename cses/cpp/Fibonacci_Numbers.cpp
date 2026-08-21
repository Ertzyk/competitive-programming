#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;

vector<vector<ll>> matrix_multiplication(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            for(int k = 0; k < B.size(); k++){
                C[i][j] += A[i][k]*B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> binary_matrix_exponentiation(vector<vector<ll>> A, ll b){
    vector<vector<ll>> result(A.size(), vector<ll>(A.size(), 0));
    for(int i = 0; i < A.size(); i++) result[i][i] = 1;
    while(b > 0){
        if(b%2) result = matrix_multiplication(result, A);
        A = matrix_multiplication(A, A);
        b /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n == 0) cout << "0\n";
    else{
        vector<vector<ll>> matrix = binary_matrix_exponentiation({{1, 1}, {1, 0}}, n - 1);
        cout << matrix[0][0] << '\n';
    }
    return 0;
}