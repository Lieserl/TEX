1、使用泵浦引理，证明下列集合不是正则集:

(1) 由文法 *G* 的生成式 $S \rightarrow aSbS|c$ 产生的语言 *L(G)*

> 设 *L* 为正则集，取足够大的整数 *n*，$\omega = a^n(cb)^nc$
> 有 $$|\omega| = |\omega_1\omega_0\omega_2| = 3n + 1 \\ 0 < |\omega_0|, 0 < |\omega_1\omega_0| \leq n$$ 设 $|\omega_0|= k \geq 1$，由于 $|\omega_0|$ 只可能取处于 $a$ 段的字符串， 取 $i = 0$，有 $$|\omega_1\omega_0^0\omega_2| = |\omega_1\omega_2| = a^{n-k}(cb)^nc$$ 此时 *a、bc* 数量不等，即 $\omega_1\omega_0^i\omega_2 \notin L$，与假设矛盾，*L* 不是正则集

(2) $\{\omega | \omega \in \{a, b\}\}$ 且 $\omega$ 有相同个数的 *a* 和 *b*

> 设 *L* 为正则集，取足够大的整数 *n*，$\omega = a^nb^n$
> 有 $$ |\omega| = |\omega_1\omega_0\omega_2| = 2n > n \\ 0 < |\omega_0|, 0 < |\omega_1\omega_0| \leq n $$ 设 $|\omega_0|= k \geq 1$，由于 $|\omega_0|$ 只可能取处于 $a$ 段的字符串，故取 $i = 0$，有 $$|\omega_1\omega_0^0\omega_2| = |\omega_1\omega_2| = a^{n-k}b^n$$ 此时 *a、b* 数量不等，即 $\omega_1\omega_2 \notin L$，与假设矛盾，*L* 不是正则集

(3) $\{0^n1^m2^{n + m}|n, m \geq 1\}$

> 设 *L* 为正则集，取足够大的整数 *n* 和任意正整数 $m$，$\omega = 0^n1^m2^{n+m}$
> 有 $$ |\omega| = |\omega_1\omega_0\omega_2| = 2(n+m) > n \\ 0 < |\omega_0|, 0 < |\omega_1\omega_0| \leq n $$ 设 $|\omega_0|= k \geq 1$，由于 $|\omega_0|$ 只可能取处于 $0$ 段的字符串，故取 $i = 0$，有 $$|\omega_1\omega_0^0\omega_2| = |\omega_1\omega_2| = 0^{n-k}1^m2^{n + m}$$ 此时不满足 $0$ 与 $1$ 的数量之和等于 $2$，即 $\omega_1\omega_2 \notin L$，与假设矛盾，*L* 不是正则集

(4) $\{\omega\omega|\omega \in \{a, b\}^*\}$

> 设 *L* 为正则集，取足够大的整数 *n*，$\omega = a^nb^n, \omega\omega = a^nb^na^nb^n$
> 有 $$ |\omega| = |\omega_1\omega_0\omega_2| = 4n > n \\ 0 < |\omega_0|, 0 < |\omega_1\omega_0| \leq n $$ 设 $|\omega_0|= k \geq 1$，由于 $|\omega_0|$ 只可能取处于第一 $a$ 段的字符串，故取 $i = 0$，有 $$|\omega_1\omega_0^0\omega_2| = |\omega_1\omega_2| = a^{n-k}b^na^nb^n$$ 此时 $\omega_1' = a^{n-k}b^n \neq \omega_2' = a^nb^n$ ，即 $\omega_1\omega_2 \notin L$，与假设矛盾，*L* 不是正则集

(5) $\{0^n | n \text{为素数}\}$

> 设 *L* 为正则集，取足够大的素数 *n*， $\omega = 0^n$
> 有 $$ |\omega| = |\omega_1\omega_0\omega_2| = n \geq n \\ 0 < |\omega_0|, 0 < |\omega_1\omega_0| \leq n $$ 设 $|\omega_0|= k \geq 1$，取 $i = n - k$，有 $$|\omega_1\omega_0^{n-k}\omega_2| = k(n - k - 1) + n = (n - k)(k + 1)$$ 显然不为素数，即 $\omega_1\omega_0^{n-k}\omega_2 \notin L$，与假设矛盾，*L* 不是正则集

2、已知 $DFA$ 的状态转移表如下，构造最小状态的等价 $DFA$

||0|1|
|:---:|:---:|:---:|
|$\rightarrow$A|B|A|
|B|D|C|
|C|D|B|
|*D|D|A|
|E|D|F|
|F|G|E|
|G|F|G|
|H|G|D|

> 1. 由状态转移表可知，由初始状态 $A$ 不可到达状态 $E、F、G、H$，删去得到的 $DFA$ 为 $A = (\{A, B, C, D\}, \{0, 1\}, \delta, \{A\}, \{D\})$，其中，$\delta$ 为 
> 
> ||$\qquad$ $0$ $\qquad$|$\qquad$ $1$$\qquad$|
> |:---: | :---: | :---: |
> |$\rightarrow A$|$B$|$A$|
> |$B$|$D$|$C$|
> |$C$|$D$|$B$|
> |$*D$|$D$|$A$|
>
> 2. 根据填表法，得
>
> |B|x|| |
> |:---:|:---:|:---:|:---:|
> |C|x|| |
> |D|x|x |x |
> | |A|B|C|
> 
> 状态集划分为 $\{A\}, \{B, C\}, \{D\}$
> 
> 3. 新的状态集合为 $[A], [B], [D]$，对应的最小状态等价 $DFA$ 为 $B = (\{[A]\}, \{0, 1\}, \delta, \{[A]\}, \{[D]\})$，其中，$\delta$ 为 
>
> ||$\qquad$ $0$ $\qquad$|$\qquad$ $1$$\qquad$|
> |:---: | :---: | :---: |
> |$\rightarrow [A]$|$[B]$|$[A]$|
> |$[B]$|$[D]$|$[B]$|
> |$*[D]$|$[D]$|$[A]$|