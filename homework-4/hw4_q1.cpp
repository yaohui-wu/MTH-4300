/*
Return the number of partitions of a positive integer n
using integers up to k for k is less or equal to n.
*/
int part(int n, int k)
{
    if (k <= 0)
    {
        return 0;
    }
    
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1; // Empty partition.
    }
    
    // The total number of partitions with k and without k.
    return part(n, k - 1) + part(n - k, k);
}