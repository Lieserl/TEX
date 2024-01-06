import numpy as np

# 对矩阵A进行Gram-Schmidt正交化处理。
def gram_schmidt(A):
    n, m = A.shape
    Q = np.zeros((n, m))

    for j in range(m):
        q = A[:, j]
        # 从Q中已计算的列中减去在这些列上的投影，确保正交性
        for i in range(j):
            q = q - np.dot(Q[:, i], A[:, j]) * Q[:, i]
        q = q / np.linalg.norm(q)  # 归一化向量
        Q[:, j] = q

    return Q

# 对矩阵A进行QR分解。
def qr_decomposition(A):

    Q = gram_schmidt(A)
    R = np.dot(Q.T, A)
    return Q, R