class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid - 1))
            {
                return mid;
            }
            else if (isBadVersion(mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

private:
    /// stubbed to prevent error
    bool isBadVersion(int version)
    {
        return true;
    }
};
