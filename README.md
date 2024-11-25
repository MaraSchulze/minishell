# Minishell
Implementation of a mini shell program in C as a group project in the 42 school core curriculum.  
We implemented a bash like behaviour with |, <, >, <<, >>, and '...' and "...".  
The shell has builtins like echo, cd, pwd, export, unset, env, exit.  
Also we implemented the signals CTRL+C, CTRL+D, CTRL+\, environment variables and exit codes.  
The shell can run headless.  

## Usage
This project was written for and compiled on a Mac.  
```
make
./minishell
```

## Caveats
In 42School we have to write our C programs according to a strict norm, which forces us to use only given functions, have no more than 25 lines in a function, use no for loops, don't use inline comments and so on. Thus the code may look unnecessary complicated in some respects to a professional C programmer.

## Thanks to
A great team partner and a very cool person, Felix (github.com/f321x).
