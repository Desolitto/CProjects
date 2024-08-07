#include "my_string.h"

void *my_trim(const char *src, const char *trim_chars) {
  char *new_src = my_NULL;
  const char *trim_ch = trim_chars;
  int num_of_trim = 0, index_src = 0, find_trim = 0;

  if ((src != my_NULL)) {
    for (int i = 0; (trim_ch) && src[i]; i++) {
      for (int j = 0; trim_ch[j]; j++) {
        if (src[i] == trim_ch[j]) {
          ++num_of_trim;
        }
      }
    }

    new_src = (char *)calloc(my_strlen(src) - num_of_trim + 1, sizeof(char));

    for (int i = 0; (new_src) && src[i]; i++) {
      find_trim = 0;
      for (int j = 0; (trim_ch) && trim_ch[j] && (find_trim == 0); j++) {
        if (src[i] == trim_ch[j]) {
          find_trim = 1;
        }
      }
      if (find_trim == 0) {
        new_src[index_src++] = src[i];
      }
    }
  }

  return new_src;
}