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
The unary operators; ```++``` is an increment and there is also a decrement ```--```.
Unary means that it operates on one variable.
Binary operators like ```+``` work on two variables.

Now it becomes exiting!
```
i = 0;
a = (i++)*5;
b = (++i)*5;
```
What are a and b?

For a, we see that i is 0, so a is 0, but after (!) that i is incremented by 1.

For b, we see that i is 1 because it was incremented in the previous statement,
and it has ```++i``` so it is incremented before (!) the expression, so i
becomes 2, so b is then 10.

The ```++``` and ```--``` have higher priorities than even ```* / % ```, so
it is not required to have it within brackets.

Would this work? No. The compiler doesn't know what to set to i in the last line.
```
i = 0;
i += i+++++i;
```

These operators can be used together with an assignment operator.
And these have the lowest priority.
```
+=
-=
*=
/=
%=

// to be discussed later
<<=
>>=
&=
^=
|=
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

## Ternary operator
We learned about unary and binary operators, and there is a ternary too.
It looks like a quick if-then-else expression using
``` expression ? expression_true : expression_false```.

```
a = -1;
str = ( a >= 0 ) ? "Positive" : "Negative";
```
