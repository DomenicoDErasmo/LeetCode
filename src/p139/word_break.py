from typing import List


class Solution:
    def helper(self, s: str, wordDict: List[str], index: int) -> bool:
        if index == len(s):
            return True

        word_choices: list[bool] = []
        for word in wordDict:
            if s[index : index + len(word)] == word:
                word_choices.append(self.helper(s, wordDict, index + len(word)))

        return any(word_choices)

    def recusriveWordBreak(self, s: str, wordDict: List[str]) -> bool:
        return self.helper(s, wordDict, 0)

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        subproblems = [False] * (len(s) + 1)
        subproblems[0] = True

        for i in range(len(s) + 1):
            for word in wordDict:
                if i < len(word):
                    continue

                substring = s[i - len(word) : i]
                if substring == word and subproblems[i - len(word)]:
                    subproblems[i] = True

        return subproblems[-1]


def testWordBreak() -> None:
    assert Solution().wordBreak("leetcode", ["leet", "code"])


def main() -> None:
    testWordBreak()


if __name__ == "__main__":
    main()
