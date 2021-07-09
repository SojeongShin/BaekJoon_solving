package baekjoon;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class baek1764_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("���� ���� ��� ���� ���� ���� ��� �� ������� �Է� ");
		int N = sc.nextInt();  // ���� ���� ��� ��
		int M = sc.nextInt();  // ���� ���� ��� ��
		int num = 0;  // �躸���� ��

		HashSet<String> hs = new HashSet(); // <HashSet>�ߺ�
		ArrayList<String> list = new ArrayList();
		
		System.out.println("��,�� ������ �̸��� �Է�(����x,�ҹ���,20���� ��) ");
		
		for(int i=0; i<N; i++) {
			hs.add(sc.next());  // �赵 ���� ��� �޾ƿ���
			}	
		for(int i=0; i<M; i++) {
			String noSee = sc.next();  // ���� ���� ��� �޾ƿ���
			// set.contains(O(1))�� �ð����⵵�� list(O(N))���� 1/n��ŭ �� ����
			if (hs.contains(noSee)) {  // �赵 ���� ����� ����-> list�� add
				num++;  // �躸�� �� ����
				list.add(noSee);
				}
			}
		Collections.sort(list);
		System.out.println("�躸���� ��:"+ num +"\n�躸�� ���");
		for(int i=0; i<list.size(); i++) {  // <size()>
			System.out.println(list.get(i));  // ����Ʈ�� �о����
		}
		sc.close();
	}
}
