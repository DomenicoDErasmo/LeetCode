struct Solution;

impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let cleaned_s = s
            .chars()
            .filter(|s| s.is_alphanumeric())
            .collect::<String>()
            .to_lowercase();

        if cleaned_s.is_empty() {
            return true;
        }

        let mut left = 0;
        let mut right = cleaned_s.len() - 1;

        while left < right {
            let Some(left_char) = cleaned_s.chars().nth(left) else {
                return false;
            };
            let Some(right_char) = cleaned_s.chars().nth(right) else {
                return false;
            };
            if left_char != right_char {
                return false;
            }

            left += 1;
            right -= 1;
        }

        true
    }
}

#[cfg(test)]
mod test_p125 {
    use crate::p125::Solution;

    #[test]
    fn test_p125() {
        assert!(Solution::is_palindrome("amanaplanacanalpanama".to_owned()));
        assert!(!Solution::is_palindrome("race a car".to_owned()));
        assert!(Solution::is_palindrome(" ".to_owned()));
    }
}
