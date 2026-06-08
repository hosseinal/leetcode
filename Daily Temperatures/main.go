type Stack struct {
	items []int
}

func (s *Stack) Push(item int) {
	s.items = append(s.items, item)
}

func (s *Stack) Pop() (int, error) {
	if s.Size() == 0 {
		return 0, nil
	}
	last_item := len(s.items) - 1
	item := s.items[last_item]
	s.items = s.items[:last_item]
	return item, nil
}

func (s *Stack) Last() int {
    if len(s.items) == 0 {
        return 0
    }

    return s.items[len(s.items)-1]
}

func (s *Stack) Size()int{
    return len(s.items)
}


func dailyTemperatures(temperatures []int) []int {
    results := make([]int, len(temperatures))
    s := Stack{
        items: make([]int, 0),
    }

    for i := 0; i < len(temperatures); i++ {
        for s.Size() > 0 && temperatures[i] > temperatures[s.Last()] {
            idx := s.Last()
            results[idx] = i - idx
            s.Pop()
        }
        s.Push(i)
    }

    return results
}

