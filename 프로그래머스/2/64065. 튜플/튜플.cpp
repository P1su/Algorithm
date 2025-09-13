#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuple; // 집합값을 담는 이차원 벡터
    set<int> check; // 중복 체크용
    
    int st, en = 0;
    
    for(int i = 0 ; i < s.size()-1 ; i++){
        if(s[i] == '{'){
            st = i;
        }if(s[i] == '}'){
            en = i;
            
            string tmp = s.substr(st + 1, en - st - 1); // 집합 파싱
            
            stringstream ss(tmp);
            string token;
            vector<int> tempVec;
            
            while(getline(ss, token, ',')){ // 집합 내 원소 파싱
                tempVec.push_back(stoi(token));
            }
            
            tuple.push_back(tempVec);
        }
            
    }
    
    // 정렬
    sort(tuple.begin(), tuple.end(), [](vector<int>& a, vector<int>& b){return a.size() < b.size();});

    
    for(vector<int> group: tuple){
        for(int num: group){
            if(check.find(num) == check.end()){ // 중복이 아닐 경우 삽입
                answer.push_back(num);   
                check.insert(num);
            }
        }
    }
    
    return answer;
}