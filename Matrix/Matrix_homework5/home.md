####P8
令 $x_{11} = - x_{12} - x_{21}$，则 $$X = \begin{bmatrix}
    -x_{12}-x_{21} & x_{12} \\ x_{21} & x_{22}
\end{bmatrix}, Y = \begin{bmatrix}
    -y_{12}-y_{21} & y_{12} \\ y_{21} & y_{22}
\end{bmatrix}$$ 定义 $V$ 的内积为 $(X, Y) = tr(XY_T) = (X_{12} + x_{21})(y_{12} + y_{21} + x_{12}y_{12} + x_{21} y_{21} + x_{22}y_{22})$
任意找一组基 $$X = \begin{bmatrix}
    -x_{12}-x_{21} & x_{12} \\ x_{21} & x_{22}
\end{bmatrix} = x_{12}\begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix} + x_{21}\begin{bmatrix}
    -1 & 0 \\ 1 & 0
\end{bmatrix} + x_{22}\begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix} = x_{12}X_1 + x_{21}X_2 + x_{22}X_3$$ $$Y_1' = X_1 = \begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix}, Y_2' = X_2 - \frac{(X_2, Y_1')}{Y_1', Y_1'}Y_1' = \begin{bmatrix}
    -1 & 0 \\ 1 & 0
\end{bmatrix} - \frac{1}{2}\begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix} = \begin{bmatrix}
    -\frac{1}{2} & -\frac{1}{2} \\ 1 & 0
\end{bmatrix}$$ $$Y_3' = X_3 - \frac{(X_3, Y_2')}{Y_2', Y_2'}Y_2' - \frac{(X_3, Y_1')}{Y_1', Y_1'}Y_1' = \begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix} - \frac{0}{\frac{3}{2}}\begin{bmatrix}
    -\frac{1}{2} & -\frac{1}{2} \\ 1 & 0
\end{bmatrix} - \frac{0}{2}\begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix} = \begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix}$$ 得到 $V$ 的一组正交基 $Y_1', Y_2', Y_3'$ $$Y_1' = \begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix}, Y_2' = \begin{bmatrix}
    -\frac{1}{2} & -\frac{1}{2} \\ 1 & 0
\end{bmatrix}, Y_3' = \begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix}$$ 则有 $$e_1 = \frac{1}{|Y_1'|}Y_1' = \frac{1}{\sqrt{2}}\begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix}, e_2 = \frac{1}{|Y_2'|}Y_2' = \frac{\sqrt{2}}{\sqrt{3}}\begin{bmatrix}
    -\frac{1}{2} & -\frac{1}{2} \\ 1 & 0
\end{bmatrix}, e_3 = \frac{1}{|Y_3'|}Y_3' = \begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix}$$ 得到 $V$ 的一组标准正交基 $e_1,e_2,e_3$ $$e_1 = \frac{1}{\sqrt{2}}\begin{bmatrix}
    -1 & 1 \\ 0 & 0
\end{bmatrix}, e_2 = \frac{\sqrt{2}}{\sqrt{3}}\begin{bmatrix}
    -\frac{1}{2} & -\frac{1}{2} \\ 1 & 0
\end{bmatrix}, e_3 = \begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix}$$ $$x = \begin{bmatrix}
    4 & -4 \\ 0 & -3
\end{bmatrix} = \begin{bmatrix}
    e_1, e_2, e_3
\end{bmatrix}\begin{bmatrix}
    k_1 \\ k_2 \\ k_3
\end{bmatrix}$$ 其中 $$k_1 = (x,e_1) = -4\sqrt{2}, k_2 = (x,e_2) = 0, k_3 = (x,e_3) = -3$$ $$Te_1 = \frac{1}{\sqrt{2}}\begin{bmatrix}
    -3 & 1 \\ 2 & 0
\end{bmatrix}, Te_2 = \frac{\sqrt{2}}{\sqrt{3}}\begin{bmatrix}
    -\frac{3}{2} & -\frac{3}{2} \\ 0 & 0
\end{bmatrix}, Te_3 = \begin{bmatrix}
    0 & 0 \\ 0 & 3
\end{bmatrix}$$ $$Te_1 = \begin{bmatrix}
    e_1, e_2, e_3
\end{bmatrix}\begin{bmatrix}
    2 \\ \sqrt{3} \\ 0
\end{bmatrix}, Te_2 = \begin{bmatrix}
    e_1, e_2, e_3
\end{bmatrix}\begin{bmatrix}
    \sqrt{3} \\ 0 \\ 0
\end{bmatrix}, Te_3 = \begin{bmatrix}
    e_1, e_2, e_3
\end{bmatrix}\begin{bmatrix}
    0 \\ 0 \\ 3
\end{bmatrix}$$ $$\Rightarrow T(e_1, \dots, e_n) = (e_1, \dots, e_n)\begin{bmatrix}
    2 & \sqrt{3} & 0 \\ \sqrt{3} & 0 & 0 \\ 0 & 0 & 3
\end{bmatrix} = (e_1, \dots, e_n)A_0$$ $$\lambda I - A_0 = \begin{bmatrix}
    \lambda - 2 & -\sqrt{3} & 0 \\ -\sqrt{3} & \lambda & 0 \\ 0 & 0 & \lambda - 3
\end{bmatrix} \rightarrow \begin{bmatrix}
      -\sqrt{3} & \lambda - 2 & 0 \\ \lambda & -\sqrt{3} & 0 \\ 0 & 0 & \lambda - 3
\end{bmatrix} \rightarrow \begin{bmatrix}
    -\sqrt{3} & 0 & 0 \\ \lambda & \frac{\lambda - 2}{\sqrt{3}}\lambda-\sqrt{3} & 0 \\ 0 & 0 & \lambda - 3
\end{bmatrix}$$ $$ \rightarrow \begin{bmatrix}
    -\sqrt{3} & 0 & 0 \\ 0 & \frac{1}{\sqrt{3}}(\lambda + 1)(\lambda - 3) & 0 \\ 0 & 0 & \lambda - 3
\end{bmatrix} \rightarrow \begin{bmatrix}
    1 & 0 & 0 \\ 0 & 0 & \lambda - 3 \\ 0 & (\lambda + 1)(\lambda - 3) & 0
\end{bmatrix} \rightarrow \begin{bmatrix}
    1 & 0 & 0 \\ 0 & \lambda - 3 & 0 \\ 0 & 0 & (\lambda + 1)(\lambda - 3)
\end{bmatrix}$$ 不变因子：$d_1(\lambda) = 1, d_2(\lambda) = \lambda - 3, d_3(\lambda) = (\lambda + 1)(\lambda - 3)$
初等因子： $\lambda - 3;\lambda + 1, \lambda - 3$
初等因子组：$\lambda - 3,\lambda + 1, \lambda - 3$
$Jordan$ 块：$J_1(\lambda_1) = (3), J_2(\lambda_2) = (-1), j_3(\lambda_3) = (3)$
$Jordan$ 标准型：$J = \begin{bmatrix}
    3 & & \\ & -1 & \\ & & 3
\end{bmatrix}$
$$P = (x_1, x_2, x_3) = \begin{bmatrix}
    \sqrt{3} & -1 & 0 \\ 1 & \sqrt{3} & 0 \\ 0 & 0 & 1
\end{bmatrix}, P^{-1} = \begin{bmatrix}
    \frac{\sqrt{3}}{4} & \frac{1}{4} & 0 \\ -\frac{1}{4} & \frac{\sqrt{3}}{4} & 0 \\ 0 & 0 & 1
\end{bmatrix}$$ 得到一组新的基 $E_1, \dots, E_n = (e_1, \dots, e_n)P$ $$E_1 = (e_1, e_2, e_3)\begin{bmatrix}
    \sqrt{3} \\ 1 \\ 0
\end{bmatrix} = \frac{2}{\sqrt{6}}\begin{bmatrix}
    -2 & 1 \\ 1 & 0
\end{bmatrix}, E_2 = (e_1, e_2, e_3)\begin{bmatrix}
    -1 \\ \sqrt{3} \\ 0
\end{bmatrix} = \sqrt{2}\begin{bmatrix}
    0 & -1 \\ 1 & 0
\end{bmatrix}, E_3 = (e_1, e_2, e_3)\begin{bmatrix}
    0 \\ 0 \\ 1
\end{bmatrix} = \begin{bmatrix}
    0 & 0 \\ 0 & 1
\end{bmatrix}$$ $$x = \begin{bmatrix}
    4 & -4 \\ 0 & -3
\end{bmatrix} = (e_1, e_2, e_3)\begin{bmatrix}
    -4\sqrt{2} \\ 0 \\ -3
\end{bmatrix} = (E_1, E_2, E_3)P^{-1}\begin{bmatrix}
    -4\sqrt{2} \\ 0 \\ -3
\end{bmatrix} = (E_1, E_2, E_3)\begin{bmatrix}
    -\sqrt{6} \\ \sqrt{2} \\ -3
\end{bmatrix}$$

$$(T^3)(x) = (E_1, E_2, E_3)\begin{bmatrix}
    27 & & \\ & -1 & \\ & & 27
\end{bmatrix}\begin{bmatrix}
    -\sqrt{6} \\ \sqrt{2} & -3
\end{bmatrix} = \begin{bmatrix}
    108 & -52 \\ -56 & -81
\end{bmatrix}$$ $$(T^k)(x) = (E_1, E_2, E_3)\begin{bmatrix}
    3^k & & \\ & (-1)^k & \\ & & 3^k
\end{bmatrix}\begin{bmatrix}
    \frac{\sqrt{3}}{4} & \frac{1}{4} & 0 \\ -\frac{1}{4} & \frac{\sqrt{3}}{4} & 0 \\ 0 & 0 & 1
\end{bmatrix}\begin{bmatrix}
    (x_1,e_1) \\ (x_2,e_2) \\ (x_3,e_3)
\end{bmatrix}$$
####P72 1.36 
(1)
设 $X \in V$，则 $$X = \begin{bmatrix}x_1 & x_2 \\ x_3 & x_4\end{bmatrix} = x_1\begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix} + x_2\begin{bmatrix}0 & 1 \\ 0 & 0\end{bmatrix}+x_3\begin{bmatrix}0 & 0 \\ 1 & 1\end{bmatrix}$$ 故 $V$ 的一个标准正交基为 $$X_1 = \begin{bmatrix}1 & 0 \\ 0 & 0\end{bmatrix}, X_2 = \begin{bmatrix}0 & 1 \\ 0 & 0\end{bmatrix},X_3 = \frac{1}{\sqrt{2}}\begin{bmatrix}0 & 0 \\ 1 & 1\end{bmatrix}$$
(2)
计算积象组：$$T(X_1) = \begin{bmatrix}1 & 2 \\ 0 & 0\end{bmatrix}=1X_1 + 2X_2 + 0X_3$$ $$T(X_2) = \begin{bmatrix}2 & 1 \\ 0 & 0\end{bmatrix}=2X_1 + 1X_2 + 0X_3$$ $$T(X_3) = \frac{1}{\sqrt{2}}\begin{bmatrix}0 & 0 \\ 3 & 3\end{bmatrix}=0X_1 + 0X_2 + 3X_3$$ 设 $T(X_1,X_2,X_3) = (X_1,X_2,X_3)A$，则 $$A = \begin{bmatrix}
    1 & 2 & 0 \\ 2 & 1 & 0 \\ 0 & 0 & 3
\end{bmatrix}$$ 易见 $A$ 时对称矩阵，由定理 1.38 知 $T$ 是对称变换.
(3)
求正交矩阵 $Q$ 使得 $Q^{-1}AQ = \varLambda$，即 $$\varLambda = \begin{bmatrix}
    3 &  &  \\  & 3 &  \\  &  & -1
\end{bmatrix}, \space \space Q = \begin{bmatrix}
    0 & \frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}} \\ 0 & \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\ 1 & 0 & 0
\end{bmatrix}$$ 根据定理 1.42 的推论 2，令 $(Y_1, Y_2, Y_3) = (X_1,X_2,X_3)Q$，求得标准正交基 $$Y_1 = \frac{1}{\sqrt{2}}\begin{bmatrix}0 & 0 \\ 1 & 1\end{bmatrix}, Y_2 = \frac{1}{\sqrt{2}}\begin{bmatrix}1 & 1 \\ 0 & 0\end{bmatrix}, Y_3 = \frac{1}{\sqrt{2}}\begin{bmatrix}-1 & 1 \\ 0 & 0\end{bmatrix}$$ 有 $T(Y_1,Y_2,Y_3) = (Y_1,Y_2,Y_3)\varLambda$

####习题1.3 15
(1) $x_1 = \frac{1}{\sqrt{2}}\begin{bmatrix}
    1 & 0 \\ 0 & 1
\end{bmatrix}, x_2 = \frac{1}{\sqrt{2}}\begin{bmatrix} 0 & 1 \\ 1 & 0
\end{bmatrix}$
(2) $T$ 在标准正交基 $x_1, x_2$ 下的矩阵为 $A = \begin{bmatrix}
    1 & 1 \\ 1 & 1
\end{bmatrix}$，$\because$ $A$ 是对称矩阵，$\therefore$ $T$ 是对称矩阵
(3) $T$ 在标准基下，$Y_1 = \frac{1}{2}\begin{bmatrix}
    -1 & 1 \\ 1 & -1
\end{bmatrix}, Y_2 = \frac{1}{2}\begin{bmatrix}
    1 & 1 \\ 1 & 1
\end{bmatrix}$，故为 $\varLambda = diag(0, 2)$



