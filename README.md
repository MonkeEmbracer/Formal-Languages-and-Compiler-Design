# Poemia - Lexical Analysis

This is the lexer for Poemia, my story-based DSL from Lab 1. It reads a `.poem` program and spits out the PIF, the ST and any lexical errors.

[GitHub link](https://github.com/MonkeEmbracer/Formal-Languages-and-Compiler-Design)

## Files
- `lexer.l` – the Flex lexer (all the token rules + `main`)
- `st.h` / `st.c` – the symbol table, a hash table I implemented in C
- `tokens.txt – the list of tokens; a token's code is its line number (starting at 0)

## Building and running
```
flex lexer.l && gcc lex.yy.c st.c -o lexer
./lexer program.poem [tokens.txt]
```

The token list defaults to `tokens.txt` in the current folder. The run produces:
- `PIF.out` - the Program Internal Form
- `ST.out` - the Symbol Table
- lexical errors printed in the terminal (with line numbers), plus `Lexically correct` at the end if there were none

## How Flex is used

Flex takes `lexer.l` and generates `lex.yy.c`, which contains `yylex()`, a function that scans the input and runs the matching rule for each piece of text. The `.l` file has three parts separated by `%%`:
1. **Definitions** - C includes and globals, options (`noyywrap`, `yylineno` for line numbers), start conditions and named regexes like `ID` and `INT`
2. **Rules** - `pattern { C action }`. Every action calls `emit("TOKEN_NAME")`, which writes the token to the PIF
3. **User code** - loading `token.in`, `emit`, error reporting and `main`

Two Flex behaviours the whole lexer relies on:
- **Longest match** - if several rules match, the longest one wins. That's why `is reborn as` beats `is`, and `", of "` beats `", "`
- **Rule order** - on a tie, the rule written first wins. That's why some keyword rules sit above the identifier rule

### Start conditions (title and author)

The first two lines of a program follow different rules than the rest (lowercase letters, `_`, punctuation, etc.), so they're lexed in their own **exclusive start conditions** (`%x`), where only that state's rules are active:

```
TITLE --\n--> AUTHOR --"by "--> AUTHOR_NAME --\n--> INITIAL (the actual program)
```

`main` starts the lexer in `TITLE`. If line 2 doesn't start with `by` , you get an error and the lexer goes back to `INITIAL` so the rest of the program still gets lexed. The catch-all error rule is written as `<*>.` so it works in every state.

## Detecting tokens

### Keywords, operators, separators

Every keyphrase from the BNF is a literal string in a rule. All the variants that mean the same thing share one token, e.g. `became`, `turned into` and `shapeshifted into` are all `ASSIGN_MID`, and `plus` / `combined with` are both `OP_PLUS`. Most operators include their surrounding spaces, so spaces never need to be skipped separately. These tokens go into the PIF with ST position `-1`.

### Identifiers

```
IDWORD [A-Z][a-zA-Z]*
ID     {IDWORD}(" "{IDWORD})*
```

One or more words separated by single spaces, each starting with a capital letter (e.g. `Number Of Sacrifices`). Since keywords like `became` start with a space followed by a lowercase word, the identifier naturally stops right before them.

**The `If`/`Should` problem:** these two if-keywords look exactly like identifier words, so `If Big Worm` would get lexed as one identifier. I fixed it with trailing context:

```
"If "/{ID}
"Should "/{ID}
```

`r/s` means "match `r` only if `s` comes after it, but don't consume `s`". Flex counts the lookahead when comparing lengths, so this ties with the identifier rule, and since it's written first, it wins. The side effect is that **identifiers can't start with the words `If` or `Should`**.

### Constants

- **Integers** – `0|-?[1-9][0-9]*`. Leading zeros (`007`) and `-0` have their own error rule, otherwise they'd be silently split into several valid integers.
- **Strings** (print messages) – `\"{MSG_TEXT}\"`, where `MSG_TEXT` is the allowed message characters from the BNF. A quote with no closing quote on the same line is reported as an unterminated string. Strings are stored in the ST with their quotes.

Title and author are only tokens in the PIF; they don't go in the ST.

### Errors

Any character no rule matches hits `<*>.` and is reported with its line number. There are also specific errors for invalid integers, unterminated strings and a missing `by` line. The lexer keeps going after an error, so you see all of them in one run.

## Symbol Table

One ST holds identifiers, integer constants and string constants.

### Data structure

A **hash table with separate chaining**:

- an array of 101 buckets, each one being the head of a linked list
- each entry stores the lexeme (a copy of the text), its position, and a pointer to the next entry in the bucket
- the hash is `h = h * 31 + c` over the characters, starting from 0, then `% 101` (31 is the same multiplier Java's `String.hashCode()` uses)

Collisions are no problem, the entry just goes into the same list. The table doesn't rehash; at 101 buckets the chains stay tiny for programs this size.

Each new lexeme gets a **position** from a counter (0, 1, 2...) that never changes. There's also a `by_position` array (doubles in size when full) so the ST can be printed in position order.

### Operations

- `st_insert_or_get(lexeme)` – hashes the lexeme and walks its bucket. If it's already there, returns its position; otherwise adds a new entry and returns the new position. That way, every use of `Romeo` points to the same entry.
- `st_print(file)` – writes `position bucket lexeme` for every entry.
- `st_free()` – frees everything.

## PIF

The PIF is the program as a list of `(token code, ST position)` pairs, in order. Identifiers and constants get their ST position, everything else gets `-1`.

## Example

```
Love Story
by Bog

There was Romeo, a math wizard
One day, Romeo became 3 plus Romeo
An enamoured poet writes down his thoughts: "Hi!"
```

`ST.out`:

```
pos      bucket   lexeme
0        15       Romeo
1        51       3
2        94       "Hi!"
```

`PIF.out` (from the declaration line on):

```
code pos  token
7    -1   DECL_KW
0    0    IDENTIFIER       <- Romeo
8    -1   COMMA_SP
9    -1   TYPE_INT
6    -1   NEWLINE
11   -1   ASSIGN_KW
0    0    IDENTIFIER       <- Romeo again, same position
12   -1   ASSIGN_MID
1    1    INT_CONST        <- 3
13   -1   OP_PLUS
0    0    IDENTIFIER
6    -1   NEWLINE
41   -1   PRINT_KW
43   -1   PRINT_MESSAGE
2    2    STRING_CONST     <- "Hi!"
6    -1   NEWLINE
```

## Known limitations

- Identifiers can't start with `If` or `Should` (see above).
- A lowercase-starting identifier like `iLoveCamelCase` reports an error on the first letter, then the rest (`LoveCamelCase`) is read as a valid identifier.
- Windows `\r\n` line endings aren't supported, files need `\n`.