# UNINE

[![Travis build status](https://travis-ci.org/pommedeterresautee/unine.svg?branch=master)](https://travis-ci.org/pommedeterresautee/unine)
[![Build status](https://ci.appveyor.com/api/projects/status/gole8beawqyw3tvy?svg=true)](https://ci.appveyor.com/project/pommedeterresautee/unine)
[![lifecycle](https://img.shields.io/badge/lifecycle-maturing-blue.svg)](https://www.tidyverse.org/lifecycle/#maturing)

Implementation of "light" stemmers for French, German, Italian, Spanish, Portuguese, Finnish, Swedish.  
They are based on the same work as the "light" stemmers found in [SolR](https://github.com/apache/lucene-solr/blob/master/lucene/analysis/common/src/java/org/apache/lucene/analysis/fr/FrenchLightStemmer.java) or [ElasticSearch](https://www.elastic.co/guide/en/elasticsearch/reference/current/analysis-stemmer-tokenfilter.html).  

A "light" stemmer (removing inflections only for noun and adjectives) presents some advantages.  

The procedures used in this stemmer are described below:  

* The stemming procedure for French is described in (Savoy, 1999).  
*  In Italian, the main inflectional rule is to modify the final character (e.g., «-o», «-a» or «-e») into another (e.g., «-i», «-e»). As a second rule, Italian morphology may also alter the final two letters (e.g., «-io» in «-o», «-co» in «-chi», «-ga» in «-ghe»).  
* In German, a few rules may be applied to obtain the plural form of words (e.g., "Frau" into "Frauen" (woman), "Bild" into "Bilder" (picture), "Sohn" into "Söhne" (son), "Apfel" into "Äpfel" (apple)), but the suggested algorithms do not account for person and tense variations, or for the morphological variations used by verbs.  

Indexing verbs for Italian, French or German is not of primary importance compared to nouns and adjectives.

## Installation

You can install the released version of unine from [CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("unine")
```

## Example

``` r
french_stemmer(words = c("complète", "caissière"))
# [1] "complet"  "caissier"

french_stemmer(words = c("tester", "testament", "chevaux", "aromatique", "personnel", "folle"))
# [1] "test"      "testament" "cheval"    "aromat"    "personnel" "fou" 

# look at how "testament" and "tester" have been stemmed. Now with porter stemmer :
SnowballC::wordStem(c("testament", "tester"), language = "french")
# [1] "test" "test"

```

References
----------

Please cite [1](#a-stemming procedure-and-stopword-list-for-general-french-corpora) if using this R package.

### A stemming procedure and stopword list for general French corpora

[1] J. Savoy, [*A stemming procedure and stopword list for general French corpora*](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.87.7093&rep=rep1&type=pdf)

```
@article{savoy1999stemming,
  title={A stemming procedure and stopword list for general French corpora},
  author={Savoy, Jacques},
  journal={Journal of the American Society for Information Science 50(10), 944-952.},
  year={2009}
}
```
