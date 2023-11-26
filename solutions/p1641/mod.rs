#![allow(dead_code)]

struct Solution {}

#[derive(Copy, Clone, Eq, Hash, PartialEq)]
enum Vowel {
    A,
    E,
    I,
    O,
    U,
}

// Best solution is to use strum and strum_macros to iterate but we don't have that for LeetCode
const CHOICES: [Vowel; 5] = [Vowel::A, Vowel::E, Vowel::I, Vowel::O, Vowel::U];

impl Vowel {
    pub fn get_succeeding_vowels(&self) -> Vec<Vowel> {
        match self {
            Vowel::A => vec![Vowel::A, Vowel::E, Vowel::I, Vowel::O, Vowel::U],
            Vowel::E => vec![Vowel::E, Vowel::I, Vowel::O, Vowel::U],
            Vowel::I => vec![Vowel::I, Vowel::O, Vowel::U],
            Vowel::O => vec![Vowel::O, Vowel::U],
            Vowel::U => vec![Vowel::U],
        }
    }
}

#[derive(Eq, Hash, PartialEq)]
struct Subproblem {
    pub start_vowel: Vowel,
    pub remaining_letters: i32,
}

impl Solution {
    pub fn count_vowel_strings(n: i32) -> i32 {
        let mut cache = std::collections::HashMap::<Subproblem, i32>::new();
        
        // base cases: when n = 0 return 1 regardless of next vowel
        for choice in CHOICES.iter() {
            let subproblem = Subproblem {start_vowel: *choice, remaining_letters: 0};
            cache.insert(subproblem, 1);
        }

        let problem = Subproblem {start_vowel: Vowel::A, remaining_letters: n};
        Self::helper(problem, &mut cache)
    }

    fn helper(problem: Subproblem, cache: &mut std::collections::HashMap<Subproblem, i32>) -> i32 {
        match cache.get(&problem) {
            Some(result) => *result,
            None => {
                let mut result = 0;

                let possible_vowels = Vowel::get_succeeding_vowels(&problem.start_vowel);
                for vowel in possible_vowels.iter() {
                    let subproblem = Subproblem {
                        start_vowel: *vowel, 
                        remaining_letters: problem.remaining_letters - 1
                    };
                    result += Solution::helper(subproblem, cache);
                }

                cache.insert(problem, result);
                result
            }
        }
    }
}

#[cfg(test)]
mod p1646_test {
    use super::*;

    #[test]
    fn test_count_vowel_strings() {
        assert_eq!(Solution::count_vowel_strings(1), 5);
        assert_eq!(Solution::count_vowel_strings(2), 15);
        assert_eq!(Solution::count_vowel_strings(33), 66_045);
    }
}