

# ANSI SGR (SGR : Select Graphic Rendition)

## Unix Colors

> [!note] 
Color representation<br/>
>
>example : <br/>
linux bash grey color 840<br/>
\u{001B}[\(x);\(y);\(z)m or<br/>
\033[\(x);\(y);\(z)m
\n{001B}[\8;40m

SGR : Select Graphic Rendition

#### foreground (text, 16 colors)

- 30	noir
- 31	rouge
- 32	vert
- 33	jaune
- 34	bleu
- 35	magenta
- 36	cyan
- 37	blanc
- 90–97	versions claires

#### background

| code range | color                  |
|------------|------------------------|
| 40–47      | normal background      |
| 100–107    | highlighted background |

#### default colors

- 39 default test
- 49 default background

#### style attributes

| code | effect            | note                 |
|------|-------------------|----------------------|
| 0    | total reset       | /                    |
| 1    | bold              | sometimes "clear"    |
| 2    | weak              | not always supported |
| 3    | intalic           | not everywhere       |
| 4    | subligned         | /                    |
| 5    | clignotant        | almost deprecated    |
| 6    | /                 | /                    |
| 7    | reversed          | exchange fg/bg       |
| 8    | /                 | /                    |
| 9    | roded text        | /                    |
| 22   | normal (not bold) | /                    |
| 23   | not italic        | /                    |
| 24   | not sublined      | /                    |

#### arguments order

- [ styles; text; background ]

example : `\033[1;31;44m`

#### extended colors

text
`\033[38;5;N m`
background 
`\033[38;5;N m`
example
`\033[38;5;196;48;5;235m`

#### real rendered clors (24 bits - RGB)
###### not guaranteed support

text
`\033[38;2;R;G;B m`
backgroound
`\033[48;2;R;G;B m`
example :
`\033[38;2;255;100;0;48;2;20;20;20m`

#### impossible things

(not supported)

- transparency (alpha (RGBA))
- linear gradients
- shadows
- roundings (curbe corners)
- entanglement

#### good practices

Always 

- reset after usage `\033[0m`
- test support 256/RGB

never : 

- add more and more styles without reset
- suppose that bold = more lenght
- count on italic

#### recommendations

adding macros for manipulation (in c)

```c
#define ANSI_RESET   "\033[0m"
#define ANSI_BOLD    "\033[1m"
#define ANSI_FG_RED  "\033[31m"
#define ANSI_BG_GRAY "\033[100m"
```


<!-- end page  -->

