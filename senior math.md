#### 

--------------------------------

#### 平面图形的面积
> $$A = \frac{1}{2}\int_{\alpha}^{\beta}[\varphi(\theta)]^2d\theta$$ 

#### 体积
> $$A = \pi\int_a^b[f(x)]^2dx$$ $$V = \int_a^bA(x)dx, \quad dv = A(x)dx$$ $$A = \int_{r_1}^{r_2}2\pi rf(r)dr$$

#### 弧长
> $$ds = \sqrt{(dx)^2 + (dy)^2} = \sqrt{x'^2(t) + y'^2(t)}dt = \sqrt{1 + (\frac{dy}{dx})^2}dx$$ $$S = \int_{\alpha}^{\beta}\sqrt{x'^2(t) + y'^2(t)}dt = \int_a^b\sqrt{1 + (\frac{dy}{dx})^2}dx$$ $$S = \int_{\alpha}^{\beta}\sqrt{\rho^2(\theta) + \rho'^2(\theta)}d\theta$$

---------------------------------------------------------------------------

#### 一、$\frac{dy}{dx} = \varphi(\frac{y}{x})$
> 令 $u = \frac{y}{x}$，有 $$y = ux, \quad \frac{dy}{dx} = \frac{d(ux)}{dx} = u + x\frac{du}{dx}$$ 原式化为 $$\frac{du}{u + \varphi(u)} = \frac{dx}{x}$$

#### 二、$\frac{dy}{dx} = \frac{ax + bx + C}{a_1x + b_1x + C_1}$
> 令 $x = X + h, \quad y = Y + k$，有 $$\frac{Y}{X} = \frac{aX + bY + ah + bk + C}{a_1X + b_1Y + a_1h + b_1l + C_1}$$ 令 $$\begin{cases}
    ah + bk + C = 0 \\ a_1h + b_1k + C_1 = 0
\end{cases}$$ 
> 1. $ab_1 \ne a_1b$ $$\frac{dY}{dX} = \frac{aX + bY}{a_1X + b_1Y} = \frac{a + b\frac{Y}{X}}{a_1 + b_1 \frac{Y}{X}} = \varphi(\frac{Y}{X})$$ 此时按照 $(一)$ 解.
> 2. $ab_1 = a_1b$ 
> 令 $\frac{a_1}{a} = \frac{b_1}{b} = \lambda$，有 $$\frac{dy}{dx} = \frac{ax + by + C}{\lambda(ax + by) + C_1}$$ 令 $v = ax + by$，有 $$\frac{dv}{dx} = a + b\frac{dy}{dx}$$ $$\frac{1}{b}(\frac{dv}{dx} - a) = \frac{v + C}{\lambda v + C_1}$$ 

#### 三、$\frac{dy}{dx} + P(x)y = Q(x)$
> 通解为 $$y = e^{-\int P(x)dx}(\int Q(x)e^{\int P(x)dx}dx + C)$$ 对 $\frac{dx}{dy}$ 依然成立

#### 四、$\frac{dy}{dx} + P(x)y = Q(x)y^n \quad (n \ne 0, 1)$
> 两边同除 $y^n$，得 $$y^{-n}\frac{dy}{dx} + P(x)y^{1-n} = Q(x)$$ $$\frac{1}{1-n}\frac{dy^{1-n}}{dx} + P(x)y^{1-n} = Q(x)$$ 令 $z = y^{1-n}$，有 $$\frac{dz}{dx} + (1-n)P(x)z = (1-n)Q(x)$$ 为 $(三)$

#### 五、$y^{(n)} = f(x)$
# 只因！

#### 六、$y'' = f(x, y')$
> 令 $y' = p(x)$，有 $$\frac{dy}{dx} = f(x, p)$$ 为 $(三)$，求完再只因一下

#### 七、$y'' = f(y, y')$
> 令 $y' = q(y)$，$y'' = \frac{dq}{dy}\frac{dy}{dx} = q\frac{dq}{dy}$，有 $$q\frac{dq}{dy} = f(y,q)$$ 为 $(三)$，求完再只因一下

#### 八、$y'' + p(x)y' + q(x)y = 0$
> 已知上述方程的一个特解 $y_1(x)$，有另一特解 $$y_2(x) = y_1(x)\int\frac{1}{y_1^2(x)}e^{-\int p(x)dx}dx$$

#### 九、$y'' + p(x)y' + q(x)y = f(x)$
> 已知对应的齐次方程的线性无关解 $y_1(x)$ 和 $y_2(x)$，有 $$Y(x) = C_1y_1(x) + C_2y_2(x)$$ 设非齐次方程的通解为 $y = y_1(x)C_1(x) + y_2(x)C_2(x)$，求导 $$y' = y_1'(x)C_1 + y_1(x)C_1' + y_2'(x)C_2 + y_2(x)C_2'$$ 可设 $y_1C_1' + y_2C_2' = 0$，有 $$y' = y_1'C_1 + y_2'C_2$$ 求导 $$y'' = y_1''C_1 + y_1'C_1' + y_2''C_2 + y_2'C_2'$$ 带入原方程解出 $C_1',C_2'$ 然后只因即可

#### 十、$y'' + py' + qy = 0$
> 特征方程 $r^2 + pr + q = 0$ 对应的特征根 $r_1, \ r_2$
> 1. $r_1 \ne r_2, r_1,r_2 \in R$ $$y = C_1e^{r_1x} + C_2e^{r_2x}$$
> 2. $r_1 = r_2, r_1,r_2 \in R$ $$y = C_1e^{r_1x} + C_2xe^{r_2x}$$
> 3. $r = \alpha \plusmn i\beta$ $$y = e^{\alpha x}(C_1cos\beta x + C_2sin\beta x)$$

#### 十一、$y^{(n)} + p_1y^{(n-1)} + \dots + p_{n-1}y' + p_ny = 0$
> |特征方程的根|微分方程的解|
> |---|---|
> |单实根 $r$|e^{rx}|
> |$k$ 重实根 $r$|$e^{rx}(C_1 + C_2x + \dots + C_{k}x^{k-1})$|
> |$r = \alpha \plusmn i\beta$|$e^{\alpha x}(C_1cos\beta x + C_2sin\beta x)$|
> |$k$ 重共轭 $r$|$e^{\alpha x}[(C_1 + C_2x + \dots + C_kx^{k-1})cos\beta x + (D_1 + D_2x + \dots + D_kx^{k-1})sin\beta x]$|

### 十二、$y'' + py' + qy = f(x)$
#### 1、$f(x) = e^{\lambda x}P_m(x)$
> $P_m(x)$，$Q_m(x)$ 是 $m$ 次多项式，$k$ 为特征根的重数
> 若 $\lambda$ 不是特征根，
> $$y* = e^{\lambda x}Q_m(x)$$
> 若 $\lambda$ 是单根，但 $2\lambda + p \ne 0$
> y* = e^{\lambda x}xQ_m(x)
> 若 $\lambda$ 是二重根且 $2\lambda + p = 0$
> y* = e^{\lambda x}x^kQ_m(x)

#### 2、$f(x) = P_x(x)e^{\alpha x}cos\beta x$
> $$y* = x^ke^{\alpha x}(Q_{m1}(x)cos\beta x - Q_{m2}(x)sin\beta x)$$

#### 3、$f(x) = P_m(x)e^{\alpha x}sin\beta x$
> $$y* = x^ke^{\alpha x}(Q_{m1}(x)sin\beta x + Q_{m2}cos\beta x)$$

#### 十三、$x^ny^{(n)} + p_1x^{n-1}y^{(n-1)} + P_2x^{n-2}y^{(n-2)} + \dots + p_{n-1}xy' + p_ny = f(x)$
> 令 $x = e^t$，只考虑 $(x > 0)$，$x < 0$ 可设 $x = -e^t$ $$\frac{dy}{dt} = \frac{dy}{dx}\frac{dx}{dt} = y'e^t = xy', \quad \frac{d^2y}{dt^2} = \frac{dx}{dt}y' + x\frac{dy'}{dx}\frac{dx}{dt} = xy' + x^2y'' \quad \text{此处 y 对 x 的导数}$$ 即 $$\frac{dy}{dt} = xy', \quad \frac{d^2y}{dt^2} = \frac{dy}{dt} + x^2y''$$ 代入，得 $$\frac{d^2y}{dt^2} - \frac{dy}{dt} + p\frac{dy}{dt} + qy = f(e^t)$$

