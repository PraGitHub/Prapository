package Methods

import(
	"fmt"
)

func merge(left,right []int)([]int){
	i := 0
	k := 0 
	n_left := len(left)
	n_right := len(right)
	var arr_merged []int
	for true {
		if i > n_left-1 {
			if j < n_right-1{
				arr_merged = append(arr_merged,right[j:])
			}else{
				break
			}
		}
		if j > n_right-1{
			if i < n_left-1{
				arr_merged = append(arr_merged,left[i:])
			}else{
				break
			}
		}
		if left[i] < right[j]{
			arr_merged = append(arr_merged,left[i])
			i = i + 1
		}else {
			arr_merged = append(arr_merged,right[i])
			j = j + 1
		}
	}
	return arr_merged
}

func merge_sort(arr *[]int)([]int){
	len := len(*arr)
	if len == 1{
		return *arr[0]
	}
	mid := len/2
	left := merge_sort(&arr[0:mid])
	right := merge_sort(&arr[mid:])
	merge()
}

func MergeSort(arr []int)([]int){
	fmt.Println("MergeSort")
}

func QuickSort(arr []int)([]int){{
	fmt.Println("QuickSort")
}