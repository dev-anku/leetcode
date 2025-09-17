#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  string consonantize(const string &s) {
    string res = s;
    for (char &c : res) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        c = '*';
      }
    }
    return res;
  }

  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    unordered_set<string> wordSet(wordlist.begin(), wordlist.end());
    unordered_map<string, string> caseInsensitiveMap;
    unordered_map<string, string> consonantMap;

    for (string &word : wordlist) {
      string lowerWord = word;
      for (char &c : lowerWord)
        c = tolower(c);

      if (!caseInsensitiveMap.count(lowerWord)) {
        caseInsensitiveMap[lowerWord] = word;
      }

      string consonantized = consonantize(lowerWord);
      if (!consonantMap.count(consonantized)) {
        consonantMap[consonantized] = word;
      }
    }

    vector<string> answer;
    for (string &query : queries) {
      if (wordSet.count(query)) {
        answer.push_back(query);
        continue;
      }

      string lowerQuery = query;
      for (char &c : lowerQuery)
        c = tolower(c);
      if (caseInsensitiveMap.count(lowerQuery)) {
        answer.push_back(caseInsensitiveMap[lowerQuery]);
        continue;
      }

      string consonantized = consonantize(lowerQuery);
      if (consonantMap.count(consonantized)) {
        answer.push_back(consonantMap[consonantized]);
        continue;
      }

      answer.push_back("");
    };

    return answer;
  }
};

class MySolution { // time limit exceeded
public:
  string toLower(const string &s) {
    string res = s;
    for (char &c : res)
      c = tolower(c);
    return res;
  }

  string consonants(const string &s) {
    string res = s;
    for (char &c : res) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        c = '*';
      }
    }
    return res;
  }

  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    vector<string> answer;
    for (int i = 0; i < queries.size(); i++) {
      string caseSensitive, caseInsensitive, consonantMatch;
      for (int j = 0; j < wordlist.size(); j++) {
        if (queries[i] == wordlist[j]) {
          caseSensitive = wordlist[j];
          break;
        }

        if (caseInsensitive == "") {
          if (toLower(queries[i]) == toLower(wordlist[j])) {
            caseInsensitive = wordlist[j];
          }
        }

        if (consonantMatch == "") {
          if (consonants(toLower(queries[i])) ==
              consonants(toLower(wordlist[j]))) {
            consonantMatch = wordlist[j];
          }
        }
      }
      if (caseSensitive != "") {
        answer.push_back(caseSensitive);
      } else if (caseInsensitive != "") {
        answer.push_back(caseInsensitive);
      } else if (consonantMatch != "") {
        answer.push_back(consonantMatch);
      } else {
        answer.push_back("");
      }
    }

    return answer;
  }
};
