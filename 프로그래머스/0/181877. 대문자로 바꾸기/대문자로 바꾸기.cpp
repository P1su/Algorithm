#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (auto& c : myString) {
        c = toupper(c);
    }
    return myString;
}