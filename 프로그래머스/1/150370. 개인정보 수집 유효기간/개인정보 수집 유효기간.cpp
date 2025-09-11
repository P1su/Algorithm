#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> termMap;
    unordered_map<string, string> privacyMap;
    
    int tYear = stoi(today.substr(0,4)); // 현재 년도
    int tMonth = stoi(today.substr(5,2)); // 현재 월
    int tDate = stoi(today.substr(8,2)); // 현재 일
    
    for(int i = 0 ; i < terms.size() ; i++){ // 약관과 기간 분리
        stringstream ss(terms[i]);
        
        string termType, validMonth;
        ss>>termType>>validMonth;
        
        termMap[termType] = stoi(validMonth);
    }
    
    for(int i = 0 ; i < privacies.size() ; i++){ // 개인정보와 약관 분리
        stringstream ss(privacies[i]);
        
        string privacyDate, privacyTerm;
        ss>>privacyDate>>privacyTerm;
        
        privacyMap[privacyDate] = privacyTerm;
    }
    
    for(int i = 0 ; i < privacies.size() ; i++){
        int year = stoi(privacies[i].substr(0,4)); // 개인정보 년도
        int month = stoi(privacies[i].substr(5,2)); // 개인정보 월
        int date = stoi(privacies[i].substr(8,2)); // 개인정보 일
        
        month += termMap[privacies[i].substr(11, 1)]; // 개인정보 약관에 맞는 기간을 더함
        
        if(month > 12){ // 달이 12월을 넘어가면 년을 추가해줌
            while(month >12){
                year ++;
                month -= 12;
            }
        }
            cout<<year<<" "<<month<<" "<<date<<endl;

        if(tYear > year){
            answer.push_back(i+1);    
        }else if(tYear == year && tMonth > month){
            answer.push_back(i+1);
        }else if(tYear == year && tMonth == month && tDate > date - 1){ // 일은 하루를 빼서 계산해줘야 함
            answer.push_back(i+1);
        }
    }
    /*
    for(const auto& it: privacyMap){
        cout<<"현재 개인정보: "<<it.first<<"의 약관 종류는 "<<it.second<<endl;
        cout<<"해당 약관의 유효기간은"<<termMap[it.second]<<endl;
        
        int year = stoi(it.first.substr(0,4));
        int month = stoi(it.first.substr(5,2));
        int date = stoi(it.first.substr(8,2));
        
        cout<<year<<" "<<month<<" "<<date<<endl;
        
        month += termMap[it.second];
        if(month > 12){
            year ++;
            month -= 12;
        }
        cout<<year<<" "<<month<<" "<<date<<endl;
        cout<<tYear<<" "<<tMonth<<" "<<tDate<<endl<<endl;
        if(tYear > year){
            answer.push_back(cnt);    
        }else if(tYear == year && tMonth > month){
            answer.push_back(cnt);
        }else if(tYear == year && tMonth == month && tDate > date - 1){
            answer.push_back(cnt);
        }
        
        cnt++;
    }
    */
    return answer;
}