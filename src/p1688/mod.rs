#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn number_of_matches(n: i32) -> i32 {
        let casted_n = n as usize;
        let mut answers = vec![0; casted_n + 1];

        for i in 2..=casted_n {
            let even_subproblem = *answers.get(i / 2).unwrap_or(&0);
            let odd_subproblem = *answers.get((i - 1) / 2 + 1).unwrap_or(&0);

            if let Some(val) = answers.get_mut(i) {
                *val = match i % 2 == 0 {
                    true => i / 2 + even_subproblem,
                    false => (i - 1) / 2 + odd_subproblem,
                };
            }
        }

        *answers.get(casted_n).unwrap_or(&0) as i32
    }
}

#[cfg(test)]
mod p1688_tests {
    use super::*;

    #[test]
    fn test_number_of_matches() {
        assert_eq!(Solution::number_of_matches(7), 6);
    }
}
