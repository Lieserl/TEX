定义 2.1
> 如果 $V$ 是数域 $k$ 上的线性空间，对任意的 $x > \in V$，定义一个实值函数 $\Vert x \Vert$，它满足以下三个条件：
> 1. 非负性：当 $x \ne 0$ 时，$\Vert x\Vert > 0$；当 $x = 0$ 时，$\Vert x\Vert = 0$；
> 2. 齐次性：$\Vert x \Vert = |a| \ \Vert x\Vert$ $(a \in K, x \in V)$
> 3. 三角不等式：$\Vert x + y \Vert \leq \Vert x \Vert + \Vert y \Vert$ $(x, y \in V)$
> 
>则称 $\Vert x \Vert$ 为 $V$ 上向量 $x$ 的范数，简称 $\textbf{向量范数}$

定理 2.1
>设 $\Vert x\Vert_{\alpha}$ 和 $\Vert x\Vert_{\beta}$ 为有限维线性空间 $V$ 上的任意两种向量范数（他们不限于 $p$ - 范数），则存在两个与向量 $x$ 无关的正常数 $c_1$ 和 $c_2$，使满足 $$c_1\Vert x\Vert_{\beta} \leq \Vert x\Vert_{\alpha} \leq c_2\Vert x\Vert_{\beta} \ (\forall x \in V) \tag{2.1.9}$$

定义 2.2
满足不等式 $(2.1.9)$ 的两种范数称为是 $\textbf{等价}$ 的，于是定理 2.1 可述为：有限维线性空间上的不同范数是等价的

定理 2.2
>$C^n$ 中的向量序列 $$x^{(k)} = (\xi_1^{(k)},\xi_2^{(k)},\dots,\xi_n^{(k)}) \ (k = 1,2,3,\dots)$$ 收敛到向量 $x = (\xi_1,\xi_2,\dots,\xi_n)$ 的充要条件是对任何一种向量范数 $\Vert \cdot \Vert$，数列 ${\Vert x^{(k)}} - x \Vert$ 收敛于零

定义 2.3
> 设 $A \in C^{m\times n}$，定义一个实值函数 $\Vert A \Vert$，它满足以下三个条件
> 1. 非负性：当 $A \ne O$ 时，$\Vert A \Vert > 0$；当 $A = O$ 时，$\Vert A \Vert = 0$；
> 2. 齐次性：$\Vert \alpha A \Vert = |\alpha| \ \Vert A \Vert \ (\alpha \in C)$；
> 3. 三角不等式：$\Vert A + B \Vert \leq \Vert A \Vert + \Vert B \Vert \ (B \in C^{m\times n})$.
>
> 则称 $\Vert A \Vert$ 为 $A$ 的 $\textbf{广义矩阵范数}$. 若对 $C^{m \times n},C^{n \times l}$ 及 $C^{m \times l}$ 上的同类广义矩阵范数 $\Vert \cdot \Vert$，还满足下面一个条件
> $\space\space$ 4. 相容性：$\Vert AB \Vert \leq \Vert A \Vert \ \Vert B \Vert \ (B \in C^{m \times l})$ 
> 则称 $\Vert A \Vert$ 为 $A$ 的 $\textbf{矩阵范数}$
 
定义 2.4
> 对于 $C^{m \times n}$ 上的矩阵范数 $\Vert \cdot \Vert_M$ 和 $C^m$ 与 $C^n$ 上的同类向量范数 $\Vert \cdot \Vert_V$，如果 $$\Vert Ax \Vert_V \leq \Vert A \Vert_M \ \Vert x \Vert_V \ (\forall A \in C ^{m \times n}, \forall x \in C^n)$$
> 则称矩阵范数 $\Vert \cdot \Vert_M$ 与向量范数 $\Vert \cdot \Vert_V$ 是相容的

定理 2.4
> 已知 $C^m$ 和 $C^n$ 上的同类向量范数 $\Vert \cdot \Vert$，设 $A \in C^{m \times n}$，则函数 $$\Vert A \Vert = max_{\Vert x \Vert = 1} \Vert Ax \Vert$$ 是 $C^{m \times n}$ 上的矩阵范数，且与已知的向量范数相容

定理 2.5
> 设 $A = (a_{ij})_{m \times n} \in C^{m \times n}$，$x = (\xi_1,\xi_2, \dots,\xi_n)^T \in C^n$，则从属于向量 $x$ 的三种范数 $\Vert x \Vert_1,\Vert x \Vert_2, \Vert x \Vert_{\infty}$ 的矩阵范数计算公式依次为
> 1. $\Vert A \Vert_1 = max_j \sum_{i=1}^{m}|a_{ij}|$；
> 2. $\Vert A \Vert_2 = \sqrt{\lambda_1}$，$\lambda_1$ 为 $A^HA$ 的最大特征值；
> 3. $\Vert A \Vert_{\infty} = max_i \sum_{j=1}^{n}|a_{ij}|$.
>
> 通常称 $\Vert A \Vert_1,\Vert A \Vert_2$ 及 $\Vert A \Vert_{\infty}$ 依次为 $\textbf{列和范数、谱范数}$ 及 $\textbf{行和范数}$

例 2.1
>(1)
根据 $\Vert x\Vert = \sqrt{|\xi_1|^2 + |\xi_2|^2 + \dots + |\xi_n|^2}$，当 $x \ne 0$ 时，显然 $\Vert x \Vert > 0$；当 $x = 0$ 时，有 $\Vert x \Vert = \sqrt{0^2 + 0^2 + \dots + 0^2} = 0$

>(2)
对任意的复数 $a$，因为 $$ax = (a\xi_1, a\xi_2, \dots, a\xi_n)$$ 所以 $$\Vert ax\Vert = \sqrt{|a\xi_1|^2 + |a\xi_2|^2 + \dots + |a\xi_n|^2} = \\ |a| \ \sqrt{|\xi_1|^2 + |\xi_2|^2 + \dots + |\xi_n|^2} = |a| \ \Vert x\Vert$$

>(3)
对于任意两个复向量 $x = (\xi_1,\xi_2,\dots,\xi_n), \ \ y = (\eta_1, \eta_2,\dots,\eta_n)$，有 $$x + y = (\xi_1 + \eta_1,\xi_2 + \eta_2,\dots,\xi_n + \eta_n)$$
可得 $$\Vert x + y \Vert = \sqrt{|\xi_1 + \eta_1|^2 + |\xi_2 + \eta_2|^2 + \dots + |\xi_n + \eta_n|^2}$$ $$\Vert x \Vert = \sqrt{|\xi_1|^2 + |\xi_2|^2 + \dots + |\xi_n|^2}$$ $$\Vert y \Vert = \sqrt{|\eta_1|^2 + |\eta_2|^2 + \dots + |\eta_n|^2}$$
借助于 $C^n$ 中内积式(1.3.24)及其性质，可得 $$\Vert x + y \Vert^2 = (x + y, x + y) = (x, x) + 2Re(x, y) + (y, y)$$ 
因为 $$Re(x,y) \leq |(x,y)| \leq \sqrt{(x,x)(y,y)} = \Vert x \Vert \ \Vert y \Vert$$
所以 $$\Vert x + y \Vert^2 \leq \Vert x \Vert^2 + 2\Vert x \Vert \ \Vert y \Vert + \Vert y \Vert^2 = (\Vert x \Vert + \Vert y \Vert)^2$$
即 $$\Vert x + y \Vert \leq \Vert x \Vert + \Vert y \Vert$$

例 2.2
> 当 $x \ne 0$ 时，有 $\Vert x \Vert = max_i|\xi_i| > 0$；当 $x = 0$ 时，显然有 $\Vert x \Vert = 0$. 又对任意的 $a \in C$，有 $$\Vert ax\Vert = max_i|a\xi_i| = |a| \ max_i \ |\xi_i| = |a| \ \Vert x \Vert$$
> 对 $C^n$ 的任意两个向量 $x = (\xi_1, \xi_2, \dots, \xi_n), \ \ y = (\eta_1, \eta_2, \dots, \eta_n)$，有 $$\Vert x + y \Vert = max_i \ |\xi_i + \eta_i| \leq max_i \ |\xi_i| + max_i \ |\eta_i| = \Vert x \Vert + \Vert y \Vert$$
> 因此， $\Vert x \Vert = max_i \ |\xi_i|$ 是 $C^n$ 上的一种范数

例 2.3
> 当 $x \ne 0$ 时，显然 $\Vert x \Vert = \sum_{i=1}^{n}|xi_i|>0$；当 $x = 0$ 时，由于 $x$ 的每一分量都是零，故 $\Vert x \Vert = 0$
> 又对于任意 $a \in C$，有 $$\Vert ax \Vert = \sum_{i=1}^{n}|a\xi_i| = |a| \sum_{i=1}^{n}|\xi_i| = |a| \ \Vert x \Vert$$
> 对任意两个向量 $x, y \in C^n$，有 $$\Vert x _ y \Vert = \sum_{i=1}^{n}|\xi_i + \eta_i| \leq \sum_{i=1}^{n}(|\xi_i| + |\eta_i|) = \sum_{i=1}^{n}|\xi_i| + \sum_{i=1}^{n}|\eta_i| = \Vert x \Vert + \Vert y \Vert$$
> 于是由定义 2.1 知 $\Vert x \Vert = \sum_{i=1}^{n}|\xi_i|$ 是 $C^n$ 上的一种范数

例 2.6
> 给定线性空间 $V^n$ 的基 $x_1,x_2,\dots,x_n$，设 $x \in V^n$ 在该基下的坐标向量为 $\alpha = (\xi_1,\xi_2,\dots,\xi_n)^T$，那么 $$\Vert x \Vert_p = \Vert \alpha \Vert_p \ (1 \leq p < +\infty)$$
> 满足范数定义的三个条件. 因此，它是 $V^n$ 上的范数，也称为 $\textbf{\textit{x}}$ 的 $\textbf{\textit{p -范数}}$

例 2.8
> 显然，$\Vert A \Vert_F$ 具有非负性和齐次性. 设 $B \in C^{m \times n}$，且 $A$ 的第 $j$ 列分别为 $a_j, b_j \ (j = 1, 2, \dots, n)$，则有 $$\Vert A + B \Vert_F^2 = \Vert a_1 + b_1 \Vert_2^2 + \dots + \Vert a_n + b_n \Vert_2^2 \leq \\ (\Vert a_1 \Vert_2 + \Vert b_1 \Vert_2)^2 + \dots + (\Vert a_n \Vert_2 + \Vert b_n \Vert_2)^2 = \\ (\Vert a_1 \Vert_2^2 + \dots + \Vert a_n \Vert_2^2) + 2(\Vert)$$
> 显然，$\Vert A \Vert_F$ 具有非负性和齐次性. 设 $B \in C^{m \times n}$，且 $A$ 的第 $j$ 列分别为 $a_j, b_j \ (j = 1, 2, \dots, n)$，则有 $$\Vert A + B \Vert_F^2 = \Vert a_1 + b_1 \Vert_2^2 + \dots + \Vert a_n + b_n \Vert_2^2 \leq \\ (\Vert a_1 \Vert_2 + \Vert b_1 \Vert_2)^2 + \dots + (\Vert a_n \Vert_2 + \Vert b_n \Vert_2)^2 = \\ (\Vert a_1 \Vert_2^2 + \dots + \Vert a_n \Vert_2^2) + 2(\Vert)$$
> 显然，$\Vert A \Vert_F$ 具有非负性和齐次性. 设 $B \in C^{m \times n}$，且 $A$ 的第 $j$ 列分别为 $a_j, b_j \ (j = 1, 2, \dots, n)$，则有 $$\Vert A + B \Vert_F^2 = \Vert a_1 + b_1 \Vert_2^2 + \dots + \Vert a_n + b_n \Vert_2^2 \leq \\ (\Vert a_1 \Vert_2 + \Vert b_1 \Vert_2)^2 + \dots + (\Vert a_n \Vert_2 + \Vert b_n \Vert_2)^2 = \\ (\Vert a_1 \Vert_2^2 + \dots + \Vert a_n \Vert_2^2) + \\ 2(\Vert a_1 \Vert_2 \Vert b_1 \Vert_2 + \dots + \Vert a_n \Vert_2 \Vert b_n \Vert_2) + \\ (\Vert b_1 \Vert_2^2 + \dots + \Vert b_n \Vert_2^2)$$
> 对上式第二项应用式 (1.3.12)，可得 $$\Vert A + B \Vert_F^2 \leq \Vert A \Vert_F^2 + 2\Vert A \Vert_F \Vert B \Vert_F + \Vert B \Vert_F^2 = (\Vert A \Vert_F + \Vert B \Vert_F)^2$$
> 即三角不等式成立
> 再设 $B = (b_{ij})_{n \times l} \in C^{n \times l}$，则 $AB = (\sum_{k=1}^n a_{ik}b_{kj})_{m \times l} \in C^{m \times l}$，于是有 $$\Vert AB \Vert_F^2 = \sum_{i=1}^m \sum_{j=1}^l |\sum_{k=1}^n a_{ik}b_{kj}| \leq \sum_{i=1}^m \sum_{j=1}^l (\sum_{k=1}^n |a_{ik}| \ |b_{kj}|)^2 $$
> 对上式括号内的项应用式 (1.3.12)，可得 $$\Vert AB \Vert_F^2 \leq \sum_{i=1}^m \sum_{j=1}^l [(\sum_{k=1}^n |a_{ik}|^2)(\sum_{k=1}^n |b_{kj}|^2)] =  \Vert A \Vert_F^2 \ \Vert B \Vert_F^2$$
> 即 $\Vert A \Vert_f$ 是 $A$ 的矩阵范数
> 在上式中取 $B = x \in C^{n \times l}$，则有 $$\Vert Ax \Vert_2 = \Vert AB \Vert_F \leq \Vert A \Vert_F \ \Vert B \Vert_F = \Vert A \Vert_F \ \Vert x \Vert_2$$
> 即矩阵范数 $\Vert \cdot \Vert_F$ 与向量范数 $\Vert \cdot \Vert_2$ 相容

例 2.9
> 非负性. 当 $x \ne 0$ 时，$xy^H \ne O$，从而 $\Vert x \Vert_V > 0$；当 $x = 0$ 时，$xy^H = O$，从而 $\Vert x \Vert_V = O$.
> 齐次性. 对任意 $k \in C$，有 $$\Vert kx \Vert_V = \Vert kxy^H \Vert_M = |k| \ \Vert xy_H \Vert_M = |k| \ \Vert x \Vert_V$$
> 三角不等式. 对任意 $x_1,x_2 \in C^n$，有 $$\Vert x_1 + x_2 \Vert_V = \Vert (x_1 + x_2)y^H \Vert_M = \Vert x_1y^H + x_2y^H \Vert_M \leq \\ \Vert x_1y^H \Vert_M + \Vert x_2y^H \Vert_M = \Vert x_1 \Vert_V + \Vert x_2 \Vert_V$$
> 因此，$\Vert x \Vert_V$ 是 $C^n$ 上的向量范数. 当 $A \in C^{n \times n}$，$x \in C^n$ 时，有 $$\Vert Ax \Vert$$
> 因此，$\Vert x \Vert_V$ 是 $C^n$ 上的向量范数. 当 $A \in C^{n \times n}$，$x \in C^n$ 时，有 $$\Vert Ax \Vert_V = \Vert (Ax)y^H \Vert_V = \Vert A(xy^H) \Vert_M \leq \Vert A \Vert_M \ \Vert xy^H \Vert_M = \Vert A \Vert_M \ \Vert x \Vert_V$$
> 即矩阵范数 $\Vert \cdot \Vert_M$ 与向量范数 $\Vert \cdot \Vert_V$ 相容

习题 2.1
1
> 对向量 $x = (x_1, x_2,\dots,x_n)$，其 $1$ -范数为 $$\Vert x \Vert_1 = |x_1| + |x_2| + \dots + |x_n|$$
> $2$ -范数为 $\Vert x \Vert_2 = \sqrt{|x_1|^2 + |x_2|^2 + \dots + |x_n|^2}$
> $\infty$ -范数为 $\Vert x \Vert_{\infty} = max_i \ |x_i|$
> 故 $l_1 = |1| + |1| + \dots + |1| = n \\ \ \ \ \ l_2 = \sqrt{|1|^2 + |1|^2 + \dots + |1|^2} = \sqrt{n} \\ \ \ \ \ l_{\infty} = max \ |1| = 1$

习题 2.2
1
> $\Vert A \Vert_1 = max_i|a_i| = 2$，$\Vert A \Vert_{\infty} = |-1| + 2 + 1 = 4$
> 由谱范数性质，可知 $$\Vert A \Vert_2 = \Vert A^T \Vert k = \sqrt{\lambda max(AA^T)} = \sqrt{6}$$
> $\Vert B \Vert_1 = max_i\sum_{j = 1}^2|b_{ij}| = 4$，$\Vert B \Vert_{\infty} = 6$\
> 则有
> $$B^HB = \begin{bmatrix}
    2 & 2j & 4j \\
    -2j & 4 & 6 \\
    -4j & 6 & 10 \\
\end{bmatrix}$$
> $|\lambda I - B^HB| = \lambda (\lambda - (8 + 2\sqrt{13}))(\lambda - (8 - 2\sqrt{13}))$
> 故 $\Vert B \Vert_2 = \sqrt{8 + 2\sqrt{13}}$