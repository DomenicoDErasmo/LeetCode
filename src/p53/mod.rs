struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut candidate = 0;
        let mut result = i32::MIN;

        for num in nums.iter() {
            candidate += num;

            if candidate > result {
                result = candidate;
            }

            candidate = i32::max(candidate, 0);
        }

        result
    }
}

#[test]
fn test_p53() {
    assert_eq!(
        Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]),
        6
    )
}
