#include <vector>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        std::vector<int> counts(3, 0);
        for (auto num : nums)
        {
            counts[num]++;
        }

        int result_index = 0;
        for (int i = 0; i < counts.size(); i++)
        {
            for (int j = 0; j < counts[i]; j++)
            {
                nums[result_index] = i;
                result_index++;
            }
        }
    }
};
