// O(|S|)

import java.util.Scanner;

class A {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int T = 0; T < t; ++T) {
			String s = in.next();
			int freq[] = new int[26];
			for(int i = 0; i < 26; ++i) {
				freq[i] = 0;
			}
			for(int i = 0; i < s.length(); ++i) {
				freq[s.charAt(i)-'a'] += 1;
			}
			boolean ans = false;
			for(int i = 0; i < 26; ++i) {
				ans |= (freq[i] > 1);
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