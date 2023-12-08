#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let mut result = vec![];
        for i in 0..n {
            result.push(nums[i as usize]);
            result.push(nums[(i + n) as usize]);
        }
        result
    }
}

#[cfg(test)]
mod p1470_tests {
    use super::*;

    #[test]
    fn test_shuffle() {
        assert_eq!(
            Solution::shuffle(vec![2, 5, 1, 3, 4, 7], 3), 
            vec![2, 3, 5, 4, 1, 7]
        );
    }
}