#include <vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        int row = findRow(matrix, target);

        if (row == -1)
        {
            return false;
        }

        int col = findCol(matrix[row], target);

        return col != -1;
    }

private:
    int findRow(const std::vector<std::vector<int>> &matrix, int target)
    {
        int top = 0, bottom = matrix.size() - 1;

        while (top <= bottom)
        {
            int middle_row = (top + bottom) / 2;
            int leftmost = matrix[middle_row].front(), rightmost = matrix[middle_row].back();
            if (target < leftmost)
            {
                bottom = middle_row - 1;
                continue;
            }

            if (target > rightmost)
            {
                top = middle_row + 1;
                continue;
            }

            return middle_row;
        }
        return -1;
    }

    int findCol(const std::vector<int> &row, int target)
    {
        int left = 0, right = row.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2, value = row[mid];
            if (target < value)
            {
                right = mid - 1;
                continue;
            }

            if (target > value)
            {
                left = mid + 1;
                continue;
            }

            return mid;
        }
        return -1;
    }
};
