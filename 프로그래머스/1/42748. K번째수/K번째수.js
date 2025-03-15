//i부터 j까지 자르고 정렬하기 -> 해당 배열의 k번째 수 구하기

function solution(array, commands) {
    var answer = [];

    commands.forEach(command => {
        //slice(a, b) a부터 b-1까지 잘라서 새 배열을 반환한다. b 는 미포함. 
        var tempArray = array.slice(command[0]-1, command[1]);
        //sort((a, b) => a - b) compare 함수 작성을 습관화하자.
        tempArray.sort((a, b) => a - b);
        //배열에 값을 추가할 때는 push 사용
        answer.push(tempArray[command[2]-1]);
    });
    
    return answer;
}

