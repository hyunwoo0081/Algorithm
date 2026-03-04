import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

public class Main {
	static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		int N = nextInt();
		int Q = nextInt();
		
		boolean visited[] = new boolean[N+1];
		for (int i = 0; i <= N; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < Q; i++) {
			int target = nextInt();
			
			int result = 0;
			int m = target;
			while (m > 0) {
				if (visited[m]) {
					result = m;
				}
				m /= 2;
			}
			
			// 못감
			if (result > 0) {
				sb.append(result+"\n");
			}
			else {
				visited[target] = true;
				sb.append("0\n");
			}
		}
		
		System.out.print(sb);
	}
	
	public static int nextInt() throws IOException {
		st.nextToken();
		return (int) st.nval;
	}
}