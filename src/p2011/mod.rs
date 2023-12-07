struct Solution {}

impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        operations.iter().fold(0, |result, operation|
            match operation.as_str() {
                "++X" | "X++" => result + 1,
                _ => result - 1,
            }
        )
    }
}

#[cfg(test)]
mod p2011_tests {
    use super::*;

    #[test]
    fn test_final_value_after_operations() {
        assert_eq!(Solution::final_value_after_operations(vec!["++X".to_owned(), "--X".to_owned(), "X++".to_owned(), "X++".to_owned(), "++X".to_owned(), "X--".to_owned()]), 2);
    }
}