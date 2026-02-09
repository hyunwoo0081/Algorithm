import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
 
public class Solution
{
    private static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    private static StringBuilder sb = new StringBuilder();
    private static List<Core> cores = new ArrayList<>();
    public static int dx[] = {1, 0, -1, 0};
    public static int dy[] = {0, 1, 0, -1};
    public static int visited[][];
    public static int maxSelected = 0;
    public static int minSum = 987654321;
    
    
    
    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
        	int N = readInt();
        	
        	visited = new int[N][N];
        	
        	cores.clear();
        	for (int y = 0; y < N; y++) {
        		for (int x = 0; x < N; x++) {
        			visited[y][x] = 0;
        			
        			if (readInt() == 1) {
        				cores.add(new Core(x, y));
        				visited[y][x] = 1;
        			}
        		}
        	}
        	
        	
        	// 선 연결 못하는 곳 
        	for (Core c1 : cores) {
        		// 가장 자리에 있는 경우
        		if (c1.x == 0 || c1.x == N-1 || c1.y == 0 || c1.y == N-1) {
        			c1.isEdge = true;
        			continue;
        		}
        		
        		for (Core c2: cores) {
        			if (c1 == c2) continue;
        			
        			// c1 => target
        			if (c1.x == c2.x) {
        				if (c1.y < c2.y) c1.canMove[1] = false;
        				else c1.canMove[3] = false;
        			}
        			else if (c1.y == c2.y) {
        				if (c1.x < c2.x) c1.canMove[0] = false;
        				else c1.canMove[2] = false;
        			}
        		}
        	}
        	
        	drawLine(N);
        	
        	sb.append("#"+t+" "+(minSum)+"\n");
        }
        
        System.out.print(sb);
    }
    
    static void printVisited(int N) {
    	for (int y = 0; y < N; y++) {
    		System.out.println(Arrays.toString(visited[y]));
    	}
    	System.out.println();
    }
    
    static void drawLine(int N) {
    	maxSelected = -1;
    	minSum = 987654321;
    	
    	drawLineReculsive(0, 0, 0, N);
    }
    
    static void drawLineReculsive(int depth, int sum, int selectedCnt, int N) {
    	if (depth >= cores.size()) {
    		if (selectedCnt > maxSelected || selectedCnt == maxSelected && sum < minSum) {
    			maxSelected = selectedCnt;
    			minSum = sum;
    		}
    		return;
    	}
    	
    	if (maxSelected > selectedCnt + cores.size() - depth) {
    		return;
    	}
    	
    	Core core = cores.get(depth);
    	if (core.isEdge) {
    		drawLineReculsive(depth+1, sum, selectedCnt+1, N);
    		return;
    	}
    	
    	for (int dir = 0; dir < 4; dir++) {
    		if (!core.canMove[dir]) continue;
    		
    		int len = setLine(core, dir, N);
    		if (len < 0) continue;
    		
    		drawLineReculsive(depth+1, sum+len, selectedCnt+1, N);
    		removeLine(core, dir, N);
    	}
    	
    	drawLineReculsive(depth+1, sum, selectedCnt, N);
    }
    
    static int setLine(Core c, int dir, int N) {
    	int nx = c.x + dx[dir];
    	int ny = c.y + dy[dir];
    	int len = 0;
    	
    	while (0 <= nx && nx < N && 0 <= ny && ny < N && visited[ny][nx] == 0) {
    		visited[ny][nx]++;
    		len++;
    		nx += dx[dir];
        	ny += dy[dir];
    	}
    	
    	// Core 또는 Line 에 부딛히지 않은 경우
    	if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) {
    		return len;
    	}
    	
    	// 되돌리기
    	nx -= dx[dir];
    	ny -= dy[dir];
    	while (nx != c.x || ny != c.y) {
    		visited[ny][nx]--;
        	nx -= dx[dir];
        	ny -= dy[dir];
    	}
    	
    	return -1;
    }
    
    static void removeLine(Core c, int dir, int N) {
    	int nx = c.x + dx[dir];
    	int ny = c.y + dy[dir];
    	
    	while (0 <= nx && nx < N && 0 <= ny && ny < N) {
    		visited[ny][nx]--;
    		nx += dx[dir];
        	ny += dy[dir];
    	}
    }
    
    static int readInt() throws IOException {
    	st.nextToken();
    	return (int) st.nval;
    }
}

class Core {
	public int x, y;
	public boolean canMove[] = new boolean[] {true, true, true, true};
	public boolean isEdge = false;

	public Core(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "Core [x=" + x + ", y=" + y + ", canMove=" + Arrays.toString(canMove) + ", isEdge=" + isEdge + "]";
	}
	
}
