#![allow(dead_code)]

struct Solution{}

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut result = 0;
        for user in accounts {
            let current: i32 = user.iter().sum();
            if current > result {
                result = current;
            }
        }
        result
    }
}

#[cfg(test)]
mod p1672_tests {
    use super::*;

    #[test]
    fn test_maximum_wealth() {
        assert_eq!(
            Solution::maximum_wealth(vec![
                vec![1, 5],
                vec![7, 3],
                vec![3, 5],
            ]),
            10
        );
    }
}