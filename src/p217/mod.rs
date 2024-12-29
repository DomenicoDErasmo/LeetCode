use std::collections::HashSet;

struct Solution {}

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut previously_encountered = HashSet::<i32>::new();
        for num in nums {
            if previously_encountered.contains(&num) {
                return true;
            }

            previously_encountered.insert(num);
        }
        false
    }
}

#[test]
fn test_p217() {
    assert!(Solution::contains_duplicate(vec![1, 2, 2, 3]))
}
