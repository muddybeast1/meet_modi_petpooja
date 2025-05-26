from itertools import permutations

nums = [1, 2, 3]
all_perms = list(permutations(nums))
for p in all_perms:
    print(list(p))