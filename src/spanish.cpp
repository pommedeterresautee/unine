#include <Rcpp.h>
#include <stdio.h>
#include <codecvt>
using namespace Rcpp;
using namespace std;

/*  Spanish stemmer tring to remove inflectional suffixes */

u16string removeSpanishAccent (u16string& word) {
  int len = word.size() - 1;
  int i;

  for(i=len; i>=0; i--) {
    if ((word[i]==u'à') || (word[i]==u'á') || (word[i]==u'â') || (word[i]==u'ä')) {
      word[i] = 'a';
    }
    if ((word[i]==u'ò') || (word[i]==u'ó') || (word[i]==u'ô') || (word[i]==u'ö')) {
      word[i] = 'o';
    }
    if ((word[i]==u'è') || (word[i]==u'é') || (word[i]==u'ê') || (word[i]==u'ë')) {
      word[i] = 'e';
    }
    if ((word[i]==u'ù') || (word[i]==u'ú') || (word[i]==u'û') || (word[i]==u'ü')) {
      word[i] = 'u';
    }
    if ((word[i]==u'ì') || (word[i]==u'í') || (word[i]==u'î') || (word[i]==u'ï')) {
      word[i] = 'i';
    }
  }
  return(word);
}

u16string spanish_word_stemmer(u16string word) {
  int len = word.size() - 1;

  if (len > 3) {
    removeSpanishAccent(word);
    if ((word[len]==u's') && (word[len-1]==u'e') && (word[len-2]==u's') && (word[len-3]==u'e')) {
      /*  corteses -> cortés  */
      word[len-1]='\0';
      return(word);
    }
    if ((word[len]==u's') && (word[len-1]==u'e') && (word[len-2]==u'c')) {
      word[len-2]='z';        /*  dos veces -> una vez  */
      word[len-1]='\0';
      return(word);
    }
    if (word[len]==u's') {  /*  ending with -os, -as  or -es */
      if (word[len-1]==u'o' || word[len-1]==u'a' || word[len-1]==u'e' ) {
        word[len-1]='\0';  /*  remove -os, -as  or -es */
      return (word);
      }
    }
    if (word[len]==u'o') {   /*  ending with  -o  */
      word[len]='\0';
      return(word);
    }
    if (word[len]==u'a') {   /*  ending with  -a  */
      word[len]='\0';
      return(word);
    }
    if (word[len]==u'e') {   /*  ending with  -e  */
      word[len]='\0';
      return(word);
    }
  } /* end if (len > 3) */
      return(word);
}

//' Stem Spanish words
//'
//' Stemmer for Spanish words
//'
//' @param words a [character] containing the original words.
//' @return [character] with stemmed words.
//' @examples
//' spanish_stemmer(c("perros"))
//' @export
// [[Rcpp::export]]
CharacterVector spanish_stemmer(Rcpp::StringVector words) {
  std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
  CharacterVector result(words.size());

  for (int i = 0; i < words.size(); ++i) {
    u16string str2 = convert.from_bytes(words[i]);
    str2 = spanish_word_stemmer(str2);
    result[i] = convert.to_bytes(str2);
  }

  return result;
}
