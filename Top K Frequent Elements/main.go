func topKFrequent(nums []int, k int) []int {

    count := make(map[int]int)

    for _,v := range(nums){
        count[v] += 1
    }

    freq := make([][]int,len(nums)+1)
    for n ,c := range count {
        freq[c] = append(freq[c],n)
    }

    res := []int{}
    size := 0
    for i := len(freq) - 1; i > 0; i-- {
        for _,num := range freq[i] {
            res = append(res,num)
            size += 1
            if size == k {
                return res
            }
        }
    }
    return res
}

