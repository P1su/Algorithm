function solution(food) {
    
    var answer = '';
    
    for(i = 1 ; i < food.length ; i++) {
        //repeat(n) => 해당 문자열을 n번 반복
        answer += String(i).repeat(food[i]/2);
    }
    //split() => 문자열을 배열로
    //reverse() => 배열 뒤집기
    //join() => 배열을 문자열로 합치기
    //var tmp = answer.split('').reverse().join('') <- 기존 방식
    
    //스프레드 연산자
    return answer + '0' + [...answer].reverse().join('');
    
}