struct Solution {}

impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let mut result = vec![];
        for _ in 0..2 {
            for num in nums.iter() {
                result.push(*num);
            }
        }
        result
    }
}

#[cfg(test)]
mod p1929_tests {
    use super::*;

    #[test]
    fn test_get_concatenation() {
        assert_eq!(Solution::get_concatenation(vec![1, 2, 1]), vec![1, 2, 1, 1, 2, 1])
    }
}