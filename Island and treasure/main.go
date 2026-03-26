type Pair struct {
    row int
    col int
}


func islandsAndTreasure(grid [][]int) {

    var q []Pair
    a_rows := len(grid)
    b_rows := len(grid[0])

    for rowIdx, row := range(grid){
        for colIdx, colElement := range(row){
            if colElement == 0 {
               q = append(q ,Pair{rowIdx,colIdx}) 
            }
        }

        
    }


    directions := [][]int{{-1,0}, {0,-1}, {1,0}, {0,1}}

    for len(q) > 0 {
        node := q[0]
        q = q[1:]
        row, col := node.row,node.col

        for _, dir := range directions {
            r, c := row+dir[0], col+dir[1]

            if r >= a_rows || c >= b_rows || r < 0 ||c < 0 || grid[r][c] != 2147483647 {
                continue
            }
        
            q = append(q,Pair{r,c})
            grid[r][c] = grid[row][col]+1
        }
    }


    
}

