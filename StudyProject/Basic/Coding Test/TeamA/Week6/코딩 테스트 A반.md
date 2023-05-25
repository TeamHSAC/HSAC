# 코딩 테스트 A반 





#### 2023.05.07 - 비 대면 코드 리뷰

---



##### 백준 1235번 - 학생번호 - 박지원, 김진하, 이경미



![image-20230507224358165](C:\Users\PC\AppData\Roaming\Typora\typora-user-images\image-20230507224358165.png)

![image-20230507224437751](C:\Users\PC\AppData\Roaming\Typora\typora-user-images\image-20230507224437751.png)



---

### 박지원

---



```java
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
	public class Main{
	   public static void main(String[]args) throws IOException{
	      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	      BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
	      int n = Integer.parseInt(br.readLine());
	      HashSet <String> hs = new HashSet<String>();
	      String arr[] = new String[n];
	      for(int i=0;i<n;i++) {
	    	  arr[i]=br.readLine();
	      }
	      int ans = 0;
	      int start = arr[0].length();
	      for(int i=start-1;i>=0;i--) {//7
		    	 hs.clear();
	    	  for(int j=0;j<n;j++) {//3
	    		 String sub = arr[j].substring(i);
	    		 hs.add(sub);
	    	  }
	    	  if(arr.length==hs.size()) {
	    		  String sub = arr[0].substring(i);
	    		  ans = sub.length();
	    		  break;
	    	  }
	    	  else
	    		  continue;
	      }
	      bw.write(ans+"\n");
	      bw.flush();
	      bw.close();
	   }
	}
```



---

### 김진하

---



```java
package Practice;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;

public class Main{ 
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int n=Integer.parseInt(br.readLine());
		String tmp[]=new String[n];
		for(int i=0;i<n;i++) {
			tmp[i]=br.readLine();
		}
		for(int i=1;i<=tmp[0].length();i++) { 
			//어차피 입력된 값들의 길이는 다 같으니 임의로 tmp[0]의 길이를 기준으로 정함.
			HashSet<String>set=new HashSet<String>();
			//중복을 제거하기 위해 HashSet을 이용함.
			for(int j=0;j<tmp.length;j++) {
				String order=tmp[j];
				set.add(order.substring(order.length()-i));
				//substring으로 문자열을 뒤에서부터 i를 빼가며 자름
			}
			if(set.size()==n) {
				//set의 size가 n의 개수와 같으면 중복된 것이 없다는 뜻이므로
				bw.write(i+"\n");
				//i는 잘린 문자열의 길이를 뜻함.
				break;
			}
		}
		bw.flush();
		bw.close();
		br.close();
	}
}
```



---

### 이경미

---



```java
public class 1235 {
   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine()); 
      Set<String> set = new HashSet<>(); 
 
      String[] input = new String[N];
      for(int i=0;i<N;i++) input[i] = br.readLine();
      int len = input[0].length();
 
      for(int k=1;k<=len;k++){
         for(int i=0;i<N;i++){
            set.add(input[i].substring(len-k));
         }
         if(set.size()==N){
            System.out.println(k);
            return;
         }
         set.clear();
      }
   }
}
```





##### 백준  2941번 - 크로아티아 알파벳 - 이재욱



![image-20230507225334091](C:\Users\PC\AppData\Roaming\Typora\typora-user-images\image-20230507225334091.png)

![image-20230507225450666](C:\Users\PC\AppData\Roaming\Typora\typora-user-images\image-20230507225450666.png)

![image-20230507225520635](C:\Users\PC\AppData\Roaming\Typora\typora-user-images\image-20230507225520635.png)



---

### 이재욱

---



```java
package stdweek5;

import java.util.Scanner;

public class week5 {
	public static void main(String[] args) {
    
		Scanner in = new Scanner(System.in);
        
		String str = in.nextLine();
        
		int count = 0;
 
		for (int i = 0; i < str.length(); i++) {
 
			char ch = str.charAt(i);
 
			if(ch == 'c') {			
				if(i < str.length() - 1) {
					if(str.charAt(i + 1) == '=') {		
						
						i++;		
					}
					else if(str.charAt(i + 1) == '-') {
						i++;
					}
				}
			}
		    
			else if(ch == 'd') {
				if(i < str.length() - 1) {
					if(str.charAt(i + 1) == 'z') {
						if(i < str.length() - 2) {
							if(str.charAt(i + 2) == '=') {	
								i += 2;
							}
						}
					}
		        
					else if(str.charAt(i + 1) == '-') {	
						i++;
					}
				}
			}
		    
			else if(ch == 'l') {
				if(i < str.length() - 1) {
					if(str.charAt(i + 1) == 'j') {	
						i++;
					}
				}
			}
		    
			else if(ch == 'n') {
				if(i < str.length() - 1) {
					if(str.charAt(i + 1) == 'j') {
						i++;
					}
				}
			}
 
			else if(ch == 's') {
				if(i < str.length() - 1) {
					if(str.charAt(i + 1) == '=') {
						i++;
					}
				}
		    }
 
			else if(ch == 'z') {
				if(i < str.length() - 1) {
					if(str.charAt(i + 1) == '=') {
						i++;
					}
				}
			}
		    
			count++;
 
		}
 
		System.out.println(count);
	}
```

