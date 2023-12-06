struct Solution {}

impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        let frequencies = Self::get_frequencies(&nums);

        for (_, value) in frequencies.iter() {
            result += (value * (value - 1)) / 2;
        }
        
        result
    }

    fn get_frequencies(nums: &Vec<i32>) -> std::collections::HashMap::<i32, i32> {
        let mut frequencies = std::collections::HashMap::<i32, i32>::new();
        for i in 0..nums.len() {
            match frequencies.get_mut(&nums[i]) {
                Some(result) => {*result = *result + 1;},
                None => {frequencies.insert(nums[i], 1);},
            }
        }
        frequencies
    }
}

#[cfg(test)]
mod p1512_tests {
    use super::*;

    #[test]
    fn test_num_identical_pairs() {
        assert_eq!(Solution::num_identical_pairs(vec![1, 2, 3, 1, 1, 3]), 4);
    }

    #[test]
    fn test_get_frequencies() {
        let answer = Solution::get_frequencies(&vec![1, 2, 3, 1, 1, 3]);
        let expected = std::collections::HashMap::<i32, i32>::from([(1, 3), (2, 1), (3, 2)]);
        assert_eq!(expected, answer);
    }
}