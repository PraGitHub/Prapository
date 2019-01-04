package Methods

import "fmt"

func merge(left, right []int) []int {
	i := 0
	j := 0
	n_left := len(left)
	n_right := len(right)
	var arr_merged []int = nil
	for true {
		if i > n_left-1 {
			if j < n_right {
				arr_merged = append(arr_merged, right[j:]...)
			}
			break
		}
		if j > n_right-1 {
			if i < n_left {
				arr_merged = append(arr_merged, left[i:]...)
			}
			break
		}
		if left[i] < right[j] {
			arr_merged = append(arr_merged, left[i])
			i = i + 1
		} else {
			arr_merged = append(arr_merged, right[j])
			j = j + 1
		}
	}
	return arr_merged
}

func merge_sort(arr []int) []int {
	n_arr := len(arr)
	if n_arr == 1 {
		return arr[0:1]
	}
	mid := n_arr / 2
	left := merge_sort(arr[0:mid])
	right := merge_sort(arr[mid:])
	return merge(left, right)
}

func MergeSort(arr []int) []int {
	arr_sorted := merge_sort(arr)
	return arr_sorted
}

func QuickSort(arr []int) []int {
	fmt.Println("QuickSort")
	return arr
}
