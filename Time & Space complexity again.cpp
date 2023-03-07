//The time complexity of an algorithm expresses how the running time of the
//algorithm grows with the input size in the worst case, and it is not affected
//by the specific input values used for testing the algorithm.

//1+2+3+...n = n*(n+1)/2;

//They are used to judge a program's worth
//a good computer can run 10^8 to 10^9 operations at a time
//O(1) -> Constant time. (any constant time suppose, O(100) will be O(1) as well)
//O(n) -> Linear time.
//O(nlogn), O(logn), O(sqrt(n)), O(n^2/n^3/n^k)polynomial, O(c^n) c=1,2,3..exponen.
//Exponential time complexities are the worst



//if-else condition is an example of constant operation O(1)
//loop depends on n. so it can't be constant operation

//int n; cin>>n; TC -> O(1)
//vector<int>a(n); TC -> O(n). because it will find n numbered consecutive space
//but, vector<int>a; TC -> O(1).

//for(int i=1; i*i<=n; i++) -> this loop runs until i square is less/equals to n.
//so, time complexity will be O(sqrt(n)).

//generally we calculate the dominating part of time complexity but sometimes it's
//uncertain. for example:
//int n, q;
//cin>>n>>q;
//for(int i=0; i<n; i++) {
//    cout<<i<<"\n";
//}
//for(int i=0; i<q; i++) {
//    cout<<i<<"\n";
//}
//here,we don't know either n is larger or q!So, we can't define who will dominate
//the time complexity will be O(n+q).


//sieve's loop:
//for(int i=1; i<=n; i++) {
//    for(int j=1; j<=n; j= j+i) {
//
//    }
//}
//this code's complexity isn't O(n^2).
//i=1 -> j will increase by 1 -> n times
//i=2 -> j will increase by 2 -> n/2 times
//i=3 -> j will increase by 3 -> n/3 times
//........................................
//i=n -> j will increase by n -> n/n times
//        summation           -> nlogn times
//n*(1/1+1/2+1/3+....) = nlogn. the first bracketed area is called the harmonic
//series. It's summation is ln(n) = log(ebased)n
//so, the complexity will be O(nlogn)


//fibonacci recursion has a complexity of O(2^n) (exponential growth)


//vector<int>d[n + 1];
//for (int i = 1; i <= n; i++)
//    for (int j = 1; j <= n; j++)
//        d[i].push_back(j);
//The space complexity of the above program is O(n^2), as it creates a 2D vector
//of size nn. The outer vector has n elements, each representing a row, and each
//row has n elements, which represent the columns. So the total number of elements
//in the 2D vector is n*n, and it increases in proportion to the square of the
//input size n.


//for(int k=1;k<=n;k=k*2)
//{
//	for(int i=1;i<=n;i++)
//	{
//		cout<<k<<" "<<i<<"\n";
//	}
//}
//time complexity is O(nlogn)
//for the outer loop, it's O(logn)When analyzing the time complexity of an
//algorithm, we are interested in understanding how the number of operations
//performed by the algorithm grows as the size of the input (in this case, n)
//increases. To do this, we use big O notation, which gives us an upper bound on
//the number of operations performed by the algorithm.
//
//In the case of O(log(n)), the number of operations performed by the algorithm
//grows logarithmically with the size of the input. This means that as the input
//size doubles (n = 8, n = 16, n = 32, etc.), the number of operations performed
//by the algorithm will increase by a constant factor (typically log2, log10, or
//ln, depending on the base of the logarithm used).
//
//When we say that the value of logn is around 0.9 for n=8, it means that the
//number of operations performed by the algorithm is less than or equal to
//0.9 * log2(8), which is around 3.32. However, the number of iterations in the
//loop is 4.
//
//It's important to note that big O notation gives us an upper bound on the
//number of operations performed by the algorithm, and not an exact number. In
//this case, we can say that the time complexity of the algorithm is O(log(n))
//which means that the number of operations performed by the algorithm will not
//exceed log(n) times.
//
//To sum up, log(n) is an approximation of the number of iterations, it gives us
//an upper bound on how many iterations the loop will run. Depending on the input
//size, it may run more or less iterations.


//for(int k=1;k<=n;k++)
//{
//	if(k==1){
//		for(int i=1;i<=n;i++)
//		{
//			cout<<k<<" "<<i<<"\n";
//		}
//	}
//}
//The time complexity of this code is O(n), not O(n^2).
//The outer loop iterates n times, and in each iteration, it checks if k is equal
//to 1, and if it is, it runs the inner loop which also iterates n times.
//The inner loop only runs once, when k is equal to 1, so the total number of
//iterations is n (from the outer loop) + n (from the inner loop) = 2n which is
//O(n)
//In general terms, the time complexity of the loop is O(n) which means the number
//of iterations will grow linearly with the size of the input.
//
//It is important to note that the time complexity calculation is based on the
//number of iterations, and not the number of statements executed. In this case,
//the if statement inside the outer loop only gets executed once, so it doesn't
//affect the time complexity.
//The time complexity of this code is O(n) in the worst-case scenario as well as
//in the best and average case scenario. The reason is that the inner loop only
//runs when k = 1. Therefore, regardless of the size of the input, the inner loop
//will only run once, and the number of iterations performed by the inner loop is
//always n. The outer loop will also run n times, independently of the input.
//Therefore, the total number of iterations is n + n = 2n, which is O(n).
//The time complexity is not affected by the value of k, it's always n, and it
//doesn't change if the value of k is different from 1, it will not run the inner
//loop and the time complexity will still be O(n).
//It's important to note that O(n) is an upper bound on the number of operations
//performed by the algorithm, meaning that the actual number of operations will
//always be less than or equal to n.
//When k is equal to 1, in the given code snippet, the inner loop runs n times,
//but the outer loop runs only one time. Therefore, the total number of iterations
//performed by the inner loop is n * 1 = n.
//The number of iterations of the outer loop and inner loop are not multiplied
//together to calculate the time complexity, it is the number of iterations of
//the inner loop that is most time-consuming.
//As the inner loop runs only once when k is equal to 1, the time complexity is
//O(n) because the number of iterations is directly proportional to the size of
//the input.
//In general terms, time complexity is a function of the number of iterations of
//the most time-consuming loop or operation in the code, not the total number of
//iterations of all loops or operations.
//It's important to note that O(n) is an upper bound on the number of operations
//performed by the algorithm, meaning that the actual number of operations will
//always be less than or equal to n.



//for(int k=1;k<=n;k++)
//{
//	if(k%2==0){
//		for(int i=1;i<=n;i++)
//		{
//			cout<<k<<" "<<i<<"\n";
//		}
//	}
//}
//the inner loop is not running n times every time the outer loop iterates.
//The inner loop only runs when k is even, and in each iteration of the outer
//loop, it runs n times, which means that the inner loop runs n/2 times in total.
//
//So, the time complexity of this code is actually O(n/2 * n) = O(n^2/2) which
//is equivalent to O(n^2) since we are only interested in the order of growth
//and the constant factor 1/2 is not significant in big O notation.
//
//In general terms, when analyzing the time complexity of an algorithm, we are
//interested in understanding how the number of operations performed by the
//algorithm grows as the size of the input (n) increases, not the exact number
//of operations.
