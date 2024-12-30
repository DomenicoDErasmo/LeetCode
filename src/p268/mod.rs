use std::collections::HashSet;

struct Solution {}

impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut all_nums = (0..=nums.len()).map(|i| i as i32).collect::<HashSet<i32>>();
        for num in nums {
            all_nums.remove(&num);
        }

        *all_nums.iter().next().unwrap()
    }
}