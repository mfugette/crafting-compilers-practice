## Introduction Notes

- The term "little languages" refers to domain-specific languages such as YAML, SWIG, JSON, CSS, HTML, etc.
- "Self-hosting" refers to a compiler that operates via the language it itself is compiling.
- "Bootstrapping" refers to when you have a compiler for the language you are creating written in another language, and use it once to compile a compiler written in your own language, thus creating a self-hosted compiler.
    - e.g. I am creating language X, so I write a compiler for language X in language X, then use a compiler for language X written in language Y to compile it, resulting in a compiler for language X written in language X.

## Hello, world! - Java Edition

- This was as basic as basic gets, so I'll just show my code:

**Steps I ran:**

1. Install the JDK (in my case, JDK 25)
2. Write the class and main function
3. Enter parent folder via terminal
4. Run `javac [filename].java`\*; this compiles into `[filename].class` in the current directory
5. Run `java [filename]`
6. Hello, world!

\* In the case of this file, `filename` is `CraftingInterpretersJavaIntro`.

```java
public class CraftingInterpretersJavaIntro {
    public static void main() {
        System.out.println("Hello, world!");
    }
}
```

## C

- This made me realize that things aren't so bad in the world of web-dev. It also made me see that I'm nowhere near the programmer I should be.

### Pointers

I did not realize how rusty my knowledge of pointers had become (it's been nearly 8 years since I last had a reason to use them), so needless to say most of my time doing the challenge questions was spent re-learning this basic concept.

The following is a list of things I wrote down, not necessarily because I didn't already know them, but because I deal with them so infrequently that I thought it worthwhile to put onto paper to better etch into my brain.

**What I knew:**

- Pointer variables are simply variables that store a location in memory.

**What I forgot:**

- If memory addresses are to be thought of as numbers, they would be in the range of 0 to n-1.
- Executable programs consist of code (machine instructions corresponding to statements in the original C program) and data (variables in the original program).
- A variable may occupy one or more bytes of memory, so the address of the first byte is said to be the address of that variable.

**Why pointers?**

- Addresses might be represented by numbers, but their range of values may differ from that of integers, thus necessitating the use of pointer variables.
- Pointers are defined like any variable, except for the fact that they are preceded by an asterisk, such as in `int *p;`.
- `int *p` -> points to objects of type `int`
- `p` may, in some cases, point to a memory location that does not belong to a variable, hence the use of the term "object" (not to be confused with the OOP understanding).
- Pointers can point to other pointers, but they are typed; an `int *` should point to an `int`, an `int **` to an `int *`, and so on (`void *` being the exception).

### The Address Operator

- `&` is used to find the address of a variable.
- `&x` -> the address of `x` in memory

```c
int i, *p;
p = &i; // always assign p before use
```

- You can also initialize on declaration:

  ```c
  int i;
  int *p = &i;
  // or even
  int i, *p = &i;
  ```

- As long as `p` points to `i`, `*p` is an alias for `i`; changing one's value changes the other's as well.