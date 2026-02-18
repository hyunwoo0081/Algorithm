import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

public class Main {
	static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static StringBuilder sb = new StringBuilder();
	static final int SIZE = 1_000_000;
	
	static long arr[] = new long[SIZE];
	
	public static void main(String[] args) throws IOException {
		int T = readInt();
		while (T --> 0) {
			int N = readInt();
			for (int i = 0; i < N; i++) {
				arr[i] = readInt();
			}
			
			long maxN = 0;
			long result = 0;
			for (int i = N-1; i >= 0; i--) {
				maxN = Math.max(maxN, arr[i]);
				result += maxN - arr[i];
			}
			
			sb.append(result + "\n");
		}
		System.out.print(sb);
	}
	
	static int readInt() throws IOException {
		st.nextToken();
		return (int) st.nval;
	}

}
