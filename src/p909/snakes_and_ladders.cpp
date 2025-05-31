#include <queue>
#include <unordered_set>
#include <vector>

using Board = std::vector<std::vector<int>>;
using FlattenedBoard = std::vector<int>;

const int DIE = 6;

class Solution {
   public:
    int snakesAndLadders(Board& board) {
        const FlattenedBoard flattened_board = from_board(board);

        std::queue<std::pair<int, int>> to_visit;
        to_visit.push({0, 0});

        std::unordered_set<int> visiting;
        visiting.insert(0);

        while (!to_visit.empty()) {
            std::pair<int, int> front = to_visit.front();

            for (int i = 1; i <= DIE; i++) {
                int next_tile = front.first + i;
                int next_distance = front.second + 1;

                if (next_tile >= flattened_board.size()) {
                    return next_distance;
                }

                int destination = flattened_board[next_tile];

                // the destination is 1-indexed
                int next_location =
                    destination == -1 ? next_tile : (destination - 1);

                if (next_location + 1 == flattened_board.size()) {
                    return next_distance;
                }

                // to prevent repeat checking
                if (visiting.count(next_location)) {
                    continue;
                }

                to_visit.push({next_location, next_distance});
                visiting.insert(next_location);
            }
            to_visit.pop();
        }

        return -1;
    }

   private:
    /* Creates a "flattened board" from a "Boustrophedon style" board.
     * A board is considered "Boustrophedon style" if it alternates from
     * left to right the right to left. For example:
     *
     * | C1 | C2 | C3 |
     * |----|----|----|
     * | 6  | 7  | 8  |
     * | 5  | 4  | 3  |
     * | 0  | 1  | 2  |
     *
     * The flattened result would be:
     *
     * 0 1 2 3 4 5 6 7 8
     */
    FlattenedBoard from_board(const Board& board) {
        FlattenedBoard flattened_board;
        bool left_to_right = true;
        for (int i = board.size() - 1; i >= 0; i--) {
            for (int j = 0; j < board[i].size(); j++) {
                flattened_board.push_back(
                    left_to_right ? board[i][j]
                                  : board[i][board[i].size() - 1 - j]);
            }
            left_to_right = !left_to_right;
        }
        return flattened_board;
    }
};
