struct Solution;

impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        (0..32)
            .map(|i| (x >> i) & 1)
            .collect::<Vec<u32>>()
            .iter()
            .rev()
            .enumerate()
            .fold(0u32, |mut sum, (power, bit)| {
                sum += bit * 2_u32.pow(power as u32);
                sum
            })
    }
}

#[test]
fn test_p190() {
    assert_eq!(
        Solution::reverse_bits(0b00000010100101000001111010011100),
        964176192
    )
}
