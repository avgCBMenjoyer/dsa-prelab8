```mermaid
graph TD
A("1")
B("1")
A --> B
style A fill:#ded
style B fill:#dde
```
---
```mermaid
graph TD
A("1 * 2")
B("1 * 2")
A --> B
style A fill:#ded
style B fill:#dde
3(("*")) --> 1[1]
3(("*")) --> 2[2]
```
---
```mermaid
graph TD
A("1 * 2 + 3")
B("1 * 2 + 3")
A --> B
style A fill:#ded
style B fill:#dde
5(("+")) --> 3(("*"))
5(("+")) --> 4[3]
3(("*")) --> 1[1]
3(("*")) --> 2[2]
```
---
```mermaid
graph TD
A("1 + ( 2 * 3 )")
B("1 + 2 * 3")
A --> B
style A fill:#ded
style B fill:#dde
5(("+")) --> 1[1]
5(("+")) --> 4(("*"))
4(("*")) --> 2[2]
4(("*")) --> 3[3]
```
---
```mermaid
graph TD
A("( ( -2 ) )")
B("-2")
A --> B
style A fill:#ded
style B fill:#dde
```
---
```mermaid
graph TD
A("1 - 2")
B("1 - 2")
A --> B
style A fill:#ded
style B fill:#dde
3(("-")) --> 1[1]
3(("-")) --> 2[2]
```
---
```mermaid
graph TD
A("( 2 + 3 ) - 5")
B("2 + 3 - 5")
A --> B
style A fill:#ded
style B fill:#dde
5(("-")) --> 3(("+"))
5(("-")) --> 4[5]
3(("+")) --> 1[2]
3(("+")) --> 2[3]
```
---
```mermaid
graph TD
A("1 + 2 - 3 - 4 + 5")
B("1 + 2 - 3 - 4 + 5")
A --> B
style A fill:#ded
style B fill:#dde
9(("+")) --> 7(("-"))
9(("+")) --> 8[5]
7(("-")) --> 5(("-"))
7(("-")) --> 6[4]
5(("-")) --> 3(("+"))
5(("-")) --> 4[3]
3(("+")) --> 1[1]
3(("+")) --> 2[2]
```
---
```mermaid
graph TD
A("1 + 2 * 3 - 5")
B("1 + 2 * 3 - 5")
A --> B
style A fill:#ded
style B fill:#dde
7(("-")) --> 5(("+"))
7(("-")) --> 6[5]
5(("+")) --> 1[1]
5(("+")) --> 4(("*"))
4(("*")) --> 2[2]
4(("*")) --> 3[3]
```
---
```mermaid
graph TD
A("7 / 2 + 7 - 5 - 2")
B("7 / 2 + 7 - 5 - 2")
A --> B
style A fill:#ded
style B fill:#dde
9(("-")) --> 7(("-"))
9(("-")) --> 8[2]
7(("-")) --> 5(("+"))
7(("-")) --> 6[5]
5(("+")) --> 3(("/"))
5(("+")) --> 4[7]
3(("/")) --> 1[7]
3(("/")) --> 2[2]
```
---
```mermaid
graph TD
A("5 * 5 / 6 + 13 % 2 - 1")
B("5 * 5 / 6 + 13 % 2 - 1")
A --> B
style A fill:#ded
style B fill:#dde
11(("-")) --> 9(("+"))
11(("-")) --> 10[1]
9(("+")) --> 5(("/"))
9(("+")) --> 8(("%"))
5(("/")) --> 3(("*"))
5(("/")) --> 4[6]
3(("*")) --> 1[5]
3(("*")) --> 2[5]
8(("%")) --> 6[13]
8(("%")) --> 7[2]
```
---
```mermaid
graph TD
A("3 ^ 3 / 5")
B("3 ^ 3 / 5")
A --> B
style A fill:#ded
style B fill:#dde
5(("/")) --> 3(("^"))
5(("/")) --> 4[5]
3(("^")) --> 1[3]
3(("^")) --> 2[3]
```
---
```mermaid
graph TD
A("1 + 2 * 2 ^ 3 / 3")
B("1 + 2 * 2 ^ 3 / 3")
A --> B
style A fill:#ded
style B fill:#dde
9(("+")) --> 1[1]
9(("+")) --> 8(("/"))
8(("/")) --> 6(("*"))
8(("/")) --> 7[3]
6(("*")) --> 2[2]
6(("*")) --> 5(("^"))
5(("^")) --> 3[2]
5(("^")) --> 4[3]
```
---
```mermaid
graph TD
A("( 1 + 2 ) + ( 3 * 4 )")
B("1 + 2 + 3 * 4")
A --> B
style A fill:#ded
style B fill:#dde
7(("+")) --> 3(("+"))
7(("+")) --> 6(("*"))
3(("+")) --> 1[1]
3(("+")) --> 2[2]
6(("*")) --> 4[3]
6(("*")) --> 5[4]
```
---
```mermaid
graph TD
A("1 + ( 4 ^ 4 % 10 )")
B("1 + 4 ^ 4 % 10")
A --> B
style A fill:#ded
style B fill:#dde
7(("+")) --> 1[1]
7(("+")) --> 6(("%"))
6(("%")) --> 4(("^"))
6(("%")) --> 5[10]
4(("^")) --> 2[4]
4(("^")) --> 3[4]
```
---
```mermaid
graph TD
A("2 * ( 1 + 2 )")
B("2 * ( 1 + 2 )")
A --> B
style A fill:#ded
style B fill:#dde
5(("*")) --> 1[2]
5(("*")) --> 4(("+"))
4(("+")) --> 2[1]
4(("+")) --> 3[2]
```
---
```mermaid
graph TD
A("( 3 - 1 ) * ( 9 / ( 4 - 2 ) )")
B("( 3 - 1 ) * 9 / ( 4 - 2 )")
A --> B
style A fill:#ded
style B fill:#dde
9(("*")) --> 3(("-"))
9(("*")) --> 8(("/"))
3(("-")) --> 1[3]
3(("-")) --> 2[1]
8(("/")) --> 4[9]
8(("/")) --> 7(("-"))
7(("-")) --> 5[4]
7(("-")) --> 6[2]
```
---
```mermaid
graph TD
A("1 + 2 * 3 ^ 4 - 163 + 9")
B("1 + 2 * 3 ^ 4 - 163 + 9")
A --> B
style A fill:#ded
style B fill:#dde
11(("+")) --> 9(("-"))
11(("+")) --> 10[9]
9(("-")) --> 7(("+"))
9(("-")) --> 8[163]
7(("+")) --> 1[1]
7(("+")) --> 6(("*"))
6(("*")) --> 2[2]
6(("*")) --> 5(("^"))
5(("^")) --> 3[3]
5(("^")) --> 4[4]
```
---
```mermaid
graph TD
A("( ( ( ( 1 + 2 ) ) ) ) * ( ( ( ( 3 + 4 ) ) ) ) - 11 ")
B("( 1 + 2 ) * ( 3 + 4 ) - 11")
A --> B
style A fill:#ded
style B fill:#dde
9(("-")) --> 7(("*"))
9(("-")) --> 8[11]
7(("*")) --> 3(("+"))
7(("*")) --> 6(("+"))
3(("+")) --> 1[1]
3(("+")) --> 2[2]
6(("+")) --> 4[3]
6(("+")) --> 5[4]
```
---
```mermaid
graph TD
A("( 1 + 2 ) ^ ( 3 % 4 ) - 16")
B("( 1 + 2 ) ^ ( 3 % 4 ) - 16")
A --> B
style A fill:#ded
style B fill:#dde
9(("-")) --> 7(("^"))
9(("-")) --> 8[16]
7(("^")) --> 3(("+"))
7(("^")) --> 6(("%"))
3(("+")) --> 1[1]
3(("+")) --> 2[2]
6(("%")) --> 4[3]
6(("%")) --> 5[4]
```
---
```mermaid
graph TD
A("( ( ( 1 + 2 ) ) ) ^ ( ( ( 3 + ( 4 - 5 ) ) ) )")
B("( 1 + 2 ) ^ ( 3 + 4 - 5 )")
A --> B
style A fill:#ded
style B fill:#dde
9(("^")) --> 3(("+"))
9(("^")) --> 8(("+"))
3(("+")) --> 1[1]
3(("+")) --> 2[2]
8(("+")) --> 4[3]
8(("+")) --> 7(("-"))
7(("-")) --> 5[4]
7(("-")) --> 6[5]
```
---
```mermaid
graph TD
A("( 1 + 2 ) * ( 3 + 4 )")
B("( 1 + 2 ) * ( 3 + 4 )")
A --> B
style A fill:#ded
style B fill:#dde
7(("*")) --> 3(("+"))
7(("*")) --> 6(("+"))
3(("+")) --> 1[1]
3(("+")) --> 2[2]
6(("+")) --> 4[3]
6(("+")) --> 5[4]
```
---
```mermaid
graph TD
A("-1 ^ 2 * 3 + 4 + 5 * 6 ^ 2")
B("-1 ^ 2 * 3 + 4 + 5 * 6 ^ 2")
A --> B
style A fill:#ded
style B fill:#dde
13(("+")) --> 7(("+"))
13(("+")) --> 12(("*"))
7(("+")) --> 5(("*"))
7(("+")) --> 6[4]
5(("*")) --> 3(("^"))
5(("*")) --> 4[3]
3(("^")) --> 1[-1]
3(("^")) --> 2[2]
12(("*")) --> 8[5]
12(("*")) --> 11(("^"))
11(("^")) --> 9[6]
11(("^")) --> 10[2]
```
---
