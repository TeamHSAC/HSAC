# 코딩테스트 A반 - Week 6





## 백준 - 12891번 DNA 비밀번호

 ##### 튜터 - 박지원



![](https://github.com/TeamHSAC/HSAC/blob/main/StudyProject/Basic/Coding%20Test/TeamA/image/image-20230525195448537.png?raw=true)

![](https://github.com/TeamHSAC/HSAC/blob/main/StudyProject/Basic/Coding%20Test/TeamA/image/image-20230525195826789.png?raw=true)

## 코드

 

```java
import java.io.*;
import java.util.*;
import java.lang.*;
public class Main {
    static char[]s;
    static int ok;
    static int cor[];
    static int count = 0;
    static char dna[] = {'A','C','G','T'};

    static int myarr[]=new int[4];//내 배열
    static void plus(char c){
        switch(c){
            case 'A':
                myarr[0]++;
                if(cor[0]==myarr[0])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok++;
                break;
            case 'C':
                myarr[1]++;
                if(cor[1]==myarr[1])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok++;
                break;
            case 'G':
                myarr[2]++;
                if(cor[2]==myarr[2])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok++;
                break;
            case 'T':
                myarr[3]++;
                if(cor[3]==myarr[3])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok++;
                break;
        }
    }
    static void minus(char c){
        switch(c){
            case 'A':
                if(cor[0]==myarr[0])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok--;
                    myarr[0]--;
                break;
            case 'C':
                if(cor[1]==myarr[1])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok--;
                    myarr[1]--;
                break;
            case 'G':
                if(cor[2]==myarr[2])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok--;
                    myarr[2]--;
                break;
            case 'T':
                if(cor[3]==myarr[3])//맞춰야하는 배열의 0번째 요소가 지금 선택한 배열의 0 번째 요소보다 크거나 같으면
                    ok--;
                    myarr[3]--;
                break;
        }
    }
    public static void main(String[]args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());//9 8
        int len = Integer.parseInt(st.nextToken());//베이스 문자열 길이
        int ps = Integer.parseInt(st.nextToken());//슬라이딩 윈도우 길이
        s = br.readLine().toCharArray();//베이스 문자열
        st=new StringTokenizer(br.readLine());//최소 필요 값들
        ok=0;
        cor = new int[4];//정답 배열
        for(int i=0;i<4;i++){
            int m = Integer.parseInt(st.nextToken());
            cor[i]=m;
            if(m==0)
                ok++;
        }
        for(int i=0;i<ps;i++){
            plus(s [i]);
        }
        if(ok==4)
            count++;
        int n = 0;
        for(int i=ps;i<len;i++){
            n=i-ps;
            plus(s[i]);
            minus(s[n++]);
            if(ok==4)
                count++;
        }
        System.out.println(count);


    }
}
```







## 백준 - 11004번 K번째 수

##### 조장 - 김진하

![](https://github.com/TeamHSAC/HSAC/blob/main/StudyProject/Basic/Coding%20Test/TeamA/image/image-20230525200245932.png?raw=true)



## 코드



```java
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{ //11004
   public static void main(String[]args) throws IOException{
      BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
      StringTokenizer st= new StringTokenizer(br.readLine()," ");
      int n=Integer.parseInt(st.nextToken());
      int k=Integer.parseInt(st.nextToken());
      int a[]=new int[n];
      st=new StringTokenizer(br.readLine()," ");
      for(int i=0;i<n;i++) {
         a[i]=Integer.parseInt(st.nextToken());
      }
      Arrays.sort(a);
      bw.write(a[k-1]+"\n");
      bw.flush();
      bw.close();
      br.close();
   }
}
```







## 백준 - 11659번 구간 합 구하기 4

##### 조원 - 이재욱

![](https://github.com/TeamHSAC/HSAC/blob/main/StudyProject/Basic/Coding%20Test/TeamA/image/image-20230525200551963.png?raw=true)



## 코드



```JAVA
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//매인 클래스 정의
public class Main {
    //I/O예외처리
    public static void main(String[] args) throws IOException {
        //콘솔로 부터 입력 받아오기위해 메인 메소드 안에 버퍼리더 객체생성
        BufferedReader bufferedReader =
                new BufferedReader(new InputStreamReader(System.in));
        //스트링토크나이저 객체 생성 첫 번째 줄에 작성한 값을 받아온다
        StringTokenizer stringTokenizer =
                new StringTokenizer(bufferedReader.readLine());
        //suNO(숫자 개수)와 quizNO(질의 개수)는 공백을 기준으로 나뉜다 이값은 각각 퀴즈 수와 수행할 쿼리 수를 나타냅니다.
        //next.Token()을 하면 string을 받아오므로 Integer.parseInt를 사용한다.
        int suNO = Integer.parseInt(stringTokenizer.nextToken());
        int quizNO = Integer.parseInt(stringTokenizer.nextToken());
        //합배열 선언 (사람은 1부터시작하지만 컴퓨터는 0부터시작하므로)0번쨰 인덱스를 무시하고자 + 1을 했다.
        long[]S = new long[suNO +1];
        //입력된 수를 배열로 받아온다.
        stringTokenizer =
                new StringTokenizer(bufferedReader.readLine());
        for (int i =1; i<=suNO; i++){
            S[i] = S[i-1] + Integer.parseInt(stringTokenizer.nextToken());
        }

       //quizNO수 만큼 계산
        //i번째부터 j번째 수 까지의 합을 구하여라
        for (int q = 0; q <quizNO; q++) {

            stringTokenizer =
                    new StringTokenizer(bufferedReader.readLine());

            int i = Integer.parseInt(stringTokenizer.nextToken());
            int j = Integer.parseInt(stringTokenizer.nextToken());
            //계산 결과는 System.out.println()을 사용하여 콘솔에 인쇄됩니다.
            System.out.println(S[j] - S[i-1]);
        }
    }
}
```







## 백준 - 2018번 수들의  합 5

##### 조원 - 이경미

![](https://github.com/TeamHSAC/HSAC/blob/main/StudyProject/Basic/Coding%20Test/TeamA/image/image-20230525200909097.png?raw=true)



## 코드



```JAVA
import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()); //숫자를 받아서 int형으로 변환 후 N에 저장
		int count=1; // 자기 자신 하나로 이루어진 경우의 수 미리저장
		int start_index=1; //시작 숫자
		int end_index=1; // 끝 숫자
		int sum=1; //sum=start_index + end_index
		
		while(end_index!=N) {
			if(sum==N) {
				count++;
				end_index++;
				sum=sum+end_index;
				
			}
			else if(sum>N) {
				sum=sum-start_index;
				start_index++;
			}
			else {
				end_index++;
				sum=sum+end_index;
			}
			
		}
		System.out.println(count);
		

	}

}

```







## 백준 2164번 - 카드2

##### 조원 - 김수아

![](https://github.com/TeamHSAC/HSAC/blob/main/StudyProject/Basic/Coding%20Test/TeamA/image/image-20230525201131892.png?raw=true)



## 코드 

```JAVA
package bj2164;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> myQueue = new LinkedList<>();
		int N = sc.nextInt();				// 카드 개수
		for(int i = 1; i <= N; i++) {
			myQueue.add(i);					// 1부터 차례대로 쌓기
		}
		
		while(myQueue.size()>1) {			// 큐의 사이즈가 1보다 클 때까지
			myQueue.poll();					// 맨위의 카드 버리기
			myQueue.add(myQueue.poll());	// 제일 아래에 넣어주기
		}
		System.out.println(myQueue.poll());	// 출력
	}
}

```

