import java.lang.*;
import java.util.*;
import java.io.*;

public class Main {
	
	static class Point{
		int x, y;
		Point(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	
	static int[][] arr;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};
	static boolean[][] visited;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] strs = br.readLine().split(" ");
		int x = Integer.parseInt(strs[0]);
		int y = Integer.parseInt(strs[1]);
		arr = new int[x][y];
		
		for(int i = 0; i < x; i++) {
			strs = br.readLine().split(" ");
			for(int j = 0; j < y; j++) {
				arr[i][j] = Integer.parseInt(strs[j]);
			}
		}
		
		int time = 0;
		int escape = -1;
		while(true) {
			visited = new boolean[x][y];
			makeMap(x,y);
			escape = checkMelt(x,y);
//			debug(x,y, time);
			if(escape == 0) {
				break;
			}
			time++;
		}
		
		System.out.println(time);
		
	}
	
	
	public static void makeMap(int x, int y) {
		Queue<Point> q = new LinkedList();
		q.add(new Point(0,0));
		visited[0][0] = true;
		while(!q.isEmpty()) {
			Point cur = q.poll();
			arr[cur.x][cur.y] = -1; 
			for(int m = 0; m < 4; m++) {
				int nx = cur.x + dx[m];
				int ny = cur.y + dy[m];
				
				if(nx < x && nx >= 0 && ny < y && ny >= 0) {
					if(arr[nx][ny] == 0 && !visited[nx][ny]) {
						q.add(new Point(nx, ny));
						visited[nx][ny] = true;
					}
					
				}
			}
		}
	}
	
	public static int checkMelt(int x, int y) {
		int cheese_count = 0;
		int[][] temp = new int[x][y];
		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				if(arr[i][j] == 1) {
					int count = 0;
					for(int m = 0; m < 4; m++) {
						int nx = i + dx[m];
						int ny = j + dy[m];
						
						if(nx < x && nx >= 0 && ny < y && ny >= 0) {
							if(arr[nx][ny] == -1) {
								count++;
							}
						}
					}
					if(count >= 2) {
						cheese_count++;
					}else {
						temp[i][j] = 1;
					}
				}
			}
			
		}
		arr = temp;
//		System.out.println(cheese_count);
		return cheese_count;
	}
	
//	static void debug(int x, int y,int a) {
//		System.out.println("#" + a);
//		for(int i = 0; i < x; i++) {
//			for(int j = 0; j < y; j++) {
//				System.out.print(arr[i][j] + " ");
//			}
//			System.out.println();
//		}
//	}
	
}

