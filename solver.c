#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char RED[8];
  char ORANGE[8];
  char GREEN[8];
  char BLUE[8];
  char WHITE[8];
  char YELLOW[8];
} cube;


//clockwise
void move_F(cube *g){
  char temps[3];

  temps[0] = (*g).BLUE[1];
  temps[1] = (*g).BLUE[2];
  //corners
  (*g).BLUE[2] = (*g).BLUE[0];
  (*g).BLUE[0] = (*g).BLUE[5];
  (*g).BLUE[5] = (*g).BLUE[7];
  (*g).BLUE[7] = temps[1];
  //edges
  (*g).BLUE[1] = (*g).BLUE[3];
  (*g).BLUE[3] = (*g).BLUE[7];
  (*g).BLUE[7] = (*g).BLUE[5];
  (*g).BLUE[5] = temps[0];

  //rotate borders

  temps[0] = (*g).RED[0]; temps[1] = (*g).RED[3]; temps[2] = (*g).RED[5];
  (*g).RED[0] = (*g).YELLOW[5]; (*g).RED[3] = (*g).YELLOW[6]; (*g).RED[5] = (*g).YELLOW[7];
  (*g).YELLOW[5] = (*g).ORANGE[7]; (*g).YELLOW[6] = (*g).ORANGE[4]; (*g).YELLOW[7] = (*g).ORANGE[2];
  (*g).ORANGE[2] = (*g).WHITE[0]; (*g).ORANGE[4] = (*g).WHITE[1]; (*g).ORANGE[7] = (*g).WHITE[2];
  (*g).WHITE[0] = temps[0]; (*g).WHITE[1] = temps[1]; (*g).WHITE[2] = temps[2];
}

int is_cube_solved(cube *g){
  int solved = 1;
  for (int r = 0; r < 8; r++){
    if  ((*g).YELLOW[r] != 'Y' || (*g).ORANGE[r] != 'O' || (*g).WHITE[r] != 'W' || (*g).GREEN[r] != 'G' || (*g).BLUE[r] != 'B' || (*g).RED[r] != 'R'){
      solved = 0;
    }
  }
  return solved;
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


  printf("        | %c %c %c |\n", Cube.YELLOW[0], Cube.YELLOW[1], Cube.YELLOW[2]);
  printf("        | %c %c %c |\n", Cube.YELLOW[3], 'Y', Cube.YELLOW[4]);
  printf("        | %c %c %c |\n\n", Cube.YELLOW[5], Cube.YELLOW[6], Cube.YELLOW[7]);

  printf("| %c %c %c | %c %c %c | %c %c %c | %c %c %c |\n",
  Cube.ORANGE[0], Cube.ORANGE[1],  Cube.ORANGE[2],
  Cube.BLUE[0],   Cube.BLUE[1],    Cube.BLUE[2],
  Cube.RED[0],    Cube.RED[1],     Cube.RED[2],
  Cube.GREEN[0],  Cube.GREEN[1],   Cube.GREEN[2]
);
  printf("| %c %c %c | %c %c %c | %c %c %c | %c %c %c |\n",
  Cube.ORANGE[3], 'O',  Cube.ORANGE[4],
  Cube.BLUE[3],   'B',  Cube.BLUE[4],
  Cube.RED[3],    'R',  Cube.RED[4],
  Cube.GREEN[3],  'G',  Cube.GREEN[4]
);
  printf("| %c %c %c | %c %c %c | %c %c %c | %c %c %c |\n\n",
  Cube.ORANGE[5], Cube.ORANGE[6],  Cube.ORANGE[7],
  Cube.BLUE[5],   Cube.BLUE[6],    Cube.BLUE[7],
  Cube.RED[5],    Cube.RED[6],     Cube.RED[7],
  Cube.GREEN[5],  Cube.GREEN[6],   Cube.GREEN[7]
);

printf("        | %c %c %c |\n", Cube.WHITE[0], Cube.WHITE[1], Cube.WHITE[2]);
printf("        | %c %c %c |\n", Cube.WHITE[3], 'W' , Cube.WHITE[4]);
printf("        | %c %c %c |\n\n", Cube.WHITE[5], Cube.WHITE[6], Cube.WHITE[7]);

}

void clean_cube(cube *g){
  for (int r = 0; r < 8; r++){
      (*g).YELLOW[r] = 'Y';
      (*g).ORANGE[r] = 'O';
      (*g).WHITE[r] = 'W';
      (*g).GREEN[r] = 'G';
      (*g).BLUE[r] = 'B';
      (*g).RED[r] = 'R';
    }
  }

int main (){

  cube starter;

  clean_cube(&starter);
  printf("1 if Cube begins solved: %d\n", is_cube_solved(&starter));

  move_F(&starter);
  printf("\nState of Starter:\n\n");
  print_cube(starter);
  printf("1 if Cube is solved: %d\n", is_cube_solved(&starter));



  return 1;
}
