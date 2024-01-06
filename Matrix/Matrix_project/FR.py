import numpy as np

def full_rank_decomposition(A):
    # 计算矩阵A的秩
    rank = np.linalg.matrix_rank(A)

    U, S, VT = svd_decomposition(A)

    # 构造满秩矩阵F和G
    F = U[:, :rank] @ np.diag(S[:rank])
    G = Vt[:rank, :]

    return F, G
