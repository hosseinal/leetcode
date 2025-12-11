
func iterate(grid [][]byte, visited [][]bool,i int,j int,rows int, cols int){
    visited[i][j] = true
    if i - 1 >= 0 && !visited[i-1][j] && grid[i-1][j] == '1' {
        iterate(grid,visited,i-1,j,rows,cols)
    } 

    if j - 1 >= 0 && !visited[i][j-1] && grid[i][j-1] == '1'{
        iterate(grid,visited,i,j-1,rows,cols)
    }

    if i + 1 < rows && !visited[i+1][j] && grid[i+1][j] == '1'{ 
        iterate(grid,visited,i+1,j,rows,cols)
    }

    if j + 1 < cols && !visited[i][j+1] && grid[i][j + 1] == '1'{
        iterate(grid,visited,i,j+1,rows,cols)
    }
}

func numIslands(grid [][]byte) int {
    rows := len(grid)
    cols := len(grid[0])
    visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}

    counter := 0

    for i := 0; i < rows ; i++ {
        for j := 0 ; j < cols ; j++ {
            if (!visited[i][j] && grid[i][j] == '1'){
             iterate(grid,visited,i,j,rows,cols)
             counter++    
            }
        }
    }

    return counter
}

