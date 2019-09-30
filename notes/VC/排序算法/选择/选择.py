def selection_sort(list2):
  for i in range(0, len (list2)-1):
    min_ = i
    for j in range(i + 1, len(list2)):
      if list2[j] < list2[min_]:
        min_ = j
    list2[i], list2[min_] = list2[min_], list2[i]  # swap