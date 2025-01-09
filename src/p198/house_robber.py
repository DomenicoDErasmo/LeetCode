from copy import deepcopy
from typing import Dict, List


class SolutionRecursive:
    def helper(self, nums: List[int], visitable: List[bool]) -> int:
        if not any(visitable):
            return 0

        result = 0
        for i, num in enumerate(nums):
            if not visitable[i]:
                continue

            new_visitable = deepcopy(visitable)
            if i != 0:
                new_visitable[i - 1] = False
            new_visitable[i] = False

            if i != len(new_visitable) - 1:
                new_visitable[i + 1] = False

            result = max(result, num + self.helper(nums, new_visitable))

        return result

    def rob(self, nums: List[int]) -> int:
        return self.helper(nums, [True] * len(nums))


class Solution:
    def rob(self, nums: List[int]) -> int:
        subproblems = [0] * (len(nums) + 1)
        subproblems[0] = 0
        subproblems[1] = nums[0]

        for i in range(2, len(nums) + 1):
            pick = subproblems[i - 2] + nums[i - 1]
            skip = subproblems[i - 1]
            subproblems[i] = max(pick, skip)

        return subproblems[-1]


def test_p198() -> None:
    assert Solution().rob([1, 2, 3, 1]) == 4
    assert Solution().rob([2, 7, 9, 3, 1]) == 12
    assert (
        Solution().rob(
            [82, 217, 170, 215, 153, 55, 185, 55, 185, 232, 69, 131, 130, 102]
        )
        == 1082
    )


def main() -> None:
    test_p198()


if __name__ == "__main__":
    main()
