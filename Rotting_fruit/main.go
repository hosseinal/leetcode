type cell struct {
	row int
	col int
}

func orangesRotting(grid [][]int) int {
    var q []cell
	Row := len(grid)
	Col := len(grid[0])

	for i := 0 ; i < len(grid) ; i++{
		for j := 0; j < len(grid[0]); j++{
			if grid[i][j] == 2 {
				q = append(q,cell{i,j})
			}
		}
	}

	min := 0
	directions := [][]int{{0,-1}, {0,1}, {1,0},{-1,0}}

	for len(q) != 0 {

		size := len(q)

		for _ = range(size){

		
		// logic
		p := q[0]
		q[0]= cell{}
		q = q[1:]
		var found bool
		for i := 0; i < 4; i++ {
			r := p.row + directions[i][0]
			c := p.col + directions[i][1]
			if r >= 0 && r < Row && c < Col && c >= 0 && grid[r][c] != 0 && grid[r][c] != 2{
				grid[r][c] = 2
				q = append(q, cell{r,c})
				found
			}
		  }
		} 
		// increase in the min
		min = min + 1
	}

	for i := 0 ; i < len(grid) ; i++{
		for j := 0; j < len(grid[0]); j++{
			if grid[i][j] == 1 {
				return -1
			}
		}
	}

	return min
}

