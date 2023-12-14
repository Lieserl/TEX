### 定义

#### 3.7
设一元函数 $f(z)$ 能够展开为 $z$ 的幂级数 $$f(z) = \sum_{k=0}^{\infty}c_kz^k \ \ \ (|z| < r) \tag{3.3.1}$$ 其中 $r > 0$ 表示该幂级数的收敛半径。当 $n$ 阶矩阵 $A$ 的谱半径 $\rho(A) < r$ 时，把收敛的矩阵幂级数 $\sum_{k=0}^{\infty}c_kA^k$ 的和称为矩阵函数，记为 $f(A)$，即 $$f(A) = \sum_{k=0}^{\infty}c_kA^k \tag{3.3.2}$$

#### 3.9
如果函数矩阵 $A(t) = (a_{ij}(t))_{m \times n}$ 的每一个元素 $a_{ij}(t)$ 是变量 $t$ 的可导/函数，则称 $A(t)$ 可导，其导数（微商）定义为 $$A'(t) = \frac{d}{dt}A(t) = (\frac{d}{dt}a_{ij}(t))_{, \times n} \tag{3.4.1}$$

#### 3.10
如果函数矩阵 $A(t)$ 的每个元素 $a_{ij}(t)$ 都是区间 $[t_0, \ \ t_1]$ 上的可积函数，则定义 $A(t)$ 在 $[t_0, \ \ t_1]$ 上的积分为 $$\int_{t_0}^{t_1}A(t)dt=(\int_{t_0}^{t_1}a_{ij}(t)dt)_{m \times n} \tag{3.4.8}$$
容易验证以下的运算规则成立：$$\int_{t_0}^{t_1}(A(t) + B(t))dt = \int_{t_0}^{t_1}A(t)dt + \int_{t_0}^{t_1}B(t)dt \tag{3.4.9}$$ $$\int_{t_0}^{t_1}A(t)Bdt = (\int_{t_0}^{t_1}A(t)dt)B \ \ \ (B 与 t 无关) \tag{3.4.10}$$ $$\int_{t_0}^{t_1}A \cdot B(t)dt = A(\int_{t_0}^{t_1}B(t)dt) \ \ \ (A 与 t 无关) \tag{3.4.11}$$ 
当 $a_{ij}(t)$ 都在 $[t_0, \ \ t_1]$ 上连续时，就称 $A(t)$ 在 $[t_0, \ \ t_1]$ 上连续，且有 $$\frac{d}{dt}\int_{a}^{t}A(s)ds = A(t) \tag{3.4.12}$$ 
当 $a_{ij}'(t)$ 都在 $[a, \ \ b]$ 上连续时，则 $$\int_{a}^{b}A'(t)dt = A(b) - A(a) \tag{3.4.12}$$

### 定理

#### 3.7
如果 $AB = BA$，则 $e^Ae^B = e^Be^A = e^{A+B}$

#### 3.8
设 $A(t)$，$B(t)$ 是能够进行下面运算的两个可导的函数矩阵，则有 $$\frac{d}{dt}(A(t) + B(t)) = \frac{d}{dt}A(t) + \frac{d}{dt}B(t) \tag{3.4.2}$$ $$\frac{d}{dt}(A(t)B(t)) = \frac{d}{dt}A(t) \cdot B(t) + A(t) \cdot \frac{d}{dt}B(t) \tag{3.4.3}$$ $$\frac{d}{dt}(aA(t)) = \frac{da}{dt} \cdot A(t) + a\frac{d}{dt}A(t) \tag{3.4.4}$$ 这里，$a = a(t)$ 为 $t$ 的可导函数

#### 3.9
设 $n$ 阶矩阵 $A$ 与 $t$ 无关，则有 $$\frac{d}{dt}e^{tA} = Ae^{tA} = e^{tA}A \tag{3.4.5}$$ $$\frac{d}{dt}cos(tA) = -A(sin(tA)) = -(sin(tA))A \tag{3.4.6}$$ $$\frac{d}{dt}sin(tA) = A(cos(tA)) = (cos(tA))A \tag{3.4.7}$$

### 例题

#### 3.3
$$cos(A + B) = \frac{1}{2}(e^{j(A+B)} + e^{-j(A+B)}) = \frac{1}{2}(e^{jA}e^{jB} + e^{-jA}e^{-jB}) \\ = \frac{1}{2}(\frac{(e^{jA} + e^{-jA})(e^{jB} + e^{-jB})}{2} + \frac{(e^{jA} - e^{-jA})(e^{jB} - e^{-jB})}{2}) \\ = \frac{e^{jA} + e^{-jA}}{2}\frac{e^{jB} + e^{-jB}}{2} - \frac{e^{jA} - e^{-jA}}{2j}\frac{e^{jB} - e^{-jB}}{2j} \\ = cosAcosB - sinAsinB$$
$$cos2A = cos(A + A) = \frac{1}{2}(e^{j(A+A)} + e^{-j(A+A)}) = \frac{1}{2}（e^{jA}e^{jA} + e^{-jA}e^{-jA} \\ = \frac{1}{2}(\frac{(e^{jA} + e^{-jA})(e^{jA} + e^{-jA})}{2} + \frac{(e^{jA} - e^{-jA})(e^{jA} - e^{-jA})}{2}) \\ = \frac{e^{jA} + e^{-jA}}{2}\frac{e^{jA} + e^{-jA}}{2} - \frac{e^{jA} - e^{-jA}}{2j}\frac{e^{jA} - e^{-jA}}{2j} \\ = cos^2A - sin^2A$$
$$sin(A+B) = \frac{1}{2j}(e^{j(A+B)} - e^{-j(A+B)}) = \frac{1}{2j}(e^{jA}e^{jB}-e^{-jA}e^{-jB}) \\ = \frac{1}{2j}(\frac{(e^{jA} - e^{-jA})(e^{jB} + e^{-jB})}{2} + \frac{(e^{jA} + e^{-jA})(e^{jB} - e^{-jB})}{2}) \\ = \frac{e^{jA} - e^{-jA}}{2j}\frac{e^{jB} + e^{-jB}}{2} + \frac{e^{jA} + e^{-jA}}{2}\frac{e^{jB} - e^{-jB}}{2j} \\ = sinAcosB + cosAsinB$$
$$sin2A = sin(A + A) = \frac{1}{2j}(e^{j(A+A)} - e^{-j(A+A)}) = \frac{1}{2j}(e^{jA}e^{jA}-e^{-jA}e^{-jA}) \\ = \frac{1}{2j}(\frac{(e^{jA} - e^{-jA})(e^{jA} + e^{-jA})}{2} + \frac{(e^{jA} + e^{-jA})(e^{jA} - e^{-jA})}{2}) \\ = \frac{e^{jA} - e^{-jA}}{2j}\frac{e^{jA} + e^{-jA}}{2} + \frac{e^{jA} + e^{-jA}}{2}\frac{e^{jA} - e^{-jA}}{2j} \\ = 2sinAcosA$$

#### 3.4
$$\because f(z) = \frac{1}{1-z} = \sum_{k=0}^{\infty}A^k \ \ (|z| < 1)$$ 
由定义 3.7，当方阵 $A$ 的谱半径 $\rho(A) < 1$ 时，有 $$f(A) = \sum_{k=0}^{\infty}A^k$$
由定理 3.4 $$f(A) = (I - A)^{-1}$$

#### 3.5
$\rho(\lambda) = det(\lambda I - A) = (\lambda - 2)^3$，容易求得 $A$ 的最小多项式 $m(\lambda) = (\lambda - 2)^2$，取 $\psi(\lambda) = (\lambda - 2)^2$
(1)
取 $f(\lambda) = e^{\lambda}$，设 $f(\lambda) = \psi(\lambda)g(\lambda) + (a + b\lambda)$，则有 $$
\left\{\begin{aligned}f(2) &= e^2 \\f'(2) &= e^2\end{aligned}\right. \qquad 或者 \qquad \left\{\begin{aligned}a + 2b &= e^2 \\b &= e^2\end{aligned}\right. $$
解方程组，得 $a = -e^2, \quad b = e^2$. 故 $\rho(\lambda) = e^2(\lambda - 1)$，从而 $$e^A = f(A) = r(A) = e^2(A - I) = e^2 \begin{bmatrix}
    1 & 0 & 0 \\ 1 & 0 & 1 \\ 1 & -1 & 2
\end{bmatrix}$$
(2)
取 $f(\lambda) = e^{t\lambda}$，设 $f(\lambda) = \psi(\lambda)g(\lambda) + (a + b\lambda)$，则有 $$\begin{cases}
    f(2) = e^{2t} \\ f'(2) = te^{2t}
\end{cases} \quad 或者 \quad \begin{cases} a + 2b &= e^{2t} \\ \qquad b &= te^{2t}\end{cases}$$
解方程组得 $a = (1-2t)e^{2t}, \, b = te^{2t}$. 于是 $r(\lambda) = e^{2t}[(1-2t) + t\lambda]$，从而 $$e^{tA} = f(A) = r(A) = e^{2t}[(1-2t)I + tA] = e^{2t}\begin{bmatrix}
    1 & 0 & 0 \\ t & 1-t & t \\ t & -t & 1+t
\end{bmatrix}$$

#### 3.7
$\varphi(\lambda) = det(\lambda I - A) = (\lambda + 2)(\lambda - 1)^2$，$\lambda_1 = -2, \ \lambda_2 = \lambda_3 = 1$，特征向量 $p_1 = (-1, 1, 1)^T, \ p_@ = (-2, 1, 0)^T, \ p_3 = (0, 0, 1)^T$，构造矩阵 $$P = (p_1, p_2, p_3) = \begin{bmatrix}
    -1 & -2 & 0 \\ 1 & 1 & 0 \\ 1 & 0 & 1 
\end{bmatrix}$$ $$P^{-1} = \begin{bmatrix} 1 & 2 & 0 \\ -1 & -1 & 0 \\ -1 & -2 & 1 \end{bmatrix}, \quad P^{-1}AP = \begin{bmatrix} -2 & & \\ & 1 & \\ & & 1 \end{bmatrix}$$
可得 $$e^A = P\begin{bmatrix} e^{-2} & & \\ & e & \\ & & e \end{bmatrix}P^{-1} = \begin{bmatrix} 2e-e^{-2} & 2e-2e^{-2} & 0 \\ e^{-2} - e & 2e^{-2} - e & 0 \\ e^{-2} - e & 2e^{-2}-2e & e \end{bmatrix}$$ $$e^{tA} = P\begin{bmatrix} e^{-2t} & & \\ & e^t & \\ & & e^t \end{bmatrix}P^{-1} = \begin{bmatrix} 2e^t-e^{-2t} & 2e^t-2e^{-2t} & 0 \\ e^{-2t} - e^t & 2e^{-2t} - e^t & 0 \\ e^{-2t} - e^t & 2e^{-2t}-2e^t & e^t \end{bmatrix}$$ $$cosA = P\begin{bmatrix} cos(-2) & & \\ & cos1 & \\ & & cos1 \end{bmatrix}p^{-1} = \begin{bmatrix} 2cos1 - cos2 & 2cos1-2cos2 & 0 \\ cos2 - cos1 & 2cos2 - cos1 & 0 \\ cos2 - cos1 & 2cos2 - 2cos1 & cos1 \end{bmatrix}$$

### 习题

#### 3.3.5
$\varphi(\lambda) = |\lambda I - A| = (\lambda + 1)(\lambda-1)(\lambda-2)$ 
$$P = \begin{bmatrix} 1 & -1 & 1 \\ -3 & 1 & 0 \\ 3 & 1 & 0 \end{bmatrix}$$ $$P^{-1} = \frac{1}{6}\begin{bmatrix} 0 & -1 & 1 \\ 0 & 3 & 3 \\ 0 & 4 & 2 \end{bmatrix}, \quad P^{-1}AP = \begin{bmatrix} -1 & & \\ & 1 & \\ & & 2 \end{bmatrix}$$
可得 $$e^A = \frac{1}{6}\begin{bmatrix}
    6e^2 & 4e^2-3e-e^{-1} & 2e^2-3e+e^{-1} \\ 0 & 3e+3e^{-1} & 3e-3e^{-1} \\ 0 & 3e-3e^{-1} & 3e + 3e^{-1}
\end{bmatrix}$$ $$e^{tA} = \frac{1}{6}\begin{bmatrix}
    6e^{2t} & 4e^{2t}-3e^t-e^{-t} & 2e^{2t}-3e^t+e^{-t} \\ 0 & 3e^t+3e^{-t} & 3e^t-3e^{-t} \\ 0 & 3e^t-3e^{-t} & 3e^t + 3e^{-t}
\end{bmatrix}$$ $$sinA = \frac{1}{6}\begin{bmatrix}sin2 & 4sin2-2sin1 & 2sin2-4sin1 \\ 0 & 0 & 6sin1 \\ 0 & 6sin1 & 0 \end{bmatrix}$$

#### 3.3.6
(1)
$$P = \begin{bmatrix} & & & 1 \\ & & 1 & \\ & 1 & & \\ 1 & & & \end{bmatrix}, \quad J = P^{-1}AP = \begin{bmatrix} 1 & 1 & & \\ & 1 & 1 &  \\ & & 1 & 1 \\ & & &  1 \end{bmatrix}$$ $$lnA = PlnJP^{-1} = \begin{bmatrix} 0 & & & \\ 1 & 0 & & \\ -\frac{1}{2} & 1 & 0 & \\ \frac{1}{3} & -\frac{1}{2} & 1 & 0 \end{bmatrix}$$

(2) 
$$A = \begin{bmatrix} J_1 & \\ & J_2 \end{bmatrix}, \quad其中\quad J_1 \begin{bmatrix} 2 & 1 \\ 0 & 2 \end{bmatrix}\quad \begin{bmatrix}1 & 1 \\ 0 & 1\end{bmatrix}$$ $$lnJ_1 = \begin{bmatrix} ln2 & \frac{1}{2} \\ 0 & ln2 \end{bmatrix}, \quad lnJ_2 = \begin{bmatrix} 0 & 1 \\ 0 & 0 \end{bmatrix}$$ $$lnA = \begin{bmatrix} lnJ_1 & \\ & lnJ_2 \end{bmatrix} = \begin{bmatrix} ln2 & \frac{1}{2} & 0 & 0 \\ & ln2 & 0 & 0 \\ & & 0 & 1 \\ & & & 0 \end{bmatrix}$$

#### 3.4.4
$$f(x) = x^TAx - b^Tx + c = Ax^2 - (b_1x_1 + b_2x_2 + \dots + b_nx_n) + c$$ $$\therefore f'(x) = 2Ax - b$$