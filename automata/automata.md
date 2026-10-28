# FA to RG converter

Finite automata for Poemia's identifiers and integer constants, plus a script that turns any FA into an equivalent regular grammar (FA -> RG).

[GitHub link](https://github.com/MonkeEmbracer/Formal-Languages-and-Compiler-Design)
## Definitions

**Finite automaton:** `M = (Q, Σ, d, q0, F)`

- `Q` - set of states
- `Σ` - alphabet
- `d` - transition function, `d(state, symbol) = next state`
- `q0` - initial state
- `F` - set of final states

A word is accepted if, starting from `q0` and following `d` symbol by symbol, we never hit a missing transition and end up in a state from `F`. Missing transitions mean an implicit dead state (reject).

**Regular grammar:** `G = (N, Σ, P, S)`

- `N` - nonterminals
- `Σ` - terminals (same alphabet as the FA)
- `P` - productions, only of the form `A -> aB` or `A -> a`
- `S` - start symbol

`S -> eps` is the only epsilon rule allowed, and only if `S` doesn't appear on the right side of any production.

**Character classes:** to keep things readable, transition labels like `A-Z`, `a-z`, `1-9` and `space` are treated as single symbols. Each one stands for all the characters in its range. Classes leaving the same state never overlap, so both FAs stay deterministic.

## FA 1 - Identifiers

Identifiers are one or more capitalised words separated by single spaces, e.g. `Bob`, `Old Bob`, `The Grey Wizard`.

```
Q = {p, q}
Σ = {A-Z, a-z, space}
d(p, A-Z) = q
d(q, A-Z) = q
d(q, a-z) = q
d(q, space) = p
q0 = p
F = {q}
```

|state|A-Z|a-z|space|
|---|---|---|---|
|-> p|q|-|-|
|* q|q|q|p|

(`->` marks the initial state, `*` marks final states.)

Examples:

- `(p, Bob) |- (q, ob) |- (q, b) |- (q, eps)` -> accepted
- `(p, bob)` -> no transition from `p` on `b` -> rejected
- `(p, "Bob ") |- ... |- (q, " ") |- (p, eps)` -> `p` isn't final -> rejected

## FA 2 - Integer constants

Integers are `0`, or an optional `-` followed by a nonzero digit and any digits. `-0`, `007` and a lone `-` are rejected.

```
Q = {a, b, c, d}
Σ = {0-9, 1-9, 0, -}
d(a, 0) = d
d(a, 1-9) = b
d(a, -) = c
d(c, 1-9) = b
d(b, 0-9) = b
q0 = a
F = {b, d}
```

|state|0|1-9|0-9|-|
|---|---|---|---|---|
|-> a|d|b|-|c|
|* b|-|-|b|-|
|c|-|b|-|-|
|* d|-|-|-|-|

Examples:

- `(a, -42) |- (c, 42) |- (b, 2) |- (b, eps)` -> accepted
- `(a, 0) |- (d, eps)` -> accepted
- `(a, 007) |- (d, 07)` -> no transition from `d` -> rejected

These FAs match the flex rules used by the scanner:

- identifiers: `[A-Z][A-Za-z]*( [A-Z][A-Za-z]*)*`
- integers: `0|-?[1-9][0-9]*`

## FA -> RG conversion

States become nonterminals and transitions become productions:

1. `N` = the states, uppercased (`p` -> `P`)
2. `Σ` stays the same
3. `S` = the initial state
4. For every transition `d(X, a) = Y`:
    - add `X -> a Y`
    - if `Y` is final, also add `X -> a`
5. If the initial state is final (the FA accepts the empty word), add a new start symbol `S'` with `S' -> eps`, plus copies of all the old start symbol's productions. `S'` never appears on a right side, so the epsilon rule stays legal. Neither of our FAs needs this, but the script handles it.

## The program

`main.py` asks for an input file (an FA in the format above) and an output file, reads the FA, converts it and writes the grammar.

How it works:

1. **Read.** Each line is matched by its prefix (`Q =`, `Σ =`, `d(`, `q0 =`, `F =`) and stored. Unknown lines are reported.
2. **Convert.** `fa_to_rg` runs the algorithm above. This happens only after the whole file is read, since we need `F` to know which stop rules to add.
3. **Write.** `N`, `Σ`, `S` and the productions go to the output file. Symbols in productions are space-separated.

## Results

Identifiers:

```
N = {P, Q}
Σ = {A-Z, a-z, space}
S = P
Productions:
    P -> A-Z Q
    P -> A-Z
    Q -> A-Z Q
    Q -> A-Z
    Q -> a-z Q
    Q -> a-z
    Q -> space P
```

There's no `Q -> space`, because `p` isn't final. You can't end on a space.

Derivation of `Old Bob`: `P => O Q => Ol Q => Old Q => Old space P => Old B Q => Old Bo Q => Old Bob`

Integers:

```
N = {A, B, C, D}
Σ = {-, 0, 0-9, 1-9}
S = A
Productions:
    A -> 0 D
    A -> 0
    A -> 1-9 B
    A -> 1-9
    A -> - C
    C -> 1-9 B
    C -> 1-9
    B -> 0-9 B
    B -> 0-9
```

`A -> 0 D` is a useless production. `d` is final but has no outgoing transitions, so `D` gets no productions and any derivation through it gets stuck. It's a normal side effect of the algorithm; the word `0` comes from `A -> 0`.

Example derivation of `-42`: `A => - C => -4 B => -42`
