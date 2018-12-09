package Methods

var sliceRec []int
var sliceNonRec []int

func memoinit(flag, n int) {
	if flag == 1 {
		sliceRec = nil
		sliceRec = make([]int, n+1)
	}

	if flag == 2 {
		sliceNonRec = nil
		sliceNonRec = make([]int, n+1)
	}
}

func SimpleRecursive(n int) int {
	if n == 1 {
		return 0
	}
	if n == 2 || n == 3 {
		return 1
	}
	return ((SimpleRecursive(n - 1)) + SimpleNonRecursive(n-2))
}

func MemoRecursive(n int, bFirstTime bool) (fibn int) {
	if bFirstTime {
		memoinit(1, n)
	}
	if n == 1 {
		return 0
	}
	if n == 2 || n == 3 {
		return 1
	}
	if sliceRec[n] != 0 {
		return sliceRec[n]
	}
	sliceRec[n] = MemoRecursive(n-1, false) + MemoRecursive(n-2, false)
	return sliceRec[n]
}

func SimpleNonRecursive(n int) (fibn int) {
	if n == 1 {
		return 0
	}
	if n == 2 || n == 3 {
		return 1
	}
	prev := 1
	temp := fibn
	fibn = 2
	for i := 4; i <= n; i++ {
		temp = fibn
		fibn = fibn + prev
		prev = temp
	}
	return fibn
}

func MemoNonRecursive(n int) (fibn int) {
	return fibn
}
