# Poemia Docs

Hi. I'm Bogdan, and this is how my DSL, Poemia, works.
It's a computational math language that allows you to write the code in various, story-based ways.

# Elements explained
### Program structure
Every Poemia program must have:
- A title, written on the first line of the program
- An authorship subtitle, written on the second line of the program (`by (...)`)
- The program's statements, separated by new line characters

### Declaring a variable
You may declare a variable using various keywords (or rather keyphrases heh), such as `There once was` or `There shall be`.

The structure of the declaration statement is as follows:
- Declaration keyword
- Variable name
- Variable type

Example:
`Once upon a time, there was Bogdan, a math wizard`

### Variable names
Variable names can contain multiple words, separated by spaces, and the separate words MUST start with a capital letter. They're proper names, after all!

Examples of valid variable names: `Radiohead`, `An Amazing Variable`, `A A A A A A AaaaAAAA`

Examples of bad variable names: `variable`, `iLoveCamelCase`, `snake_case_too`, `I Sometimes Forget to Capitalise My Words`

### Variable types
Currently, there are two big variable types:
- Math wizards 
	- Boring name: Integers
- Eternal worms
	- Boring name: Queues

You know integers. We'll tackle eternal worms later.

### Assignment statements
You may assign various integer values and expressions to your math wizard variables.

Statement structure:
- Intro keyword (e.g. `Then,`, `One day, `)
- Variable name
- Middle keyword (e.g. `became`, `turned`)
- Integer expression

Example:
`Suddenly, Cosmin shapeshifted into 6 times 6`

### Integer expressions
You may write arithmetic expressions that include any integer values and the usual operands.

Supported operations and some (not all!) ways to express them:
- Addition -- `plus`, `added to`, `combined with`
- Subtraction -- `minus`, `without`, `subtracting`
- Multiplication -- `multiplied by`, `times`
- Division -- `divided by`, `given evenly to`, `shared between`

### Boolean expressions
You may write boolean expressions using various elements:
- AND/OR operators (`or`/`and`)
- Comparison expressions
- True/False values (`grass is green`/`black is white`)

Comparison operators supported, with some ways to express them:
- Greater than -- `is greater than`, `trumps`, `surpasses`
- Greater or equal than -- `is at least`, `is greater or equal to`
- Smaller than -- `is smaller than`, `is dwarfed by`, `is trumped by`
- Smaller or equal than -- `is at most`, `is smaller or equal to`
- Equality -- `is`, `is exactly`, `mirrors`
- Inequality -- `is different from`, `differs from`

### Decision statements
Decision statements are perhaps the ones that allow the most freedom and creativity! You can mix and match the various keywords to make the story yours!

Statement structure:
- Intro keyword
- Continuation keyword
- Condition
- Statement block
- Optional else keyword + block

Example:
```
They encountered a witch, who advised them carefully:
'Tread carefully, for if Your Variable is greater than My Variable split in 2,
I shall make sure that
To your dismay, Your Variable turns into My Variable.
Should the odds be in your favour,
Then, My Variable shall turn into Your Variable.'
```

### Loop statements
Loop statements are fairly simple -- they allow you to run a block of code repeatedly until the condition is met (it's a `repeat ... until`, if you will).

Statement structure:
- Intro keyword
- Statement block
- End keyword (always starting with `But`)
- Condition

Example:
```
A curse has been cast upon our heroes, rendering them to repeat the following, mindlessly:
Repeatedly, Codrin becomes Codrin times Codrin
But fortunately, they were able to break the curse under the condition that Codrin is at least Dede
```

### Eternal worms
Eternal worms are, at their core, spicy queue data structures.

The following operations are available on eternal worms:
- Devour (push)
	- Example: `The eternal worm Bogdan devours Connecticut`
- Release (pop)
	- Example: `The eternal worm Bogdan has released its earliest victim`
- Peek/Top (it's an expression!)
	- Example: `the earliest victim of Bogdan`
- Slay (clear)
	- Example: `Rejoice! Bogdan has been slain!`
- Is Hungry (empty) (also, this one's an expression too)
	- Example: `Bogdan is hungry`

### Input/Output operations
Read and write statements are very straightforward.

You may read an integer value into a variable using various keywords.

Example:
`The gods shall communicate the role Your Variable shall take`

You may print out both integer or boolean expressions, as well as messages!

Examples:
- Integer expression: `An enamoured poet writes down his thoughts, of Positive Numbers Count`
- Message: `A pale spectator hurried to town, to preach what he had found: "Suntem cooked"`

# Sample programs
### Mystery program #1
```
An Old Poem
by anonymous_poet213

Once upon a time, there was Romeo, a math wizard
There also was Juliet, a math wizard

A song only their ears can hear has inspired Romeo to find a new identity
Dissatisfied with their existence, Juliet has decided to look for their purpose in the stars

Let there be Love, a math wizard
One day, Love was reborn as Romeo combined with Juliet

An enamoured poet writes down his thoughts, of Love
```

### Mystery program #2
```
Please
by Yours Truly

There once was My Grade, a math wizard
The gods shall communicate the role My Grade shall take

An old lady approaches, teary eyed, warning our heroes:
'Should My Grade be dwarfed by 5,
The legend says that
Words shall be written down for generations to come: "Its so over".'
```

### Mystery program #3
```
Gory Tale
by Shakespeare

Once upon a time, there was Claudiu, an eternal worm
There also was Claudia, an eternal worm

There was Counter, a math wizard
There also was Number Of Sacrifices, a math wizard
Unbeknownst to man, there also was Cosmin, a math wizard

The gods shall communicate the role Number Of Sacrifices shall take
One day, Counter became 0

A curse has been cast upon our heroes, rendering them to repeat the following, mindlessly:
Struck by divine inspiration, Cosmin is ready to take on a newfound identity
The eternal worm Claudiu devours Cosmin
Obviously, Counter is reborn as Counter compounded with 1
But fortunately, they were able to break the curse under the condition that Counter mirrored Number Of Sacrifices

Shockingly, Counter became 0

They realised they had been dreaming the same strange dream every night:
A voice is heard from above, speaking of the reborn Cosmin
The eternal worm Claudia devours Cosmin
Repeatedly, Counter turns into Counter merged with 1
But they realised the condition to break the spell was that Counter was exactly Number Of Sacrifices

Let there be Pickles, an eternal worm
Let there be Vessel One, a math wizard
Let there be Vessel Two, a math wizard

Our heroes found themselves waking up every day to experience the following scenario exactly:
Out of the blue, Vessel One shapeshifted into the earliest victim of Claudiu
Suddenly, Vessel Two turned into the earliest victim of Claudia
The eternal worm Claudiu released its earliest victim
The eternal worm Claudia released its earliest victim

To their dismay, Cosmin was reborn as Vessel One combined with Vessel Two
They passed by a drunken sailor, who loudly shouted at them:
'Listen here, bastards! If Cosmin split in 2 multiplied by 2 is precisely Cosmin,
Then the gods shall decree that
The eternal worm Pickles shall devour Cosmin
Words shall be written down for generations to come, of Cosmin
Channels across the globe broadcast breaking news: " ".'

But they realised they wouldn't go back to normal until Claudiu is hungry or Claudia is famished
```

