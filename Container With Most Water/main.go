func maxArea(heights []int) int {
    r := len(heights) - 1
    l := 0
    max := 0
    for l < r {
        cap := (r - l) * min(heights[l],heights[r])
        if cap > max {
            max = cap
        }

        if (heights[l]>heights[r]){
            r = r-1
        }else{
            l = l + 1
        }
    }
    return max
}

