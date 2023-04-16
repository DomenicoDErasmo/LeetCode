struct Config {
    other_letters_uppercase: Option<bool>,
    early_return: Option<bool>,
}

impl Config {
    pub fn new(word: &String) -> Config {
        let first_letter_uppercase = match word.chars().nth(0) {
            Some(ch) => Some(ch.is_uppercase()),
            None => None,
        };

        let (other_letters_uppercase, 
             early_return) = match (
                word.chars().nth(1), first_letter_uppercase) {
            (Some(ch), Some(true)) => (Some(ch.is_uppercase()), None),
            (Some(ch), Some(false)) => {
                if ch.is_uppercase() {
                    (None, Some(false))
                } else {
                    (Some(false), None)
                }
            }
            (_, _) => (None, Some(true)),
        };

        Config {other_letters_uppercase, early_return}   
    }
}

pub struct DetectCapital {}

impl DetectCapital {
    pub fn detect_capital_use(&self, word: String) -> bool {
        let config = Config::new(&word);

        if config.early_return != None {
            return config.early_return.unwrap();
        }

        for ch in word[2..].chars() {
            if ch.is_uppercase() != config.other_letters_uppercase.unwrap() {
                return false;
            }
        }

        true
    }
}

#[cfg(test)]
mod p520_tests {
    use crate::p520::DetectCapital;

    #[test]
    fn empty_string_true() {
        let problem = DetectCapital{};
        assert! (problem.detect_capital_use(String::new()));
    }

    #[test]
    fn one_char_true() {
        let problem = DetectCapital{};
        assert!(problem.detect_capital_use("a".to_string()));
    }

    #[test]
    fn first_lower_second_upper_false() {
        let problem = DetectCapital{};
        assert!(!problem.detect_capital_use("aBcd".to_string()));
    }

    #[test]
    fn all_uppercase_true() {
        let problem = DetectCapital{};
        assert!(problem.detect_capital_use("USA".to_string()));
    }

    #[test]
    fn all_lowercase_true() {
        let problem = DetectCapital{};
        assert!(problem.detect_capital_use("league".to_string()));
    }

    #[test]
    fn only_first_uppercase_true() {
        let problem = DetectCapital{};
        assert!(problem.detect_capital_use("Domenico".to_string()));
    }

    #[test]
    fn first_lowercase_others_uppercase_false() {
        let problem = DetectCapital{};
        assert!(!problem.detect_capital_use("aHa".to_string()));
    }

}