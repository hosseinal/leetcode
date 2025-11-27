type MinStack struct {
    stack []int
    min   []int
    first bool
}

func Constructor() MinStack {
    return MinStack {
        stack : make([]int,0),
        min : make([]int,0),
        first : true,
    }
}

func (this *MinStack) Push(val int) {

    this.stack = append(this.stack, val)

    if len(this.min) == 0 || val <= this.min[len(this.min)-1] {
        this.min = append(this.min, val)
    }
}

func (this *MinStack) Pop() {

     if len(this.stack) == 0 {
        return // or panic, depending on the problem spec
    }

    temp := this.stack[len(this.stack)-1]
    this.stack = this.stack[:len(this.stack)-1]

    if temp == this.min[len(this.min)-1]{
        this.min = this.min[:len(this.min)-1]
    }

}

func (this *MinStack) Top() int {

    return this.stack[len(this.stack) -1]
}

func (this *MinStack) GetMin() int {
    return this.min[len(this.min)-1]
}

