# 1차 스터디

### 1번 문제
```
#include <stdio.h>

void binary(int n) {  

     if (n < 2) { 
        printf("%d", n);
    }
    else {
        binary(n / 2);
        printf("%d", n % 2);
    }
}


int main () {

    int n;
    printf("숫자를 입력하세요: ");
    scanf("%d", &n);
    printf("%d의 이진수: 0b", n);
    binary(n);
    return 0;
}
```

### 2번 문제
사진 첨부


### 3번 문제
1)버스: CPU,메모리,보조기억장치,입출력장치 간의 명령어,데이터를 전달할 수 있게 해줌. 입출력 버스는 외부기기에 데이터를 전달해주고 시스템 버스는 CPU,메모리 간에 데이터와 명령어를 전달해주기 때문에 구분되어 운용됨. 만약 구분되어 있지 않다면 각 버스간의 데이터,명령어 충돌이 일어나 병목현상이 일어날 수 있음.

(2)EUC-KR의  인코딩 방식은 완성형 인코당 방식이다. 완성형 인코딩 방식이란, 글자 하나에 코드를 부여하는 것이다. 한 글자는 16진수로 표현했을 때 2byte=16bit로 표현된다.
문제점: 모든 한글을 표현할 수 없다. 이를 해결하기 위해서 유니코드 UTF-8로 작성함. 각 나라의 문자나 기호를 통일하면 해결 가능

### 4번 문제
사진 첨부

### 5번 문제
```
<python>
import random

newArr = []

alphabetArr = [
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
  'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
]

for i in range(0, 10):
  newArr.append(alphabetArr[random.randrange(0, 26)].upper())

print(newArr)

<c>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char newArr[26];
  int num = 0;

  for (int i = 0; i < 10; i++) {
    num = rand() % 26;
    newArr[i] = alpha[num];
  }
  for (int i = 0; i < 10; i++) {
    printf("%c ", newArr[i] - 32);
  }

  return 0;
}

```