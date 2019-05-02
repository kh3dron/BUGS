#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIFFICULTY = 1;

typedef struct {
  char RED[4];
  char ORANGE[4];
  char GREEN[4];
  char BLUE[4];
  char WHITE[4];
  char YELLOW[4];
}
cube;

//Done
void move_u(cube *g){
  char temp = (*g).YELLOW[0];
  for (int r = 0; r < 3; r++){(*g).YELLOW[r] = (*g).YELLOW[r+1];}
  (*g).YELLOW[3] = temp;
  char temps[2];
  temps[0] = (*g).BLUE[0]; temps[1] = (*g).BLUE[1];
  (*g).BLUE[0] = (*g).ORANGE[0]; (*g).BLUE[1] = (*g).ORANGE[1];
  (*g).ORANGE[0] = (*g).GREEN[0]; (*g).ORANGE[1] = (*g).GREEN[1];
  (*g).GREEN[0] = (*g).RED[0]; (*g).GREEN[1] = (*g).RED[1];
  (*g).RED[0] = temps[0]; (*g).RED[1] = temps[1];
}
void move_U(cube *g){for (int r = 0; r < 3; r++){move_u(g);}}

void move_l(cube * g){
  char temp = (*g).ORANGE[0];
  for (int r = 0; r < 3; r++){(*g).ORANGE[r] = (*g).ORANGE[r+1];}
  (*g).ORANGE[3] = temp;

  char temps[2]; temps[0] = (*g).BLUE[0]; temps[1] = (*g).BLUE[3];
  (*g).BLUE[0] = (*g).WHITE[0]; (*g).BLUE[3] = (*g).WHITE[3];
  (*g).WHITE[0] = (*g).GREEN[1]; (*g).WHITE[3] = (*g).GREEN[2];
  (*g).GREEN[1] = (*g).YELLOW[3]; (*g).GREEN[2] = (*g).YELLOW[0];
  (*g).YELLOW[0] = temps[0]; (*g).YELLOW[3] = temps[1];
}
void move_L(cube *g){ for (int r = 0; r < 3; r++){move_l(g);}}

void move_f(cube * g) {
  char temp = (*g).BLUE[0];
  for (int r = 0; r < 3; r++){(*g).BLUE[r] = (*g).BLUE[r+1];}
  (*g).BLUE[3] = temp;
  char temps[2];
  temps[0] = (*g).YELLOW[2]; temps[1] = (*g).YELLOW[3];
  (*g).YELLOW[2] = (*g).RED[3]; (*g).YELLOW[3] = (*g).RED[0];
  (*g).RED[0] = (*g).WHITE[1]; (*g).RED[3] = (*g).WHITE[0];
  (*g).WHITE[1] = (*g).ORANGE[2]; (*g).WHITE[0] = (*g).ORANGE[1];
  (*g).ORANGE[2] = temps[0]; (*g).ORANGE[1] = temps[1];
}
void move_F(cube *g) {for (int r = 0; r < 3; r++){move_f(g);}}

void move_r(cube *g){
  char temp = (*g).RED[0];
  for (int r = 0; r < 3; r++){(*g).RED[r] = (*g).RED[r+1];}
  (*g).RED[3] = temp;

  char temps[2];
  temps[0] = (*g).YELLOW[1]; temps[1] = (*g).YELLOW[2];
  (*g).YELLOW[1] = (*g).GREEN[3]; (*g).YELLOW[2] = (*g).GREEN[0];
  (*g).GREEN[0] = (*g).WHITE[2]; (*g).GREEN[3] = (*g).WHITE[1];
  (*g).WHITE[2] = (*g).BLUE[2]; (*g).WHITE[1] = (*g).BLUE[1];
  (*g).BLUE[2] = temps[0]; (*g).BLUE[1] = temps[1];
}
void move_R(cube *g){for (int r = 0; r < 3; r++){move_r(g);}}

void move_B(cube *g){
}

void move_D(cube *g){
}

int is_cube_solved(cube * g) {
  int solved = 1;
  for (int r = 0; r < 4; r++) {
    if (( * g).YELLOW[r] != 'Y' || ( * g).ORANGE[r] != 'O' ||
    ( * g).WHITE[r] != 'W' || ( * g).GREEN[r] != 'G' ||
    ( * g).BLUE[r] != 'B'  || ( * g).RED[r] != 'R') {
      solved = 0;
    }
  }
  return solved;
}

void evaluate_moves(){}

void generate_rand_sequence() {
  char moves[12] = {
    'U',
    'u',
    'L',
    'l',
    'F',
    'f',
    'R',
    'r',
    'B',
    'b',
    'D',
    'd'
  };
  char returner[DIFFICULTY];

  for (int r = 0; r < DIFFICULTY; r++) {
    returner[r] = moves[(rand() % 12)];
    printf("%c", returner[r]);
  }
}

void print_cube(cube Cube) {

  printf("        / %c %c /\n", Cube.YELLOW[0], Cube.YELLOW[1]);
  printf("       / %c %c /\n\n", Cube.YELLOW[3], Cube.YELLOW[2]);
  printf("| %c %c | %c %c | %c %c | %c %c |\n",
    Cube.ORANGE[0], Cube.ORANGE[1],
    Cube.BLUE[0], Cube.BLUE[1],
    Cube.RED[0], Cube.RED[1],
    Cube.GREEN[0], Cube.GREEN[1]);
  printf("| %c %c | %c %c | %c %c | %c %c |\n\n",
    Cube.ORANGE[3], Cube.ORANGE[2],
    Cube.BLUE[3], Cube.BLUE[2],
    Cube.RED[3], Cube.RED[2],
    Cube.GREEN[3], Cube.GREEN[2]);
  printf("       %c %c %c %c\n", '\\', Cube.WHITE[0], Cube.WHITE[1], '\\');
  printf("        %c %c %c %c\n\n", '\\', Cube.WHITE[3], Cube.WHITE[2], '\\');
}

void clean_cube(cube * g) {
  for (int r = 0; r < 4; r++) {
    ( * g).YELLOW[r] = 'Y';
    ( * g).ORANGE[r] = 'O';
    ( * g).WHITE[r] = 'W';
    ( * g).GREEN[r] = 'G';
    ( * g).BLUE[r] = 'B';
    ( * g).RED[r] = 'R';
  }
}

int main() {

  cube starter;

  clean_cube(&starter);
  printf("\nState of Starter:\n\n");
  print_cube(starter);

  move_l(&starter);
  printf("\nState of Starter:\n\n");
  print_cube(starter);

  move_l(&starter);
  move_l(&starter);
  move_l(&starter);
  printf("\nState of Starter:\n\n");
  print_cube(starter);

  return 1;
}
