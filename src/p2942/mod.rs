pub struct Solution {}

impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut result = vec![];

        for (i, word) in words.iter().enumerate() {
            match word.find(x) {
                Some(_) => result.push(i as i32),
                None => {}
            }
        }

        result
    }
}

#[cfg(test)]
mod p2942_tests {
    use super::*;
    #[test]
    fn test_find_words_containing() {
        assert_eq!(
            Solution::find_words_containing(
                vec!["leet".to_owned(), "code".to_owned()], 
                'e'
            ), 
            vec![0, 1]
        );
    }
}