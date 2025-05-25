#include <iostream>
using namespace std;

bool is_letter(char ch){
    if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, word_count = 0, longest_word = 0, cur_length = 0;
    string s;
    cin >> n >> s;
    bool inside_parentheses = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') inside_parentheses = true;
        else if(s[i] == ')'){
            inside_parentheses = false;
            longest_word = max(longest_word, cur_length);
            cur_length = 0;
        }
        else if(inside_parentheses){
            if(is_letter(s[i]) && (!is_letter(s[i - 1]))) word_count++;
        }
        else {
            if(is_letter(s[i])) cur_length++;
            else{
                longest_word = max(longest_word, cur_length);
                cur_length = 0;
            }
        }
    }
    longest_word = max(longest_word, cur_length);
    cout << longest_word << ' ' << word_count << '\n';
    return 0;
}