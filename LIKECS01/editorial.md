# Problem Link
[Practice](https://www.codechef.com/problems/LIKECS01)

[Contest](https://www.codechef.com/COOK86/problems/LIKECS01)

**Author:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

**Tester:** [Hasan Jaddouh](https://www.codechef.com/users/kingofnumbers)

**Editorialist:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

# Difficulty
CAKEWALK

# Prerequisites
Looping Techniques

# Problem
You are given a string $S$ and you are required to find whether there exists $2$ different non-empty subsequences in $S$ which are equal.

# Quick Explanation
Check whether there exist 2 equal characters in the string.

# Explanation
**Lemma : If there exists a solution, then the smallest such equal subsequences will be of length 1.**

**Proof :** Let us assume the solution exists and the length of smallest equal subsequence is greater than $1$. Let the subsequences be $a$ and $b$. Since they are equal, they should be of same length and each character should be same on every index. Since, the first character should also be equal, we get a smaller subsequence of length $1$ which is also equal contradicting our assumption. Hence, the lemma is correct.

Now, to implement the above claim, we can simply loop over all the possible pair of positions and check if they are equal or not. The complexity of the above approach will be $O(N^2)$, which is sufficient to pass the problem.

Actually, the above solution can be made more efficient by simply creating a frequency array of size 26 (or equivalently Alphabet size) and storing the count of every character in it. The answer exist if the frequency of any alphabet is more than 1. The complexity of this approach is $O(N + ALPHABET)$.

### Bonus problem
What is the smallest length of string required to be sure that answer will be always "yes" irrespective of the string?

# Time Complexity
$O(N^2)$ or $O(N + ALPHABET)$, where $N = $ length of string.

# Space Complexity
$O(N)$

# Solution Links
[Setter's solution]()

[Tester's solution]()
