struct Solution {}

impl Solution {
    pub fn maximum_gap(nums: Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return 0;
        }

        let mut max = 0;
        let mut sorted_nums = nums.clone();
        sorted_nums.sort();

        for i in 1..nums.len() {
            let current = sorted_nums[i] - sorted_nums[i-1];
            if current > max {
                max = current;
            }
        }

        max
    }
}

#[cfg(test)]
mod p164_tests {
    use super::*;

    #[test]
    fn test_maximum_gap() {
        assert_eq!(Solution::maximum_gap(vec![3, 6, 9, 1]), 3);
    }
}