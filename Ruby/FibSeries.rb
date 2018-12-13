$memo = Array.new(1,-1)

def SimpleRecursive(n)
    /puts("SimpleRecursive :: n = ",n)/
    if n == 1
        return 0
    end

    if n == 2 || n == 3
        return 1
    end

    return ((SimpleRecursive(n-1))+(SimpleRecursive(n-2)))
end

def NonRecursive(n)
    if n == 1
        return 0
    end

    if n == 2 || n == 3
        return 1
    end

    fib = 2
    curr = 1
    prev = 1
    i = 4

    while i <= n do
        fib = curr + prev
        prev = curr
        curr = fib
        i = i + 1
    end

    return fib
end

def MemoRecursive(n,is_first_time)
    if is_first_time
        $memo = Array.new(n,-1)
        $memo[0] = 0
        $memo[1] = $memo[2] = 1
    end

    /puts("MemoRecursive :: n = ",n)
    puts("MemoRecursive :: memo = ",$memo)/

    if $memo[n-1] != -1
        return $memo[n-1]
    end

    $memo[n-1] = MemoRecursive(n-1,false) + MemoRecursive(n-2,false)

    return $memo[n-1]
end

puts("FibSeries app started...")

puts("Enter n = ")

n = gets.chomp

n = n.to_i

puts(String(Time.now.to_f) + " :: Called NonRecursive")
result = String(NonRecursive(n))
puts(String(Time.now.to_f) + " :: " + result)

puts(String(Time.now.to_f) + " :: Called MemoRecursive")
result = String(MemoRecursive(n,true))
puts(String(Time.now.to_f) + " :: " + result)

puts(String(Time.now.to_f) + " :: Called SimpleRecursive")
result = String(SimpleRecursive(n))
puts(String(Time.now.to_f) + " :: " + result)