# Functions

```
int func(int arg1, int arg2) {
    //BODY
    return 0;
}
```

## Arguments and Return Values

By convention, we use $a registers ($a0, $a1, etc) as our arguments and $v0 as our return value.

## Calling and Returning From Functions

To call a function:
1. Store the arguments in $a registers.
2. Use ```jal <function name>```, this jump and link command stores the next line of code as our return address and then jumps to the function label.

To return from a function:
1. Save the return value in $v0.
2. Use ```jr $ra``` to return to line after our function call.

## Stack Frame

![stack frame and function calls](stackframefunctioncall.png)

When we call another function, this function can change registers freely. To store data that we need, we store it at s registers by convention.

Note: we do not need to create and remove stack frames if we do not call other functions, i.e., leaf function.

```
    begin           # create a stack frame
    push    $ra     # store our return address on the stack so we know where to return to
    push    $s0

    // FUNC BODY

    pop     $s0     # pop things off the stack in reverse order as stacks as follow LIFO
    pop     $ra    
    end             # remove our stack frame  
```


Say we don't have stack frame:

max(int array[], int length)

max(0x0, 10):
$s0 = 1
    max(0x4, 9):
    $s0 = 2
        ...
            ...
    
...
$s0 = 2

