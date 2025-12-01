func lengthOfLongestSubstring(s string) int {
    m := make(map[byte]int)
    startPoint := 0
    size := 0

    for i:= 0; i < (len(s)); i++ {
        id, found := m[s[i]]
        if found {
            startPoint = max(id + 1, startPoint)
        }
        m[s[i]] = i
        size = max(size, i - startPoint + 1)
    }

    return size
}

