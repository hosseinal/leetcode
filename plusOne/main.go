func plusOne(digits []int) []int {
    output := make([]int, len(digits))
    copy(output, digits)

    for i:= len(output)-1 ; i >=0 ; i--{
        if output[i] == 9 {
            output[i] = 0
            if i == 0 {
                output = append([]int{1}, output...)
            }
        }else{
            output[i]+=1
            break
        }
    }

    return output
}

