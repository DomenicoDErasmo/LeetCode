struct Solution {}

impl Solution {
    pub fn best_time_to_buy_and_sell_stock(prices: Vec<i32>) -> i32 {
        let mut max_profit = 0;

        let mut max_price = 0;
        let mut min_price = 0;

        for price in &prices {
            if price > &max_price {
                max_price = *price;
            }
            if price < &min_price {
                min_price = *price;
            }

            let current_profit = max_price - min_price;
            if current_profit > max_profit {
                max_profit = current_profit;
            }
        }

        max_profit
    }
}

#[cfg(test)]
mod p121_tests {
    use crate::p121::Solution;

    #[test]
    fn test_best_time_to_buy_and_sell_stock() {
        assert_eq!(Solution::best_time_to_buy_and_sell_stock(vec![7, 1, 5, 3, 6, 4]), 5);
    }
}