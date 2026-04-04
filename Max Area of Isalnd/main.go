type point struct {
	i int
	j int
}

func dfs(grid [][]int, visited [][]int, i, j int) int {
	n := len(grid)
	m := len(grid[0])

	counter := 1
	arr := make([]point, 0)
	arr = append(arr, point{i: i, j: j})
	visited[i][j] = 1

	for len(arr) != 0 {
		item := arr[0]
		arr = arr[1:]

		x := item.i
		y := item.j

		if x-1 >= 0 && grid[x-1][y] == 1 && visited[x-1][y] == 0 {
			visited[x-1][y] = 1
			counter++
			arr = append(arr, point{i: x - 1, j: y})
		}

		if x+1 < n && grid[x+1][y] == 1 && visited[x+1][y] == 0 {
			visited[x+1][y] = 1
			counter++
			arr = append(arr, point{i: x + 1, j: y})
		}

		if y-1 >= 0 && grid[x][y-1] == 1 && visited[x][y-1] == 0 {
			visited[x][y-1] = 1
			counter++
			arr = append(arr, point{i: x, j: y - 1})
		}

		if y+1 < m && grid[x][y+1] == 1 && visited[x][y+1] == 0 {
			visited[x][y+1] = 1
			counter++
			arr = append(arr, point{i: x, j: y + 1})
		}
	}

	return counter
}

func maxAreaOfIsland(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])

	visited := make([][]int, n)
	for i := 0; i < n; i++ {
		visited[i] = make([]int, m)
	}

	max := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 && visited[i][j] == 0 {
				val := dfs(grid, visited, i, j)
				if val > max {
					max = val
				}
			}
		}
	}

	return max
}

