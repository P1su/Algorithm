function solution(number, limit, power) {
    var answer = 0;
    var arr = [];
    
    for(i = 1 ; i <= number ; i++){
        var cnt = 0;
        for(j = 1 ; j <= Math.sqrt(i); j++) {
            if(i % j === 0){
                cnt++;
                if(i / j != j) cnt++;
            }
        }
        
        if(cnt > limit)cnt = power;
        arr.push(cnt);
    }
    
    arr.forEach((num) => {
        answer += num;
    });
    
    return answer;
}