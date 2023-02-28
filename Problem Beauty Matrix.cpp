//You will be given a test case number. You have to take number of matrices equal
//to the test case number. Then you will given a n, you have to create the matrices.
//the matrices will contain all the values from 1 to n^2.
//Then you have to find the absolute differences between the adjacent
//numbers of the matrix. You have to print exact matrix which has the maximum count
//of distinct differences containing value from 1 to n^2.
//the highest difference among the adjacent numbers will be n^2-1. ok, suppose,n is
//3.here, we will get a 3*3 matrix where 1 to 9 numbers will be present.the highest
//difference can be 8 where the adjacent numbers are 1 and 9. so, (n^2-1). If the
//input is 3:
//╔═══╦═══╦═══╗
//║ 9 ║ 1 ║ 8 ║look, here we're taking the maximum value once, then the minimum.
//╠═══╬═══╬═══╣again maimum, again minimum. (9->1->8->2) like this and so on.
//║ 3 ║ 7 ║ 2 ║first we are going forward, then we're going backward. 9->1->8 and
//╠═══╬═══╬═══╣then 2<-7<-3. For the odd rows we are going forward and for the even
//║ 6 ║ 4 ║ 5 ║rows, we are going backward. look here: (9-1)=8, (8-1)=7, (8-2)=6,
//╚═══╩═══╩═══╝(7-2)=5, (7-3)=4, and so on. so the maximum distinct differences
//can be counted from this matrix like this and only can be found by this kinda
//implementation. Here the maximum distinct differences are 8(n^2-1)

//So, at first we will push the elements from 1 to n^2 in a grid.

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    list<int>l; //at first taking a linked list to push the elements from 1 to n^2

    for(int i=1; i<=(n*n); i++) l.push_back(i); //pushed

    int grid[n][n]; //taking a grid(2D array) which will be the matrix

    for(int i=0; i<n; i++)
    {
        if((i+1)%2!=0)  //for odd row.
        {
//╔═══╦═══╦═══╗
//║ 9 ║ 1 ║ 8 ║ if the columns are odd for odd row, we will take the biggest
//╠═══╬═══╬═══╣ numbers.
//║ 3 ║ 7 ║ 2 ║ if the columns are even for odd row, we will take the lowest
//╠═══╬═══╬═══╣ numbers.
//║ 6 ║ 4 ║ 5 ║ vice versa for even row.
//╚═══╩═══╩═══╝
            for(int j=0; j<n; j++)
            {
                if((j+1)%2!=0) //okay now, for odd row, look at the columns.
                {
                    grid[i][j] = l.back(); //backs will contain higher numbers
                    l.pop_back();
                }
                else
                {
                    grid[i][j] = l.front(); //fronts will contain lower numbers
                    l.pop_front();
                }
            }
        }
        else //for even rows.
        {
            for(int j=n-1; j>=0; j--) //because we are going backward now.
            {
                if((j+1)%2!=0)
                {
                    grid[i][j] = l.front(); //vice versa applied
                    l.pop_front();
                }
                else
                {
                    grid[i][j] = l.back();
                    l.pop_back();
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) cout<<grid[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}
