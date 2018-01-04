    def containsDuplicate(self, nums):
        d = {}
        for index in nums:
            if index in d:
                return True
            d[index] = 1
        return False