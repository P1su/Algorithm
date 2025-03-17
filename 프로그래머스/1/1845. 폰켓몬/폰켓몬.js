//고유 번호를 맵에 저장함
//맵의 크기 == 최대로 가질 수 있는 포켓몬 마리수
//따라서 맵의 크기가 더 크면 N/2마리를 보장하며, 그것이 아니라면 맵의 크기만큼만 번호 조합이 가능
function solution(nums) {
    const cnt = nums.length/2;
    const map = new Map();
    
    for(const num of nums){
       if(map.get(num)){
           continue;
       } else map.set(num, true);
    };
    
    //map은 length가 아닌 size 프로퍼티
    const mapSize = map.size;
    
    if(mapSize > cnt)return cnt;
    else return mapSize;
}