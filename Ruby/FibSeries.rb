memo = Array.new(1,-1)

def SimpleRecursive(n)
    if n == 1
        return 1
    end

    if n == 2 || n == 3
        return 2
    end

    return ((SimpleRecursive(n-1))+(SimpleRecursive(n-2)))
end

def NonRecursive(n)
    if n == 1
        return 1
    end

    if n == 2 || n == 3
        return 2
    end

    fib = 1
    curr = 1
    prev = 1
    i = 4
    while i <= n
        fib = curr + prev
        prev = curr
        curr = fib
        i++
    end

    return fib
end

def MemoRecursive(n,is_first_time)
    if is_first_time
        memo = Array.new(n,-1)
        memo[0] = 0
        memo[1] = memo[2] = 1
    end

    if memo[n-1] != -1
        return memo[n-1]
    end

    memo[n-1] = MemoRecursive(n-1,false) + MemoRecursive(n-2,false)

    return memo[n-1]
end

puts("FibSeries app started...")

puts("Enter n = ")

n = gets.chomp

n = n.to_i

puts(String(Time.now.to_f) + " :: Called NonRecursive")
puts(String(Time.now.to_f) + " :: " + String(NonRecursive(n)))

puts(String(Time.now.to_f) + " :: Called MemoRecursive")
puts(String(Time.now.to_f) + " :: " + String(MemoRecursive(n,true)))

puts(String(Time.now.to_f) + " :: Called SimpleRecursive")
puts(String(Time.now.to_f) + " :: " + String(SimpleRecursive(n)))