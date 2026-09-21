class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        char_counts = {}
        for char in s:
            char_counts[char] = char_counts.get(char, 0) + 1

        for char in t:
            char_counts[char] = char_counts.get(char, 0) - 1

        return all(count == 0 for count in char_counts.values())