struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for (i, outer_num) in nums.iter().enumerate() {
            for (j, inner_num) in nums.iter().enumerate() {
                if i == j {
                    continue;
                }

                if inner_num + outer_num == target {
                    return vec![i as i32, j as i32];
                }
            }
        }
        return vec![];
    }
}

#[cfg(test)]
mod p1_tests {
    use crate::p1::Solution;

    #[test]
    fn test_two_sum() {
        assert_eq!(Solution::two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
        assert_eq!(Solution::two_sum(vec![11, 7, 2, 15], 9), vec![2, 1]);
    }
}