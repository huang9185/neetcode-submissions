class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = []
        t,b = 0,len(matrix)-1
        m=0
        while t <= b:
            m = t+((b-t)//2)
            if matrix[m][0] > target:
                b = m-1
            elif matrix[m][0] < target:
                rows.append(m)
                t = m+1
            else:
                return True

        rows.sort(reverse=True)
        if not len(rows):
            return False
        row = rows[0]
        l,r = 0, len(matrix[row])-1
        i = 0
        while (l<= r):
            i = l+((r-l)//2)
            if matrix[row][i] < target:
                l = i+1
            elif matrix[row][i] > target:
                r = i-1
            else:
                return True
            
        return False