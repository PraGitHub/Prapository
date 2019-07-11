int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    if(n == 0) return 1;
    if(n == 1)
    {
        if(A[0] > 1 || A[0] < 1) return 1;
        if(A[0] == 1) return 2;
    }
    
    int j = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] <= 0)
        {
            A[i] = A[i] + A[j];
            A[j] = A[i] - A[j];
            A[i] = A[i] - A[j];
            j++;
        }
    }
    for(int i=j; i<n; i++)
    {
        if((abs(A[i])-1 < (n-j)) && A[abs(A[i])-1] > 0)
        {
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        }
    }
    for(int i=j; i<n; i++)
    {
        if(A[i] > 0)
        {
            return (i+1);
        }
    }
    return (n-j+1);
}
