#include <iostream>
#include <vector>
using namespace std;

bool check_row(int x, int y, const vector<string> &matrix){
    return matrix[x][y] == 'X' && 
    matrix[x][y + 1] == 'X' &&
    matrix[x][y + 2] == 'X' &&
    matrix[x][y + 3] == 'X' &&
    matrix[x][y + 4] == 'X';
}

bool check_column(int x, int y, const vector<string> &matrix){
    return matrix[x][y] == 'X' && 
    matrix[x + 1][y] == 'X' &&
    matrix[x + 2][y] == 'X' &&
    matrix[x + 3][y] == 'X' &&
    matrix[x + 4][y] == 'X';
}

bool check_d1(int x, int y, const vector<string> &matrix){
    return matrix[x][y] == 'X' && 
    matrix[x + 1][y + 1] == 'X' &&
    matrix[x + 2][y + 2] == 'X' &&
    matrix[x + 3][y + 3] == 'X' &&
    matrix[x + 4][y + 4] == 'X';
}

bool check_d2(int x, int y, const vector<string> &matrix){
    return matrix[x][y] == 'X' && 
    matrix[x - 1][y + 1] == 'X' &&
    matrix[x - 2][y + 2] == 'X' &&
    matrix[x - 3][y + 3] == 'X' &&
    matrix[x - 4][y + 4] == 'X';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> matrix(10);
    for(string &x: matrix) cin >> x;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(matrix[i][j] == '.'){
                matrix[i][j] = 'X';
                for(int k = 0; k < 10; k++) for(int l = 0; l < 6; l++){
                    if(check_row(k, l, matrix)){
                        cout << "YES\n";
                        return 0;
                    }
                }
                for(int k = 0; k < 6; k++) for(int l = 0; l < 10; l++){
                    if(check_column(k, l, matrix)){
                        cout << "YES\n";
                        return 0;
                    }
                }
                for(int k = 0; k < 6; k++) for(int l = 0; l < 6; l++){
                    if(check_d1(k, l, matrix)){
                        cout << "YES\n";
                        return 0;
                    }
                }
                for(int k = 4; k < 10; k++)for(int l = 0; l < 6; l++){
                    if(check_d2(k, l, matrix)){
                        cout << "YES\n";
                        return 0;
                    }
                }
                matrix[i][j] = '.';
            }
        }
    }
    cout << "NO\n";
    return 0;
}