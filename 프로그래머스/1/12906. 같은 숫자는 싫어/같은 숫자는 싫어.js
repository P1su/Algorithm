function solution(arr)
{
    var answer = [];
    var idx = 0;
    arr.forEach(num => {
        if(answer[idx - 1] != num){
            answer.push(num);
            idx++;
        }
    })
    
    return answer;
}