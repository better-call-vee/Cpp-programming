#include<bits/stdc++.h>
//sieve of eratosthenes
using namespace std;
int main ()
{
    int n;
    cin>>n;
    vector<int>primes;
    vector<bool>visited(n+1); //because, I have to visit the nth number.
    for(int i=2; i<=n; i++)
    {
        if(visited[i]==false) //at first, i=2. so, it's pushed to be prime which it is
        {
            primes.push_back(i);
            for(int x=2; i*x<=n; x++)
            {
                visited[i*x] = true;  //now, the multiples of 2 or other numbers are
                //set true and not visited
            }
        }
    }
    cout<<primes.size()<<"\n";
    for(int i=0; i<primes.size(); i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<"\n";
    return 0;
}


//time complexity => O(nlogn)
//ln(n) => loge^n = nlogn (solving harmonic series)

//there's another sieve complexity => n(log(logn))
