class Solution:
    def isIsomorphic(self, s, t):
        count_s, count_t = 0, 0
        dict_s, dict_t = {}, {}
        for index in range(len(s)):
            if not s[index] in dict_s:
                dict_s[s[index]] = count_s
                count_s += 1
            cur_s = dict_s[s[index]]
            if not t[index] in dict_t:
                dict_t[t[index]] = count_t
                count_t += 1
            cur_t = dict_t[t[index]]
            if not cur_s == cur_t:
                return False
        return True