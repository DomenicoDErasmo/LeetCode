#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn count_pairs(nums: Vec<i32>, target: i32) -> i32 {
        let mut result = 0;

        for i in 0..nums.len() {
            for j in (i+1)..nums.len() {
                let ith_num = *nums.get(i).unwrap_or(&0);
                let jth_num = *nums.get(j).unwrap_or(&0);
                
                if ith_num + jth_num < target {
                    result += 1;
                }
            }
        }

        result
    }
}

#[cfg(test)]
mod p2824_tests {
    use super::*;

    #[test]
    fn test_count_pairs() {
        assert_eq!(Solution::count_pairs(vec![-1, 1, 2, 3, 1], 2), 3);
    }
}