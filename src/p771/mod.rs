struct Solution {}

impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut result = 0;
        for stone in stones.chars() {
            match jewels.find(stone) {
                Some(_) => {result += 1;},
                None => {},
            };
        }
        result
    }
}

#[cfg(test)]
mod p771_tests {
    use super::*;

    #[test]
    fn test_num_jewels_in_stones() {
        assert_eq!(
            Solution::num_jewels_in_stones(
                "aA".to_owned(), 
                "aAAbbbb".to_owned(),
            ),
            3
        );
    }
}