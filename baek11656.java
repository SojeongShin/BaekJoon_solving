import java.util.Arrays;
import java.util.Scanner;

public class Baek11656 {

	public static void main(String[] args) {
		//���ڿ� S �޾ƿ���
		Scanner sc = new Scanner(System.in);
		System.out.println("���ڿ� S �Է�(���ĺ��ҹ���, ����:1000���� �۰ų� ����) ");
		String S = sc.next();
		
		//���̻� ���ϱ� <substring>
		String[]arrayS = new String[S.length()];
		for(int i=0; i<arrayS.length; i++) {
			arrayS[i] = S.substring(i, arrayS.length);
		}
		
		//������ ���̻� �����ϱ�(���ĺ� ��) <sort>
		Arrays.sort(arrayS);
		
		for(int i=0; i<arrayS.length; i++) {
			System.out.println(arrayS[i]);
		}
		sc.close();
	}

}
