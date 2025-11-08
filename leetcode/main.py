class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # find row

        u,l=0,len(matrix) -1 
        while u <= l:
            r = (u+l)//2
            if matrix[r][-1] < target:
                u = r + 1
            if matrix[r][0] > target:
                l = r - 1
            else:
                break

        if not (u <= l):
            return False
        row = ( u+l ) // 2
        l,r=0,len(matrix[0])-1
        while l<=r:
            m = (l+r) // 2
            if target > matrix[row][m]:
                l = m+1
            elif target < matrix[row][m]:
                r = m - 1
            else:
                return True
            
        return False
