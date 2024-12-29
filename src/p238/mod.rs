struct Solution {}

impl Solution {
    fn get_prefixes(nums: &[i32]) -> Vec<i32> {
        let mut result = vec![1; nums.len()];

        for i in 1..nums.len() {
            result[i] = result[i - 1] * nums[i - 1];
        }

        result
    }

    fn get_suffixes(nums: &[i32]) -> Vec<i32> {
        let mut result = vec![1; nums.len()];

        for i in (0..nums.len() - 1).rev() {
            result[i] = result[i + 1] * nums[i + 1];
        }

        result
    }

    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let prefixes = Solution::get_prefixes(&nums);
        let suffixes = Solution::get_suffixes(&nums);

        let mut result = vec![0; nums.len()];

        for i in 0..nums.len() {
            result[i] = prefixes[i] * suffixes[i];
        }

        result
    }
}

#[test]
fn test_p238() {
    assert_eq!(
        Solution::product_except_self(vec![1, 2, 3, 4]),
        vec![24, 12, 8, 6]
    )
}
