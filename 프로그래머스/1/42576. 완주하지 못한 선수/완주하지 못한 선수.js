//처음 생각한 방법 => map에 participant를 key로 설정하고, 중복되면 value를 늘려감
//반복문을 돌며 completion 에 대한 값이 존재하는지 확인 후 value 줄이기(이중반복문)
//이후 map에 남은 값을 return

//제시한 방법 => completion 에 대한 반복문을 돌며 participant에서 값 삭제
//한번 삭제하고 바로 내부 반복문을 break하여 중복이 되어도 하나만 삭제할 수 있도록 설정
//남은 값을 return => 시간 초과 발생... n^2이내로 해야함.

function solution(participant, completion) {
    const map = new Map();
    
    participant.forEach((runner) => {
        if(map.get(runner)){
            map.set(runner, map.get(runner) + 1);
        }else map.set(runner, 1);
    });
    
    completion.forEach((runner) => {
        map.set(runner, map.get(runner) - 1);
    })
    
    for(const [key, value] of map){
        if(value > 0)return key;
    }
        
}