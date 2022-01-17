class Solution {
    fun reverse(x: Int): Int {
        if (x == 0) {
            return 0
        }
        
        var temp: Long
        var resStr: String = ""
        
        temp = if (x < 0) -x.toLong() else x.toLong()
        
        while (temp > 0) {
            var digit = temp % 10
            resStr = resStr.plus(digit.toString())
            temp = temp / 10
        }

        var res: Long = resStr.toLong()
        
        if (res > Int.MAX_VALUE) {
            return 0
        }
        
        if (x < 0) {
            res = -res
        }
        return res.toInt()
    }
}