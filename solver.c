#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char RED[3][3];
  char ORANGE[3][3];
  char GREEN[3][3];
  char BLUE[3][3];
  char WHITE[3][3];
  char YELLOW[3][3];
} cube;


/*
Edge replacement function
edges are numberede 1, 2, 3, 4 clockwise starting on the right edge
example: destedge 2, fromedge 4 would put the top of from into the bottom of
dest
*/
void replace_edge(char dest[3][3], int destedge, char from[3][3], int fromedge){
  for (int r = 0; r < 3; r++){
    switch(destedge){
      case (1):
        switch (fromedge){
          case(1):
            dest[r][2] = from[r][2];
            break;
          case(2):
            dest[r][2] = from[2][r];
            break;
          case(3):
            dest[r][2] = from[0][r];
            break;
          case(4):
            dest[r][2] = from[r][0];
            break;
          }
          break;
      case (2):
        switch (fromedge){
          case(1):
            dest[2][r] = from[r][2];
            break;
          case(2):
            dest[2][r] = from[2][r];
            break;
          case(3):
            dest[2][r] = from[0][r];
            break;
          case(4):
            dest[2][r] = from[r][0];
            break;
          }
          break;
      case (3):
        switch (fromedge){
          case(1):
            dest[r][0] = from[r][2];
            break;
          case(2):
            dest[r][0] = from[2][r];
            break;
          case(3):
            dest[r][0] = from[0][r];
            break;
          case(4):
            dest[r][0] = from[r][0];
            break;
          }
          break;
      case (4):
        switch (fromedge){
          case(1):
            dest[0][r] = from[r][2];
            break;
          case(2):
            dest[0][r] = from[2][r];
            break;
          case(3):
            dest[0][r] = from[0][r];
            break;
          case(4):
            dest[0][r] = from[r][0];
            break;
          }
          break;
    }
  }
}

void turn_clockwise_face(char side[3][3]){
  char temp = side[0][0];
  side[0][0] = side[2][0];
  side[2][0] = side[2][2];
  side[2][2] = side[0][2];
  side[0][2] = temp;

  temp = side[0][1];
  side[0][1] = side[1][0];
  side[1][0] = side[2][0];
  side[2][1] = side[1][2];
  side[1][2] = temp;
}

void move_F(cube g){
  turn_clockwise_face(g.BLUE);

  replace_edge(g.RED, 3, g.YELLOW, 2);
  replace_edge(g.YELLOW, 2, g.ORANGE, 1);
  replace_edge(g.ORANGE, 1, g.WHITE, 4);
  replace_edge(g.WHITE, 4, g.RED, 3);


}

void evaluate_moves(){
}

void generate_rand_sequence(){
  char moves[12] = {'U', 'u', 'L', 'l', 'F', 'f', 'R', 'r', 'B', 'b', 'D', 'd'};
  char returner[26];

  for (int r = 0; r < 26; r++){
    returner[r] = moves[(rand() % 12)];
    printf("%c", returner[r]);
  }
}

void print_cube(cube Cube){
  printf("        | %c %c %c |\n", Cube.YELLOW[0][0], Cube.YELLOW[0][1], Cube.YELLOW[0][2]);
  printf("        | %c %c %c |\n", Cube.YELLOW[1][0], Cube.YELLOW[1][1], Cube.YELLOW[1][2]);
  printf("        | %c %c %c |\n\n", Cube.YELLOW[2][0], Cube.YELLOW[2][1], Cube.YELLOW[2][2]);

  printf("| %c %c %c | %c %c %c | %c %c %c | %c %c %c |\n",
  Cube.ORANGE[0][0], Cube.ORANGE[0][1], Cube.ORANGE[0][2],
  Cube.BLUE[0][0], Cube.BLUE[0][1], Cube.BLUE[0][2],
  Cube.RED[0][0], Cube.RED[0][1], Cube.RED[0][2],
  Cube.GREEN[0][0], Cube.GREEN[0][1], Cube.GREEN[0][2]
);
printf("| %c %c %c | %c %c %c | %c %c %c | %c %c %c |\n",
Cube.ORANGE[1][0], Cube.ORANGE[1][1], Cube.ORANGE[1][2],
Cube.BLUE[1][0], Cube.BLUE[1][1], Cube.BLUE[1][2],
Cube.RED[1][0], Cube.RED[1][1], Cube.RED[1][2],
Cube.GREEN[1][0], Cube.GREEN[1][1], Cube.GREEN[1][2]

);  printf("| %c %c %c | %c %c %c | %c %c %c | %c %c %c |\n\n",
Cube.ORANGE[2][0], Cube.ORANGE[2][1], Cube.ORANGE[2][2],
Cube.BLUE[2][0], Cube.BLUE[2][1], Cube.BLUE[2][2],
Cube.RED[2][0], Cube.RED[2][1], Cube.RED[2][2],
Cube.GREEN[2][0], Cube.GREEN[2][1], Cube.GREEN[2][2]
);

printf("        | %c %c %c |\n", Cube.WHITE[0][0], Cube.WHITE[0][1], Cube.WHITE[0][2]);
printf("        | %c %c %c |\n", Cube.WHITE[1][0], Cube.WHITE[1][1], Cube.WHITE[1][2]);
printf("        | %c %c %c |\n\n", Cube.WHITE[2][0], Cube.WHITE[2][1], Cube.WHITE[2][2]);

}
void clean_cube(cube *g){

  for (int r = 0; r < 3; r++){
    for (int m = 0; m < 3; m++){
      (*g).YELLOW[r][m] = 'Y';
      (*g).ORANGE[r][m] = 'O';
      (*g).WHITE[r][m] = 'W';
      (*g).GREEN[r][m] = 'G';
      (*g).BLUE[r][m] = 'B';
      (*g).RED[r][m] = 'R';
    }
  }
}

int main (){

  cube starter;

  clean_cube(&starter);

  printf("\nState of Starter:\n\n");
  print_cube(starter);


  return 1;
}
