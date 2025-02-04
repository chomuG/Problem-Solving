import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder read = new StringBuilder(br.readLine());
		String[] arr = Arrays.copyOf(read.toString().split(""), read.length());
		Arrays.sort(arr, Comparator.reverseOrder());

		for (String s : arr) {
			System.out.print(s);
		}
	}

}
