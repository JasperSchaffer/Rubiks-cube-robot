#include <Stepper.h>
#include <Servo.h>




int del = 0;
int moves = -1;
int reduced = 0;
int motorDelay = 300;

bool inverted = false;
bool withSteps = true;

#define STEPS 200
#define moveAway 95
#define moveTowards 20

Servo leftServo;
Servo rightServo;
Servo frontServo;
Servo backServo;

Servo leftMoveServo;
Servo rightMoveServo;
Servo frontMoveServo;
Servo backMoveServo;



//top
String yellow_side[9] = {"y0", "y1", "y2",
                         "y3", "y4", "y5",
                         "y6", "y7", "y8"
                        };
//down
String white_side[9] =  {"w0", "w1", "w2",
                         "w3", "w4", "w5",
                         "w6", "w7", "w8"
                        };
//front
String blue_side[9] =   {"b0", "b1", "b2",
                         "b3", "b4", "b5",
                         "b6", "b7", "b8"
                        };
//left
String red_side[9] =    {"r0", "r1", "r2",
                         "r3", "r4", "r5",
                         "r6", "r7", "r8"
                        };
//back
String green_side[9] =  {"g0", "g1", "g2",
                         "g3", "g4", "g5",
                         "g6", "g7", "g8"
                        };
//right
String orange_side[9] = {"o0", "o1", "o2",
                         "o3", "o4", "o5",
                         "o6", "o7", "o8"
                        };



//movments
void left() {

  moves++;

  delay(del);
  if (withSteps)
    leftMove(false);

  Serial.print("L, ");
  String r_green_side[9];
  String r_blue_side[9];
  String r_red_side[9];
  String r_white_side[9];
  String r_yellow_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }

  for (int x = 0; x < 9; x++)
  {
    r_yellow_side[x] = yellow_side[x];
  }

  yellow_side[0] = r_blue_side[8];
  yellow_side[3] = r_blue_side[5];
  yellow_side[6] = r_blue_side[2];

  blue_side[2] = r_white_side[6];
  blue_side[5] = r_white_side[3];
  blue_side[8] = r_white_side[0];

  white_side[0] = r_green_side[0];
  white_side[3] = r_green_side[3];
  white_side[6] = r_green_side[6];

  green_side[0] = r_yellow_side[0];
  green_side[3] = r_yellow_side[3];
  green_side[6] = r_yellow_side[6];

  red_side[0] = r_red_side[6];
  red_side[1] = r_red_side[3];
  red_side[2] = r_red_side[0];
  red_side[3] = r_red_side[7];
  red_side[4] = r_red_side[4];
  red_side[5] = r_red_side[1];
  red_side[6] = r_red_side[8];
  red_side[7] = r_red_side[5];
  red_side[8] = r_red_side[2];

}

void left_i() {
  moves++;
  delay(del);
  if (withSteps)
    leftMove(true);

  Serial.print("L', ");
  String r_green_side[9];
  String r_blue_side[9];
  String r_red_side[9];
  String r_white_side[9];
  String r_yellow_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }

  for (int x = 0; x < 9; x++)
  {
    r_yellow_side[x] = yellow_side[x];
  }

  yellow_side[0] = r_green_side[0];
  yellow_side[3] = r_green_side[3];
  yellow_side[6] = r_green_side[6];

  blue_side[8] = r_yellow_side[0];
  blue_side[5] = r_yellow_side[3];
  blue_side[2] = r_yellow_side[6];

  white_side[0] = r_blue_side[8];
  white_side[3] = r_blue_side[5];
  white_side[6] = r_blue_side[2];

  green_side[0] = r_white_side[0];
  green_side[3] = r_white_side[3];
  green_side[6] = r_white_side[6];


  red_side[0] = r_red_side[2];
  red_side[1] = r_red_side[5];
  red_side[2] = r_red_side[8];
  red_side[3] = r_red_side[1];
  red_side[4] = r_red_side[4];
  red_side[5] = r_red_side[7];
  red_side[6] = r_red_side[0];
  red_side[7] = r_red_side[3];
  red_side[8] = r_red_side[6];

}

void right() {
  moves++;


  delay(del);
  if (withSteps)
    rightMove(false);


  Serial.print("R, ");
  String r_green_side[9];
  String r_blue_side[9];
  String r_orange_side[9];
  String r_white_side[9];
  String r_yellow_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }

  for (int x = 0; x < 9; x++)
  {
    r_yellow_side[x] = yellow_side[x];
  }

  yellow_side[2] = r_green_side[2];
  yellow_side[5] = r_green_side[5];
  yellow_side[8] = r_green_side[8];

  blue_side[0] = r_yellow_side[8];
  blue_side[3] = r_yellow_side[5];
  blue_side[6] = r_yellow_side[2];

  white_side[2] = r_blue_side[6];
  white_side[5] = r_blue_side[3];
  white_side[8] = r_blue_side[0];

  green_side[2] = r_white_side[2];
  green_side[5] = r_white_side[5];
  green_side[8] = r_white_side[8];

  orange_side[0] = r_orange_side[6];
  orange_side[1] = r_orange_side[3];
  orange_side[2] = r_orange_side[0];
  orange_side[3] = r_orange_side[7];
  orange_side[4] = r_orange_side[4];
  orange_side[5] = r_orange_side[1];
  orange_side[6] = r_orange_side[8];
  orange_side[7] = r_orange_side[5];
  orange_side[8] = r_orange_side[2];

}

void right_i() {
  moves++;


  delay(del);
  if (withSteps)
    rightMove(true);


  Serial.print("R', ");
  String r_green_side[9];
  String r_blue_side[9];
  String r_orange_side[9];
  String r_white_side[9];
  String r_yellow_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }

  for (int x = 0; x < 9; x++)
  {
    r_yellow_side[x] = yellow_side[x];
  }

  yellow_side[2] = r_blue_side[6];
  yellow_side[5] = r_blue_side[3];
  yellow_side[8] = r_blue_side[0];

  blue_side[0] = r_white_side[8];
  blue_side[3] = r_white_side[5];
  blue_side[6] = r_white_side[2];

  white_side[2] = r_green_side[2];
  white_side[5] = r_green_side[5];
  white_side[8] = r_green_side[8];

  green_side[2] = r_yellow_side[2];
  green_side[5] = r_yellow_side[5];
  green_side[8] = r_yellow_side[8];

  orange_side[0] = r_orange_side[2];
  orange_side[1] = r_orange_side[5];
  orange_side[2] = r_orange_side[8];
  orange_side[3] = r_orange_side[1];
  orange_side[4] = r_orange_side[4];
  orange_side[5] = r_orange_side[7];
  orange_side[6] = r_orange_side[0];
  orange_side[7] = r_orange_side[3];
  orange_side[8] = r_orange_side[6];

}

void front() {
  moves++;

  if (!inverted) {

    delay(del);
    if (withSteps)
      frontMove(false);




    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }


    orange_side[0] = r_yellow_side[6];
    orange_side[3] = r_yellow_side[7];
    orange_side[6] = r_yellow_side[8];

    yellow_side[6] = r_red_side[8];
    yellow_side[7] = r_red_side[5];
    yellow_side[8] = r_red_side[2];

    red_side[2] = r_white_side[0];
    red_side[5] = r_white_side[1];
    red_side[8] = r_white_side[2];

    white_side[0] = r_orange_side[6];
    white_side[1] = r_orange_side[3];
    white_side[2] = r_orange_side[0];

    green_side[0] = r_green_side[6];
    green_side[1] = r_green_side[3];
    green_side[2] = r_green_side[0];
    green_side[3] = r_green_side[7];
    green_side[4] = r_green_side[4];
    green_side[5] = r_green_side[1];
    green_side[6] = r_green_side[8];
    green_side[7] = r_green_side[5];
    green_side[8] = r_green_side[2];
  } else {

    delay(del);
    if (withSteps)
      frontMove(false);



    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }
    yellow_side[0] = r_orange_side[2];
    yellow_side[1] = r_orange_side[5];
    yellow_side[2] = r_orange_side[8];

    red_side[0] = r_yellow_side[2];
    red_side[3] = r_yellow_side[1];
    red_side[6] = r_yellow_side[0];

    white_side[6] = r_red_side[0];
    white_side[7] = r_red_side[3];
    white_side[8] = r_red_side[6];

    orange_side[2] = r_white_side[8];
    orange_side[5] = r_white_side[7];
    orange_side[8] = r_white_side[6];

    blue_side[0] = r_blue_side[6];
    blue_side[1] = r_blue_side[3];
    blue_side[2] = r_blue_side[0];
    blue_side[3] = r_blue_side[7];
    blue_side[4] = r_blue_side[4];
    blue_side[5] = r_blue_side[1];
    blue_side[6] = r_blue_side[8];
    blue_side[7] = r_blue_side[5];
    blue_side[8] = r_blue_side[2];
  }
  Serial.print("F, ");
}

void front_i() {
  moves++;
  if (!inverted) {

    delay(del);
    if (withSteps)
      frontMove(true);

    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    orange_side[0] = r_white_side[2];
    orange_side[3] = r_white_side[1];
    orange_side[6] = r_white_side[0];

    yellow_side[6] = r_orange_side[0];
    yellow_side[7] = r_orange_side[3];
    yellow_side[8] = r_orange_side[6];

    red_side[2] = r_yellow_side[8];
    red_side[5] = r_yellow_side[7];
    red_side[8] = r_yellow_side[6];

    white_side[0] = r_red_side[2];
    white_side[1] = r_red_side[5];
    white_side[2] = r_red_side[8];

    green_side[0] = r_green_side[2];
    green_side[1] = r_green_side[5];
    green_side[2] = r_green_side[8];
    green_side[3] = r_green_side[1];
    green_side[4] = r_green_side[4];
    green_side[5] = r_green_side[7];
    green_side[6] = r_green_side[0];
    green_side[7] = r_green_side[3];
    green_side[8] = r_green_side[6];
  } else {

    delay(del);
    if (withSteps)
      frontMove(true);




    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    yellow_side[0] = r_red_side[6];
    yellow_side[1] = r_red_side[3];
    yellow_side[2] = r_red_side[0];

    red_side[6] = r_white_side[8];
    red_side[3] = r_white_side[7];
    red_side[0] = r_white_side[6];

    white_side[6] = r_orange_side[8];
    white_side[7] = r_orange_side[5];
    white_side[8] = r_orange_side[2];

    orange_side[8] = r_yellow_side[2];
    orange_side[5] = r_yellow_side[1];
    orange_side[2] = r_yellow_side[0];

    blue_side[0] = r_blue_side[2];
    blue_side[1] = r_blue_side[5];
    blue_side[2] = r_blue_side[8];
    blue_side[3] = r_blue_side[1];
    blue_side[4] = r_blue_side[4];
    blue_side[5] = r_blue_side[7];
    blue_side[6] = r_blue_side[0];
    blue_side[7] = r_blue_side[3];
    blue_side[8] = r_blue_side[6];
  }
  Serial.print("F', ");
}

void down() {
  moves++;

  Serial.print("D, ");
  if (!inverted) {

    delay(del);
    if (withSteps)
      downMove(false, false);

    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    blue_side[6] = r_orange_side[6];
    blue_side[7] = r_orange_side[7];
    blue_side[8] = r_orange_side[8];

    red_side[6] = r_blue_side[6];
    red_side[7] = r_blue_side[7];
    red_side[8] = r_blue_side[8];

    green_side[6] = r_red_side[6];
    green_side[7] = r_red_side[7];
    green_side[8] = r_red_side[8];

    orange_side[6] = r_green_side[6];
    orange_side[7] = r_green_side[7];
    orange_side[8] = r_green_side[8];

    white_side[0] = r_white_side[6];
    white_side[1] = r_white_side[3];
    white_side[2] = r_white_side[0];
    white_side[3] = r_white_side[7];
    white_side[4] = r_white_side[4];
    white_side[5] = r_white_side[1];
    white_side[6] = r_white_side[8];
    white_side[7] = r_white_side[5];
    white_side[8] = r_white_side[2];
  } else {

    delay(del);
    if (withSteps)
      downMove(false, false);





    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    blue_side[0] = r_red_side[0];
    blue_side[1] = r_red_side[1];
    blue_side[2] = r_red_side[2];

    red_side[0] = r_green_side[0];
    red_side[1] = r_green_side[1];
    red_side[2] = r_green_side[2];

    green_side[0] = r_orange_side[0];
    green_side[1] = r_orange_side[1];
    green_side[2] = r_orange_side[2];

    orange_side[0] = r_blue_side[0];
    orange_side[1] = r_blue_side[1];
    orange_side[2] = r_blue_side[2];


    yellow_side[0] = r_yellow_side[6];
    yellow_side[1] = r_yellow_side[3];
    yellow_side[2] = r_yellow_side[0];
    yellow_side[3] = r_yellow_side[7];
    yellow_side[4] = r_yellow_side[4];
    yellow_side[5] = r_yellow_side[1];
    yellow_side[6] = r_yellow_side[8];
    yellow_side[7] = r_yellow_side[5];
    yellow_side[8] = r_yellow_side[2];
  }

}

void down_i() {
  moves++;
  Serial.print("D', ");

  if (!inverted) {

    delay(del);
    if (withSteps)
      downMove(true, false);


    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    green_side[6] = r_orange_side[6];
    green_side[7] = r_orange_side[7];
    green_side[8] = r_orange_side[8];

    red_side[6] = r_green_side[6];
    red_side[7] = r_green_side[7];
    red_side[8] = r_green_side[8];

    blue_side[6] = r_red_side[6];
    blue_side[7] = r_red_side[7];
    blue_side[8] = r_red_side[8];

    orange_side[6] = r_blue_side[6];
    orange_side[7] = r_blue_side[7];
    orange_side[8] = r_blue_side[8];

    white_side[0] = r_white_side[2];
    white_side[1] = r_white_side[5];
    white_side[2] = r_white_side[8];
    white_side[3] = r_white_side[1];
    white_side[4] = r_white_side[4];
    white_side[5] = r_white_side[7];
    white_side[6] = r_white_side[0];
    white_side[7] = r_white_side[3];
    white_side[8] = r_white_side[6];
  } else {

    delay(del);
    if (withSteps)
      downMove(true, false);


    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }
    green_side[0] = r_red_side[0];
    green_side[1] = r_red_side[1];
    green_side[2] = r_red_side[2];

    red_side[0] = r_blue_side[0];
    red_side[1] = r_blue_side[1];
    red_side[2] = r_blue_side[2];

    blue_side[0] = r_orange_side[0];
    blue_side[1] = r_orange_side[1];
    blue_side[2] = r_orange_side[2];

    orange_side[0] = r_green_side[0];
    orange_side[1] = r_green_side[1];
    orange_side[2] = r_green_side[2];

    yellow_side[0] = r_yellow_side[2];
    yellow_side[1] = r_yellow_side[5];
    yellow_side[2] = r_yellow_side[8];
    yellow_side[3] = r_yellow_side[1];
    yellow_side[4] = r_yellow_side[4];
    yellow_side[5] = r_yellow_side[7];
    yellow_side[6] = r_yellow_side[0];
    yellow_side[7] = r_yellow_side[3];
    yellow_side[8] = r_yellow_side[6];
  }

}

void two_down() {
  moves++;
  Serial.print("2D, ");

  if (!inverted) {

    delay(del);
    if (withSteps)
      downMove(true, true);


    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 2; i++) {
      for (int i = 0; i < 9; i++)
      {
        r_green_side[i] = green_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_orange_side[i] = orange_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_blue_side[i] = blue_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_red_side[i] = red_side[i];
      }

      for (int x = 0; x < 9; x++)
      {
        r_yellow_side[x] = yellow_side[x];
      }
      for (int x = 0; x < 9; x++)
      {
        r_white_side[x] = white_side[x];
      }

      green_side[6] = r_orange_side[6];
      green_side[7] = r_orange_side[7];
      green_side[8] = r_orange_side[8];

      red_side[6] = r_green_side[6];
      red_side[7] = r_green_side[7];
      red_side[8] = r_green_side[8];

      blue_side[6] = r_red_side[6];
      blue_side[7] = r_red_side[7];
      blue_side[8] = r_red_side[8];

      orange_side[6] = r_blue_side[6];
      orange_side[7] = r_blue_side[7];
      orange_side[8] = r_blue_side[8];

      white_side[0] = r_white_side[2];
      white_side[1] = r_white_side[5];
      white_side[2] = r_white_side[8];
      white_side[3] = r_white_side[1];
      white_side[4] = r_white_side[4];
      white_side[5] = r_white_side[7];
      white_side[6] = r_white_side[0];
      white_side[7] = r_white_side[3];
      white_side[8] = r_white_side[6];
    }
  } else {

    delay(del);
    if (withSteps)
      downMove(true, true);

    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 2; i++) {
      for (int i = 0; i < 9; i++)
      {
        r_green_side[i] = green_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_orange_side[i] = orange_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_blue_side[i] = blue_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_red_side[i] = red_side[i];
      }

      for (int x = 0; x < 9; x++)
      {
        r_yellow_side[x] = yellow_side[x];
      }
      for (int x = 0; x < 9; x++)
      {
        r_white_side[x] = white_side[x];
      }
      green_side[0] = r_red_side[0];
      green_side[1] = r_red_side[1];
      green_side[2] = r_red_side[2];

      red_side[0] = r_blue_side[0];
      red_side[1] = r_blue_side[1];
      red_side[2] = r_blue_side[2];

      blue_side[0] = r_orange_side[0];
      blue_side[1] = r_orange_side[1];
      blue_side[2] = r_orange_side[2];

      orange_side[0] = r_green_side[0];
      orange_side[1] = r_green_side[1];
      orange_side[2] = r_green_side[2];

      yellow_side[0] = r_yellow_side[2];
      yellow_side[1] = r_yellow_side[5];
      yellow_side[2] = r_yellow_side[8];
      yellow_side[3] = r_yellow_side[1];
      yellow_side[4] = r_yellow_side[4];
      yellow_side[5] = r_yellow_side[7];
      yellow_side[6] = r_yellow_side[0];
      yellow_side[7] = r_yellow_side[3];
      yellow_side[8] = r_yellow_side[6];
    }
  }
}

void back() {
  moves++;

  Serial.print("B, ");

  if (!inverted) {

    delay(del);
    if (withSteps)
      backMove(false);





    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    yellow_side[0] = r_orange_side[2];
    yellow_side[1] = r_orange_side[5];
    yellow_side[2] = r_orange_side[8];

    red_side[0] = r_yellow_side[2];
    red_side[3] = r_yellow_side[1];
    red_side[6] = r_yellow_side[0];

    white_side[6] = r_red_side[0];
    white_side[7] = r_red_side[3];
    white_side[8] = r_red_side[6];

    orange_side[2] = r_white_side[8];
    orange_side[5] = r_white_side[7];
    orange_side[8] = r_white_side[6];

    blue_side[0] = r_blue_side[6];
    blue_side[1] = r_blue_side[3];
    blue_side[2] = r_blue_side[0];
    blue_side[3] = r_blue_side[7];
    blue_side[4] = r_blue_side[4];
    blue_side[5] = r_blue_side[1];
    blue_side[6] = r_blue_side[8];
    blue_side[7] = r_blue_side[5];
    blue_side[8] = r_blue_side[2];
  } else {

    delay(del);
    if (withSteps)
      backMove(false);



    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }


    orange_side[0] = r_yellow_side[6];
    orange_side[3] = r_yellow_side[7];
    orange_side[6] = r_yellow_side[8];

    yellow_side[6] = r_red_side[8];
    yellow_side[7] = r_red_side[5];
    yellow_side[8] = r_red_side[2];

    red_side[2] = r_white_side[0];
    red_side[5] = r_white_side[1];
    red_side[8] = r_white_side[2];

    white_side[0] = r_orange_side[6];
    white_side[1] = r_orange_side[3];
    white_side[2] = r_orange_side[0];

    green_side[0] = r_green_side[6];
    green_side[1] = r_green_side[3];
    green_side[2] = r_green_side[0];
    green_side[3] = r_green_side[7];
    green_side[4] = r_green_side[4];
    green_side[5] = r_green_side[1];
    green_side[6] = r_green_side[8];
    green_side[7] = r_green_side[5];
    green_side[8] = r_green_side[2];
  }

}

void back_i() {
  moves++;

  Serial.print("B', ");
  if (!inverted) {

    delay(del);
    if (withSteps)
      backMove(true);




    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    yellow_side[0] = r_red_side[6];
    yellow_side[1] = r_red_side[3];
    yellow_side[2] = r_red_side[0];

    red_side[6] = r_white_side[8];
    red_side[3] = r_white_side[7];
    red_side[0] = r_white_side[6];

    white_side[6] = r_orange_side[8];
    white_side[7] = r_orange_side[5];
    white_side[8] = r_orange_side[2];

    orange_side[8] = r_yellow_side[2];
    orange_side[5] = r_yellow_side[1];
    orange_side[2] = r_yellow_side[0];

    blue_side[0] = r_blue_side[2];
    blue_side[1] = r_blue_side[5];
    blue_side[2] = r_blue_side[8];
    blue_side[3] = r_blue_side[1];
    blue_side[4] = r_blue_side[4];
    blue_side[5] = r_blue_side[7];
    blue_side[6] = r_blue_side[0];
    blue_side[7] = r_blue_side[3];
    blue_side[8] = r_blue_side[6];
  } else {

    delay(del);
    if (withSteps)
      backMove(true);





    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    orange_side[0] = r_white_side[2];
    orange_side[3] = r_white_side[1];
    orange_side[6] = r_white_side[0];

    yellow_side[6] = r_orange_side[0];
    yellow_side[7] = r_orange_side[3];
    yellow_side[8] = r_orange_side[6];

    red_side[2] = r_yellow_side[8];
    red_side[5] = r_yellow_side[7];
    red_side[8] = r_yellow_side[6];

    white_side[0] = r_red_side[2];
    white_side[1] = r_red_side[5];
    white_side[2] = r_red_side[8];

    green_side[0] = r_green_side[2];
    green_side[1] = r_green_side[5];
    green_side[2] = r_green_side[8];
    green_side[3] = r_green_side[1];
    green_side[4] = r_green_side[4];
    green_side[5] = r_green_side[7];
    green_side[6] = r_green_side[0];
    green_side[7] = r_green_side[3];
    green_side[8] = r_green_side[6];

  }

}

void up() {
  moves++;

  Serial.print("U, ");

  if (!inverted) {

    delay(del);
    if (withSteps)
      upMove(false, false);

    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    blue_side[0] = r_red_side[0];
    blue_side[1] = r_red_side[1];
    blue_side[2] = r_red_side[2];

    red_side[0] = r_green_side[0];
    red_side[1] = r_green_side[1];
    red_side[2] = r_green_side[2];

    green_side[0] = r_orange_side[0];
    green_side[1] = r_orange_side[1];
    green_side[2] = r_orange_side[2];

    orange_side[0] = r_blue_side[0];
    orange_side[1] = r_blue_side[1];
    orange_side[2] = r_blue_side[2];


    yellow_side[0] = r_yellow_side[6];
    yellow_side[1] = r_yellow_side[3];
    yellow_side[2] = r_yellow_side[0];
    yellow_side[3] = r_yellow_side[7];
    yellow_side[4] = r_yellow_side[4];
    yellow_side[5] = r_yellow_side[1];
    yellow_side[6] = r_yellow_side[8];
    yellow_side[7] = r_yellow_side[5];
    yellow_side[8] = r_yellow_side[2];
  } else {

    delay(del);
    if (withSteps)
      upMove(false, false);


    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    blue_side[6] = r_orange_side[6];
    blue_side[7] = r_orange_side[7];
    blue_side[8] = r_orange_side[8];

    red_side[6] = r_blue_side[6];
    red_side[7] = r_blue_side[7];
    red_side[8] = r_blue_side[8];

    green_side[6] = r_red_side[6];
    green_side[7] = r_red_side[7];
    green_side[8] = r_red_side[8];

    orange_side[6] = r_green_side[6];
    orange_side[7] = r_green_side[7];
    orange_side[8] = r_green_side[8];

    white_side[0] = r_white_side[6];
    white_side[1] = r_white_side[3];
    white_side[2] = r_white_side[0];
    white_side[3] = r_white_side[7];
    white_side[4] = r_white_side[4];
    white_side[5] = r_white_side[1];
    white_side[6] = r_white_side[8];
    white_side[7] = r_white_side[5];
    white_side[8] = r_white_side[2];
  }

}

void up_i() {
  moves++;

  Serial.print("U', ");
  if (!inverted) {

    delay(del);
    if (withSteps)
      upMove(true, false);



    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }
    green_side[0] = r_red_side[0];
    green_side[1] = r_red_side[1];
    green_side[2] = r_red_side[2];

    red_side[0] = r_blue_side[0];
    red_side[1] = r_blue_side[1];
    red_side[2] = r_blue_side[2];

    blue_side[0] = r_orange_side[0];
    blue_side[1] = r_orange_side[1];
    blue_side[2] = r_orange_side[2];

    orange_side[0] = r_green_side[0];
    orange_side[1] = r_green_side[1];
    orange_side[2] = r_green_side[2];

    yellow_side[0] = r_yellow_side[2];
    yellow_side[1] = r_yellow_side[5];
    yellow_side[2] = r_yellow_side[8];
    yellow_side[3] = r_yellow_side[1];
    yellow_side[4] = r_yellow_side[4];
    yellow_side[5] = r_yellow_side[7];
    yellow_side[6] = r_yellow_side[0];
    yellow_side[7] = r_yellow_side[3];
    yellow_side[8] = r_yellow_side[6];
  } else {

    delay(del);
    if (withSteps)
      upMove(true, false);




    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 9; i++)
    {
      r_green_side[i] = green_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_orange_side[i] = orange_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_blue_side[i] = blue_side[i];
    }
    for (int i = 0; i < 9; i++)
    {
      r_red_side[i] = red_side[i];
    }

    for (int x = 0; x < 9; x++)
    {
      r_yellow_side[x] = yellow_side[x];
    }
    for (int x = 0; x < 9; x++)
    {
      r_white_side[x] = white_side[x];
    }

    green_side[6] = r_orange_side[6];
    green_side[7] = r_orange_side[7];
    green_side[8] = r_orange_side[8];

    red_side[6] = r_green_side[6];
    red_side[7] = r_green_side[7];
    red_side[8] = r_green_side[8];

    blue_side[6] = r_red_side[6];
    blue_side[7] = r_red_side[7];
    blue_side[8] = r_red_side[8];

    orange_side[6] = r_blue_side[6];
    orange_side[7] = r_blue_side[7];
    orange_side[8] = r_blue_side[8];

    white_side[0] = r_white_side[2];
    white_side[1] = r_white_side[5];
    white_side[2] = r_white_side[8];
    white_side[3] = r_white_side[1];
    white_side[4] = r_white_side[4];
    white_side[5] = r_white_side[7];
    white_side[6] = r_white_side[0];
    white_side[7] = r_white_side[3];
    white_side[8] = r_white_side[6];
  }
}

void two_up() {
  moves++;

  Serial.print("2U, ");
  if (!inverted) {

    delay(del);
    if (withSteps)
      upMove(true, true);

    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 2; i++) {
      for (int i = 0; i < 9; i++)
      {
        r_green_side[i] = green_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_orange_side[i] = orange_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_blue_side[i] = blue_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_red_side[i] = red_side[i];
      }

      for (int x = 0; x < 9; x++)
      {
        r_yellow_side[x] = yellow_side[x];
      }
      for (int x = 0; x < 9; x++)
      {
        r_white_side[x] = white_side[x];
      }
      green_side[0] = r_red_side[0];
      green_side[1] = r_red_side[1];
      green_side[2] = r_red_side[2];

      red_side[0] = r_blue_side[0];
      red_side[1] = r_blue_side[1];
      red_side[2] = r_blue_side[2];

      blue_side[0] = r_orange_side[0];
      blue_side[1] = r_orange_side[1];
      blue_side[2] = r_orange_side[2];

      orange_side[0] = r_green_side[0];
      orange_side[1] = r_green_side[1];
      orange_side[2] = r_green_side[2];

      yellow_side[0] = r_yellow_side[2];
      yellow_side[1] = r_yellow_side[5];
      yellow_side[2] = r_yellow_side[8];
      yellow_side[3] = r_yellow_side[1];
      yellow_side[4] = r_yellow_side[4];
      yellow_side[5] = r_yellow_side[7];
      yellow_side[6] = r_yellow_side[0];
      yellow_side[7] = r_yellow_side[3];
      yellow_side[8] = r_yellow_side[6];
    }
  } else {

    delay(del);
    if (withSteps)
      upMove(true, true);


    String r_green_side[9];
    String r_blue_side[9];
    String r_orange_side[9];
    String r_red_side[9];
    String r_yellow_side[9];
    String r_white_side[9];
    for (int i = 0; i < 2; i++) {
      for (int i = 0; i < 9; i++)
      {
        r_green_side[i] = green_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_orange_side[i] = orange_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_blue_side[i] = blue_side[i];
      }
      for (int i = 0; i < 9; i++)
      {
        r_red_side[i] = red_side[i];
      }

      for (int x = 0; x < 9; x++)
      {
        r_yellow_side[x] = yellow_side[x];
      }
      for (int x = 0; x < 9; x++)
      {
        r_white_side[x] = white_side[x];
      }

      green_side[6] = r_orange_side[6];
      green_side[7] = r_orange_side[7];
      green_side[8] = r_orange_side[8];

      red_side[6] = r_green_side[6];
      red_side[7] = r_green_side[7];
      red_side[8] = r_green_side[8];

      blue_side[6] = r_red_side[6];
      blue_side[7] = r_red_side[7];
      blue_side[8] = r_red_side[8];

      orange_side[6] = r_blue_side[6];
      orange_side[7] = r_blue_side[7];
      orange_side[8] = r_blue_side[8];

      white_side[0] = r_white_side[2];
      white_side[1] = r_white_side[5];
      white_side[2] = r_white_side[8];
      white_side[3] = r_white_side[1];
      white_side[4] = r_white_side[4];
      white_side[5] = r_white_side[7];
      white_side[6] = r_white_side[0];
      white_side[7] = r_white_side[3];
      white_side[8] = r_white_side[6];
    }
  }
}



void leftMove(bool invertedTurn) {
  if (invertedTurn) {
    leftServo.write(12);
  } else {
    leftServo.write(175);
  }
  delay(motorDelay);
  leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(92);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
}

void downMove(bool invertedTurn, bool doubleTurn) {
  leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(170);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
  frontMoveServo.write(moveAway);
  backMoveServo.write(moveAway);
  delay(motorDelay);

  leftServo.write(92);
  rightServo.write(162);
  delay(motorDelay);
  frontMoveServo.write(moveTowards+1);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  
  rightServo.write(78);
  delay(motorDelay);

  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);

  if (invertedTurn) {
    frontServo.write(0);
  } else {
    frontServo.write(180);
  }
  delay(motorDelay);

  frontMoveServo.write(moveAway);
  delay(motorDelay);
  frontServo.write(85);
  delay(motorDelay);
  frontMoveServo.write(moveTowards+1);
  delay(motorDelay);

  if (doubleTurn) {
    if (invertedTurn) {
      frontServo.write(0);
    } else {
      frontServo.write(180);
    }
    delay(motorDelay);

    frontMoveServo.write(moveAway);
    delay(motorDelay);
    frontServo.write(85);
    delay(motorDelay);
    frontMoveServo.write(moveTowards+1);
    delay(motorDelay);
  }

  leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(12);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
  frontMoveServo.write(moveAway);
  backMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(92);
  rightServo.write(5);
  delay(motorDelay);

  frontMoveServo.write(moveTowards+1);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  rightServo.write(78);
  delay(motorDelay);
  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);
}

void rightMove(bool invertedTurn) {
  if (invertedTurn) {
    rightServo.write(5);
  } else {
    rightServo.write(162);
  }
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  rightServo.write(78);
  delay(motorDelay);
  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);
}

void upMove(bool invertedTurn, bool doubleTurn) {
  leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(12);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
  frontMoveServo.write(moveAway);
  backMoveServo.write(moveAway);
  delay(motorDelay);

  leftServo.write(92);
  rightServo.write(5);
  delay(motorDelay);

  frontMoveServo.write(moveTowards+1);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  rightServo.write(78);
  delay(motorDelay);
  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);

  if (invertedTurn) {
    frontServo.write(0);
  } else {
    frontServo.write(180);
  }
  delay(motorDelay);

  frontMoveServo.write(moveAway);
  delay(motorDelay);
  frontServo.write(83);
  delay(motorDelay);
  frontMoveServo.write(moveTowards+1);
  delay(motorDelay);

  if (doubleTurn) {
    if (invertedTurn) {
      frontServo.write(0);
    } else {
      frontServo.write(180);
    }
    delay(motorDelay);

    frontMoveServo.write(moveAway);
    delay(motorDelay);
    frontServo.write(83);
    delay(motorDelay);
    frontMoveServo.write(moveTowards+1);
    delay(motorDelay);

  }

  leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(170);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
  backMoveServo.write(moveAway);
  frontMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(92);
  rightServo.write(162);
  delay(motorDelay);

  frontMoveServo.write(moveTowards+1);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  rightServo.write(78);
  delay(motorDelay);
  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);
}

void frontMove(bool invertedTurn) {
  if (invertedTurn) {
    frontServo.write(0);
  } else {
    frontServo.write(180);
  }
  delay(motorDelay);
  frontMoveServo.write(moveAway);
  delay(motorDelay);
  frontServo.write(85);
  delay(motorDelay);
  frontMoveServo.write(moveTowards+1);
  delay(motorDelay);
}

void backMove(bool invertedTurn) {
  if (invertedTurn) {
    backServo.write(0);
  } else {
    backServo.write(180);
  }
  delay(motorDelay);
  backMoveServo.write(moveAway);
  delay(motorDelay);
  backServo.write(83);
  delay(motorDelay);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
}






//**solving cubes**
void cross() {
  Serial.println();
  Serial.println();
  Serial.println("cross: ");
  //make cross
  while (yellow_side[1] != "y1" || yellow_side[3] != "y3" || yellow_side[5] != "y5" || yellow_side[7] != "y7") {
    while (yellow_side[1] != "y1" ) {
      Serial.println("1: ");
      putEdges("y1");
      if (yellow_side[3] == "y1" ) {
        left();
        left();
        down_i();
        back();
        back();
      } else if (yellow_side[5] == "y1" ) {
        right();
        right();
        down();
        back();
        back();
      } else if (yellow_side[7] == "y1" ) {
        front();
        front();
        two_down();
        back();
        back();
      }

    }
    while (yellow_side[3] != "y3" ) {
      Serial.println("2: ");
      up();
      putEdges("y3");
      if (yellow_side[5] == "y1" ) {
        right();
        right();
        down();
        back();
        back();
      } else if (yellow_side[7] == "y1" ) {
        front();
        front();
        two_down();
        back();
        back();
      }
      up_i();

    }
    while (yellow_side[5] != "y5") {
      Serial.println("3: ");
      up_i();
      putEdges("y5");
      if (yellow_side[7] == "y1" ) {
        front();
        front();
        two_down();
        back();
        back();
      }
      up();


    }
    while (yellow_side[7] != "y7") {
      Serial.println("4: ");
      up();
      up();
      putEdges("y7");
      up();
      up();
    }

  }
}//end of cross

void corners() {
  Serial.println();
  Serial.println();
  Serial.println("corner: ");
  while (yellow_side[0] != "y0" || yellow_side[2] != "y2" || yellow_side[6] != "y6" || yellow_side[8] != "y8") {
    while (yellow_side[0] != "y0") {
      Serial.println("1: ");
      if (green_side[6] == "y0") {
        two_up();
        down();
        placeCornerRight();
        two_up();
      } else  if (green_side[8] == "y0") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[6] == "y0") {
        two_up();
        placeCornerRight();
        two_up();
      } else  if (blue_side[6] == "y0") {
        down_i();
        two_up();
        placeCornerRight();
        two_up();
      } else  if (blue_side[8] == "y0") {
        two_down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (red_side[6] == "y0") {
        two_down();
        two_up();
        placeCornerRight();
        two_up();
      } else  if (red_side[8] == "y0") {
        down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (red_side[0] == "y0") {
        two_up();
        placeCornerRight();
        two_up();
      } else  if (red_side[2] == "y0") {
        up_i();
        placeCornerLeft();
        up();
      } else  if (blue_side[0] == "y0") {
        up();
        placeCornerRight();
        up_i();
      } else  if (blue_side[2] == "y0") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[0] == "y0") {
        placeCornerRight();
      } else  if (orange_side[2] == "y0") {
        up();
        placeCornerLeft();
        up_i();
      } else  if (green_side[0] == "y0") {
        up_i();
        placeCornerRight();
        up();
      } else  if (green_side[2] == "y0") {
        placeCornerLeft();
      } else  if (white_side[0] == "y0") {
        down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[2] == "y0") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[6] == "y0") {
        two_down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[8] == "y0") {
        down_i();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[8] == "y0") {
        two_up();
        down_i();
        placeCornerLeft();
        two_up();
      } else  if (yellow_side[8] == "y0") {
        placeCornerRight();
      } else  if (yellow_side[6] == "y0") {
        up_i();
        placeCornerRight();
        up();
      } else  if (yellow_side[2] == "y0") {
        up();
        placeCornerRight();
        up_i();
      } else {
        Serial.println("error cant find peice");

        break;
      }
    }

    while (yellow_side[2] != "y2") {
      Serial.println("2: ");

      if (green_side[6] == "y2") {
        up();
        down();
        placeCornerRight();
        up_i();
      } else  if (green_side[8] == "y2") {
        up();
        placeCornerLeft();
        up_i();
      } else  if (orange_side[6] == "y2") {
        up();
        placeCornerRight();
        up_i();
      } else  if (orange_side[8] == "y2") {
        up();
        down_i();
        placeCornerLeft();
        up_i();
      } else  if (blue_side[6] == "y2") {
        down_i();
        up();
        placeCornerRight();
        up_i();
      } else  if (blue_side[8] == "y2") {
        two_down();
        up();
        placeCornerLeft();
        up_i();
      } else  if (red_side[6] == "y2") {
        two_down();
        up();
        placeCornerRight();
        up_i();
      } else  if (red_side[8] == "y2") {
        down();
        up();
        placeCornerLeft();
        up_i();
      } else  if (red_side[0] == "y2") {
        two_up();
        placeCornerRight();
        two_up();
      } else  if (red_side[2] == "y2") {
        up_i();
        placeCornerLeft();
        up();
      } else  if (blue_side[0] == "y2") {
        up();
        placeCornerRight();
        up_i();
      } else  if (blue_side[2] == "y2") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[0] == "y2") {
        placeCornerRight();
      } else  if (orange_side[2] == "y2") {
        up();
        placeCornerLeft();
        up_i();
      } else  if (green_side[0] == "y2") {
        up_i();
        placeCornerRight();
        up();
      } else  if (green_side[2] == "y2") {
        placeCornerLeft();
      } else  if (white_side[0] == "y2") {
        down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[2] == "y2") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[6] == "y2") {
        two_down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[8] == "y2") {
        down_i();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (yellow_side[8] == "y2") {
        placeCornerRight();
      } else  if (yellow_side[6] == "y2") {
        up_i();
        placeCornerRight();
        up();
      } else {
        Serial.println("error cant find peice");
        corners();
        break;
      }
    }

    while (yellow_side[6] != "y6") {
      Serial.println("3: ");
      if (green_side[6] == "y6") {
        down();
        up_i();
        placeCornerRight();
        up();
      } else  if (green_side[8] == "y6") {
        placeCornerLeft();
      } else  if (orange_side[6] == "y6") {
        placeCornerRight();
      } else  if (blue_side[6] == "y6") {
        down_i();
        placeCornerRight();
      } else  if (blue_side[8] == "y6") {
        two_down();
        up_i();
        placeCornerLeft();
        up();
      } else  if (red_side[6] == "y6") {
        two_down();
        placeCornerRight();
      } else  if (red_side[8] == "y6") {
        down();
        placeCornerLeft();
      } else  if (red_side[0] == "y6") {
        two_up();
        placeCornerRight();
        two_up();
      } else  if (red_side[2] == "y6") {
        up_i();
        placeCornerLeft();
        up();
      } else  if (blue_side[0] == "y6") {
        up();
        placeCornerRight();
        up_i();
      } else  if (blue_side[2] == "y6") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[0] == "y6") {
        placeCornerRight();
      } else  if (orange_side[2] == "y6") {
        up();
        placeCornerLeft();
        up_i();
      } else  if (green_side[0] == "y6") {
        up_i();
        placeCornerRight();
        up();
      } else  if (green_side[2] == "y6") {
        placeCornerLeft();
      } else  if (white_side[0] == "y6") {
        down();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[2] == "y6") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (white_side[6] == "y6") {
        two_down();
        up_i();
        placeCornerLeft();
        up();
      } else  if (white_side[8] == "y6") {
        down_i();
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[8] == "y6") {
        up_i();
        down_i();
        placeCornerLeft();
        up();
      } else  if (yellow_side[8] == "y6") {
        placeCornerRight();
      } else {
        Serial.println("error cant find peice");
        corners();
        break;
      }
    }

    while (yellow_side[8] != "y8") {
      Serial.println("4: ");
      if (green_side[6] == "y8") {
        down();
        placeCornerRight();
      } else  if (green_side[8] == "y8") {
        placeCornerLeft();
      } else  if (orange_side[6] == "y8") {
        placeCornerRight();
      } else  if (blue_side[6] == "y8") {
        down_i();
        placeCornerRight();
      } else  if (blue_side[8] == "y8") {
        two_down();
        placeCornerLeft();
      } else  if (red_side[6] == "y8") {
        two_down();
        placeCornerRight();
      } else  if (red_side[8] == "y8") {
        down();
        placeCornerLeft();
      } else  if (red_side[0] == "y8") {
        two_up();
        placeCornerRight();
        two_up();
      } else  if (red_side[2] == "y8") {
        up_i();
        placeCornerLeft();
        up();
      } else  if (blue_side[0] == "y8") {
        up();
        placeCornerRight();
        up_i();
      } else  if (blue_side[2] == "y8") {
        two_up();
        placeCornerLeft();
        two_up();
      } else  if (orange_side[0] == "y8") {
        placeCornerRight();
      } else  if (orange_side[2] == "y8") {
        up();
        placeCornerLeft();
        up_i();
      } else  if (green_side[0] == "y8") {
        up_i();
        placeCornerRight();
        up();
      } else  if (green_side[2] == "y8") {
        placeCornerLeft();
      } else  if (white_side[0] == "y8") {
        down();
        placeCornerLeft();
      } else  if (white_side[2] == "y8") {
        placeCornerLeft();
      } else  if (white_side[6] == "y8") {
        two_down();
        placeCornerLeft();
      } else  if (white_side[8] == "y8") {
        down_i();
        placeCornerLeft();
      } else  if (orange_side[8] == "y8") {
        down_i();
        placeCornerLeft();
      } else {
        Serial.println("error cant find peice");
        corners();
        break;
      }
    }
  }
}

void edges() {

  Serial.println();
  Serial.println();
  Serial.println("edges: ");
  while (orange_side[3] != "o3" || orange_side[5] != "o5" || red_side[3] != "r3" || red_side[5] != "r5") {
    Serial.println("edge retry");
    if (green_side[7] == "g3") {
      greenLeft();
    } else if (green_side[7] == "g5") {
      greenRight();
    } else if (orange_side[7] == "g3") {
      down_i();
      greenLeft();
    } else if (orange_side[7] == "g5") {
      down_i();
      greenRight();
    } else if (blue_side[7] == "g3") {
      two_down();
      greenLeft();
    } else if (blue_side[7] == "g5") {
      two_down();
      greenRight();
    } else if (red_side[7] == "g3") {
      down();
      greenLeft();

    } else if (red_side[7] == "g5") {
      down();
      greenRight();
    }

    if (green_side[7] == "o3") {
      down();
      orangeLeft();
    } else if (green_side[7] == "o5") {
      down();
      orangeRight();
    } else if (orange_side[7] == "o3") {
      orangeLeft();

    } else if (orange_side[7] == "o5") {
      orangeRight();

    } else if (blue_side[7] == "o3") {
      down_i();
      orangeLeft();

    } else if (blue_side[7] == "o5") {
      down_i();
      orangeRight();
    } else if (red_side[7] == "o3") {
      two_down();
      orangeLeft();

    } else if (red_side[7] == "o5") {
      two_down();
      orangeRight();

    }

    if (green_side[7] == "b3") {
      two_down();
      blueLeft();
    } else if (green_side[7] == "b5") {
      two_down();
      blueRight();
    } else if (orange_side[7] == "b3") {
      down();
      blueLeft();

    } else if (orange_side[7] == "b5") {
      down();
      blueRight();

    } else if (blue_side[7] == "b3") {
      blueLeft();

    } else if (blue_side[7] == "b5") {
      blueRight();
    } else if (red_side[7] == "b3") {
      down_i();
      blueLeft();
    } else if (red_side[7] == "b5") {
      down_i();
      blueRight();
    }

    if (green_side[7] == "r3") {
      down_i();
      redLeft();
    } else if (green_side[7] == "r5") {
      down_i();
      redRight();
    } else if (orange_side[7] == "r3") {
      two_down();
      redLeft();

      two_down();
      redRight();

    } else if (blue_side[7] == "r3") {
      down();
      redLeft();

    } else if (blue_side[7] == "r5") {
      down();
      redRight();
    } else if (red_side[7] == "r3") {
      redLeft();

    } else if (red_side[7] == "r5") {
      redRight();


    }

    if (red_side[5] == "g5" || red_side[5] == "g3" || red_side[5] == "o5" || red_side[5] == "o3" || red_side[5] == "b5" || red_side[5] == "b3" || red_side[5] == "r3") {
      redRight();

    } else if (red_side[3] == "g5" || red_side[3] == "g3" || red_side[3] == "o5" || red_side[3] == "o3" || red_side[3] == "b5" || red_side[3] == "b3" || red_side[3] == "r5") {
      redLeft();

    } else if (green_side[5] == "r5" || green_side[5] == "g3" || green_side[5] == "o5" || green_side[5] == "o3" || green_side[5] == "b5" || green_side[5] == "b3" || green_side[5] == "r3") {
      greenRight();

    } else if (green_side[3] == "g5" || green_side[3] == "r5" || green_side[3] == "o5" || green_side[3] == "o3" || green_side[3] == "b5" || green_side[3] == "b3" || green_side[3] == "r3") {
      greenLeft();

    } else if (blue_side[5] == "g5" || blue_side[5] == "g3" || blue_side[5] == "o5" || blue_side[5] == "o3" || blue_side[5] == "r5" || blue_side[5] == "b3" || blue_side[5] == "r3") {
      blueRight();

    } else if (blue_side[3] == "g5" || blue_side[3] == "g3" || blue_side[3] == "o5" || blue_side[3] == "o3" || blue_side[3] == "b5" || blue_side[3] == "r5" || blue_side[3] == "r3") {
      blueLeft();

    } else if (orange_side[5] == "g5" || orange_side[5] == "g3" || orange_side[5] == "r5" || orange_side[5] == "o3" || orange_side[5] == "b5" || orange_side[5] == "b3" || orange_side[5] == "r3") {
      orangeRight();

    } else if (orange_side[3] == "g5" || orange_side[3] == "g3" || orange_side[3] == "o5" || orange_side[3] == "r5" || orange_side[3] == "b5" || orange_side[3] == "b3" || orange_side[3] == "r3") {
      orangeLeft();

    }

  }



}

void bottomCross() {
  Serial.println();
  Serial.println();
  Serial.println("bottom cross: ");
  flipCube();
  inverted = true;
  Serial.println("flip cube");
  while (white_side[1].charAt(0) != 'w' || white_side[3].charAt(0) != 'w' || white_side[5].charAt(0) != 'w' || white_side[7].charAt(0) != 'w') {
    if (white_side[0].charAt(0) == 'w' && white_side[8].charAt(0) == 'w' && orange_side[7].charAt(0) == 'w' && green_side[7].charAt(0) == 'w' && green_side[8].charAt(0) == 'w' && red_side[7].charAt(0) == 'w' && red_side[6].charAt(0) == 'w' && blue_side[7].charAt(0) == 'w') {
      diagonal();
    } else if (white_side[0].charAt(0) == 'w' && white_side[8].charAt(0) == 'w' && red_side[7].charAt(0) == 'w' && blue_side[7].charAt(0) == 'w' && blue_side[8].charAt(0) == 'w' && orange_side[7].charAt(0) == 'w' && orange_side[6].charAt(0) == 'w' && green_side[7].charAt(0) == 'w') {
      two_up();
      diagonal();
    } else if (white_side[2].charAt(0) == 'w' && white_side[6].charAt(0) == 'w' && green_side[7].charAt(0) == 'w' && red_side[7].charAt(0) == 'w' && red_side[8].charAt(0) == 'w' && blue_side[7].charAt(0) == 'w' && blue_side[6].charAt(0) == 'w' && orange_side[7].charAt(0) == 'w') {
      up();
      diagonal();
    } else if (white_side[2].charAt(0) == 'w' && white_side[6].charAt(0) == 'w' && blue_side[7].charAt(0) == 'w' && orange_side[7].charAt(0) == 'w' && orange_side[8].charAt(0) == 'w' && green_side[7].charAt(0) == 'w' && green_side[6].charAt(0) == 'w' && red_side[7].charAt(0) == 'w') {
      up_i();
      diagonal();
    } else if (orange_side[6].charAt(0) == 'w' && orange_side[7].charAt(0) == 'w' && orange_side[8].charAt(0) == 'w' && red_side[6].charAt(0) == 'w' && red_side[7].charAt(0) == 'w' && red_side[8].charAt(0) == 'w' && blue_side[7].charAt(0) == 'w') {
      allRight();
    } else if (blue_side[6].charAt(0) == 'w' && blue_side[7].charAt(0) == 'w' && blue_side[8].charAt(0) == 'w' && green_side[6].charAt(0) == 'w' && green_side[7].charAt(0) == 'w' && green_side[8].charAt(0) == 'w' && red_side[7].charAt(0) == 'w') {
      up();
      allRight();
    } else if (white_side[1].charAt(0) == 'w' && white_side[7].charAt(0) == 'w') {
      up();
      line();
    } else if (white_side[3].charAt(0) == 'w' && white_side[5].charAt(0) == 'w') {
      line();
    } else if (white_side[1].charAt(0) == 'w' && white_side[3].charAt(0) == 'w') {
      line();
    } else if (white_side[1].charAt(0) == 'w' && white_side[5].charAt(0) == 'w') {
      up_i();
      line();
    } else if (white_side[3].charAt(0) == 'w' && white_side[7].charAt(0) == 'w') {
      up();
      line();

    } else if (white_side[5].charAt(0) == 'w' && white_side[7].charAt(0) == 'w') {
      two_up();
      line();
    } else {
      line();
    }
  }

}

void bottomCorners() {
  Serial.println();
  Serial.println();
  Serial.println("bottom corners: ");
  while (white_side[0].charAt(0) != 'w' || white_side[2].charAt(0) != 'w' || white_side[6].charAt(0) != 'w' || white_side[8].charAt(0) != 'w') {
    Serial.println("attempt: ");
    //one
    if (white_side[0].charAt(0) != 'w' && white_side[2].charAt(0) != 'w' && white_side[6].charAt(0) != 'w' && white_side[8].charAt(0) == 'w') {
      Serial.println("one: 8 ");
      if (green_side[8].charAt(0) == 'w') {
        up();
        one();
        two_up();
        one();

      } else {
        up();
        one();

      }
    } else if (white_side[8].charAt(0) != 'w' && white_side[2].charAt(0) != 'w' && white_side[6].charAt(0) != 'w' && white_side[0].charAt(0) == 'w') {
      Serial.println("one: 0 ");

      if (blue_side[8].charAt(0) == 'w') {
        up_i();
        one();
        two_up();
        one();
      } else {
        up_i();
        one();
      }
    } else if (white_side[0].charAt(0) != 'w' && white_side[8].charAt(0) != 'w' && white_side[6].charAt(0) != 'w' && white_side[2].charAt(0) == 'w') {
      Serial.println("one: 2 ");
      if (red_side[8].charAt(0) == 'w') {
        two_up();
        one();
        two_up();
        one();
      } else {
        two_up();
        one();
      }
    } else if (white_side[0].charAt(0) != 'w' && white_side[2].charAt(0) != 'w' && white_side[8].charAt(0) != 'w' && white_side[6].charAt(0) == 'w') {
      Serial.println("one: 6 ");
      if (orange_side[8].charAt(0) == 'w') {
        one();
        two_up();
        one();
      } else {
        one();
      }
    }

    //none
    if (white_side[0].charAt(0) != 'w' && white_side[2].charAt(0) != 'w' && white_side[6].charAt(0) != 'w' && white_side[8].charAt(0) != 'w') {
      Serial.println("none: ");
      if (red_side[8].charAt(0) == 'w' && red_side[6].charAt(0) == 'w' && orange_side[8].charAt(0) == 'w' && orange_side[6].charAt(0) == 'w') {
        up();
        noneSame();
      } else if (green_side[8].charAt(0) == 'w' && green_side[6].charAt(0) == 'w' && blue_side[8].charAt(0) == 'w' && blue_side[6].charAt(0) == 'w') {
        noneSame();
      } else if (blue_side[6].charAt(0) == 'w' && red_side[6].charAt(0) == 'w' && red_side[8].charAt(0) == 'w') {
        noneDiff();
      } else if (blue_side[8].charAt(0) == 'w' && blue_side[6].charAt(0) == 'w' && orange_side[6].charAt(0) == 'w') {
        up();
        noneDiff();
      } else if (orange_side[8].charAt(0) == 'w' && orange_side[6].charAt(0) == 'w' && green_side[6].charAt(0) == 'w') {
        two_up();
        noneDiff();
      } else if (green_side[8].charAt(0) == 'w' && green_side[6].charAt(0) == 'w' && red_side[6].charAt(0) == 'w') {
        up_i();
        noneDiff();
      }

    }

    //two
    if (white_side[0].charAt(0) != 'w' && white_side[2].charAt(0) != 'w' && white_side[6].charAt(0) == 'w' && white_side[8].charAt(0) == 'w') {
      Serial.println("two: ");
      if (green_side[0].charAt(0) == 'w') {
        two_up();
        twoFront();
      } else {
        two_up();
        twoSide();
      }
    } else if (white_side[0].charAt(0) == 'w' && white_side[2].charAt(0) == 'w' && white_side[6].charAt(0) != 'w' && white_side[8].charAt(0) != 'w') {
      if (blue_side[0].charAt(0) == 'w') {
        twoFront();
      } else {
        twoSide();
      }
    } else if (white_side[0].charAt(0) == 'w' && white_side[2].charAt(0) != 'w' && white_side[6].charAt(0) == 'w' && white_side[8].charAt(0) != 'w') {
      if (orange_side[0].charAt(0) == 'w') {
        up();
        twoFront();
      } else {
        up();
        twoSide();
      }
    } else if (white_side[0].charAt(0) != 'w' && white_side[2].charAt(0) == 'w' && white_side[6].charAt(0) != 'w' && white_side[8].charAt(0) == 'w') {
      if (red_side[0].charAt(0) == 'w') {
        up_i();
        twoFront();
      } else {
        up_i();
        twoSide();
      }
    } else if (white_side[0].charAt(0) == 'w' && white_side[2].charAt(0) != 'w' && white_side[6].charAt(0) != 'w' && white_side[8].charAt(0) == 'w') {
      if (blue_side[0].charAt(0) == 'w') {
        twoOpp();
      } else {
        two_up();
        twoSide();
      }
    } else if (white_side[0].charAt(0) != 'w' && white_side[2].charAt(0) == 'w' && white_side[6].charAt(0) == 'w' && white_side[8].charAt(0) != 'w') {
      if (red_side[0].charAt(0) == 'w') {
        up_i();
        twoOpp();
      } else {
        up();
        twoSide();
      }
    }

  }
}

void PLLCorner() {
  Serial.println();
  Serial.println();
  Serial.println("PLL corners: ");
  while (red_side[6].charAt(0) != red_side[8].charAt(0) || orange_side[6].charAt(0) != orange_side[8].charAt(0) || green_side[6].charAt(0) != green_side[8].charAt(0) || blue_side[6].charAt(0) != blue_side[8].charAt(0) ) {
    Serial.println("attempt: ");

    if (green_side[8].charAt(0) == green_side[6].charAt(0)) {
      ref();
    } else if (red_side[8].charAt(0) == red_side[6].charAt(0)) {
      up();
      ref();
    } else if (blue_side[8].charAt(0) == blue_side[6].charAt(0)) {
      two_up();
      ref();
    } else if (orange_side[8].charAt(0) == orange_side[6].charAt(0)) {
      up_i();
      ref();
    } else {
      doubleRef();
    }
  }
}

void PLLEdge() {
  Serial.println();
  Serial.println();
  Serial.println("PLL edges: ");
  while (blue_side[6].charAt(0) != blue_side[7].charAt(0) || green_side[6].charAt(0) != green_side[7].charAt(0) ) {

    if (blue_side[6].charAt(0) == blue_side[7].charAt(0)) {
      two_up();
    } else if (red_side[6].charAt(0) == red_side[7].charAt(0)) {
      up();
    } else if (orange_side[6].charAt(0) == orange_side[7].charAt(0)) {
      up_i();
    }
    edgeSwitch();

  }
  while (white_side[0] != "w0") {
    if (white_side[2] == "w0") {
      up_i();
    } else if(white_side[0] == "w8") {
      two_up();
    }else{
      up();
    }
  }

}



//**algorithmes**

//edges algorithems
void greenLeft() {
  down();
  left();
  down();
  left_i();
  down_i();
  front_i();
  down_i();
  front();
}

void greenRight() {
  down_i();
  right_i();
  down_i();
  right();
  down();
  placeCornerLeft();
}

void orangeLeft() {
  down();
  front();
  down();
  front_i();
  down_i();
  right_i();
  down_i();
  right();
}

void orangeRight() {
  down_i();
  back_i();
  down_i();
  back();
  down();
  right();
  down();
  right_i();
}

void blueLeft() {
  down();
  right();
  down();
  right_i();
  down_i();
  back_i();
  down_i();
  back();
}

void blueRight() {
  down_i();
  left_i();
  down_i();
  left();
  down();
  back();
  down();
  back_i();
}

void redLeft() {
  down();
  back();
  down();
  back_i();
  down_i();
  left_i();
  down_i();
  left();
}

void redRight() {
  down_i();
  front_i();
  down_i();
  front();
  down();
  left();
  down();
  left_i();
}



//cross algorithmes
void putEdges(String peice) {
  if (green_side[3] == peice ) {
    up_i();
    left_i();
    up();
  } else if (green_side[5] == peice ) {
    up();
    right();
    up_i();
  } else if (green_side[7] == peice ) {
    down();
    up();
    right_i();
    up_i();
    back();
  } else  if (orange_side[3] == peice ) {
    two_up();
    front_i();
    two_up();
  } else if (orange_side[5] == peice ) {
    back();
  } else if (orange_side[7] == peice ) {
    up();
    right_i();
    up_i();
    back();
  } else  if (white_side[3] == peice ) {
    down_i();
    back();
    back();
  } else if (white_side[5] == peice ) {
    down();
    back();
    back();
  } else if (white_side[7] == peice ) {
    back();
    back();
  } else  if (blue_side[3] == peice ) {
    up();
    right_i();
    up_i();
  } else if (blue_side[5] == peice ) {
    up_i();
    left();
    up();
  } else if (blue_side[7] == peice ) {
    down();
    up_i();
    left();
    up();
    back_i();
  } else  if (red_side[3] == peice ) {
    back_i();
  } else if (red_side[5] == peice ) {
    two_up();
    front();
    two_up();
  } else if (red_side[7] == peice ) {
    up_i();
    left();
    up();
    back_i();
  } else if (red_side[1] == peice ) {
    left_i();
    back_i();
  } else if (orange_side[1] == peice ) {
    right();
    back();
  } else if (green_side[1] == peice ) {
    front();
    two_up();
    front_i();
    two_up();
  } else if (white_side[1] == peice ) {
    two_down();
    back();
    back();
  } else if (blue_side[1] == peice ) {
    back_i();
    up();
    right_i();
    up_i();
  } else if (yellow_side[3] == peice ) {
    left();
    left();
    down_i();
    back();
    back();
    left();
    left();
  } else if (yellow_side[5] == peice ) {
    right();
    right();
    down();
    back();
    back();
    right();
    right();
  } else if (yellow_side[7] == peice ) {
    front();
    front();
    two_down();
    back();
    back();
    front();
    front();
  } else {
    Serial.println("error cant find peice");
  }
}



//bottom PLL algorithmes
void ref() {
  right_i();
  front();
  right_i();
  back();
  back();
  right();
  front_i();
  right_i();
  back();
  back();
  right();
  right();
}

void edgeSwitch() {
  front();
  front();
  up();
  right_i();
  left();
  front();
  front();
  right();
  left_i();
  up();
  front();
  front();
}

void doubleRef() {
  front();
  right();
  up_i();
  right_i();
  up_i();
  right();
  up();
  right_i();
  front_i();
  right();
  up();
  right_i();
  up_i();
  right_i();
  front();
  right();
  front_i();
}

//bottom cross algorithmes
void line() {
  front();
  right();
  up();
  right_i();
  up_i();
  front_i();
}

void diagonal() {
  right();
  up();
  right_i();
  up();
  right_i();
  front();
  right();
  front_i();
  two_up();
  right_i();
  front();
  right();
  front_i();

}

void allRight() {
  right();
  two_up();
  right();
  right();
  front();
  right();
  front_i();
  two_up();
  right_i();
  front();
  right();
  front_i();
}



//bottom edge algorithmes
void one() {
  right();
  up();
  right_i();
  up();
  right();
  two_up();
  right_i();
}

void twoFront() {
  right();
  right();
  down();
  right_i();
  two_up();
  right();
  down_i();
  right_i();
  two_up();
  right_i();
}

void twoSide() {
  one();
  up();
  one();
  two_up();
  one();
}

void twoOpp() {
  right_i();
  front();
  right();
  back_i();
  right_i();
  front_i();
  right();
  back();

}

void noneSame() {
  right();
  two_up();
  right_i();
  up_i();
  right();
  up();
  right_i();
  up_i();
  right();
  up_i();
  right_i();
}

void noneDiff() {
  right();
  two_up();
  right();
  right();
  up_i();
  right();
  right();
  up_i();
  right();
  right();
  two_up();
  right();

}


void flipCube(){
leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(12);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
  frontMoveServo.write(moveAway);
  backMoveServo.write(moveAway);
  delay(motorDelay);

  leftServo.write(92);
  rightServo.write(5);
  delay(motorDelay);

  frontMoveServo.write(moveTowards+1);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  rightServo.write(78);
  delay(motorDelay);
  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);leftMoveServo.write(moveAway);
  delay(motorDelay);
  leftServo.write(12);
  delay(motorDelay);
  leftMoveServo.write(moveTowards-1);
  delay(motorDelay);
  frontMoveServo.write(moveAway);
  backMoveServo.write(moveAway);
  delay(motorDelay);

  leftServo.write(92);
  rightServo.write(5);
  delay(motorDelay);

  frontMoveServo.write(moveTowards+1);
  backMoveServo.write(moveTowards);
  delay(motorDelay);
  rightMoveServo.write(moveAway);
  delay(motorDelay);
  rightServo.write(78);
  delay(motorDelay);
  rightMoveServo.write(moveTowards-1);
  delay(motorDelay);
}


//top corner algorithmes
void placeCornerLeft() {
  front();
  down();
  front_i();
}

void placeCornerRight() {
  right_i();
  down();
  right();
}



//printing functions
void print_cube(String cube_side[]) {
  // make a for loop for this
  for (int i = 0; i < 1; i++)
  {
    Serial.println('\r');
  }

  Serial.print("Face: ");
  Serial.println(cube_side[4]);

  for (int i = 0; i < 9; i = i + 3)
  {
    Serial.print("|");
    Serial.print(cube_side[i]);
    Serial.print("|");
    Serial.print(cube_side[i + 1]);
    Serial.print("|");
    Serial.print(cube_side[i + 2]);
    Serial.println("|");
  }
}

void print_whole_cube() {
  print_cube(yellow_side);
  print_cube(white_side);
  print_cube(blue_side);
  print_cube(red_side);
  print_cube(green_side);
  print_cube(orange_side);
}



void scramble() {
  digitalWrite(22,HIGH);
    digitalWrite(24,LOW);
  Serial.println();
  Serial.println("Scramble: ");
  int move = random(1, 14);
  int past = random(1, 14);
  int pastP = random(1, 14);
  for (int j = 0; j < 25; j++)
  {
    randomSeed(analogRead(3));
    pastP = past;
    past = move;
    move = random(1, 14);
    while (move - 1 == past && past % 2 == 0 || move + 1 == past && past % 2 == 1 || pastP == move) {
      move = random(1, 14);
    }
    switch (move)
    {
      case 1:
        right();
        break;
      case 2:
        right_i();
        break;
      case 3:
        left();
        break;
      case 4:
        left_i();
        break;
      case 5:
        up();
        break;
      case 6:
        up_i();
        break;
      case 7:
        down();
        break;
      case 8:
        down_i();
        break;
      case 9:
        front();
        break;
      case 10:
        front_i();
        break;
      case 11:
        back();
        break;
      case 12:
        back_i();
        break;
      case 13:
        two_down();
        break;
       case 14:
        two_up();
        break;
    }
  }
  Serial.println();
  Serial.println("done scramble");
}

void error(){
        while(true){
        digitalWrite(22,HIGH);
    digitalWrite(24,LOW);
    delay(500);
          digitalWrite(22,LOW);
    digitalWrite(24,LOW);
    delay(500);
        }
}

void reciveCube(){
     char cube[109];
cube[108]='p';
  while(cube[108]!='-'){
    if(Serial.available()){
      //delay(50);
      String test =Serial.readString();
Serial.print(test);
for (int i=0; i <109 ; i++){
  cube[i]=test.charAt(i);
}
//      }
    }
        digitalWrite(24,HIGH);
    digitalWrite(22,LOW);
 
    }

      digitalWrite(22,HIGH);
    digitalWrite(24,LOW);

for (int i = 0;i<108;i++){
  if (cube[i]=='x'){
    error();
  }
}

        for (int i = 0;i<18;i++){
  green_side[i/2]=String(cube[i]);
  green_side[i/2]=String(green_side[i/2]+cube[i+1]);
    i++;
        }
        for (int i = 0;i<18;i++){
      blue_side[i/2]=String(cube[i+18]);
  blue_side[i/2]=String(blue_side[i/2]+cube[i+19]);
    i++;
        }
    for (int i = 0;i<18;i++){
          red_side[i/2]=String(cube[i+36]);
  red_side[i/2]=String(red_side[i/2]+cube[i+37]);
    i++;
    }
    
    for (int i = 0;i<18;i++){
          orange_side[i/2]=String(cube[i+54]);
  orange_side[i/2]=String(orange_side[i/2]+cube[i+55]);
    i++;
    }
  
    for (int i = 0;i<18;i++){
      yellow_side[i/2]=String(cube[i+72]);
  yellow_side[i/2]=String(yellow_side[i/2]+cube[i+73]);
    i++;
    }
  
    for (int i = 0;i<18;i++){
      white_side[i/2]=String(cube[i+90]);
  white_side[i/2]=String(white_side[i/2]+cube[i+91]);
    i++;
    }

    
  
  
   print_whole_cube();
    digitalWrite(22,LOW);
    digitalWrite(24,LOW);
}


//testing functions
void testTurns() {
//  up();
//  up_i();
  two_up();
//  down();
//  down_i();
  two_down();
  left();
  left_i();
  right();
  right_i();
  front();
  front_i();
  back();
  back_i();

}

void test(int amount) {
  withSteps = false;
  int least = 1000;
  int smallest;
  for (int i = 0; i < amount; i++) {
    scramble();
    solve();
    if (moves < least) {
      least = moves;
      smallest = i;
    }
    Serial.println();
    Serial.print("solved in ");
    Serial.print(moves);
    Serial.println(" moves");
    Serial.print(reduced);
    Serial.print(" moves avoided");
    Serial.println();
    Serial.print("solve number ");
    Serial.print(i);
    moves = -25;
    inverted = false;
  }
  Serial.println();
  Serial.print("finished all ");
  Serial.print(amount);
  Serial.print(" solves least moves needed:  ");
  Serial.print(least);
  Serial.print(" moves:   ");
  Serial.print(smallest);
}



//soling functions
void solveWithPrint() {
  cross();
  print_whole_cube();
  corners();
  print_whole_cube();
  edges();
  print_whole_cube();
  bottomCross();
  print_whole_cube();
  bottomCorners();
  print_whole_cube();
  PLLCorner();
  print_whole_cube();
  PLLEdge();
  print_whole_cube();
}

void solve() {
    digitalWrite(24,HIGH);
    digitalWrite(22,LOW);
  cross();
  corners();
  edges();
  bottomCross();
  bottomCorners();
  PLLCorner();
  PLLEdge();
  print_whole_cube();
      digitalWrite(24,LOW);
    digitalWrite(22,LOW);
}




void setup() {
  for (int i = 2; i < 25; i++) {
    pinMode(i, OUTPUT);
  }


  leftServo.attach(6);
  rightServo.attach(7);
  frontServo.attach(8);
  backServo.attach(9);
  leftMoveServo.attach(5);
  rightMoveServo.attach(4);
  frontMoveServo.attach(3);
  backMoveServo.attach(2);

  Serial.begin(9600);



  leftServo.write(92);
  rightServo.write(78);
  frontServo.write(85);
  backServo.write(83);
  delay(motorDelay);

}

void loop() {
//print_whole_cube();
pinMode(A6, OUTPUT);
digitalWrite(A6,LOW);
  if(analogRead(A0)>150 && analogRead(A7)<5){
     for (int i = moveAway; i > moveTowards; i--) {
    leftMoveServo.write(i);
    rightMoveServo.write(i);
    frontMoveServo.write(i);
    backMoveServo.write(i);
    delay(motorDelay / 15);
  }
  delay(motorDelay);
  scramble();
  delay(2000);
  solve();
  for (int i = moveTowards; i < moveAway; i++) {
    leftMoveServo.write(i);
    rightMoveServo.write(i);
    frontMoveServo.write(i);
    backMoveServo.write(i);
    delay(motorDelay / 20);
  }
  }

if(analogRead(A0)>150 && analogRead(A5)<5){
    reciveCube();
frontServo.write(0);
delay(motorDelay);
frontServo.write(180);
delay(motorDelay);
frontServo.write(85);
delay(motorDelay);
  
    for (int i = 0; i < 6;i++){
              digitalWrite(24,HIGH);
    digitalWrite(22,LOW);
    delay(200);
          digitalWrite(22,LOW);
    digitalWrite(24,LOW);
    delay(200);
    }
     for (int i = moveAway; i > moveTowards; i--) {
    leftMoveServo.write(i);
    rightMoveServo.write(i);
    frontMoveServo.write(i);
    backMoveServo.write(i);
    delay(motorDelay / 15);
  }
  delay(motorDelay);
  solve();
  for (int i = moveTowards; i < moveAway; i++) {
    leftMoveServo.write(i);
    rightMoveServo.write(i);
    frontMoveServo.write(i);
    backMoveServo.write(i);
    delay(motorDelay / 20);
  }
  }
  
}
