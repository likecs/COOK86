# Problem Link
[Practice](https://www.codechef.com/problems/LIKECS05)

[Contest](https://www.codechef.com/COOK86/problems/LIKECS05)

**Author:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

**Tester:** [Hasan Jaddouh](https://www.codechef.com/users/kingofnumbers)

**Editorialist:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

# Difficulty
MEDIUM-HARD

# Prerequisites
Inclusion-Exclusion, Fast Fourier Transforms(Faster method for Polynomial Multiplication)

# Problem
You are given a grid of size $N * N$ and $M$ updates on it. All the cells of the grid initally do not have any color. Each update colors a row, column or diagonal with red or green color. If a cell already has a color present in it, then rules based on mixing of colors are applied. (For the mixing rules, see the image provided in the problem).

We need to print the count of cells of each color after all the operations have been applied.

# Quick Explanation
We will use inclusion-exclusion to find the count of each color.

For a single color, first ignore the diagonals in the queries. For this, the answer is simply $(R + C)*N - R*C$, where $R$ and $C$ are the number of distinct rows and cells colored during the operations. Now, add the contribution due to the diagonal updates, making sure to add only contribution of those not colored cells. This part involves the use of fast fourier transforms.

# Explanation
First of all we represent all the different colored cells using the below Venn-diagram:

![Venn Diagram][1]

The sum of counts of cells of each color should be total number of cells in the grid i.e. $N * N$. To find the count of each cell, we will use [inclusion-exclusion principle](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle). Suppose we have the count of the following:

1. Red cells (yellow cells are also red) = RC
2. Green cells (yellow cells are also green) = GC
3. Colored cells (only red + only green + only yellow) = AC

For the above quantites, we can calculate the answer of the problem as:

1. Yellow cells = RC + GC - AC.
2. Red cells = RC - Yellow cells.
3. Green cells = GC - Yellow cells.
4. No color = N * N - Red cells - Green cells - Yellow cells.

The above is also clear from the Venn diagram.

To count the required quantities, $RC, GC, AC$ effciently, we see that all of them require the same procedure. Basically, we consider only updates which affect their count and then efficiently compute their count. So from now, we consider the problem being reduce to find the count of one color on the grid after $M$ operations are performed.

Let us first solve an easy version of the problem. Suppose, you are only given updates regarding rows and columns, i.e. diagonal updates were missing. Then the answer is simply $(R + C) * N - R * C$, where $R$ and $C$ are the number of distinct rows and cells colored during the operations. This is because we first count the contribution to answer due to operation on the rows only, then due to operation on columns only and finally subtract the common contribution.

Consider the following example where initially row $2$ and $5$ and column $2$ and $4$ are colored. Suppose, the update in diagonal is to color one with index $6$, then we see extra $2$ cells should be added to answer (marked in purple in the image).

![Example][2]

Suppose we consider the polynomials, corresponding to each row and column, where coefficient is $1$ for all the terms. The polynomials for rows and columns are $(x + x^2 + x^3 + x^4 + x^5)$. What is the result we get if we multiply them?

$(x + x^2 + x^3 + x^4 + x^5) * (x + x^2 + x^3 + x^4 + x^5) = (x^2 + 2x^3 + 3x^4 + 4x^5 + 5x^6 + 4x^7 + 3x^8 + 2x^9 + 1x^{10})$.

If you observe carefully, then coefficient of $i$ in the product basically represent the number of cells in the diagonal with index $i$. The initution behind this is that while multiplying polynomials, we perform convultion i.e.

$Coeffcient[k] = {Coefficient}_{1}[i] * {Coefficient}_{2}[k - i]$

Since, we kept the coefficient as $1$, we basically count the number of cells. So, to solve the problem, we basically, make the coefficient of colored rows and columns to $0$. Hence, the coefficient we now get in the product is basically the number of uncolored cells along each diagonal. Fot the above figure we have,

$(x + x^3 + x^4) * (x + x^3 + x^5) = (x^2 + 2x^4 + x^5 + 2x^6 + x^7 + x^8 + x^9)$

Hence, the problem seems solved. We multiply the required polynomials formed for the rows and columns after the updates and add the number of cells along the diagonals given in the updates. Since, we colored diagonal with index $6$ in the example, we add $2$ to the final answer.

Now, the only problem which remains is to multiply 2 polynomials efficiently. This is a standard problem and can be done in $O(N \log{N})$ using Fast Fourier Transforms. You can more about it from [e-maxx](http://e-maxx.ru/algo/fft_multiply) and [codeforces blog](http://codeforces.com/blog/entry/43499).

In case of any doubts, you can refer setter's and tester's implementation of the above logic or ask in the comments below.

### Bonus Problem
Suppose in the problem instead of diagonal with index $x = (i + j)$, we ask to update along the index $y = (i - j)$, can you still apply fast fourier transforms? What if you given both ($x$ and $y$) type of diagonals in the update?

# Time Complexity
$O(N + M + N \log{N})$,

# Space Complexity
$O(2^{ceil({log}_{2}{N})} + M)$

# Solution Links
[Setter's solution]()

[Tester's solution]()

[1]: https://cook86.discuss.codechef.com/upfiles/img-3.png
[2]: https://cook86.discuss.codechef.com/upfiles/img-4.png