class Solution
{
public:
    int guessNumber(int n)
    {
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int guess_result = guess(mid);
            if (guess_result == -1)
            {
                high = mid - 1;
            }
            else if (guess_result == 1)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

private:
    // stub to avoid squigglies
    int guess(int n)
    {
        return 0;
    }
};
