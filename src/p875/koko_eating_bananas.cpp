#include <vector>
#include <cmath>
#include <algorithm>

class Solution
{
public:
    int minEatingSpeed(std::vector<int> &piles, int h)
    {
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right)
        {
            int speed = left + (right - left) / 2;

            long long totalTime = 0;
            for (int pile : piles)
            {
                totalTime += std::ceil(double(pile) / speed);
            }
            if (totalTime <= h)
            {
                result = speed;
                right = speed - 1;
            }
            else
            {
                left = speed + 1;
            }
        }

        return result;
    }
};
