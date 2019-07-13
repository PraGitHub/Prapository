
 #include<algorithm>
 
 /*
 This input should expect -1 but it is expecting 1
  8 4 -9 8 5 -1 7 5 3 
  */

int Solution::solve(vector<int>& A) {
    int n = A.size();
    
    if(n == 0) return -1;
    
    if(n == 1)
    {
        if(A[0] == 0) return 1;
        return -1;
    }
    
    sort(A.begin(),A.end());
    for(int i=0; i<n; i++)
    {
        if(i == (n-1))
        {
            if(A[i] == 0) return 1;
            return -1;
        }
        
        if(A[i] <= 0) continue;
        
        if(A[i] == A[i+1]) continue;

        int count = 0;
        //cout<<"A[i] == "<<A[i]<<endl;
        for(int j=i+1; j<n; j++)
        {
            if(A[j]>A[j-1]) count++;
        }
        //cout<<"count = "<<count<<endl;
        if(count == A[i]) return 1;
    }
    return -1;
}
