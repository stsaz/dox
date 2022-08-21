# About C programming

This is a theoretical information about C language and native programming in general - if you are already familiar with basics, feel free to skip it and go straight to the next practical lesson.

Contents:

* Fundamental information
* Why use C
* Why not to use C
* The problem with C++


## Fundamental information

First of all, there are several fundamental things we need to define.

* *C* is a programming language meaning that we can use C to write a computer program the same way as we use English to write a sentence.
* *Computer* is a set of electronics (power supply, motherboard, CPU, memory and Input-Output (I/O) devices) that can run programs.
* *Computer program* is actually a set of CPU instructions that solve a particular task.
* *CPU* (Central Processing Unit) is a small but the most complex thing inside computer that operates with numbers and executes commands.
* *Motherboard* connects all computer hardware together so that CPU can issue commands to all devices and receive signals from them.
* Keyboard and mouse are examples of *input devices*; monitor and audio system are examples of *output devices*.
Every device works through its *device driver* - a kernel-level program that translates software commands to the hardware and vice versa.
* But CPU doesn't know what to do (it just executes instructions) - it needs a program that constantly tells it what to do and how to operate with computer memory and devices.
*OS* (Operating System) is that kind of a program - it's a large set of programs including boot loader, kernel, device drivers and essential apps.
It takes control when computer boots up and provides a user interface so that we can issue commands to our computer through the software that operates on top of OS (*userspace software*).
And C is a language we can use to create such software - we'll learn how to do it through this course.
* OS provides *API* (Application Programming Interface - a set of C header files with functions and constants) so that native programming languages can communicate with OS through this API.
When we say "the program asks OS" to do something, it actually means that our program calls a function from this API.
(To be precise: userspace API that we use on Linux isn't exactly a part of OS kernel, but rather it's the standard C library - *libc*, which in turn calls system functions (*syscalls*).)


## Why use C

The advantages of C over other languages:

* C isn't a complex language: it has a short set of keywords and a few standard operators, it has a plain and simple control flow without any surprises (no hidden/automatic instructions).
* C programs can run on everything that has a CPU, even if there's no OS.
* C is a native language meaning that C programs can directly communicate with computer hardware and OS.
* C programs are usually very fast, need less hardware resources (CPU power, memory size), use hardware resources more effectively and thus conserve energy.
And one of the reasons behind this statement is that C programmers usually know what they're doing from the bottom to the top.
* It's easier to learn any other language if we already know C, because it means that we at least understand how CPU and memory function and how OS processes work.
* The most popular open-source OS kernel (Linux) is written in C.
* Most device drivers are written in C.
* Most popular high performance server software is written in C.
* Many complex algorithms such as video, audio, text, image compression are originally written in C.


## Why not to use C

The disadvantages of C are:

* C compilers don't check the programmer for his potential mistakes.
Instead, C compiler just believes the programmer knows what he's doing.
In C world programmer is in control and everything else is just a tool in his hands.
Although modern compilers usually warn us about some kinds of small mistakes, it's still not enough.
In other words, to be able to program in C we have to be careful and persistent enough to achieve our goal.
* Most other languages provide the means to automatically release unused resources (in C++ - via class destructors, in Go - via garbage collector).
In C we do everything ourselves, it doesn't do anything automatically.
* It takes more time to write code when operating on many dynamic entities (e.g. in GUI applications or database-driven applications) - Object Oriented Programming (OOP) languages such as C++ seem better in this case.
* Sometimes it's hard to find the right library to use in our program because there's no standard way or place to do so.
Sometimes there's no cross-platform library that implements the necessary feature set at all.
* C isn't JavaScript: it can't be used to run client-side scripts in web browser.

As we can see, some disadvantages of C are not the problem of language itself, but rather its environment.


## The problem with C++

C++, like C, is another native language sharing the same advantages but also it adds numerous other advantages.
In fact, there are so many advantages in C++ over C, that it becomes difficult to choose what means we should use to solve a particular task which is so obvious to do in C, and it's like these advantages actually become disadvantages.
C++ language is so complicated that large companies such as Google have a really huge list of rules on what *not* to use in C++ and how to use the rest of it properly.
Isn't it better to use plain C in the first place instead of trying to remember all those rules that restrict C++?
As for me, since I stopped writing in C++ and started writing in C my programs have become clearer to me and easier to fix and improve.
But nevertheless, C++ has a wide application area and it's a very powerful and convenient tool when used properly.
And even if your language of choice is C++ these lessons can help you to start programming in it, because we can roughly say that C++ is just an improved C, and the things I explain through this course usually apply to both languages.
