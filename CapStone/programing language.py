import time
import copy
import numpy as np


large_array = np.random.rand(1_000_000)


def pass_by_reference(arr):
    return arr[0]

def pass_by_value(arr):
    copied = copy.deepcopy(arr)
    return copied[0]

N = 1000

start_ref = time.time()
for _ in range(N):
    pass_by_reference(large_array)
end_ref = time.time()
time_ref = end_ref - start_ref

start_val = time.time()
for _ in range(N):
    pass_by_value(large_array)
end_val = time.time()
time_val = end_val - start_val

print(f"Pass-by-reference time: {time_ref:.4f} seconds")
print(f"Pass-by-value time:     {time_val:.4f} seconds")
print(f"Ratio (value / reference): {time_val / time_ref:.2f}")