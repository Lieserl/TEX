### 定义
#### 3.1
>设有矩阵序列 $\{A^{(k)}\}$，其中 $A^{(k)} = (a_{ij}^{(k)})_{m \times n}$，当 $a_{ij}^{(k)} \rightarrow a_{ij}(k \rightarrow \infty)$ 时，称 $\{A^{(k)}\}$ 收敛，或称矩阵 $A = (a_{ij}^{(k)})_{m \times n}$ 为 $\{A^{(k)}\}$ 的极限，或称 $\{A^{(k)}\}$ 收敛于 $A$，记为 $$\lim_{k \rightarrow \infty}A^{(k)} = A 或 A^{(k)} \rightarrow A$$ 不收敛的矩阵序列称为发散
矩阵序列收敛的性质
>1. 设 $A^{(k)} \rightarrow A_{m \times n}, \ \ B^{(k)} \rightarrow B_{m \times n}$，则 $$\lim_{k \rightarrow \infty}(\alpha A^{(k)} + \beta B^{(k)}) = \alpha A + \beta B \ \ (\forall \alpha, \ \beta \in C) \tag{3.1.1}$$
>2. 设 $A^{(k)} \rightarrow A_{m \times n}, \ \ B^{(k)} \rightarrow B_{n \times l}$，则 $$\lim_{k \rightarrow \infty} A^{(k)}B^{(B)} = AB \tag{3.1.2}$$
>3. 设 $A^{(k)}$ 与 $A$ 都是可逆矩阵，且 $A^{(k)} \rightarrow A$，则 $$(A^{(k)})^{-1} \rightarrow A^{-1} \tag{3.1.3}$$

#### 3.2
>矩阵序列 $\{A^{(k)}\}$ 称为 $\textbf{有界}$ 的，如果存在常数 $M > 0$，使得对一切 $k$ 都有 $$|a_{ij}^{(k)}| < M \ \ (i = 1, 2, \dots, m; \ j = 1, 2, \dots, n)$$

#### 3.3
>设 $A$ 为方阵，且 $A^k \rightarrow O \ (k \rightarrow \infty)$，则称 $A$ 为收敛矩阵

#### 3.4 
>把定义 3.1 中的矩阵序列所形成的无穷和 $A^{(0)} + A^{(1)} + A^{(2)} + \dots + A^{(k)} + \dots$ 称为 $\textbf{矩阵级数}$，记为 $\sum_{k=0}^{\infty}A^{(k)}$，则有 $$\sum_{k=0}^{\infty}A^{(k)} = A^{(0)} + A^{(1)} + A^{(2)} + \dots + A^{(k)} + \dots \tag{3.2.1}$$

#### 3.5
>记 $S^{(N)} = \sum_{k=0}^{N}A^{(k)}$，称其为矩阵级数式 (3.2.1) 的 $\textbf{部分和}$. 如果矩阵序列 $\{S^{(N)}\}$ 收敛，且有极限 $S$，则有 $$\lim_{N \rightarrow \infty}S^{(N)} = S$$ 那么就称矩阵级数式 (3.2.1) 收敛，而且有和 $S$，记为 $$S = \sum_{k=0}^{\infty}A^{(k)}$$ 不收敛的矩阵级数称为是 $\textbf{发散}$ 的
若用 $s_{ij}$ 表示 $S$ 的第 $i$ 行第 $j$ 列的元素，那么，和 $\sum_{k=0}^{\infty}A^{(k)} = S$ 的意义指的是 $$\sum_{k=0}^{\infty}a_{ij}^{(k)} = s_{ij} \ \ (i = 1, 2, \dots, m; \ j = 1, 2, \dots, n) \tag{3.2.4}$$

#### 3.6
>如果式 (3.2.4) 中左端 $mn$ 个数项级数都是绝对收敛的，则称矩阵级数式 (3.2.1) 是 $\textbf{绝对收敛}$ 的

### 定理

#### 3.1 
>设 $A^{(k)} \in C^{m \times n}$，则
> 1. $A^{(k)} \rightarrow O$ 的充要条件是 $\Vert A^{(k)} \Vert \rightarrow 0$；
> 2. $A^{(k)} \rightarrow A$ 的充要条件是 $\Vert A^{(k)} - A \Vert \rightarrow 0$
>
>这里，$\Vert \cdot \Vert$ 是 $C^{m \times n}$ 上的任何一种矩阵范数

#### 3.2
>$A$ 为收敛矩阵的充要条件是 $\rho(A) < 1$

#### 3.3
>$A$ 为收敛矩阵的充分条件是只要有一种矩阵范数 $\Vert \cdot \Vert$，使得 $\Vert A \Vert < 1$

#### 3.5
>设方阵 $A$ 对某一矩阵范数 $\Vert \cdot \Vert$ 有 $\Vert A \Vert < 1$，则对任何非负整数 $N$，以 $(I - A)^{-1}$ 为部分和 $I + A + A^2 + \dots + A^N$ 的近似矩阵时，其误差为 $$\Vert (I - A)^{-1} - (I + A + A^2 + \dots + A^N) \Vert \leq \frac{\Vert A \Vert^{N + 1}}{1 - \Vert A \Vert}$$

#### 3.6
>设幂级数 $$f(z) = \sum_{k=0}^{\infty}c_kz^k \tag{3.2.10}$$ 的收敛半径为 $r$，如果方阵 $A$ 满足 $\rho(A) < r$，则矩阵幂级数 $$\sum_{k=0}^{\infty}c_kA^k \tag{3.2.11}$$ 时绝对收敛的；如果 $\rho(A) > r$，则矩阵幂级数式 (3.2.11) 是发散的

### 例题

#### 3.1
>$$\because \Vert A \Vert_1 = max_j\sum_{i=1}^{m}|a_{ij}| = 0.9 < 1$$ $$\therefore 由定理3.1, \ \ A \ 是收敛矩阵$$

#### 3.2
>$$\because S^{(N)} = \sum_{k=1}^{N}A^{(k)} = \begin{bmatrix}
    \sum_{k=1}^{N}\frac{1}{2^k} & \sum_{k=1}^{N}\frac{\pi}{3 \times 4^k} \\ 0 & \sum_{k=1}^{N}\frac{1}{k(k+1)}
 \end{bmatrix} = \begin{bmatrix}
    1-(\frac{1}{2})^N & \frac{\pi}{9}[1 - (\frac{1}{4})^N] \\ 0 & \frac{N}{N + 1}
 \end{bmatrix}$$ 
 $$\therefore S = \lim_{N \rightarrow \infty}S^{(N)} = \begin{bmatrix}
    1 & \frac{\pi}{9} \\ 0 & 1
 \end{bmatrix}$$

 ### 习题

#### 3.1.2  
>$$\because det(\lambda I - A) = (a-2c)(a+c)^2$$ $$\therefore\rho(A) = 2|c|$$ 
由定理 3.2，当且仅当 $$\rho(A) < 1, \ \ \ 2|c| < 1, \ \ \ |c| < \frac{1}{2}$$ 有 $A$ 是收敛矩阵

#### 3.2.1
>$$\because \rho(A) = 1$$ $$\therefore 由定理 3.2 \ \ \ 矩阵级数\sum_{l=0}^{\infty}A^{(k)} 发散$$

#### 3.2.3
>(1)
令 $A = \begin{bmatrix} 1 & 7 \\ -1 & -3 \end{bmatrix}$，易知其特征值为 $\lambda_1 = \lambda_2 = -2$，故 $\rho(A) = 2$
又，幂级数 $\sum_{k=1}^{\infty}\frac{1}{k^2}x^k$ 的收敛半径为 $$r = \lim_{k\rightarrow \infty}|\frac{a_{k}}{a_{k+1}}| = 1$$
有 $\rho(A) = 2 > r$，由定理 3.6 该矩阵幂级数发散

>(2)
令 $A = \begin{bmatrix} 1 & -8 \\ -2 & 1 \end{bmatrix}$，易知其特征值为 $\lambda_1 = -3, \ \lambda_2 = 5$，故 $\rho(A) = 5$
又，幂级数 $\sum_{k=0}^{\infty}\frac{1}{6^k}x^k$ 的收敛半径为 $$r = \lim_{k\rightarrow \infty}|\frac{a_{k}}{a_{k+1}}| = 6$$
有 $\rho(A) = 2 < r$，由定理 3.6 该矩阵幂级数绝对收敛

#### 3.2.4
>$$\because S^{(N)} = \sum_{k=0}^{N}A^{(k)}, \ \ 矩阵级数\sum_{k=0}^{N}A^{(k)} 收敛$$ $$\therefore \lim_{N \rightarrow \infty}S^{(N)} = C$$ $$\therefore \lim_{N \rightarrow \infty }A^{(N)}= \lim_{N \rightarrow \infty}(S^{(N)} - S^{(N-1)}) = S - S = O$$ $$\therefore \lim_{k \rightarrow \infty}A^{(k)} = O$$
