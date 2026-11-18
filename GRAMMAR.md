# Poemia Grammar Definition

[GitHub link](https://github.com/MonkeEmbracer/Formal-Languages-and-Compiler-Design)
## 1. Overview

The grammar is G = (N, Σ, P, S), written for an parser generator (yacc/bison). The scanner (flex) and parser split the work like this:

- **Scanner (flex):** recognises identifiers and constants (validated by finite automata), the title, the author and messages, and groups each list of synonymous keyword phrases into one token class (e.g. all 8 declaration phrases → `DECL_KW`). The spaces around a keyword phrase belong to its token (e.g. `plus`), and some punctuation–newline combinations are single tokens (e.g. `IF_OPEN` = `:` newline `'`). Other newlines are returned as `NEWLINE`. The title and author lines are lexed with start conditions.
- **Parser (bison):** works only on token classes, so the productions below describe the syntax, not the spelling.

The grammar was checked with bison: 0 shift/reduce and 0 reduce/reduce conflicts.

## 2. Terminals (Σ)

| Token | Lexemes |
| --- | --- |
| `TITLE` | the whole first line: a letter followed by letters, digits, space, `. ; , ! ? -` |
| `BY` | ` by  ` at the start of line 2 |
| `AUTHOR` | rest of line 2: a letter followed by letters, digits, space, `. , - _` |
| `NEWLINE` | newline |
| `IDENTIFIER` | one or more capitalised words separated by single spaces (e.g. `Bob The Great`), validated by the identifier FA |
| `INT_CONST` | `0`, or optional `-` followed by a nonzero digit and any digits, validated by the integer FA |
| `STRING_CONST` | a message between double quotes |
| `DECL_KW` | There once was / Let there be / There existed / Once upon a time, there was / There also was / There was / Unbeknownst to man, there also was / There shall be |
| `COMMA_SP` | ` ,  ` |
| `TYPE_INT` | a math wizard |
| `TYPE_QUEUE` | an eternal worm |
| `ASSIGN_KW` | Then, / One day, / Suddenly, / Surprisingly, / Shockingly, / As foretold, / Obviously, / To your dismay, / To their dismay, / Repeatedly, / Out of the blue, |
| `ASSIGN_MID` | became / turned into / turned / was reborn as / will turn to / turns into / becomes / shall become / shapeshifts into / shapeshifted into / shall shapeshift into / shall turn into / is reborn as |
| `OP_PLUS` | plus / added to / combined with / compounded with / merged with / along with |
| `OP_MINUS` | minus / without / subtracting |
| `OP_TIMES` | multiplied by / multiplied with / times |
| `OP_DIV` | divided by / shared between / given evenly to / split in |
| `LPAREN` / `RPAREN` | `(` / `)` |
| `CMP_GT` | is greater than / trumps / shall be greater than / surpasses / dwarfs / dwarfed / surpassed / was greater than / dwarf / be greater than |
| `CMP_GE` | is greater or equal to / shall be at least / is at least / was at least / be at least |
| `CMP_LT` | is smaller than / is trumped by / is dwarfed by / shall be smaller than / was dwarfed by / was smaller than / be dwarfed by |
| `CMP_LE` | is smaller or equal to / shall be smaller or equal to / is at most / shall be at most / was at most / be at most |
| `CMP_EQ` | is exactly / is precisely / is / mirrors / shall mirror / mirrored / was / be / was exactly / be exactly |
| `CMP_NE` | is different from / differs from / shall be different from / was different from / differ from |
| `OR` | or |
| `AND` | and |
| `BOOL_TRUE` | grass is green |
| `BOOL_FALSE` | black is white |
| `WORM_EMPTY` | is hungry / is famished |
| `IF_START` | They encountered a witch, who advised them carefully / They passed by a drunken sailor, who loudly shouted at them / Hearing the distant song of a bard, they approached to listen closely / You shall encounter an old lady, who will advise you the following / An old lady approaches, teary eyed, warning our heroes |
| `IF_OPEN` | `:` newline `'` |
| `IF_CONT` | Should / If (both only when an identifier follows) / Beware travellers, for if / Tread carefully, for if / Listen here, bastards! If / I curse you, peasants! If / So says the old song, that if / The townsfolk have been saying that / I heard that if |
| `COMMA_NL` | `,` newline |
| `IF_THEN` | Then the gods shall decree that / The legend says that / It is said that / I shall make sure that |
| `ELSE_KW` | Should the prophecy not be fulfilled, / Otherwise, / Should lady luck not be on your side, / Should the odds be in your favour, |
| `DOT` | `.` |
| `QUOTE_END` | `'` |
| `REPEAT_START` | Our heroes found themselves waking up every day to experience the following scenario exactly / They realised they had been dreaming the same strange dream every night / A curse has been cast upon our heroes, rendering them to repeat the following, mindlessly |
| `REPEAT_COLON` | `:` newline |
| `REPEAT_END` | But they realised they wouldn't go back to normal until / But they realised the condition to break the spell was that / But fortunately, they were able to break the curse under the condition that |
| `WORM_PUSH_START` | The eternal worm (starts both push and pop statements) |
| `WORM_PUSH_VERB` | has devoured / devours / shall devour |
| `WORM_PUSH_PREFIX` | Our dear |
| `WORM_PUSH_BY` | has been devoured by |
| `WORM_POP_VERB` | has released / releases / shall release / released |
| `WORM_POP_OBJ` | its earliest victim |
| `WORM_TOP` | the earliest victim of |
| `WORM_CLEAR_START` | Rejoice! / With a swift blow, / Blood of an eternal worm shall spill, |
| `WORM_CLEAR_END` | has been slain! / is slain / , by name |
| `READ_START` | The gods shall communicate the role / A voice is heard from above, speaking of the reborn / Struck by divine inspiration, / The gods have bestowed a new identity upon / A song only their ears can hear has inspired / Dissatisfied with their existence, |
| `READ_END` | shall take / is ready to take on a newfound identity / to find a new identity / has decided to look for their purpose in the stars |
| `PRINT_KW` | An enamoured poet writes down his thoughts / Channels across the globe broadcast breaking news / Words shall be written down for generations to come / A pale spectator hurried to town, to preach what he had found |
| `PRINT_MESSAGE` | ` :  ` |
| `PRINT_OF` | ` , of  ` |

## 3. Nonterminals (N)

program, stmt\_list, statement, decl\_stmt, type, assign\_stmt, expr, term, factor, add\_op, mul\_op, if\_stmt, else\_part, bool\_expr, bool\_term, bool\_factor, comparison, cmp\_op, repeat\_stmt, push\_stmt, pop\_stmt, clear\_stmt, read\_stmt, read\_end, print\_stmt, printable

## 4. Start symbol (S)

program

## 5. Productions (P)

The numbers are the ones the parser prints in its output (the string of productions).

```
 1  program      → TITLE NEWLINE BY AUTHOR NEWLINE stmt_list

 2  stmt_list    → stmt_list NEWLINE statement
 3  stmt_list    → statement

 4  statement    → decl_stmt
 5  statement    → assign_stmt
 6  statement    → if_stmt
 7  statement    → repeat_stmt
 8  statement    → print_stmt
 9  statement    → read_stmt
10  statement    → push_stmt
11  statement    → pop_stmt
12  statement    → clear_stmt
13  statement    → ε

14  decl_stmt    → DECL_KW IDENTIFIER COMMA_SP type
15  type         → TYPE_INT
16  type         → TYPE_QUEUE

17  assign_stmt  → ASSIGN_KW IDENTIFIER ASSIGN_MID expr

18  expr         → expr add_op term
19  expr         → term
20  term         → term mul_op factor
21  term         → factor
22  factor       → IDENTIFIER
23  factor       → INT_CONST
24  factor       → LPAREN expr RPAREN
25  factor       → WORM_TOP IDENTIFIER
26  add_op       → OP_PLUS
27  add_op       → OP_MINUS
28  mul_op       → OP_TIMES
29  mul_op       → OP_DIV

30  if_stmt      → IF_START IF_OPEN IF_CONT bool_expr COMMA_NL
                   IF_THEN NEWLINE stmt_list DOT else_part QUOTE_END
31  else_part    → NEWLINE ELSE_KW NEWLINE stmt_list DOT
32  else_part    → ε

33  bool_expr    → bool_expr OR bool_term
34  bool_expr    → bool_term
35  bool_term    → bool_term AND bool_factor
36  bool_term    → bool_factor
37  bool_factor  → comparison
38  bool_factor  → LPAREN bool_expr RPAREN
39  bool_factor  → BOOL_TRUE
40  bool_factor  → BOOL_FALSE
41  bool_factor  → IDENTIFIER WORM_EMPTY
42  comparison   → expr cmp_op expr
43  cmp_op       → CMP_GT
44  cmp_op       → CMP_GE
45  cmp_op       → CMP_LT
46  cmp_op       → CMP_LE
47  cmp_op       → CMP_EQ
48  cmp_op       → CMP_NE

49  repeat_stmt  → REPEAT_START REPEAT_COLON stmt_list NEWLINE REPEAT_END bool_expr

50  push_stmt    → WORM_PUSH_START IDENTIFIER WORM_PUSH_VERB expr
51  push_stmt    → WORM_PUSH_PREFIX expr WORM_PUSH_BY IDENTIFIER
52  pop_stmt     → WORM_PUSH_START IDENTIFIER WORM_POP_VERB WORM_POP_OBJ
53  clear_stmt   → WORM_CLEAR_START IDENTIFIER WORM_CLEAR_END
54  read_stmt    → READ_START IDENTIFIER read_end
55  read_end     → READ_END
56  read_end     → ε

57  print_stmt   → PRINT_KW PRINT_MESSAGE STRING_CONST
58  print_stmt   → PRINT_KW PRINT_OF printable
59  printable    → expr
60  printable    → bool_expr
```

## 6. Design notes

- Character-level rules moved to the scanner. The original BNF rules for identifiers, integers, title, author and message are regular, so they are flex patterns (plus FA validation) rather than productions.
- The LL-style `_rest` rules from the original BNF are rewritten left-recursive (rules 2, 18, 20, 33, 35), the natural form for LALR(1). Operator precedence comes from the expr → term → factor and bool\_expr → bool\_term → bool\_factor layering, so no `%left`/`%right` declarations are needed.
- Parentheses: `(` can open an integer or a boolean subexpression. LALR(1) resolves this by lookahead after the inner expression (`)` vs. a comparison operator), and bison reports no conflict.
- No dangling else. Every if statement is closed by `'`, so an else always belongs to the innermost open if.
- Empty statement (rule 13) allows blank lines and empty if/repeat blocks, as in the original BNF.
- `Should` / `If`. Identifiers may contain spaces between capitalised words, so the scanner matches these two `IF_CONT` phrases with trailing context (only when an identifier follows); otherwise longest match would read `If Bob` as one identifier.
- Bison reduces bottom-up, so the production numbers are emitted in reverse rightmost-derivation order. Reversing the list gives the rightmost derivation.
