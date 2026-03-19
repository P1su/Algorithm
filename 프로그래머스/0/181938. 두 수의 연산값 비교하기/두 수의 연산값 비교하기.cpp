#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string sum = to_string(a) + to_string(b);
    string mul = to_string(2 * a * b);
    
    if(stoi(sum) >= stoi(mul)){
        return stoi(sum);
    }else{
        return stoi(mul);
    }
}