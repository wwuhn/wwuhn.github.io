def bubble_sort(nums):
    for i in range(len(nums) - 1):
        for j in range(len(nums) - i - 1):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
    return nums
 
print(bubble_sort([45, 32, 8.3, 33, 12, 22.1, 19, 97]))
# 输出：[8.3, 12, 19, 22.1, 32, 33, 45, 97]
