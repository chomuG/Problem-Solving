import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(in.readLine());

		for(int i=0; i<n; ++i) {
			String str = in.readLine();
			int cnt=0, sum=0;
			for(int j=0; j<str.length(); ++j) {
				if(str.charAt(j)=='O') {
					cnt++;
					sum+=cnt;
				}else {
					cnt=0;
				}
			}
			System.out.println(sum);
		}
	}
}
