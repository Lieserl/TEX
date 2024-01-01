### 定义

#### 4.11
设 $A \in C_r^{m \times n}(r > 0)$，$A^HA$ 的特征值为 $$\lambda_1 \geq \lambda_2 \geq \dots \geq \lambda_r \ > \lambda_{r+1} = \dots = \lambda_n = 0$$ 则称 $\sigma_i = \sqrt{\lambda_i}(i = 1, \ 2, \ \dots, \ n)$ 为 $A$ 的 奇异值. 当 $A$ 为零矩阵时，它的奇异值都是 $0$.

### 定理 

#### 4.15
设 $A \in R^{n \times n}$ 可逆，则存在正交矩阵 $P$ 和 $Q$，使得 $$P^TAQ = diag(\sigma_1, \ \sigma_2, \ \dots, \ \sigma_n)$$ 其中 $\sigma_i > 0 \ (i = 1, \ 2, \ \dots, \ n)$

#### 4.16
设 $A \in C_r^{m \times n} \ (r > 0)$，则存在 $m$ 阶酉矩阵 $U$ 和 $n$ 阶酉矩阵 $V$，使得 $$U^HAV = \begin{bmatrix}
    \varSigma & O \\ O & O
\end{bmatrix}$$ 其中 $\varSigma = diag(\sigma_1, \ \sigma_2, \ \dots, \ \sigma_r)$，而 $\sigma_i(i = 1, \ 2, \ \dots, \ r)$ 为矩阵 $A$ 的全部非零奇异值.

### 例题

#### 4.14
计算 $$B = A^TA = \begin{bmatrix}
    1 & 0 & 1 \\ 0 & 1 & 1 \\ 1 & 1 & 2
\end{bmatrix}$$ 求得 $B$ 的特征值为 $\lambda_1 = 3, \ \lambda_2 = 1, \ \lambda_3 = 0$，对应的特征向量依次为 $$\xi_1 = \begin{bmatrix}
    1 \\ 1 \\ 2
\end{bmatrix}, \quad \xi_2 = \begin{bmatrix}
    1 \\ -1 \\ 0
\end{bmatrix}, \quad \xi_3 = \begin{bmatrix}
    1 \\ 1 \\ -1
\end{bmatrix}$$ 于是可得 $$rankA = 2, \quad \varSigma = \begin{bmatrix}
    \sqrt{3} & 0 \\ 0 & 1
\end{bmatrix}$$ 且使得定理4.16 中式成立的正交矩阵为 $$V = \begin{bmatrix}
\frac{1}{\sqrt{6}} & \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{3}} \\ \frac{1}{\sqrt{6}} & -\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{3}} \\ \frac{2}{\sqrt{6}} & 0 & -\frac{1}{\sqrt{3}}
\end{bmatrix}$$ 计算 $$U_1 = AV_1\varSigma^{-1} = \begin{bmatrix}
    \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}} \\ 0 & 0
\end{bmatrix}$$ 构造 $$U_2 = \begin{bmatrix}
    0 \\ 0 \\ 1
\end{bmatrix}, \quad U = \begin{bmatrix}
    U_1 | U_2
\end{bmatrix} = \begin{bmatrix}
    \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} & 0 \\ \frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}} & 0 \\ 0 & 0 & 1
\end{bmatrix}$$ 则 $A$ 的奇异值分解为 $$A = U\begin{bmatrix}
    \sqrt{3} & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 0
\end{bmatrix}V^T$$

#### 4.15
根据定理 4.16 中式可以求得 $$AA^H = U \begin{bmatrix}
    \varSigma^2 & O \\ O & O
\end{bmatrix}U^H$$ 即 $$(AA^H)U = U \cdot diag(\lambda_1, \ \lambda_2, \ \dots, \ \lambda_r, \ , \ 0, \ \dots, \ 0)$$ 记 $U = (u_1, \ u_2, \ \dots, \ u_m)$，则上式可写为 $$(AA^H)u_i = \lambda_iu_i \quad (i = 1, \ 2, \ \dots, \ m)$$ 这表明 $u_i$ 是 $AA^H$ 的属于特征值 $\lambda_i$ 的特征向量(当 $i > r$ 时，$\lambda_i = 0$). 同理可证另一结论.

### 习题

#### 4.4.2
设 $A \in R_r^{m \times n}$ 的奇异值分解为 $$A = UDV^T, \quad D = \begin{bmatrix}
    \varSigma & O \\ O & O
\end{bmatrix}$$ 其中，$U$ 是 $m$ 阶正交矩阵，$V$ 是 $n$ 阶正交矩阵，$\varSigma = diag(\sigma_1, \ \sigma_2, \ \dots, \ \sigma_r)$. 于是 $Ax = 0$ 可写为 $UDV^T x = 0$，即 $DV^Tx = 0$，令 $V^Tx = y$，则有 $Dy = 0$，故通解为 $$y = k_1e_{r+1} + \dots + k_{n-r}e_n \quad (k_1, \ \dots, \ k_{n-r} \in R)$$ 设 $V$ 的第 $j$ 个列向量为 $v_j(j = 1, \ 2, \ \dots, \ n)$，则 $$x = Vy = k_1v_{r+1} + \dots + k_{n-r}v_n \quad (k_1, \ \dots, \ k_{n-r} \in R)$$

#### 4.4.4
$A^TA = \begin{bmatrix}
    2 & 1 \\ 1 & 2
\end{bmatrix}$ 的特征值是 $\lambda_1 = 3, \ \lambda_2 = 1$，对应的特征向量依次为 $$\xi_1 = \begin{bmatrix}
    1 \\ 1
\end{bmatrix}, \quad \xi_2 = \begin{bmatrix}
    -1 \\ 1
\end{bmatrix}$$ 于是可得 $$rankA = 2, \quad \varSigma = \begin{bmatrix}
    \sqrt{3} & 0 \\ 0 & 1
\end{bmatrix}, \quad V = \begin{bmatrix}
    \frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}}
\end{bmatrix}$$ 此时 $V_1 = V$，计算 $$U_1 = AV_1\varSigma^{-1} = \begin{bmatrix}
    \frac{1}{\sqrt{6}} & -\frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{6}} & \frac{1}{\sqrt{2}} \\ \frac{2}{\sqrt{6}} & 0
\end{bmatrix}$$ 构造 $$U_2 = \begin{bmatrix}
    -\frac{1}{\sqrt{3}} \\ -\frac{1}{\sqrt{3}} \\ \frac{1}{\sqrt{3}}
\end{bmatrix}, \quad U = \begin{bmatrix}
    U_1 | U_2
\end{bmatrix} = \begin{bmatrix}
    \frac{1}{\sqrt{6}} & -\frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{3}} \\ \frac{1}{\sqrt{6}} & \frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{3}} \\ \frac{2}{\sqrt{6}} & 0 & \frac{1}{\sqrt{3}}
\end{bmatrix}$$ 则 $A$ 的奇异值分解为 $$A = U\begin{bmatrix}
    \sqrt{3} & 0 \\ 0 & 1 \\ 0 & 0
\end{bmatrix}V^T$$