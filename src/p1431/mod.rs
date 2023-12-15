#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut result = vec![];
        
        let max = match candies.iter().max() {
            Some(num) => *num,
            None => 0,
        };

        for candy in candies.iter() {
            result.push(candy + extra_candies >= max);
        }

        result
    }
}

#[cfg(test)]
mod p1431_tests {
    use super::*;

    #[test]
    fn test_kids_with_candles() {
        assert_eq!(
            Solution::kids_with_candies(vec![2, 3, 5, 1, 3], 3), 
            vec![true, true, true, false, true]
        );
    }
}