#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void *hall_of_fame[5];
unsigned int best_scores[5];

int words_size = 0;
void *words[32];

char name[32];
unsigned int score = 0;


unsigned int read_number() {
  char c[16];
  fgets(c, 16, stdin);
  unsigned int number = atoi(c);
  return number;
}

void read_string(char *buf, int len) {
  int i = 0;
  char c;
  while(i <= len) {
    c = getchar();
    if (c != '\n') {
      buf[i] = c; 
    } else {
      break;
    }
    i += 1;
  }
  buf[i] = '\0';
  while(c != '\n') {
    c = getchar();
  }
}

void show(int choice) {
  switch(choice) {
    case 0:
      printf("\n    ||===== ");
      printf("\n    ||    | ");
      printf("\n    ||   \\O/");
      printf("\n    ||    | ");
      printf("\n    ||   / \\");
      printf("\n    || ");
      break;
    case 1:
      printf("\n    ||===== ");
      printf("\n    ||    | ");
      printf("\n    ||   \\O/");
      printf("\n    ||    | ");
      printf("\n    ||     \\");
      printf("\n    || ");
      break;
    case 2:
      printf("\n    ||===== ");
      printf("\n    ||    | ");
      printf("\n    ||   \\O/");
      printf("\n    ||    | ");
      printf("\n    ||      ");
      printf("\n    || ");
      break;
    case 3:
      printf("\n    ||===== ");
      printf("\n    ||    | ");
      printf("\n    ||   \\O/");
      printf("\n    ||      ");
      printf("\n    ||      ");
      printf("\n    || ");
      break;
    case 4:
      printf("\n    ||===== ");
      printf("\n    ||    | ");
      printf("\n    ||   \\O ");
      printf("\n    ||      ");
      printf("\n    ||      ");
      printf("\n    || ");
      break;
    case 5:
      printf("\n    ||===== ");
      printf("\n    ||    | ");
      printf("\n    ||    O ");
      printf("\n    ||      ");
      printf("\n    ||      ");
      printf("\n    || ");
      break;
  }
  return;
}

void prepare() {
  int i;
  for (i = 0; i < 5; i ++) {
    hall_of_fame[i] = malloc(sizeof(char) * 256);
  }

  srand(time(NULL));
  setvbuf(stdout, NULL, _IONBF, 0);
}

void title() {
  printf("  _                                             \n");
  printf(" | |                                            \n");
  printf(" | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
  printf(" | '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
  printf(" | | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
  printf(" |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
  printf("                     __/ |                      \n");
  printf("                    |___/  \n");
  printf("                                               \n");
}

void print_hall_of_fame() {
  int i;

  puts("\n[+] \\ /   Hangman    \\ /");
  puts("     0  Hall of Fame  0\n");
  for (i = 0; i < 5; i++) {
    printf("    %d. Name  : %s\n", i+1, hall_of_fame[i]);
    printf("       Score : %u\n\n", best_scores[i]);
  }
}

void menu() {
  printf("\n[+] Greetings %s! What would you like to do?\n", name);
  puts("    1. Play");
  puts("    2. Score");
  puts("    3. Hall of Fame");
  puts("    4. Prize");
  puts("    5. Rename");
  puts("    6. Restart");
  puts("    7. Exit");
  printf("\n[+] Your choice: ");
}

void prize() {
  int i;
  for (i = 0; i < 5; i++) {
    if (strcmp(name, hall_of_fame[i]) == 0) {
      printf("\n[+] Flag: ");
      system("cat flag");
      exit(0);
    }
  }
  if (i == 5) {
    puts("\n[+] You are not eligible for the prize yet.");
    printf("    Get %u more point(s) to redeem flag!\n", best_scores[4]-score);
  }
}

void update() {
  int i, temp_score;
  void *temp_name;
  if (score > best_scores[4]) {
    best_scores[4] = score;
    memcpy(hall_of_fame[4], name, strlen(name)+1);
    for (i = 4; i > 0; i--) {
      if (best_scores[i] > best_scores[i-1]) {
        temp_score = best_scores[i-1];
        best_scores[i-1] = best_scores[i];
        best_scores[i] = temp_score;

        temp_name = hall_of_fame[i-1];
        hall_of_fame[i-1] = hall_of_fame[i];
        hall_of_fame[i] = temp_name;
      }
    }
  }
}

void change_name() {
  char buf[1024];

  printf("\n[+] Enter your new name: ");
  read_string(buf, strlen(name));

  int i;
  for (i = 0; i < 5; i++) {
    if (strcmp(buf, hall_of_fame[i]) == 0) {
      puts("\n[+] Sorry, name is already taken.");
      return;
    }
  }
  memcpy(name, buf, strlen(buf)+1);
}

void play() {
  int life = 5;
  char answer[64];
  char guess[64];

  memcpy(answer, words[rand() % words_size], 64);

  int i;
  for (i = 0; i < strlen(answer); i++) {
    guess[i] = '_';
  }
  guess[i] = '\0';

  puts("\n[+] Game begin!");

  int char_remain = strlen(guess);
  while(life > 0 && char_remain > 0) {
    int guessed = 0;
    show(life);
    for (i = 0; i < strlen(guess); i++) {
      printf("%c ", guess[i]);
    }
    printf("\n\n    Guess a letter: ");
    
    char c = getchar();
    for (i = 0; i < strlen(answer); i++) {
      if (answer[i] == c && guess[i] != c) {
        guess[i] = c;
        char_remain -= 1;
        guessed = 1;
      }
    }

    if (!guessed) {
      printf("    Better luck next time. %d letter(s) to go.\n", char_remain);
      life -= 1;
    } else {
      printf("    Great job! %d letter(s) to go.\n", char_remain);
    }

    while (c != '\n') {
      c = getchar();
    }
  }

  show(life);
  for (i = 0; i < strlen(answer); i++) {
    printf("%c ", answer[i]);
  }

  if (life == 0) {
    printf("\n\n[+] You are dead. Try again. Your score: %u", score);
  } else {
    score += 100;
    printf("\n\n[+] Congratulations! Your score: %u", score);
  }

  getchar();
}

void game() {
  while(1) {
    update();
    menu();
    unsigned int choice = read_number();
    if (choice == 1) {
      play();
    } else if (choice == 2) {
      printf("\n[+] Your score: %u\n", score);
    } else if (choice == 3) {
      print_hall_of_fame();
    } else if (choice == 4) {
      prize();
    } else if (choice == 5) {
      change_name();
    } else if (choice == 6) {
      return;
    } else if (choice == 7) {
      puts("\n[+] Thanks for playing!");
      exit(0);
    }
  }
}

void load() {
  FILE *fp;
  fp = fopen("hall_of_fame","r");
  if (fp == NULL) {
    exit(1);
  }

  char buf[128];
  int i = 0;
  int idx = 0;
  while (1) {
    char c = fgetc(fp);
    if (c == EOF) {
      break;
    } else if (c == ':') {
      memcpy(hall_of_fame[idx], buf, i);
      i = 0;
    } else if (c == '\n') {
      buf[i] = '\0';
      best_scores[idx] = strtol(buf, NULL, 10);
      idx += 1;
      i = 0;
      if (idx > 5) {
        break;
      }
    } else {
      buf[i] = c;
      i += 1;
    }
  }
  fclose(fp);

  fp = fopen("wordlist","r");
  if (fp == NULL) {
    exit(1);
  }

  idx = 0;
  for (i = 0; i < 64; i++) {
    if (fscanf(fp, "%s", buf) == EOF) {
      break;
    } else {
      words[i] = malloc(sizeof(char) * (strlen(buf) + 1));
      memcpy(words[i], buf, strlen(buf) + 1);
    }
  }
  words_size = i;
  fclose(fp);
}

void startup() {
  load();

  int valid;
  do {
    valid = 1;
    printf("[+] Enter your name: ");
    read_string(name, 20);

    int i;
    for (i = 0; i < 5; i++) {
      if (strcmp(name, hall_of_fame[i]) == 0) {
        puts("[+] Sorry, name is already taken.\n");
        valid = 0;
        break;
      }
    }
  } while (!valid);
}

int main() {
  prepare();
  while (1) {
    title();
    startup();
    game();
  }
}