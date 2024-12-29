"""Solution for Two Sum."""

from typing import List


class Solution:
    """Two Sum"""

    def two_sum(self, nums: List[int], target: int) -> List[int]:
        """
        Given a list of numbers and a target, return the two numbers in the list that
        add up to that target.

        Args:
            nums (List[int]): The list of numbers.
            target (int): Thet number to sum to.

        Returns:
            List[int]: The two numbers that add up to the target.
        """
        for i, num in enumerate(nums):
            for j, num2 in enumerate(nums):
                if i != j and num + num2 == target:
                    return [i, j]

        return [-1, -1]

    def fast_two_sum(self, nums: List[int], target: int) -> List[int]:
        """
        Fast two sum.

        Args:
            nums (List[int]): The list of numbers.
            target (int): Thet number to sum to.

        Returns:
            List[int]: The two numbers that add up to the target.
        """
        sorted_nums = sorted(nums)
        left = 0
        right = len(sorted_nums) - 1

        while left < right:
            candidate_two_sum = sorted_nums[left] + sorted_nums[right]

            if candidate_two_sum < target:
                left += 1
                continue

            if candidate_two_sum > target:
                right -= 1
                continue

            original_left = nums.index(sorted_nums[left])

            search_start = (
                original_left + 1 if sorted_nums[left] == sorted_nums[right] else 0
            )
            original_right = nums.index(sorted_nums[right], search_start)

            return [original_left, original_right]

        return [-1, -1]


def main():
    """Test the script."""
    solution = Solution()
    print(solution.fast_two_sum([-1, -2, -3, -4, -5], -8))


if __name__ == "__main__":
    main()
