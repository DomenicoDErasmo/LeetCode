#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn convert_temperature(celsius: f64) -> Vec<f64> {
        let kelvin = celsius + 273.15;
        let farenheit = celsius * 1.8 + 32.0;

        vec![kelvin, farenheit]
    }
}

#[cfg(test)]
mod p2469_tests {
    use super::*;

    #[test]
    fn test_convert_temperature() {
        assert_eq!(Solution::convert_temperature(36.50), vec![309.65000, 97.70000]);
    }
}