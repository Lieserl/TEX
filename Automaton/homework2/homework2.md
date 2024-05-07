#### 4. 找出右线性文法，能构成长度为1至3个字符且以字母为首的字符串。

$$G = \{N, T, P, S\}$$ 
其中，
$$N = \{S, A, B\} \quad T = \{a, b\}$$ $$a = \{所有字母\}, \quad b = \{所有字符\}$$ $P:$ $$\begin{align*}
    S &\rightarrow aA \\ A &\rightarrow bB | \epsilon \\ B &\rightarrow b | \epsilon
\end{align*} $$

#### 5. 找出右线性文法，能构成具有奇数个a和奇数个b的所有由a和b组成的字符串。

$$G = \{N, T, P, S\}$$ 
其中，
$$N = \{S, A, B, C\}, \quad T = \{a, b\}$$
P: $$\begin{align*}
    S &\rightarrow aA | bB \\
    A &\rightarrow bC | b | aS \\
    B &\rightarrow aC | a | bS \\
    C &\rightarrow aB | bA
\end{align*}$$

#### 6. 构造上下文无关文法能够产生所有含有相同个数0和1的字符串。

$$G = \{N, T, P, S\}$$ 
其中，
$$N = \{S, A, B\}, \quad T = \{0, 1\}$$
P: $$\begin{align*}
    S &\rightarrow 0S1 | 1S0 | 0A0 | 1B1 |\epsilon\\
    A &\rightarrow 1S1 \\
    B &\rightarrow 0S0 
\end{align*}$$

#### 7. 找出由下列各组生成式产生的语言（起始符为S）
1. $S \rightarrow SaS, \quad S \rightarrow b$
2. $S \rightarrow aSb, \quad S \rightarrow c$
3. $S \rightarrow a, \quad S \rightarrow aE, \quad E \rightarrow aS$

(1) $$L = \{(ba)^nb| n \geq 0\}$$
(2) $$L = \{ a^ncb^n | n \geq 0\}$$
(3) $$L = \{a^{2n + 1} | n \geq 0\}$$

