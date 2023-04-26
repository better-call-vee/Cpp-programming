/*
Statement:
You'll be given a number. You have to make the number equivalent to 1 and you can do that with 3
measures:
1. substracting 1
2. dividing by 2
3. dividing by 3

you have to find the minimum steps to reach 1 from the given number

examples:
7 => minimum steps 3
     substracting 1 = 6. dividing by 2 = 3. dividing by 3 = 1.

11 => minimum steps 4
      substracting 1 = 10. substracting 1 = 9. dividing by 3 = 3.
      dividing by 3 = 3.

*/



#include<bits/stdc++.h>
using namespace std;

vector<int>dparr(100001, -1);

int minStepsTo1(int n)
{
    if(n<=1) return 0; //which means we have already reached 1, and no more steps are required.

    if(dparr[n] != -1) return dparr[n];

    int ans = 1 + minStepsTo1(n-1); //try to go deep down using some test cases.

    if(n % 2 == 0) ans = min(ans, 1 + minStepsTo1(n/2));

    if(n % 3 == 0) ans = min(ans, 1 + minStepsTo1(n/3));

    /*
    suppose for input = 3.
    34th line => ans = 1 + minStepsTo1(2)
                     = 1 + 1 + minStepsTo1(1)
                     = 1 + 1 + 0
    now, as we got the return here for minStepsTo1(1), this call will now go down. go down means
    it will go to the 36th and 38th line and set a value for dparr[that called n, here 1].
    then it will return to the second call(minStepsTo1(2)). And will do the same. Finally the first
    call will get it's return and go down.
    */

    dparr[n] = ans;

    return ans;
}

int main ()
{

    int n;
    cin >> n;
    cout << minStepsTo1(n);

    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

vector<int>dparr(100001, -1);

int main ()
{

    int n;
    cin >> n;

    dparr[0] = 0;
    dparr[1] = 0;

    for(int i=2; i<=n; i++)
    {

        int ans = 1 + dparr[i-1];
        if(i % 2 == 0) ans = min(ans, 1 + dparr[i/2]);
        if(i % 3 == 0) ans = min(ans, 1 + dparr[i/3]);

        dparr[i] = ans;
    }

    cout<<dparr[n];

    return 0;
}
*/