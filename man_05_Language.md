## Operators

Some is already shown.
```
a = a + b;
i = i + 1;
```
The above can be rewritten as;
```
a += b;
i++;
```
The unary operators;  `++ ` is an increment and there is also a decrement  `-- `.
Unary means that it operates on one variable.
Binary operators like  `+ ` work on two variables.

Now it becomes exiting!
```
i = 0;
a = (i++)*5;
b = (++i)*5;
```
What are a and b?

For a, we see that i is 0, so a is 0, but after (!) that i is incremented by 1.

For b, we see that i is 1 because it was incremented in the previous statement,
and it has  `++i ` so it is incremented before (!) the expression, so i becomes 2, so b is then 10.

The  `++ ` and  `-- ` have higher priorities than even  `* / %  `, so
it is not required to have it within brackets.

Would this work? No. The compiler doesn't know what to set to i in the last line (which of the 3 i's will when be incremented?).
```
i = 0;
i += i+++++i;
```

These operators can be used together with an assignment operator.
And these have the lowest priority.
```
Oper   Expr   Expr      
+=     a+=b   a=a+b
-=     a-=b   a=a-b
*=     a*=b   a=a*b
/=     a/=b   a=a/b
%=     a%=b   a=a%b

<<=    a<<=b  a=a<<b
>>=    a>>=b  a=a>>b
&=     a&=b   a=a&b
^=     a^=b   a=a^b
|=     a|=b   a=a|b
```

## Bitwise Operators

```
&    bitwise and
|    bitwise or
^    bitwise exclusive-or
<<   bitwise shift left
>>   bitwise shift right
~    1-complement (unary)
```

For this it is useful to know about bits and bytes.

See the 06_bits.c


## Ternary operator
We learned about unary and binary operators, and there is a ternary too.
It looks like a quick if-then-else expression using
 ` expression ? expression_true : expression_false `.

Examples;
```
a = -1;
str = a >= 0 ? "Positive" : "Negative";
x = a < b ? a+1 : b-1;
```

## Comma operator
Comma separator between expressions;
 ` expression1, expression2  `
are evaluated left to right, and the last one determines also the result. Function calls and assignments are also expressions.

```
s=0;
while (scanf("%d", &n), n>0) s+=n;
```

The two expressions in  `while() ` are evaluated left to right, so first a number can be entered, then it is tested if it is a positive number, and while it is, it is added to  `s `.
