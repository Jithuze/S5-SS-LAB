#include <stdio.h>
#include <string.h>

struct dirct {
  char dir[20], file[20][10];
  int findex;
};

void main() {
  int i, j, ch = 1, dindex = 0, found = 0;
  struct dirct d[10];
  char ser[20];
  for (i = 0; i < 10; i++) d[i].findex = 0;

  do {
    printf(
        "\n1.Create new Directory\n2.Create new file\n3.Delete a "
        "file\n4.Search a file\n5.List files\n0.Exit\n");
    printf("Enter Your Choice : ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("\nEnter the directory name : ");
        scanf("%s", d[dindex].dir);
        dindex++;
        printf("Directory Created \n");
        break;
      case 2:
        printf("\nEnter the directory name : ");
        scanf("%s", ser);
        found = 0;
        for (i = 0; i < dindex; i++) {
          if (!strcmp(ser, d[i].dir)) {
            printf("\nEnter the file name : ");
            scanf("%s", d[i].file[d[i].findex++]);
            printf("File Created\n");
            break;
          }
        }
        if (i == dindex) {
          printf("\nSearch Completed\nNo such file or directory\n");
        }
        break;
      case 3:
        printf("\nEnter the file name : ");
        scanf("%s", ser);
        found = 0;
        for (i = 0; i < dindex; i++) {
          for (j = 0; j < d[i].findex; j++) {
            if (!strcmp(ser, d[i].file[j])) {
              printf("%s is removed \n", d[i].file[j]);
              strcpy(d[i].file[j], d[i].file[d[i].findex - 1]);
              d[i].findex--;
              found = 1;
              break;
            }
          }
        }
        if (!found) {
          printf("\nSearch completed\nNo such file or directory\n");
        }
        break;
      case 4:
        printf("\nEnter the file name");
        scanf("%s", ser);
        found = 0;
        for (i = 0; i < dindex; i++) {
          for (j = 0; j < d[i].findex; j++) {
            if (!strcmp(ser, d[i].file[j])) {
              printf("%s is removed\n", d[i].file[j]);
              found = 1;
              break;
            }
          }
        }
        if (!found) {
          printf("\nSearch completed\nNo such file or directory\n");
        }
        break;
      case 5:
        for (i = 0; i < dindex; i++) {
          printf("\nThe files in the dir %s are \n", d[i].dir);
          for (j = 0; j < d[i].findex; j++) printf("%s\n", d[i].file[j]);
        }
        break;
    }
  } while (ch);
  printf("\n");
}
