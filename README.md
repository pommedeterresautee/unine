![UNINE](https://github.com/pommedeterresautee/unine/raw/master/tools/logo_unine.png) 
=========

[![Travis build status](https://travis-ci.org/pommedeterresautee/unine.svg?branch=master)](https://travis-ci.org/pommedeterresautee/unine)
[![Build status](https://ci.appveyor.com/api/projects/status/gole8beawqyw3tvy?svg=true)](https://ci.appveyor.com/project/pommedeterresautee/unine)
[![Coverage status](https://codecov.io/gh/pommedeterresautee/unine/branch/master/graph/badge.svg)](https://codecov.io/github/pommedeterresautee/unine?branch=master)
[![CRAN status](https://www.r-pkg.org/badges/version/unine)](https://cran.r-project.org/package=unine)
[![lifecycle](https://img.shields.io/badge/lifecycle-maturing-blue.svg)](https://www.tidyverse.org/lifecycle/#maturing)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Implementation of "light" stemmers for **French, German, Italian, Spanish, Portuguese, Finnish, Swedish**.  
They are based on the same work as the "light" stemmers found in [SolR](https://github.com/apache/lucene-solr/blob/master/lucene/analysis/common/src/java/org/apache/lucene/analysis/fr/FrenchLightStemmer.java) or [ElasticSearch](https://www.elastic.co/guide/en/elasticsearch/reference/current/analysis-stemmer-tokenfilter.html).  
A "light" stemmer consists in removing inflections only for noun and adjectives.  
Indexing verbs for these languages is not of primary importance compared to nouns and adjectives. 

The procedures used in this stemmer are described below:  

* the stemming procedure for French is described in (Savoy, 1999).  
* in Italian, the main inflectional rule is to modify the final character (e.g., «-o», «-a» or «-e») into another (e.g., «-i», «-e»). As a second rule, Italian morphology may also alter the final two letters (e.g., «-io» in «-o», «-co» in «-chi», «-ga» in «-ghe»).  
* in German, a few rules may be applied to obtain the plural form of words (e.g., "Frau" into "Frauen" (woman), "Bild" into "Bilder" (picture), "Sohn" into "Söhne" (son), "Apfel" into "Äpfel" (apple)), but the suggested algorithms do not account for person and tense variations, or for the morphological variations used by verbs.  

Online tests are available [on this website](http://yomguithereal.github.io/talisman/stemmers/french).

### Installation

You can install the released version of unine from [CRAN](https://CRAN.R-project.org) with: (**NOT YET PUBLISHED**)

``` r
install.packages("unine")
```

... or the last version from [Github](https://github.com/pommedeterresautee/unine)

``` r
devtools::install_github("pommedeterresautee/unine")
```


### Example

Below some examples for French and a comparaison with Porter French stemmer.

``` r
french_stemmer(words = c("complète", "caissière"))
# [1] "complet"  "caisier"
# Not that below double letters are deduplicated: caissière -> caisier

french_stemmer(words = c("tester", "testament", "chevaux", "aromatique", "personnel", "folle"))
# [1] "test"      "testament" "cheval"    "aromat"    "personel" "fou" 
# Not that below double letters are deduplicated: personnel -> personel

# look at how "testament" and "tester" have been stemmed above. 
# Now with Porter stemmer :
SnowballC::wordStem(c("testament", "tester"), language = "french")
# [1] "test" "test"

```

### References

Please cite [1] if using this R package.

[1] J. Savoy, [*A stemming procedure and stopword list for general French corpora*](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.87.7093&rep=rep1&type=pdf)

```
@article{savoy1999stemming,
  title={A stemming procedure and stopword list for general French corpora},
  author={Savoy, Jacques},
  journal={Journal of the American Society for Information Science 50(10), 944-952.},
  year={2009}
}
```
