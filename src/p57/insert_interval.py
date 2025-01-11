from typing import List, Set

class Solution:
    @staticmethod
    def getMergedInterval(intervals: List[List[int]], merged_interval_indices: Set[int], newInterval: List[int]) -> List[int]:
        # using sentinel values to cut verbosity, values can only be 0 to 100,000
        merged_min = 100_001
        merged_max = -1

        for i in merged_interval_indices:
            merged_min = min(merged_min, intervals[i][0])
            merged_max = max(merged_max, intervals[i][1])

        merged_min = min(merged_min, newInterval[0])
        merged_max = max(merged_max, newInterval[1])

        return [merged_min, merged_max]

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []

        all_intervals = set(range(len(intervals)))
        non_merged_intervals = {
            i for i, interval in enumerate(intervals) 
            if interval[1] < newInterval[0] or interval[0] > newInterval[1]
        }
        merged_intervals = all_intervals - non_merged_intervals
        merged_interval = self.getMergedInterval(intervals, merged_intervals, newInterval)
        
        # result should be all non-merged intervals and the merged interval sorted
        result = [
            *[
                interval for i, interval in enumerate(intervals) 
                if i in non_merged_intervals
            ], 
            merged_interval
        ]
        return sorted(result, key=lambda x: x[0])
    

def test_p57() -> None:
    # assert Solution().insert([[1, 3], [6, 9]], [4, 5]) == [[1, 3], [4, 5], [6, 9]]
    # assert Solution().insert([[1, 3], [6, 9]], [2, 5]) == [[1, 5], [6, 9]]
    assert Solution().insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4, 8]) == [[1,2],[3,10],[12,16]]


def main() -> None:
    test_p57()


if __name__ == "__main__":
    main()
