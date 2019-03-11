#include <Rcpp.h>
#include <stdio.h>
#include <codecvt>
using namespace Rcpp;
using namespace std;

/*  Italian stemmer tring to remove inflectional suffixes */


static void removeItalianAccent(u16string& word) {
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
}

static u16string italian_stemming(u16string word) {
  int len = word.size() - 1;

  if (len > 4) {
    removeItalianAccent(word);
    if (word[len]==u'e') {  /*  ending with -ie or -he  */
if (word[len-1]==u'i' || word[len-1]==u'h') {
  word[len-1]=u'\0';
  return (word);
}
word[len]=u'\0';  /*  ending with -e  */
return(word);
    }
    if (word[len]==u'i') {  /*  ending with -hi or -ii */
if ((word[len-1]==u'h') || (word[len-1]==u'i')) {
  word[len-1]=u'\0';
  return (word);
}
word[len]=u'\0';  /*  ending with -i  */
return(word);
    }
    if (word[len]==u'a') {  /*  ending with -ia  */
if (word[len-1]==u'i') {
  word[len-1]=u'\0';
  return (word);
}
word[len]=u'\0';  /*  ending with -a  */
return(word);
    }
    if (word[len]==u'o') {  /*  ending with -io  */
if (word[len-1]==u'i') {
  word[len-1]=u'\0';
  return (word);
}
word[len]=u'\0';  /*  ending with -o  */
return(word);
    }

  } /* end if (len > 4) */
return(word);
}

//' Stem Italian words
//'
//' Stemmer for Italian words
//'
//' @param words a [character] containing the original words.
//' @return [character] with stemmed words.
//' @examples
//' italian_stemmer(c("arrivederci"))
//' @export
// [[Rcpp::export]]
CharacterVector italian_stemmer(Rcpp::StringVector words) {
  std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
  CharacterVector result(words.size());

  for (int i = 0; i < words.size(); ++i) {
    u16string str2 = convert.from_bytes(words[i]);
    str2 = italian_stemming(str2);
    result[i] = convert.to_bytes(str2);
  }

  return result;
}