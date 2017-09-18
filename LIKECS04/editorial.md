# Problem Link
[Practice](https://www.codechef.com/problems/LIKECS04)

[Contest](https://www.codechef.com/COOK86/problems/LIKECS04)

**Author:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

**Tester:** [Hasan Jaddouh](https://www.codechef.com/users/kingofnumbers)

**Editorialist:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

# Difficulty
MEDIUM

# Prerequisites
Dynamic Programming, Proof using Invariants

# Problem
Let us consider an array of $N$ non-negative integers. In one move, we select 2 integers, $(x, y)$ such that $x$ &le; $y$ and replace them by $(x - y, 2*y)$. After some number of moves, we want the array to consist of exactly $(N-1)$ zeros. Let us consider such an array good.

The problem is to find the number of such good arrays such that for each $i$, it is satisfied that $0$ &le; $a[i]$ &le; $b[i]$, where $N$ and array $b$ is given in input.

# Quick Explanation
The array is good if :

$\frac{\sum\limits_{i = 1}^{i = N} A[i]}{\gcd\limits_{i = 1}^{i = N} A[i]} = 2^k$, for some integer $k$ &ge; $0$.

To calculate the number of such arrays, we can use a three dimensional dynamic programming solution with states as $dp[pos][gcd][sum]$.

# Explanation
The first observation is that the sum of numbers in the board never changes. This is because $(x, y)$ transforms to $(x - y, 2*y)$, which means the sum of numbers doesn't change. Also, once a number becomes $0$, it will always remain $0$. This is because even if it is selected again for operation, it will be smallest element only as array initially consisted of non-negative numbers. Thus $(x, 0)$ changes to $(x, 0)$. Hence, we can say that the number of zeros in the array can only increase with number of moves.

Let us try to consider arrays consisting of $2$ numbers only $(x, y)$. The moves of the game consist as follows :

<pre>
<code>
			(x, y)				(x-y, 2y)
			(x-y, 2y)			(x-3y, 4y)
			(x-3y, 4y)			(x-7y, 8y)
			(x-7y, 8y)			(x-15y, 16y)
			and so on..
</code>
</pre>

Assuming that in all steps $(x - q*y)$ &ge; $(r*y)$. To end up with zero, after any step, we would require the $2$ numbers to become equal. Thus, we need $(x - qY) = rY$, i.e. $x = y * (r + q)$. From above, pattern of events you can see that $(r + q)$ is always $1$ less than some power of $2$. So the sum of the numbers in initial array should be a power of $2$ multiplied by the smallest number in the array.

Thus, $x + y$ = $y * (r + q + 1)$ = $y * 2^k$, some integer, $k$.

For now, for rest of proof, consider that $gcd$ of all the numbers in the array is initially $1$. The intuition behind this will be clear in a moment.

Now, for arrays with $2$ numbers, we want their sum to be some power of $2$ and their gcd as $1$. Thus, both of them can be odd only. Now, after the first move, both the numbers are converted into even. Thus, their $gcd$ becomes greater than $1$. (it is some even number). Thus, we could divide both the number by their $gcd$ and proceed with the game. The intuition behind $gcd$ is that after the operations, the number are changed into some linear combination of each other. So, we could perform further operations as if the number on further steps will always remain multiple of $gcd$ but the process with reduced numbers is also same. To illustrate this, consider the initial number as $(9, 7)$.

The steps are:

<pre>
<code>
			(9, 7)				(2, 14)
			(14, 2)				(12, 4)
			(12, 4)				(8, 8)
			(8, 8)				(0, 16)			It ends here.
</code>
</pre>

You can see that in above example in step 2 onwards, if you performed operation of $(7, 1)$ instead of $(14, 2)$, the result will be same just that final answer differs by factor of $gcd$. But since, we need only zeros and one positive number in the end, it doesn't matter.

Thus, let the numbers be $(x', y')$ after $i$ moves. After this move, they change to $(x' - y', 2 * y')$. So, the $gcd(x' - y', 2 * y')$ = $gcd(x', y')$ or $2 * gcd(x', y')$. To prove this claim, one can use laws of $gcd$ containing linear combinations and also the fact that $gcd(a * u, b * u) = u * gcd(a, b)$. If it is still not clear, one can ask in comments below.

Now, we make a claim for general $n$ and prove it using induction. The claim is, given any array of $N$ integers such that their initial $gcd$ is $1$, it is possible to convert them into $(N - 1)$ zeros, using the steps mentioned above if :

$\sum_{i = 1}^{i = N} a[i] = 2^k$, for some integer $k$ &ge; $0$.

To prove the claim using induction, we proved the base case with $N = 2$. We also claimed that playing the game on $\{a_1, a_2, \dots , a_N\}$ is same as playing on $\{a_1 / d, a_2 / d, \dots, a_N / d\}$, where $d = $ gcd of all numbers as the array being good doesn't change. Since, the $gcd$ of the numbers to start with is $1$, it follows that the $gcd$ of the numbers on the board is a power of 2 after any number of moves. (Using the fact : $gcd(x' - y', 2 * y')$ = $gcd(x', y')$ or $2 * gcd(x', y')$). If we can reach a point where $(N − 1)$ of the numbers are zero, then the non-zero number at this stage is a power of $2$. But, by the invariant that sum of numbers do not change, this is the sum of all the numbers at the beginning.

Now suppose that $a_1 ≤ a_2 ≤ \dots ≤ a_N$ are $N$ non-negative integers initially such that their $gcd$ is $1$ and their sum is power of $2$, say $2^k$. We prove by induction on $k$. The base case for $k = 0$ is true as the numbers can be only zero except $a_N = 1$. Now, assume that claim is true for all $z < k$.

Suppose that $k > 0$. Then the number of odd numbers among $a_1, a_2, \dots , a_N$ is even. We can pair them up of perform the move on each of them. After this move, all the numbers in the array are even. Thus, we can operate on the modified array such that each number is reduced by factor of $2$. Thus, the sum of array elements also decreases by factor of $2$. But using induction hypothesis on $z (= k - 1)$, we claim that solution exists only when the claim is true.

In the above solution, we assumed that $gcd$ of all the numbers is initially $1$. To make the claim for general arrays, we take help of the last part of proof in inductive step. Here, we basically reduce the numbers by their $gcd$ after performing some steps and claimed using induction that we will reach the desired configuration, i.e. consisting of $(N - 1)$ zeros. Thus, we generalise the solution as follows :

$\frac{\sum\limits_{i = 1}^{i = N} A[i]}{\gcd\limits_{i = 1}^{i = N} A[i]} = 2^k$, for some integer $k$ &ge; $0$.

To calculate the number of such arrays, we can use a three dimensional dynamic programming solution with states as $dp[pos][gcd][sum]$.

Pseudo code for above implementation (recursive style) is:

<pre>
<code>
int GCD(a, b):
	return (b > 0 ? gcd(b, a%b) : a)

int solve(pos, gcd, sum):
	if (pos == n+1):
		return 1

	int memo = dp[pos][gcd][sum]
	if (memo != -1):
		return memo

	memo = 0
	for x in [0 .. b[pos]]:
		memo += solve(pos + 1, GCD(gcd, x), sum + x)

	return memo
</code>
</pre>

**Note that above approach is will be slow**, not because it uses recursive approach, it is due to the number of calls to $GCD$ function. Each call to it costs **logarithmic time** and thus overall complexity also increases by this factor. Since, the numbers in the problem are fairly small, we can simply pre-compute the gcd of all the pairs and then use the above pseudo-code.

Thus, once the above dynamic programming is constructed, we fix a particular $gcd$ and sum over all values such that sum of elements in array by their $gcd$ is power of $2$.

For more details, you can refer to setter's or tester's code.

### Bonus Problem
You can see that if the gcd of the numbers in array is say $x$, then the sum of the numbers in the array is also a multiple of $x$. Thus, in iterative version of dynammic programming states likes $dp[pos][x][y]$, where $y$ is not a multiple of $x$ is never reached. So, try to write the iterative version in a different manner so that you visit only the required states. Note that this optimisation is not required to pass this problem but this trick can be useful in some other problems.

# Time Complexity
$O(N * {B}_{max}^{2} * {B}_{sum})$,

where ${B}_{max} =$ maximum element of $b$ and ${B}_{sum} = \sum_{i=1}^{i=N} b[i]$.

# Space Complexity
$O(N * {B}_{max} * {B}_{sum})$

# Solution Links
[Setter's solution]()

[Tester's solution]()
