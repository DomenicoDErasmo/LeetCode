"""Solution to best time to buy and sell stock."""

from typing import List


class Solution:
    """Solution to best time to buy and sell stock."""

    def max_profit(self, prices: List[int]) -> int:
        """
        Given an array of prices, where prices[i] is the price of a given stock on the
        ith day, what would be the max profit if bought on one day and sold on another?

        Args:
            prices (List[int]): The list of prices by day.

        Returns:
            int: The max profit.
        """
        max_profit = 0
        min_price = prices[0]
        max_price = prices[0]

        for price in prices:
            if price < min_price:
                min_price = price
                max_price = price
            max_price = max(max_price, price)

            current_profit = max_price - min_price
            max_profit = max(current_profit, max_profit)

        return max_profit


def main():
    """Test the solution."""
    solution = Solution()
    print(solution.max_profit([7, 1, 5, 3, 6, 4]))


if __name__ == "__main__":
    main()
