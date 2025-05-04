a = int(input())
nums = input().split()
for i in range(a):
    nums[i] = int(nums[i])%2

if nums[0] == nums[1]:
    for i in range(2, a):
        if nums[i] != nums[0]:
            print(i+1)
else:
    print(2 if nums[0] == nums[2] else 1)