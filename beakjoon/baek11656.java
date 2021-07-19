import java.util.Arrays;
import java.util.Scanner;

public class Baek11656 {

	public static void main(String[] args) {
		//문자열 S 받아오기
		Scanner sc = new Scanner(System.in);
		System.out.println("문자열 S 입력(알파벳소문자, 길이:1000보다 작거나 같음) ");
		String S = sc.next();
		
		//접미사 구하기 <substring>
		String[]arrayS = new String[S.length()];
		for(int i=0; i<arrayS.length; i++) {
			arrayS[i] = S.substring(i, arrayS.length);
		}
		
		//추출한 접미사 정렬하기(알파벳 순) <sort>
		Arrays.sort(arrayS);
		
		for(int i=0; i<arrayS.length; i++) {
			System.out.println(arrayS[i]);
		}
		sc.close();
	}

}
