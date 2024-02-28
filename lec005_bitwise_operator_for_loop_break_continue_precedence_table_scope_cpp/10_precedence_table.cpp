//Highest	::	Scope resolution
/*

        | () [] -> .             | Function call, array subscripting, member access
        | ++ --                  | Postfix increment, postfix decrement
        | typeid                 | Type identification
        | dynamic_cast           | Run-time type checking
        | static_cast            | Type casting
        | reinterpret_cast       | Type casting
        | const_cast             | Type casting
        | new, new[]             | Dynamic memory allocation
        | delete, delete[]       | Dynamic memory deallocation
        | sizeof                 | Size of type or object
        | ~                      | Bitwise NOT
        | !                      | Logical NOT
        | +, -                   | Unary plus, unary minus
        | ++ --                  | Prefix increment, prefix decrement
        | &                      | Address-of
        | *                      | Indirection (dereference)
        | +, -                   | Addition, subtraction
        | /, %                   | Division, modulus
        | +, -                   | Unary plus, unary minus (binary)
        | <<, >>                 | Bitwise shift left, bitwise shift right
        | <, <=, >, >=           | Relational less than, less than or equal, greater than, greater than or equal
        | ==, !=                 | Relational equal to, not equal to
        | &                      | Bitwise AND
        | ^                      | Bitwise XOR
        | |                      | Bitwise OR
        | &&                     | Logical AND
        | ||                     | Logical OR
        | ?:                     | Ternary conditional
        | =, +=, -=, *=, /=, %=  | Assignment and compound assignment
        | ,                      | Comma





Lowest | |

Operators with higher precedence are evaluated 
before operators with lower precedence. 
In case of the same precedence, the associativity determines 
the order of evaluation. For example, in the expression a + b - c, 
the addition (+) and subtraction (-) operators have the same precedence, 
but the left-to-right associativity ensures that a + b is evaluated first.

It's important to note that parentheses ( ) 
can be used to override the default precedence 
and force a specific order of evaluation.
*/