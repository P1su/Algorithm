function solution(phone_book) {
  phone_book.sort();//sort를 하면 가장 유사한 접두어가 옆에 오게 됨. 문자 기준 정렬!
    
  for (let i = 0; i < phone_book.length - 1; i++) {
    if (phone_book[i] === phone_book[i + 1].substring(0, phone_book[i].length)) {
      return false;
    }
  }

  return true;
}
