#### 定义
定理 2.8
设 $A \in C^{n \times n}$ 可逆，$B \in C^{n \times n}$，且对 $C^{n \times n}$ 上的某种矩阵范数 $\Vert \cdot \Vert$，有 $\Vert A^{-1}B \Vert < 1$，有以下结论：
1. $A + B$ 可逆；
2. 记 $F = I - (I + A^{-1}B)^{-1}$，则 $\Vert F \Vert \leq \frac{\Vert A^{-1}B \Vert}{1 - \Vert A^{-1}B \Vert}$；
3. $\frac{\Vert A^{-1} - (A + B)^{-1} \Vert}{\Vert A^{-1} \Vert} \leq \frac{\Vert A^{-1}B \Vert}{1 - \Vert A^{-1}B \Vert}$

条件数
在定理 2.8 中，若令 $cond(A) = \Vert A \Vert \ \Vert A^{-1} \Vert$，$d_A = \Vert \delta A \Vert \ \Vert A\Vert^{-1}$，则当 $\Vert A^{-1} \Vert \ \Vert \delta A \Vert < 1$ 时，由结论 (2) 和 (3) 可得 $$\Vert I - (I + A^{-1}\delta A)^{-1} \Vert \leq \frac{d_Acond(A)}{1 - d_Acond(A)}$$ $$\frac{\Vert A^{-1} - (A + \delta A)^{-1} \Vert}{\Vert A^{-1} \Vert} \leq \frac{d_Acond(A)}{1 - d_Acond(A)}$$
称 $cond(A)$ 为矩阵 $A$ 的 $条件数$，它是求矩阵逆的摄动的一个重要量。一般来说，条件数越大，$(A + \delta A)^{-1}$ 与 $A^{-1}$ 的相对误差就愈大

2.5
设 $A \in C^{n \times n}$ 的 $n$ 个特征值为 $\lambda_1, \lambda_2, \dots, \lambda_n$，称 $$\rho(A) = max_i |\lambda_i|$$ 为 $A$ 的 $谱半径$

#### 定理
2.9
设 $A \in C^{n \times n}$，则对 $C^{n \times n}$ 上任何一种矩阵范数 $\Vert \cdot \Vert$，都有 $$\rho(A) \leq \Vert A \Vert$$

2.10
设 $A \in C^{n \times n}$，对任意的正数 $\varepsilon$，存在某种矩阵范数 $\Vert \cdot \Vert_M$，使得 $$\Vert A \Vert_M \leq \rho(A) + \varepsilon$$

#### 例题
2.10
$$\because det(\lambda I - A) = (\lambda - 1)^2 - 5 $$ $$\therefore\lambda_1(A) = 1 + \sqrt{5}, \ \ \lambda_2(A) = 1 - \sqrt{5}$$ 从而 $$\rho(A) = 1 + \sqrt{5} $$ 又 $$\Vert A \Vert_1 = \Vert A \Vert_{\infty} = 3 + \sqrt{2}$$ 而 $$A^HA = \begin{bmatrix}
    6 & 5 + 5j \\
    5 - 5j & 11
\end{bmatrix}, \ \ det(\lambda I - A^HA) = \lambda^2 - 17\lambda + 16$$ 
由此得 $\lambda_1(A^HA) = 16, \ \ \lambda_2(A^HA) = 1$，则有 $$\Vert A \Vert_2 = \sqrt{\lambda_1(A^HA)} = 4$$ 易见 $$\rho(A) < \Vert A \Vert_1, \ \ \rho(A) < \Vert A \Vert_2, \ \ \rho(A) < \Vert A \Vert_{\infty}$$