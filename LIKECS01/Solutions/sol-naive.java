// O(|S| ^ 2)

import java.util.Scanner;

class A {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int T = 0; T < t; ++T) {
			String s = in.next();
			boolean ans = false;
			for(int i = 0; i < s.length(); ++i) {
				for(int j = i+1; j < s.length(); ++j) {
					if (s.charAt(i) == s.charAt(j)) {
						ans = true;
					}
				}
			}
			if (ans) {
				System.out.println("yes");
			}
			else {
				System.out.println("no");
			}
		}
		in.close();
	}
}