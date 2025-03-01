#![allow(dead_code)]

struct Solution {}


const DIRECTIONS: [Pair; 4] = [
    Pair {i: -1, j: 0},
    Pair {i: 1, j: 0},
    Pair {i: 0, j: 1},
    Pair {i: 0, j: -1},
];


struct Pair {
    pub i: isize,
    pub j: isize,
}


impl Solution {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let mut result = 0;
        let mut visited = vec![vec![false; grid[0].len()]; grid.len()];

        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                let pair = Pair {i: i as _, j: j as _};
                if Self::is_unvisited_land(&pair, &grid, &visited) {
                    result += 1;

                    // visit all
                    let mut queue = std::collections::VecDeque::<Pair>::new();
                    visited[pair.i as usize][pair.j as usize] = true;
                    queue.push_back(pair);

                    while let Some(current_pair) = queue.pop_front() {
                        for direction in DIRECTIONS.iter() {
                            let new_pair = Pair {
                                i: current_pair.i + direction.i,
                                j: current_pair.j + direction.j,
                            };

                            if (0..(grid.len() as isize)).contains(&new_pair.i) 
                                && (0..(grid[0].len() as isize)).contains(&new_pair.j) 
                                && Self::is_unvisited_land(&new_pair, &grid, &visited) {
                                    visited[new_pair.i as usize][new_pair.j as usize] = true;
                                    queue.push_back(new_pair);
                            }
                        }
                    }
                }
                
            }
        }
        
        result
    }

    fn is_unvisited_land(pair: &Pair, grid: &[Vec<char>], visited: &[Vec<bool>]) -> bool {
        !visited[pair.i as usize][pair.j as usize] && grid[pair.i as usize][pair.j as usize] == '1'
    }
}

#[cfg(test)]
mod p200_tests {
    use super::*;

    #[test]
    fn test_num_islands() {
        assert_eq!(
            Solution::num_islands(
                vec![
                    vec!['1', '1', '1', '1', '0'],
                    vec!['1', '1', '0', '1', '0'],
                    vec!['1', '1', '0', '0', '0'],
                    vec!['0', '0', '0', '0', '0'],
                ]
            ),
            1
        );
        assert_eq!(
            Solution::num_islands(
                vec![
                    vec!['1', '1', '0', '0', '0'],
                    vec!['1', '1', '0', '0', '0'],
                    vec!['0', '0', '1', '0', '0'],
                    vec!['0', '0', '0', '1', '1'],
                ]
            ),
            3
        );
        assert_eq!(
            Solution::num_islands(
                vec![
                    vec!['1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'],
                    vec!['0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'],
                    vec!['1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '0', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'],
                    vec!['0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'],
                    vec!['1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1']
                ]
            ),
            1
        );
    }
}