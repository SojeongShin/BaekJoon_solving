package baekjoon;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class baek1764_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("듣지 못한 사람 수와 보지 못한 사람 수 순서대로 입력 ");
		int N = sc.nextInt();  // 듣지 못한 사람 수
		int M = sc.nextInt();  // 보지 못한 사람 수
		int num = 0;  // 듣보잡의 수

		HashSet<String> hs = new HashSet(); // <HashSet>중복
		ArrayList<String> list = new ArrayList();
		
		System.out.println("듣,보 순으로 이름을 입력(띄어쓰기x,소문자,20글자 내) ");
		
		for(int i=0; i<N; i++) {
			hs.add(sc.next());  // 듣도 못한 사람 받아오기
			}	
		for(int i=0; i<M; i++) {
			String noSee = sc.next();  // 보도 못한 사람 받아오기
			// set.contains(O(1))의 시간복잡도는 list(O(N))보다 1/n만큼 더 빠름
			if (hs.contains(noSee)) {  // 듣도 못한 사람에 포함-> list에 add
				num++;  // 듣보의 수 증가
				list.add(noSee);
				}
			}
		Collections.sort(list);
		System.out.println("듣보잡의 수:"+ num +"\n듣보잡 명단");
		for(int i=0; i<list.size(); i++) {  // <size()>
			System.out.println(list.get(i));  // 리스트값 읽어오기
		}
		sc.close();
	}
}
