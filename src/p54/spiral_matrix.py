from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        left = 0
        right = len(matrix[0]) - 1
        top = 0
        bottom = len(matrix) - 1

        result = []

        while True:
            # left to right
            if left > right or top > bottom:
                break
            for i in range(left, right + 1):
                result.append(matrix[top][i])
            top += 1

            # top to down
            if left > right or top > bottom:
                break
            for j in range(top, bottom + 1):
                result.append(matrix[j][right])
            right -= 1

            # right to left
            if left > right or top > bottom:
                break
            for i in range(right, left - 1, -1):
                result.append(matrix[bottom][i])
            bottom -= 1

            # down to top
            if left > right or top > bottom:
                break
            for j in range(bottom, top - 1, -1):
                result.append(matrix[j][left])
            left += 1

        return result


def testP54() -> None:
    result = Solution().spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    expected = [1, 2, 3, 6, 9, 8, 7, 4, 5]
    assert result == expected, f"Expected {expected} but got {result}"


def main() -> None:
    testP54()


if __name__ == "__main__":
    main()
