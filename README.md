# ft_printf
## Description

This repository will hold all the information I have in regards to ft_printf. This project aims to recreate some of the aspects of the C function printf. Here I shall document my work via commit messages that describe what I have done and also within this readme file. This will be my first attempt at writing a somewhat proper readme where I describe my work, my code and what new things this project taught me and perhaps can teach you some day. If you are a 42 student have fun reading through it. Many might disagree with my mentality regarding this. But we learn from eachother. If you copy my code that is okay. Just try to understand it yourself. Try to figure out other solutions if you can. For example think about how a structure could of made my life easier or how to implement the bonuses which would mean redesigning some of the core functions and static helper functions here. 

## Table of Contents

- [ft_printf](#ft_printf)
- [Description](#description)
- [Knowledge Gained](#Knowledge-Gained)
- [Explanation of Code](#Explanation-of-Code)
- [Installation](#installation)
- [Usage](#usage)
- [Inspirations And Thank Yous](#inspirations-and-thank-you)

### Knowledge-Gained

I learnt so much during this project about so many new topics. It's hard to even know where to start. 

1.  The first new concept was that I could give a function the ... (From what I know it's called an Ellipsis?). Here is all I know about it.
    -  Firstly it is used to denote ranges, an unspecified number of arguments.
    - It is part of the syntax for creating functions with a variable number of parameters. Uncertain if there is a way to use it without the va functions provided by the library stdarg.h.
    - We can see a similarity with the argc and argv parameters when using a main function. Where they represent the amount of command-line arguments passed to the program.

2.  Secondly the VA functions. Also known as the variadic functions. I personally only used four and I will describe them below.
    - va_list This is the type used to declare a variable that will hold the information needed by the other va_ functions to iterate over the variable arguments.
    - va_start Initializes a va_list variable to point to the first variable argument.
    - va_end Finalizes the use of the variable argument list, performing any necessary cleanup.
    - va_arg Retrieves the next argument of a specified type from the variable argument list. It also advances the va_list to the next argument.
    - Variadic functions are commonly used in scenarios where the number or types of arguments are determined at runtime, such as in functions like printf and scanf. They provide flexibility and are a powerful tool for designing functions that can handle a wide range of parameters and inputs. Super cool stuff.
3.  I also learnt how to navigate pointers better and using the & symbol more (called the Address-of Operator) The & symbol is used to obtain the memory address of a variable. For example, if x is a variable, then &x gives the address of x.
    - This for example has helped in regards of counting how long something is. Say I have a function that has a paramater set as (int *x) and I only ever call up this function inside of another or something akin to that. I can just have a regular integer variable there and give the function (&x) to modify x but return some other value or not return anything and just modify x.
    - Useful cases for this can be with structures for example. Or with arrays where functions can modify parts of the array and you can afterwards use if statements to check on the results.
    - a hard learnt lesson was the importance of parentheses and operator precedence. Like ++ takes precedence over * which means for example *digit++ increments the pointer itself not the value it points to. while (*digit)++ increments the value it points to. 
4.  I also learnt the hard lesson to perhaps take into account everything before beginning on a project. Consider it's difficulties, consider your options, read the documentation, etc. before striking out. You will save yourself a lot of trouble in the future if I can keep that in mind.
5.   I learnt that the putchar function. The very first we ever made is basically useless. Write can be just used as is and as such putchar has no need. I left it here as a testiment and constrast to just using write instead and in hopes to not muck up my work as it works as intended. In the future I most likely shall not use putchar in anything anymore.
6.   I learnt how to make and use the .gitignore file. All this time I was just careful with what I uploaded for my projects. But the .gitignore is such a nice extra layer of protection. It's easy to use and really fun.
7.   I learnt how to make more slightly more complex Makefiles as well. Super duper fun and here are the new things I learnt in regards to Makefiles:
     - So one of the main things was creating sub_folders instead of just having them within the root of the repository. So sources instead of just being src_name.c is now set up like $(SRCDIR)/src_name.c
     - Another fun one is the notdir function. Basically it removes the directory portion of a path.  Addprefix is kind of like the opposite. It adds a prefix aka like the directory to file names.
     - And through stuff like that I was able to generate object files into a seperate object file folder.
     - Or how I can use -p with mkdir to not produce an error if the directory already exists.
8.  In general this was a very rewarding experience. In the end I am also learning this right here. Learning how to write a readme. Hopefully I can produce a decent one.
     
