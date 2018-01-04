class Solution(object):

    def quickSplit(self, nums, l, h):
        pivot = nums[l]
        while l < h:
            while l < h and pivot >= nums[h]:
                h -= 1
            nums[l] = nums[h]
            while l < h and pivot <= nums[l]:
                l += 1
            nums[h] = nums[l]
        nums[l] = pivot
        return l

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        l = 0
        h = len(nums) - 1
        while True:
            pos = self.quickSplit(nums, l, h)
            if pos == k - 1:
                return nums[pos]
            elif pos > k - 1:
                h = pos - 1
            else:
                l = pos + 1