#![allow(dead_code)]

use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut result = vec![];
        let mut cache = HashMap::<i32, i32>::new();

        for i in 0..nums.len() {
            let ith_num = *nums.get(i).unwrap_or(&0);

            match cache.get(&(ith_num)) {
                Some(num) => {
                    result.push(*num);
                },
                None => {
                    let mut subproblem_result = 0;
                    for j in 0..nums.len() {
                        if j == i {
                            continue;
                        }

                        let jth_num = *nums.get(j).unwrap_or(&0); 
                        if jth_num < ith_num {
                            subproblem_result += 1;
                        }
                    }
                    cache.insert(ith_num, subproblem_result);
                    result.push(subproblem_result);
                }
            }
        }

        result
    }
}

#[cfg(test)]
mod p1365_tests {
    use super::*;

    #[test]
    fn test_smaller_numbers_than_current() {
        assert_eq!(
            Solution::smaller_numbers_than_current(vec![6, 5, 4, 8]), 
            vec![2, 1, 0, 3]
        );
    }
}