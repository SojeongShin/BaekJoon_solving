
import java.util.*;


public class prog_sort1 {

	public static void main(String[] args) {
		int[] array = {1, 5, 2, 6, 3, 7, 4}; 
		int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
		
	    int N = commands.length;
	    int[] answer = new int [N];
	   
	    for(int i=0; i<N; i++) {
	    	int[] list = new int[commands[i][1] - commands[i][0]];
	    	
	    	int start = commands[i][0]-1;
	    	int end = commands[i][1];
	    	int index = commands[i][2]-1;
	    	
	    	list = Arrays.copyOfRange(array,start,end);
	    	Arrays.sort(list);
	    	answer[i] = list[index];
	    	
	    	System.out.println(answer[i]);
	    }

	}

}
