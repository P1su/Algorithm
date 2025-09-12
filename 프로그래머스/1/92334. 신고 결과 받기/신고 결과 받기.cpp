#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map <string, int> reportCntMap;
    map <string, set<string>> reportMap;
    
    for(int i = 0 ; i < report.size() ; i++){
        stringstream ss(report[i]); // 공백 제거
        
        string reporter, reported;
        ss>>reporter>>reported;
        
        // 중복 방지를 위해 set 사용
        reportMap[reporter].insert(reported); // 유저와 신고한 ID를 삽입
    }
    
    for(const auto& it: reportMap){
        for(const auto& val: it.second){ // set을 돌며 신고당한 횟수 카운트
            reportCntMap[val]++;
        }
    }
    
    for(string user: id_list){
        int cnt = 0;
        for(const auto& val: reportMap[user]){ // 유저의 신고 set에서 신고한 유저의 신고 횟수가 k 이상이면 카운트
            if(reportCntMap[val] >= k){
                cnt++;
            }
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}