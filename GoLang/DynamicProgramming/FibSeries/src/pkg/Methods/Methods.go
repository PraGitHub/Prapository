package Methods

var sliceRecursive []int
var sliceNonRecursive []int

func Init() {
	sliceRecursive = sliceRecursive[:0]
	sliceNonRecursive = sliceNonRecursive[:0]
}

func SimpleRecursive(n int) int {
	if n == 1 {
		return 0
	}
	if n == 2 || n == 3 {
		return 1
	}
	return ((SimpleRecursive(n - 2)) + SimpleNonRecursive(n-1))
}

func MemoRecursive(n int) (fibn int) {
	if n == 1 {
		return 0
	}
	if n == 2 || n == 3 {
		return 1
	}

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
