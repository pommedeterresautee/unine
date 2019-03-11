#include <Rcpp.h>
#include <stdio.h>
#include <codecvt>
using namespace Rcpp;
using namespace std;


/*  German stemmer tring to remove inflectional suffixes */

//
// u16string removeGermanAccent();
// u16string remove_Step1();
// u16string remove_Step2();
// static int STEnding();



u16string removeGermanAccent(u16string word) {
  int len = word.size() - 1;
  int i;

    for(i=len; i>=0; i--) {
      if ((word[i]==u'ä') || (word[i]==u'à') || (word[i]==u'á') || (word[i]==u'â')) {
        word[i] = 'a';
      }
      if ((word[i]==u'ö') || (word[i]==u'ò') || (word[i]==u'ó') || (word[i]==u'ô')) {
        word[i] = 'o';
      }
      if ((word[i]==u'ï') || (word[i]==u'ì') || (word[i]==u'í') || (word[i]==u'î')) {
        word[i] = 'i';
      }
      if ((word[i]==u'ü') || (word[i]==u'ù') || (word[i]==u'ú') || (word[i]==u'û')) {
        word[i] = 'u';
      }
    }
    return(word);
}


static int STEnding (wchar_t aLetter) {
    if (aLetter=='b' || aLetter==u'd' || aLetter=='f' ||
        aLetter=='g' || aLetter=='h' || aLetter=='k' ||
        aLetter=='l' || aLetter=='m' || aLetter=='n' ||
        aLetter=='t')
      return(1);
    return(0);
}


u16string remove_Step1 (u16string word) {
  int len = word.size() - 1;

    if (len > 4) {
      if (word[len]=='n' && word[len-1]=='r' && word[len-2]=='e') {
        word[len-2]='\0';  /*  ending with -ern ->   */
return(word);
      }
    }
    if (len > 3) {
      if (word[len]=='m' && word[len-1]=='e') {
        word[len-1]='\0';  /*  ending with -em ->  */
return(word);
      }
      if (word[len]=='n' && word[len-1]=='e') {
        word[len-1]='\0';  /*  ending with -en ->  */
return(word);
      }
      if (word[len]=='r' && word[len-1]=='e') {
        word[len-1]='\0';  /*  ending with -er ->  */
return(word);
      }
      if (word[len]=='s' && word[len-1]=='e') {
        word[len-1]='\0';  /*  ending with -es ->  */
return(word);
      }
    }
    if (len > 2) {
      if (word[len]=='e') {
        word[len]='\0';  /*  ending with -e ->  */
return(word);
      }
      if (word[len]=='s' && STEnding(word[len-1])) {
        word[len]='\0';  /*  ending with -s ->  */
return(word);
      }
    }
    return(word);
}

u16string remove_Step2 (u16string word) {
  int len = word.size() - 1;

  if (len > 4) {
    if (word[len]=='t' && word[len-1]=='s' && word[len-2]=='e') {
      word[len-2]='\0';  /*  ending with -est ->   */
return(word);
    }
  }
  if (len > 3) {
    if (word[len]=='r' && word[len-1]=='e') {
      word[len-1]='\0';  /*  ending with -er ->  */
return(word);
    }
    if (word[len]=='n' && word[len-1]=='e') {
      word[len-1]='\0';  /*  ending with -en ->  */
return(word);
    }
    if (word[len]=='t' && word[len-1]=='s' && STEnding(word[len-2])) {
      word[len-1]='\0';  /*  ending with -st ->  */
return(word);
    }
  }
  return(word);
}



u16string german_stemming (u16string word) {
  removeGermanAccent(word);
  remove_Step1(word);
  remove_Step2(word);
  return(word);
}



//' Stem German words
//'
//' Stemmer for German words
//'
//' @param words a [character] containing the original words.
//' @return [character] with stemmed words.
//' @examples
//' german_stemmer(c("kinder"))
//' @export
// [[Rcpp::export]]
CharacterVector german_stemmer(Rcpp::StringVector words) {
  std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
  CharacterVector result(words.size());

  for (int i = 0; i < words.size(); ++i) {
    u16string str2 = convert.from_bytes(words[i]);
    str2 = removeGermanAccent(str2);
    str2 = remove_Step1(str2);
    str2 = remove_Step2(str2);
    result[i] = convert.to_bytes(str2);
  }

  return result;
}
