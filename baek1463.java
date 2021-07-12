package baekjoon;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/* 1�� �����
 * ��͹����� Ǯ��
 */

public class baek1463 {

	public static void main(String[] args) throws IOException {
	       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	       int X = Integer.parseInt(br.readLine());
	
	    System.out.println("2�̻� 1000000������ ���� �Է�: ");
		// �ش� �迭�� ��Ұ� ���� Ƚ��
		int list [] = new int[X+1]; // ���ڸ� �״�� ǥ���ϱ� ����(�迭 �ε����� 0���� ����)
		list[0] = 0; list[1] = 0;  // 2�̻��� �� ���� ��� ���
		
		
		for(int i=2; i<=X; i++) {
			
			list[i] = list[i-1]+1;  //1�� ���� ����, �� ���길 ��ӵǸ� �־��� ���
			
			if(i%2 == 0) list[i] = Math.min(list[i], list[i/2]+1);
			if(i%3 == 0) list[i] = Math.min(list[i], list[i/3]+1);
		}
		System.out.println(list[X]);
		br.close();
	}
	
}
