//so, basically the problem is like doing "vangti"
//first, certain number of inputs will be given referring vangti.
//you have to make certain amount adding those vangtis. but you have to also do
//that considering the minimum possible way.
//suppose, vangtis given => 1 3 4. and you have to make 6. you can make 4+1+1 or you
//can make 3+3. so, here the answer will be 3+3,2

#include<bits/stdc++.h>
using namespace std;
vector<int>vangti = {1,3,4};

int coinChange(int n)
{
    if(n==0) return 0; //base case
    int ans = 100000000; //just a random initialization, if we take 0 as the
    //initialization ans, the min will always be set to 0.
    for(int i=0; i<vangti.size(); i++) //we are traversing to every vangti coin
    {
        if(n>=vangti[i]) //n has to be bigger than the vangtis.
        {
            ans = min(ans, 1+coinChange(n-vangti[i])); //this 1 is for vangti[i]
            //do example analysis to learn more intensely.
        }
    }
    return ans;
}

int main () {
    int n;
    cin>>n;
    cout<<coinChange(n)<<"\n";
}
