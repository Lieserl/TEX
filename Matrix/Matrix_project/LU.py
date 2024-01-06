import numpy as np

def lu_decomposition(A):
    n = len(A) # 获取矩阵的维数，即行数（假设矩阵是方阵）

    # 初始化下三角矩阵L和上三角矩阵U为零矩阵
    L = np.zeros((n, n))
    U = np.zeros((n, n))

    # 遍历矩阵的每一行
    for i in range(n):
        # 计算上三角矩阵U的元素
        for k in range(i, n):
            sum = 0  # 初始化求和变量，用于计算U矩阵的元素
            for j in range(i):
                sum += (L[i][j] * U[j][k])
            U[i][k] = A[i][k] - sum  # 更新U矩阵的元素

        # 计算下三角矩阵L的元素
        for k in range(i, n):
            if i == k:
                L[i][i] = 1 # 对角线上的元素设置为1
            else:
                sum = 0 # 初始化求和变量，用于计算L矩阵的元素
                for j in range(i):
                    sum += (L[k][j] * U[j][i])
                L[k][i] = (A[k][i] - sum) / U[i][i] # 更新L矩阵的元素

    return L, U
