class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        temp = []
        for i in range(len(matrix)):
            x=[]
            for j in range(len(matrix[i])):
                x.append(matrix[j][i])
            x = x[::-1]
            # print(x)
            temp.append(x)
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = temp[i][j]
        
        