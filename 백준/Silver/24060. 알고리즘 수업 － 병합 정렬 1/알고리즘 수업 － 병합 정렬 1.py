N, K = (int(i) for i in input().split(' '))
A = [int(i) for i in input().split(' ')]
B = [0]*N;

count = 0
result = -1
    

def merge(A, start, mid, end):
  global count
  global result
  
  i = start
  j = mid+1
  k = 0
  while i <= mid and j <= end:
    if A[i] <= A[j]:
      B[k] = A[i]
      k += 1
      i += 1
    else:
      B[k] = A[j]
      k += 1
      j += 1

  while i <= mid:
    B[k] = A[i]
    k += 1
    i += 1

  while j <= end:
    B[k] = A[j]
    k += 1
    j += 1

  for i in range(k):
    A[start + i] = B[i]

    count += 1
    if count == K:
      result = B[i]

def mergeSort(A, start, end):
  if start < end:
    mid = (start + end) // 2
    
    mergeSort(A, start, mid)
    mergeSort(A, mid+1, end)
    merge(A, start, mid, end)


# main
mergeSort(A, 0, N-1)
print(result)
