from typing import List


class Solution:
    def helper(self, nums: List[int]) -> int:
        subproblems = [0] * (len(nums) + 1)
        subproblems[0] = 0
        subproblems[1] = nums[0]

        for i in range(2, len(nums) + 1):
            pick = subproblems[i - 2] + nums[i - 1]
            skip = subproblems[i - 1]
            subproblems[i] = max(pick, skip)

        return subproblems[-1]

    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        include_first = self.helper(nums[0:-1])
        include_last = self.helper(nums[1:])
        return max(include_first, include_last)


def test_p198() -> None:
    assert Solution().rob([2, 3, 2]) == 3


def main() -> None:
    test_p198()


if __name__ == "__main__":
    main()
