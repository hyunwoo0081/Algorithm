import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main
{
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringBuilder sb = new StringBuilder();
	private static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		long allBits = 0;
		long bits[] = new long[N];
		for (int n = 0; n < N; n++) {
			st = new StringTokenizer(br.readLine());
			
			//String name = 
			st.nextToken();
			String value = st.nextToken();
			
			bits[n] = 0L;
			for (int i = 0; i < value.length(); i++) {
				bits[n] = (bits[n] << 1) | (value.charAt(i) == 'Y' ? 1L : 0L);
			}
			allBits |= bits[n];
		}
		
		if (allBits == 0) {
			System.out.println(-1);
			return;
		}
		
		System.out.println(search(bits, N, 0, 0, allBits));
	}
	
	public static int search(long bits[], int N, int depth, int cnt, long used) {
		if (used == 0) {
			return cnt;
		}
		
		if (depth == N) {
		    return N;
		}
		
		return Math.min(
		        search(bits, N, depth+1, cnt, used),
				search(bits, N, depth+1, cnt+1, used & (~bits[depth]))
			);
	}
}
