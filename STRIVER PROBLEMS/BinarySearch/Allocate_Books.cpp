int isPossible(vector<int> &A, int B, int mid)
{
    int count = 0;
    int subtotal = 0;

    for (int i = 0; i < A.size(); i++)
    {

        if (subtotal + A[i] > mid)
        {
            count++;
            subtotal = A[i];
        }
        else
        {
            subtotal += A[i];
        }
        if (subtotal > mid)
        {
            return false;
        }
    }

    if (count < B)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Solution::books(vector<int> &A, int B)
{
    if (B > A.size())
    {
        return -1;
    }
    int low = A[0];
    int high = 0;
    for (int i = 0; i < A.size(); i++)
    {
        high = high + A[i];
        low = min(low, A[i]);
    }

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(A, B, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
