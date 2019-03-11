# unine

Implementation of "light" stemmers for French, German, Italian, Spanish, Portuguese, Finnish, Swedish based on the work described.  
A "light" stemmer (removing inflections only for noun and adjectives) presents some advantages.  
The stemming procedure for French is described in (Savoy, 1999).  
In Italian, the main inflectional rule is to modify the final character (e.g., «-o», «-a» or «-e») into another (e.g., «-i», «-e»).  
As a second rule, Italian morphology may also alter the final two letters (e.g., «-io» in «-o», «-co» in «-chi», «-ga» in «-ghe»).  
In German, a few rules may be applied to obtain the plural form of words (e.g., "Frau" into "Frauen" (woman), "Bild" into "Bilder" (picture), "Sohn" into "Söhne" (son), "Apfel" into "Äpfel" (apple)), but the suggested algorithms do not account for person and tense variations, or for the morphological variations used by verbs.  
Indexing verbs for Italian, French or German is not of primary importance compared to nouns and adjectives.

## Installation

You can install the released version of unine from [CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("unine")
```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
## basic example code
```

