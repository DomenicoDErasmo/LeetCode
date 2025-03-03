#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

template <typename T>
using Row = std::vector<T>;

template <typename T>
using Grid = Row<Row<T>>;

struct Pair {
    int row, col;
    Pair(int row, int col) : row(row), col(col) {}

    Pair operator+(const Pair& rhs) { return {row + rhs.row, col + rhs.col}; }
    bool operator<(const Pair& rhs) const {
        return row * row + col * col < rhs.row * rhs.row + rhs.col * rhs.col;
    }
};

const Row<Pair> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

enum CellState {
    EMPTY = 0,
    FRESH = 1,
    ROTTEN = 2,
};

void printFreshOranges(const std::set<std::pair<int, int>>& freshOranges) {
    std::cout << "fresh oranges: [";
    for (std::set<std::pair<int, int>>::iterator it = freshOranges.begin();
         it != freshOranges.end(); it++) {
        std::cout << "(" << it->first << ", " << it->second << "), ";
    }
    std::cout << "]" << std::endl;
}

class Solution {
   public:
    int orangesRotting(Grid<int>& grid) {
        auto [rottenOranges, freshOranges, visited] =
            initRottenOrangesAndVisited(grid);

        if (freshOranges.empty()) {
            return 0;
        }

        if (rottenOranges.empty()) {
            return -1;
        }

        int minutes = 0;
        while (!rottenOranges.empty()) {
            int numRottenOranges = rottenOranges.size();
            for (int i = 0; i < numRottenOranges; i++) {
                Pair current = rottenOranges.front();
                visited[current.row][current.col] = true;
                rottenOranges.pop();

                for (Pair direction : DIRECTIONS) {
                    Pair newPair = current + direction;
                    if (isOutOfBounds(grid, newPair) || alreadyVisited(visited, newPair)) {
                        continue;
                    }

                    if (grid[newPair.row][newPair.col] == CellState::FRESH) {
                        grid[newPair.row][newPair.col] = CellState::ROTTEN;
                        rottenOranges.push(newPair);
                        freshOranges.erase({newPair.row, newPair.col});
                    }
                }
            }

            minutes++;

            if (freshOranges.empty()) {
                return minutes;
            }
        }

        return -1;
    }

   private:
    std::tuple<std::queue<Pair>, std::set<std::pair<int, int>>, Grid<bool>>
    initRottenOrangesAndVisited(const Grid<int>& grid) {
        Grid<bool> visited(grid.size(), Row<bool>(grid[0].size(), false));
        std::queue<Pair> rottenOranges;
        std::set<std::pair<int, int>> freshOranges;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == CellState::ROTTEN) {
                    rottenOranges.push(Pair(i, j));
                    visited[i][j] = true;
                } else if (grid[i][j] == CellState::FRESH) {
                    freshOranges.insert({i, j});
                }
            }
        }
        return {rottenOranges, freshOranges, visited};
    }

    bool isOutOfBounds(const Grid<int>& grid, const Pair& pair) {
        return pair.row < 0 || pair.col < 0 || pair.row >= grid.size() ||
               pair.col >= grid[0].size();
    }

    bool alreadyVisited(const Grid<bool>& visited, const Pair& pair) {
        return visited[pair.row][pair.col];
    }
};
