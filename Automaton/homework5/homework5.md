4、对下列文法的生成式，找出其正则式
(1) $G_1 = (\{S, A, B, C\}, \{a, b, c, d\}, P, S)$，其中生成式如下：
$$\begin{align*}
    &S \rightarrow baA \qquad &S \rightarrow B \\ &A \rightarrow aS \qquad &A \rightarrow bB \\ &B \rightarrow b \qquad &B \rightarrow bC \\ &C \rightarrow cB \qquad &C \rightarrow d
\end{align*}$$

> $$\begin{align*}
    &S = baA + B &(1)\\ &A = aS + bB &(2)\\ &B = b + bC &(3)\\ &C = cB + d &(4)
\end{align*}$$ 将式 $(4)$ 代入式 $(3)$ $$\begin{equation*}
    B = b + b(cB + d) = bcB + b + d = (bc)^*(b + d) \tag{5}
\end{equation*}$$ 将式 $(2)$、$(5)$ 代入式 $(1)$ $$
    S = baaS + babB + B = (baa)^*(bab + \epsilon)B \\ = (baa)^*(bab + \epsilon)(bc)^*(b + d)
$$

(2) $G_2 = (\{S, A, B, C, D\}, \{a, b, c, d\}, P, S)$，其中生成式 $P$ 如下：
$$\begin{align*}
    &S \rightarrow aA \qquad &S \rightarrow B \\ &A \rightarrow cC \qquad &A \rightarrow bB \\ &B \rightarrow bB \qquad &B \rightarrow a \\ &C \rightarrow D \qquad &C \rightarrow abB \\ &D \rightarrow d
\end{align*}$$

> $$\begin{align*}
    &S = aA + B &(1) \\ &A = cC + bB &(2)\\ &B = bB + a = b^*a &(3) \\ &C = D + abB = D + abB &(4) \\ &D = d &(5)
\end{align*}$$ 将式 $(5)$、$(3)$ 代入式 $(4)$ $$C = d + abb^*a = d + abb^*a \tag{6}$$ 将式 $(2)$、$(3)$、$(6)$ 代入式 $(1)$ $$S = acC + abB + B = acd + acabb^*a + abb^*a + b^*a \\ = acd + (acab + ab + \epsilon)b^*a$$

5、为下列正则集构造右线性文法：
(1) $\{a, b\}^*$

> 设右线性文法 $G = (S, \{ a , b \} , P , S )$
> $$\{a, b\}^* = (a + b)* \\ S \rightarrow aS | bS | \epsilon$$

(2) 以 $abb$ 结尾的由 $a$ 和 $b$ 组成的所有字符串的集合

> 设右线性文法 $G = (S, \{ a , b \} , P , S )$
> $$S = (a + b)^*abb \\ S \rightarrow aS | bS | aab$$ 

(3) 以 $b$ 为首后跟若干个 $a$ 的字符串集合

> 设右线性文法 $G = (\{S, A\}, \{ a , b \} , P , S )$
> $$S = ba^* \\ S \rightarrow bA \\ A \rightarrow aA | \epsilon$$

(4) 含有两个相继 $a$ 或两个相继 $b$ 的由 $a$ 和 $b$ 组成的所有字符串的集合

> 设右线性文法 $G = (\{S, A, B, C\}, \{ a , b \} , P , S )$
> $$S = (a + b)^*aa(a+b)^*bb(a+b)^* + \\ (a + b)^*bb(a + b)^*aa(a + b)^*$$ $$S \rightarrow aS | bS | aaA | bbB \\ A \rightarrow aA | bA | bbC \\ B \rightarrow aB | bB | aaC \\ C \rightarrow aC | bC | \epsilon$$