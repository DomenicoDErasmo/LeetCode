from typing import List


class SolutionRecursive:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        if target < 0:
            return 0

        if target == 0:
            return 1

        result = 0

        for num in nums:
            result += self.combinationSum4(nums, target - num)

        return result


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        subproblems = [0] * (target + 1)
        subproblems[0] = 1

        for i in range(target):
            subresult = 0
            for num in nums:
                if num > (i + 1):
                    continue
                subresult += subproblems[i + 1 - num]
            subproblems[i + 1] = subresult

        return subproblems[-1]


def testCombinationSum() -> None:
    assert Solution().combinationSum4([1, 2, 3], 4) == 7


def main() -> None:
    testCombinationSum()


if __name__ == "__main__":
    main()
