1、[4 points]Give examples of relations on {1, 2, 3, 4} having the properties specified
a) Reflexive, symmetric, and not transitive.
b) Not reflexive, not symmetric and transitive.

2、[10 points]Suppose A = {2, 3, 5, 6, 10, 15, 20, 30} and R is the partial order relation defined on A where xRy means x is a divisor of y
(1) Draw the Hasse diagram for R.
(2) Find all maximal elements.
(3) Find all minimal elements.
(4) Find all upper bounds for 3, 5.
(5) Find LUB({5, 10}).
(6) Find GLB({6, 15}).
(7) Is the poset(A, R) a lattice? Explain your answer.

3、[8 points]Let B = {1, 2, 3, 4, 5}, A = B x B, and define R on A as follows: (a, b)R(c, d) if and only if a - b = c - d.
(1) Prove that R is an equivalence relation.
(2) Find [(3, 5)].
(3) Compute A/R.

4、[9 points]In the questions below find the matrix that represents the given relation. Use elements in the order given to determine rows and columns of the matrix.
a) R on {-2, -1, 0, 1, 2}, where aRb means $a^2 = b^2$.
b) $R^2$, where R is relation on {1, 2, 3, 4} such that aRb means $|a - b| \leq 1$.
c) $\overline{R}$, where R is the relation on {w, x, y, z} such that R = {(w, w), (w, x), (x, x), (x, z), (y, y), (z, y), (z, z)}.

5、[9 points]Let R be the relation on A = {1, 2, 3, 4, 5} where R = {(1, 1), (1, 3), (1, 4), (2, 2), (2, 1), (3, 3), (3, 4), (4, 1), (4, 3), (5, 5)}.
(1) Find the reflexive closure of R.
(2) Find the symmetric closure of R.
(3) Use Warshall's algorithm to find the transitive closure of R.

6、[4 points]Let (G, *) be a group with G = {1, 2, 3, 4}. Here is an incomplete operation table for *:

$$\begin{pmatrix}
    * & 1 & 2 & 3 & 4 \\
    1 & 1 & 2 & 3 & ? \\
    2 & 2 & 1 & ? & ? \\
    3 & 3 & ? & 1 & ? \\
    4 & ? & ? & ? & 1 \\
\end{pmatrix}$$


Redraw this table and fill the missing entries.

7、[20 points]Let $H = \begin{bmatrix} 1 & 0 & 0 \\ 1 & 1 & 0 \\ 0 & 1 & 1 \\ 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \\ \end{bmatrix}$ be a parity check matrix.
(a) Determine the (3, 6) group code $e_H$. (5 points)
(b) Determine the number of errors that $e_H$ will detect and its associated decoding function will correct. (2 points)
(c) Constructing a decoding table relative to a maximum likelihood decoding function associated with $e_H$. (5 points)
(d) Decode the following words with the decoding table. (2 points)
$\space \space \space \space $ a) 011001 $\space \space \space \space $ b) 101011 $\space \space \space \space $ c) 100101
(e) Compute the syndrome for each coset leader found in (c). (3 points)
(f) Decoding the following words with the syndromes of coset leader. (3 points)
$\space \space \space \space $ a) 101001 $\space \space \space \space $ b) 010011 $\space \space \space \space $ c) 100101

8、[10 points]Let N be a normal subgroup of a group, and let R be the following relation on G: aRb if and only if $a^{-2}b \in N$.
Prove that R is a congruence relation on G and N is the equivalence class [e] relative to R, where e is the identity of G.

9、[10 points]Let R = [2 x 1 matrices, $\square$], a, b, c, d are real number, where $$\begin{bmatrix} a \\ b \\ \end{bmatrix} \square \begin{bmatrix} c \\ d \\ \end{bmatrix} = \begin{bmatrix} a + c - 1 \\ b + d + 1 \\ \end{bmatrix}$$
Determine which of the following properties hold for this structure:
(a) Close
(b) Commutative
(c) Associative
(d) An identity element
(e) An inverse for every elment

10、[6 points]Given (Z, +) is an Abelian group. Prove that (Z x Z, *) is also an Abelian group. * is defined as $(a_1, b_1)*(a_2, b_2) = $(a_1 + a_2, b_1 + b_2).

11、[10 points]Consider a group $Z_6$, the operation table shown in following figure.
$$\begin{vmatrix}
    \bigoplus & [0] & [1] & [2] & [3] & [4] & [5] \\ [0] & [0]
 & [1] & [2] & [3] & [4] & [5] \\ [1]
 & [1] & [2] & [3] & [4] & [5] & [0] \\ [2] & [2] & [3] & [4] & [5] & [0] & [1] \\ [3] & [3] & [4] & [5] & [0] & [1] & [2] \\ [4] & [4] & [5] & [0] & [1] & [2] & [3] \\ [5] & [5] & [0] & [1] & [2] & [3] & [4]\end{vmatrix}$$
a) Find all of the normal subgroups of $Z_6$. (4 points)
b) Describe a congruence relation R on $Z_6$ and find a corresponding normal subgroup from (a). (3 points)
c) For this congruence relation R in (b). Write the operation table of quotient group $Z_6/R$. (3 points)
