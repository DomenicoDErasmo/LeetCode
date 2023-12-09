#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn number_of_employees_who_met_target(hours: Vec<i32>, target: i32) -> i32 {
        hours.into_iter().filter(|worked| *worked >= target).into_iter().collect::<Vec<_>>().len() as _
    }
}

#[cfg(test)]
mod p2798_tests {
    use super::*;

    #[test]
    fn test_number_of_employees_who_met_target() {
        assert_eq!(Solution::number_of_employees_who_met_target(vec![0, 1, 2, 3, 4], 2), 3);
    }
}