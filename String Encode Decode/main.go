type Solution struct{}

func (s *Solution) Encode(strs []string) string {

    result := ""

    for _, str := range strs{
        result = result + str + "-"
    }

    return result

}

func (s *Solution) Decode(encoded string) []string {
    temp := ""
    var results []string

    for _,i:= range encoded{
        if i != '-' {
            temp += string(i)
        }else{
            results = append(results,temp)
            temp =  ""
        }
    }

    return results
}

