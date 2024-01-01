### 定义 

#### 4.1

如果方阵 $A$ 可分解成一个下三角矩阵 $L$ 和一个上三角矩阵 $U$ 的乘积 ，则称 $A$ 可作$三角分解$或 $LU(LR)分解$. 如果方阵 $A$ 可分解成 $A = LDU$ ，其中 $L$ 是单位下三角矩阵，$D$ 是对角矩阵，$U$ 是单位上三角矩阵，则称 $A$ 可作 $LDU分解$.

#### 4.2
设矩阵 $A$ 有唯一的 $LDU$ 分解.若把 $A = LDU$ 中的 $D$ 与 $U$ 结合起来，并且用 $\hat U$ 来表示，就得到唯一的分解为
$$A = L(DU)= L \hat U$$
称为 $A$ 的 $Doolittle分解$; 若把 $A = LDU$ 中的 $L$ 与 $D$ 结合起来，并且用 $\hat L$ 来表示，就得到唯一的分解为
$$A = (LD)U = \hat L U$$
称为 $A$ 的 $Crout分解$.

#### 4.3
称 $A = L\widetilde{D}^2L^T = (L\widetilde{D})(L\widetilde{D})^T = GG^T$ 为实对称正定矩阵的 $Cholesky分解$(平方根分解、对称三角分解).

### 例题

#### 4.1
因为 $\Delta_1 = 2, \ \Delta_2 = 5$，所以 $A$ 有唯一的 $LDU$ 分解. 构造矩阵 $$L_1 = \begin{bmatrix}
    1 & & \\ \frac{1}{2} & 1 & \\ 1 & 0 & 1
\end{bmatrix}, \quad L_1^{-1} = \begin{bmatrix}
    1 & & \\ -\frac{1}{2} & 1 & \\ -1 & 0 & 1
\end{bmatrix}$$
计算，得 $$L_1^{-1}A^{(0)} = \begin{bmatrix}
    2 & -1 & 3 \\ 0 & \frac{5}{2} & -\frac{1}{2} \\ 0 & 5 & -1
\end{bmatrix} = A^{(1)}$$
对 $A^{(1)}$ 构造矩阵，有 $$L_2 = \begin{bmatrix}
    1 & & \\ 0 & 1 & \\ 0 & 2 & 1
\end{bmatrix}, \quad L_2^{-1} = \begin{bmatrix}
    1 & & \\ 0 & 1 & \\ 0 & -2 & 1
\end{bmatrix}$$
计算，得 $$L_2^{-1}A^{(1)} = \begin{bmatrix}
    2 & -1 & 3 \\ 0 & \frac{5}{2} & -\frac{1}{2} \\ 0 & 0 & 0
\end{bmatrix} = \begin{bmatrix}
    2 & 0 & 0 \\ 0 & \frac{5}{2} & 0 \\ 0 & 0 & 0
\end{bmatrix}\begin{bmatrix}
    1 & -\frac{1}{2} & \frac{3}{2} \\ 0 & 1 & -\frac{1}{5} \\ 0 & 0 & 1
\end{bmatrix} = A^{(2)}$$
$$L = L_1L_2 = \begin{bmatrix}
    1 & & \\ \frac{1}{2} & 1 & \\ 1 & 2 & 1
\end{bmatrix}$$
于是得 $A^{(0)} = A$ 的 $LDU$ 分解为
$$A = L_1L_2A^{(2)} = \begin{bmatrix}
    1 & 0 & 0 \\ \frac{1}{2} & 1 & 0 \\ 1 & 2 & 1
\end{bmatrix}\begin{bmatrix}
    2 & 0 & 0 \\ 0 & \frac{5}{2} & 0 \\ 0 & 0 & 0
\end{bmatrix}\begin{bmatrix}
    1 & -\frac{1}{2} & \frac{3}{2} \\ 0 & 1 & -\frac{1}{5} \\ 0 & 0 & 1
\end{bmatrix}$$

#### 4.2
容易验证 $A$ 是对称正定矩阵. 由 $$g_{ij} = \begin{cases}
    (a_{ii} - \sum_{k=1}^{i-1}g_{ik}^2)^{1/2} &\quad (i = j) \\ \frac{1}{g_{jj}}(a_{ij} - \sum_{k=1}^{j-1}h_{ik}g_{jk}) &\quad (i > j) \\ 0 &\quad (i < j)
\end{cases}$$
有 $$\begin{align*}
    g_{11} &= \sqrt{a_{11}} = \sqrt{5} \\ g_{21} &= \frac{a_{21}}{g_{11}} = -\frac{2}{\sqrt{5}}, \quad g_{22} = (a_{22} - g_{21}^2)^{1/2} = \frac{11}{5} \\ g_{31} &= \frac{a_{31}}{g_{11}} = 0, \quad g_{32} = \frac{a_{32} - g_{31}g_{21}}{g_{22}} = -\sqrt{\frac{5}{11}} \\ g_{33} &= (a_{33} - g_{31}^2 - g_{32}^2)^{1/2} = (1 - \frac{5}{11})^{1/2} = \sqrt{\frac{6}{11}}
\end{align*}$$
从而 $$A = \begin{bmatrix}
    \sqrt{5} & 0 & 0 \\ -\frac{2}{\sqrt{5}} & \sqrt{\frac{11}{5}} & 0 \\ 0 & -\sqrt{\frac{5}{11}} & \sqrt{\frac{6}{11}}
\end{bmatrix}\begin{bmatrix}
    \sqrt{5} & -\frac{2}{\sqrt{5}} & 0 \\ 0 & \sqrt{\frac{11}{5}} & -\sqrt{\frac{5}{11}} \\ 0 & 0 & \sqrt{\frac{6}{11}}
\end{bmatrix}$$

### 习题

#### 4.1.1
对 $A$ 构造矩阵 $$L_1 = \begin{bmatrix}
    1 & & & \\ frac{2}{5} & 1 & & \\ -frac{4}{5} & 0 & 1 & \\ 0 & 0 & 0 & 1
\end{bmatrix}, \quad L_1^{-1} = \begin{bmatrix}
    1 & & & \\ -\frac{3}{5} & 1 &  & \\ \frac{4}{5} & 0 & 1 & \\ 0 & 0 & 0 & 1
\end{bmatrix}$$
计算，得 $$L_1^{-1}A = \begin{bmatrix}
    5 & 2 & -4 & 0 \\ 0 & \frac{1}{5} & -\frac{2}{5} & 1 \\ 0 & -\frac{2}{5} & \frac{4}{5} & 0 \\ 0 & 1 & 0 & 2
\end{bmatrix} = A^{(1)}$$
对 $A^{(1)}$ 构造矩阵 $$L_2 = \begin{bmatrix}
    1 & & & \\ 0 & 1 & & \\ 0 & -2 & 1 & \\ 0 & 5 & 0 & 1
\end{bmatrix}, \quad L_2^{-1} = \begin{bmatrix}
    1 & & & \\ 0 & 1 & & \\ 0 & 2 & 1 & \\ 0 & -5 & 0 & 1
\end{bmatrix}$$
计算，得 $$L_2^{-1}A^{(1)} = \begin{bmatrix}
    5 & 2 & -4 & 0 \\ 0 & \frac{1}{5} & - \frac{2}{5} & 1 \\ 0 & 0 & 1 & 2 \\ 0 & 0 & 2 & -3
\end{bmatrix} = A^{(2)}$$
对 $A^{(2)}$ 构造矩阵 $$L_3 = \begin{bmatrix}
    1 & & & \\ 0 & 1 & & \\ 0 & 0 & 1 & \\ 0 & 0 & 2 & 1
\end{bmatrix}, \quad L_3^{-1} = \begin{bmatrix}
    1 & & & \\ 0 & 1 & & \\ 0 & 0 & 1 & \\ 0 & 0 & -2 & 1
\end{bmatrix}$$
计算，得 $$L_3^{-1}A^{(2)} = \begin{bmatrix}
    5 & 2 & -4 & 0 \\ & \frac{1}{5} & -\frac{2}{5} & 1 \\ & & 1 & 2 \\ & & & -7
\end{bmatrix} = A^{(3)}$$
令 $L = L_1L_2L_3 = \begin{bmatrix}
    1 & & & \\ \frac{2}{5} & 1 & & \\ -\frac{4}{5} & -2 & 1 & \\ 0 & 5 & 2 & 1
\end{bmatrix}$，可得 $A$ 的 $Doolittle$ 分解为 $A = LA^{(3)}$，$LDU$ 分解为 $$A = \begin{bmatrix}
    1 & \frac{2}{5} & -\frac{4}{5} & 0 \\ & 1 & -2 & 5 \\ & & 1 & -2 \\ & & & 1
\end{bmatrix}$$

#### 4.1.4
可求得 $A$ 的 $Crout$ 分解为 $$A = \begin{bmatrix}
    5 & & \\ 2 & \frac{1}{5} & \\ -4 & -\frac{2}{5} & 1
\end{bmatrix}\begin{bmatrix}
    1 & \frac{2}{5} & -\frac{4}{5} \\ & 1 & -2 \\ & & 1
\end{bmatrix}$$
$A$ 的 $cholesky$ 分解为 $$A = \begin{bmatrix}
    1 & & \\ \frac{2}{5} & 1 & \\ -\frac{4}{5} & -2 & 1
\end{bmatrix}\begin{bmatrix}
    5 & & \\ & \frac{1}{5} & \\ & & 1
\end{bmatrix}\begin{bmatrix}
    1 & \frac{2}{5} & -\frac{4}{5} \\ & 1 & -2 \\ & & 1
\end{bmatrix} = \begin{bmatrix}
    \sqrt{5} & & \\ \frac{2}{\sqrt{5}} & \frac{1}{\sqrt{5}} & \\ -\frac{4}{\sqrt{5}} & -\frac{2}{\sqrt{5}} & 1
\end{bmatrix}$$