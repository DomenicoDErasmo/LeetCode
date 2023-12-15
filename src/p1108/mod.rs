#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        let mut result = String::new();

        for ch in address.chars() {
            let addon = if ch == '.' {"[.]".to_owned()} else {ch.to_string()};
            result = format!("{result}{addon}");
        }

        result
    }
}

#[cfg(test)]
mod p1108_tests {
    use super::*;

    #[test]
    fn test_defang_i_paddr() {
        assert_eq!(Solution::defang_i_paddr("1.1.1.1".to_owned()), "1[.]1[.]1[.]1".to_owned());
    }
}