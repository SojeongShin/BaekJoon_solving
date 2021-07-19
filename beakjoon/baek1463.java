package baekjoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/* 1로 만들기
 * 재귀법으로 풀기
 */

public class baek1463 {

	public static void main(String[] args) throws IOException {
	       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	       int X = Integer.parseInt(br.readLine());
	
	    System.out.println("2이상 1000000이하의 정수 입력: ");
		// 해당 배열의 요소가 연산 횟수
		int list [] = new int[X+1]; // 숫자를 그대로 표현하기 위함(배열 인덱스는 0부터 시작)
		list[0] = 0; list[1] = 0;  // 2이상의 수 만이 계산 대상
		
		
		for(int i=2; i<=X; i++) {
			
			list[i] = list[i-1]+1;  //1을 빼는 연산, 이 연산만 계속되면 최악의 결과
			
			if(i%2 == 0) list[i] = Math.min(list[i], list[i/2]+1);
			if(i%3 == 0) list[i] = Math.min(list[i], list[i/3]+1);
		}
		System.out.println(list[X]);
		br.close();
	}
	
}
