pub struct MaxInArray {}
    
impl MaxInArray {
    pub fn get_maximum_in_generated_array(n: i32) -> i32 {
        if n < 2 {return n;}

        let mut table = vec![0; (n + 1) as usize];
        table[1] = 1;
        
        for i in 2..((n + 1) as usize) {
            table[i] = match i % 2 == 0 {
                true => table[i/2],
                false => table[i/2] + table[i/2 + 1],
            };
        }
        
        match table.iter().max() {
            Some(max) => *max,
            None => 0,
        }
    }
}

#[cfg(test)]
mod p1646_tests {
    use crate::p1646::MaxInArray;

    #[test]
    fn n_equals_zero_yields_zero() {
        assert_eq!(MaxInArray::get_maximum_in_generated_array(0), 0);
    }

    #[test]
    fn n_equals_one_yields_one() {
        assert_eq!(MaxInArray::get_maximum_in_generated_array(1), 1);
    }

    #[test]
    fn n_equals_three_yields_two() {
        assert_eq!(MaxInArray::get_maximum_in_generated_array(3), 2);
    }

    #[test]
    fn n_equals_six_yields_two() {
        assert_eq!(MaxInArray::get_maximum_in_generated_array(6), 3);
    }

    #[test]
    fn n_equals_seven_yields_three() {
        assert_eq!(MaxInArray::get_maximum_in_generated_array(7), 3);
    }

    #[test]
    fn n_equals_fifteen_yields_five() {
        assert_eq!(MaxInArray::get_maximum_in_generated_array(15), 5);
    }
}
