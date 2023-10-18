#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <cctype>

using namespace std;

// string solution(string myString) {
//     string answer = "";
//     return answer;
// }

int main(void) {
    string str = "aBcDeFg"; 
    char c = 'a';
    toupper(c);
    str = c;
    cout << str;
}