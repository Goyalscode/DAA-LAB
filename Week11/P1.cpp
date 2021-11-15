/*  Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
    matrices together. To find the optimal solution, you need to find the order in which these
    matrices should be multiplied.  */

#include<iostream>
using namespace std;

int matMultiply(int p[], int n)
{
    n = n+1;
    int mat[n][n];
    for(int i=1; i<n; i++)
        mat[i][i] = 0;
    for(int l=2; l<n; l++)
    {
        for(int i=1; i<n-l+1; i++)
        {
            int j = i+l-1;
            mat[i][j] = INT_MAX;
            for(int k=i; k<=(j-1); k++)
            {
                int q = mat[i][k] + mat[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < mat[i][j])
                    mat[i][j] = q;
            }
        }
    }
    return mat[1][n-1];
}

int main()
{
    int n;
    cin>>n;
    int r, c;
    int j = 0;
    int p[n+1];
    for(int i=0; i<n; i++)
    {
        cin>>r>>c;
        p[i] = r;
        if(i == n-1)
            p[i+1] = c;
    }
    int tot = matMultiply(p, n);
    cout<<tot<<"\n";
}
