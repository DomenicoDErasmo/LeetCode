from copy import deepcopy
from typing import List


class Solution:
    def setZeroesLong(self, matrix: List[List[int]]) -> None:
        original = deepcopy(matrix)
        for i in range(len(original)):
            for j in range(len(original[i])):
                if original[i][j] == 0:
                    for k in range(len(original)):
                        matrix[k][j] = 0
                    for l in range(len(original[i])):
                        matrix[i][l] = 0

    def setZeroes(self, matrix: List[List[int]]) -> None:
        zero_rows = set()
        zero_cols = set()
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if not matrix[i][j]:
                    zero_rows.add(i)
                    zero_cols.add(j)

        for i in zero_rows:
            for j in range(len(matrix[i])):
                matrix[i][j] = 0

        for i in range(len(matrix)):
            for j in zero_cols:
                matrix[i][j] = 0


def testP73() -> None:
    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    Solution().setZeroes(matrix)
    expected = [
        [1, 0, 1],
        [0, 0, 0],
        [1, 0, 1],
    ]
    assert matrix == expected, f"Expected {expected}, got {matrix}"


def main() -> None:
    testP73()


if __name__ == "__main__":
    main()
