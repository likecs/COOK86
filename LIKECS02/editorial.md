# Problem Link
[Practice](https://www.codechef.com/problems/LIKECS02)

[Contest](https://www.codechef.com/COOK86/problems/LIKECS02)

**Author:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

**Tester:** [Hasan Jaddouh](https://www.codechef.com/users/kingofnumbers)

**Editorialist:** [Bhuvnesh Jain](https://www.codechef.com/users/likecs)

# Difficulty
EASY

# Prerequisites
Maths, Looping Techniques, Constructive Algorithms

# Problem
Construct an array of size $N$, such that the mean of median of all subarrays lies between $[N-1, N+1]$.

# Quick Explanation
Try to think about the sum of all integers from $l$ to $r$.

# Explanation
As multiple solutions exist, we should try to think how to approach the problem. Since we need to find median of the every subarray, what if the subarray was already sorted. This would easily reduce our task at hand. We can simply find the middle elements. Since, we want all subarrays to be sorted, which means the full array should be sorted as well.

Now, we want that the mean of every subarray should lie between $[x, y]$ where $x$ and $y$ are any integers. So, what we can do is simply, chose any random number, not far away from $x$ or $y$ and then try to add a number such that mean (average) of these 2 numbers lies within out range. If we have only one number of chose, then we can simply chose the integer which lies in the middle of $x$ and $y$.

With these 2 above observations, we now try to construct some solution and prove that it is correct. Now, since we want increasing numbers and all of them should be distinct as well and mostly equidistant from $(N-1)$ and $(N+1)$ ($x$ and $y$ in the problem), we try to take numbers as simply $A[i] = 2*i$, the list of even numbers.

You can easily prove using formula of sum of consecutive numbers that the median of the above array construct will always be $(N+1)$. The intuition of chosing only even numbers is basically the formula easy as the sum of numbers in range require the factor of $2$ in the denominator. Also, in the case the median of every subarray will be integer only, even if the size of subarray is even. Thus, this type of solution, basically easies out appraoch to the solution. To verify, you can simply write a brute force code and test it locally or prove using mathematical formulas.

One other solution is simply the list of odd numbers, i.e. $A[i] = 2*i - 1$. In this case, the median of the array will always be $(N-1)$.

Since, we wanted any solution, odd or even to pass and not restrict thinking of user to any particular direction, we made the range $[N-1, N+1]$ in the problem, even though solution with exact boundary ranges exist as shown above.

Since many solutions exist in the problem, feel free to discuss your approach in the comments below.

### Bonus problem
Try to write a test judge for the problem.

# Time Complexity
$O(N)$

# Space Complexity
$O(1)$

# Solution Links
[Setter's solution]()

[Tester's solution]()
