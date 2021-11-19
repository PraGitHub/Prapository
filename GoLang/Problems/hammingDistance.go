func getZeroes(n int) []int {
    zeroes := []int{}
    for i := 0; i < n; i++ {
        zeroes = append(zeroes, 0)
    }
    return zeroes
}

func reverseArray(arr []int) []int {
    rev_arr := []int{}
    for i := len(arr)-1; i >= 0; i-- {
        rev_arr = append(rev_arr, arr[i])
    }
    return rev_arr
}

func toBitsArray(n int) []int {
    bits := []int{}
    for n > 0 {
        bits = append(bits, n%2)
        n = n/2
    }
    return reverseArray(bits)
}

func hammingDistance(x int, y int) int {
    bits_a := toBitsArray(x)
    bits_b := toBitsArray(y)
    hd := 0
    
    if len(bits_b) > len(bits_a) {
        bits_a, bits_b = bits_b, bits_a
    }
    
    if len(bits_a) > len(bits_b) {
        bits_b = append(getZeroes(len(bits_a) - len(bits_b)), bits_b...)   
    }
    
    for i := 0; i < len(bits_a); i++ {
        if bits_a[i] != bits_b[i] {
            hd++
        }
    }
    return hd
}
