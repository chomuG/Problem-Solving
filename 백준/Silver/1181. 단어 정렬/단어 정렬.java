import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Set<String> treeSet = new TreeSet<>((a, b) -> {
			if (a.length() < b.length()) {
				return -1;
			} else if (a.length() > b.length()) {
				return 1;
			} else {
					return a.compareTo(b);
			}

		});
		
		for (int i = 0; i < n; ++i) {
			treeSet.add(br.readLine());
		}
		for(String s: treeSet)
		System.out.println(s);

	}
}
