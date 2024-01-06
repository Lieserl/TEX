import numpy as np

def svd_decomposition(A):
    # 计算 A^T * A 和 A * A^T
    ATA = np.dot(A.T, A)
    AAT = np.dot(A, A.T)

    # 计算特征值和特征向量
    eig_vals_ATA, eig_vecs_ATA = np.linalg.eig(ATA)
    eig_vals_AAT, eig_vecs_AAT = np.linalg.eig(AAT)

    # 对特征值进行排序并计算奇异值
    singular_values = np.sqrt(np.sort(eig_vals_ATA)[::-1])

    # 对应的特征向量是奇异向量
    U = eig_vecs_AAT
    VT = eig_vecs_ATA.T

    # 构造对角矩阵 Sigma
    Sigma = np.zeros(A.shape)
    np.fill_diagonal(Sigma, singular_values)

    return U, Sigma, VT

