import processing.serial.*; //<>//
Serial port;
char[] cube=new char[108];
boolean save=true;
int topLeft=0;
int topMiddle=0;
int topRight=0;
int midLeft=0;
int middle=0;
int midRight=0;
int botLeft=0;
int botMiddle=0;
int botRight=0;
int[] cubeLayout = new int[54];
String[] top = new String [9];
String[] left = new String [9];
String[] right = new String [9];
String[] front = new String [9];
String[] back = new String [9];
String[] down = new String [9];



void setup() {
  for (int i = 0; i<9; i++) {
    top[i]="xx";
    down[i]="xx";
    left[i]="xx";
    right[i]="xx";
    back[i]="xx";
    front[i]="xx";
  }
  size(300, 350);
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  port = new Serial(this, portName, 9600);
 // port.bufferUntil('\n');
  background(255);
}

void draw() {
  if (save) {
    background(255);
    line(100, 0, 100, 300);
    line(200, 0, 200, 300);
    line(0, 100, 300, 100);
    line(0, 200, 300, 200);
    line(0, 300, 300, 300);


    switch(middle) {
    case 0:
      textSize(15);
      fill(0);
      text("yellow side", 20, 325);
      fill(248, 252, 0);//yellow
      rect(100, 100, 100, 100);
      changeColor();
      break;
    case 1:
      topLeft=1;
      topMiddle=1;
      topRight=1;
      midLeft=1;
      midRight=1;
      botLeft=1;
      botMiddle=1;
      botRight=1;
      textSize(15);
      fill(0);
      text("orange side", 20, 325);
      fill(252, 139, 0);//orange
      rect(100, 100, 100, 100);
      changeColor();
      break;
    case 2:
      topLeft=2;
      topMiddle=2;
      topRight=2;
      midLeft=2;
      midRight=2;
      botLeft=2;
      botMiddle=2;
      botRight=2;
      textSize(15);
      fill(0);
      text("red side", 20, 325);
      fill(255, 0, 0);//red
      rect(100, 100, 100, 100);
      changeColor();
      break;
    case 3:
      topLeft=3;
      topMiddle=3;
      topRight=3;
      midLeft=3;
      midRight=3;
      botLeft=3;
      botMiddle=3;
      botRight=3;
      textSize(15);
      fill(0);
      text("blue side", 20, 325);
      fill(0, 0, 255);//blue
      rect(100, 100, 100, 100);
      changeColor();
      break;
    case 4:
      topLeft=4;
      topMiddle=4;
      topRight=4;
      midLeft=4;
      midRight=4;
      botLeft=4;
      botMiddle=4;
      botRight=4;
      textSize(15);
      fill(0);
      text("green side", 20, 325);
      fill(0, 255, 0);//green
      rect(100, 100, 100, 100);
      changeColor();
      break;
    case 5:
      topLeft=5;
      topMiddle=5;
      topRight=5;
      midLeft=5;
      midRight=5;
      botLeft=5;
      botMiddle=5;
      botRight=5;
      textSize(15);
      fill(0);
      text("white side", 20, 325);
      fill(255);//white
      rect(100, 100, 100, 100);
      changeColor();
      break;
    case 6:
      makeTheCube();
      background(255);
      textSize(45);
      fill(0);
      text("finished!", 50, 175);
      break;
    default:
      background(255);
      textSize(45);
      fill(0);
      text("finished!", 50, 175);
      break;
    }

    save=false;
  }
}

void changeColor() {
  int square=0;

  //  background(255);
  //line(100, 0, 100, 300);
  //line(200, 0, 200, 300);
  //line(0, 100, 300, 100);
  //line(0, 200, 300, 200);
  //line(0, 300, 300, 300);

  for (int i = 0; i<9; i++) {
    switch(i) {
    case 0:
      square=topLeft%6;
      break;
    case 1:
      square=topMiddle%6;
      break;
    case 2:
      square=topRight%6;
      break;
    case 3:
      square=midLeft%6;
      break;
    case 5:
      square=midRight%6;
      break;
    case 4:
      square=middle;
      break;
    case 6:
      square=botLeft%6;
      break;
    case 7:
      square=botMiddle%6;
      break;
    case 8:
      square=botRight%6;
      break;
    }

    switch(square) {
    case 5:
      fill(255);//white
      rect((i%3)*100, (i/3)*100, 100, 100);
      break;
    case 4:
      fill(0, 255, 0);//green
      rect((i%3)*100, (i/3)*100, 100, 100);
      break;
    case 0:
      fill(248, 252, 0);//yellow
      rect((i%3)*100, (i/3)*100, 100, 100);
      break;
    case 3:
      fill(0, 0, 255);//blue
      rect((i%3)*100, (i/3)*100, 100, 100);
      break;
    case 2:
      fill(255, 0, 0);//red
      rect((i%3)*100, (i/3)*100, 100, 100);
      break;
    case 1:
      fill(252, 139, 0);//orange
      rect((i%3)*100, (i/3)*100, 100, 100);
      break;
    case 7:
      break;
    }
  }
}

void mouseClicked() {
  if (mouseX<100 && mouseY<100) {
    topLeft++;
  } else if (mouseX<200 && mouseY<100) {
    topMiddle++;
  } else if (mouseX<300 && mouseY<100) {
    topRight++;
  } else if (mouseX<100 && mouseY<200) {
    midLeft++;
  } else if (mouseX>200 && mouseY<200) {
    midRight++;
  } else if (mouseX<100 && mouseY<300) {
    botLeft++;
  } else if (mouseX<200 && mouseY<300 && mouseY>200) {
    botMiddle++;
  } else if (mouseX<300 && mouseY<300 && mouseY>200) {
    botRight++;
  } else if (mouseY>300) {

    if(middle<6){
    cubeLayout[9*middle]=topLeft%6;
    cubeLayout[9*middle+1]=topMiddle%6;
    cubeLayout[9*middle+2]=topRight%6;
    cubeLayout[9*middle+3]=midLeft%6;
    cubeLayout[9*middle+4]= middle%6;
    cubeLayout[9*middle+5]=midRight%6;
    cubeLayout[9*middle+6]=botLeft%6;
    cubeLayout[9*middle+7]=botMiddle%6;
    cubeLayout[9*middle+8]=botRight%6;
    }
    middle++;
    save=true;
  }

  changeColor();
}

void makeTheCube() {
  if (cubeLayout[0]==0) {
    if (cubeLayout[29]==3 && cubeLayout[18]==2) {
      top[0] = "y0";
      left[0] = "r0";
      back[2] = "b2";
    } else if (cubeLayout[29]==1 && cubeLayout[18]==3) {
      top[0]="y2";
      left[0] = "b0";
      back[2] = "o2";
    } else if (cubeLayout[29]==4 && cubeLayout[18]==1) {
      top[0]="y8";
      left[0] = "o0";
      back[2] = "g2";
    } else if (cubeLayout[29]==2 && cubeLayout[18]==4) {
      top[0]="y6";
      left[0] = "g0";
      back[2] = "r2";
    }
  } else if (cubeLayout[0]==1) {
    if (cubeLayout[29]==3 && cubeLayout[18]==0) {
      top[0] = "o2";
      left[0] = "y2";
      back[2] = "b0";
    } else if (cubeLayout[29]==5 && cubeLayout[18]==3) {
      top[0]="o8";
      left[0] = "b6";
      back[2] = "w8";
    } else if (cubeLayout[29]==0 && cubeLayout[18]==4) {
      top[0]="o0";
      left[0] = "g2";
      back[2] = "y8";
    } else if (cubeLayout[29]==4 && cubeLayout[18]==5) {
      top[0]="o6";
      left[0] = "w2";
      back[2] = "g8";
    }
  } else if (cubeLayout[0]==2) {
    if (cubeLayout[29]==3 && cubeLayout[18]==5) {
      top[0] = "r6";
      left[0] = "w6";
      back[2] = "b8";
    } else if (cubeLayout[29]==0 && cubeLayout[18]==3) {
      top[0]="r0";
      left[0] = "b2";
      back[2] = "y0";
    } else if (cubeLayout[29]==5 && cubeLayout[18]==4) {
      top[0]="r8";
      left[0] = "g6";
      back[2] = "w0";
    } else if (cubeLayout[29]==4 && cubeLayout[18]==0) {
      top[0]="r2";
      left[0] = "y6";
      back[2] = "g0";
    }
  } else if (cubeLayout[0]==3) {
    if (cubeLayout[29]==5 && cubeLayout[18]==2) {
      top[0] = "b8";
      left[0] = "r6";
      back[2] = "w6";
    } else if (cubeLayout[29]==2 && cubeLayout[18]==0) {
      top[0]="b2";
      left[0] = "y0";
      back[2] = "r0";
    } else if (cubeLayout[29]==1 && cubeLayout[18]==5) {
      top[0]="b6";
      left[0] = "w8";
      back[2] = "o8";
    } else if (cubeLayout[29]==0 && cubeLayout[18]==1) {
      top[0]="b0";
      left[0] = "o2";
      back[2] = "y2";
    }
  } else if (cubeLayout[0]==4) {
    if (cubeLayout[29]==0 && cubeLayout[18]==2) {
      top[0] = "g0";
      left[0] = "r2";
      back[2] = "y6";
    } else if (cubeLayout[29]==2 && cubeLayout[18]==5) {
      top[0]="g6";
      left[0] = "w0";
      back[2] = "r8";
    } else if (cubeLayout[29]==1 && cubeLayout[18]==0) {
      top[0]="g2";
      left[0] = "y8";
      back[2] = "o0";
    } else if (cubeLayout[29]==5 && cubeLayout[18]==1) {
      top[0]="g8";
      left[0] = "o6";
      back[2] = "w2";
    }
  } else if (cubeLayout[0]==5) {
    if (cubeLayout[29]==1 && cubeLayout[18]==4) {
      top[0] = "w2";
      left[0] = "g8";
      back[2] = "o6";
    } else if (cubeLayout[29]==4 && cubeLayout[18]==2) {
      top[0]="w0";
      left[0] = "r8";
      back[2] = "g6";
    } else if (cubeLayout[29]==3 && cubeLayout[18]==1) {
      top[0]="w8";
      left[0] = "o8";
      back[2] = "b6";
    } else if (cubeLayout[29]==2 && cubeLayout[18]==3) {
      top[0]="w6";
      left[0] = "b8";
      back[2] = "r6";
    }
  }


  if (cubeLayout[2]==0) {
    if (cubeLayout[11]==3 && cubeLayout[27]==2) {
      top[2] = "y0";
      back[0] = "r0";
      right[2]= "b2";
    } else if (cubeLayout[11]==1 && cubeLayout[27]==3) {
      top[2]="y2";
      back[0] = "b0";
      right[2] = "o2";
    } else if (cubeLayout[11]==4 && cubeLayout[27]==1) {
      top[2]="y8";
      back[0] = "o0";
      right[2] = "g2";
    } else if (cubeLayout[11]==2 && cubeLayout[27]==4) {
      top[2]="y6";
      back[0] = "g0";
      right[2] = "r2";
    }
  } else if (cubeLayout[2]==1) {
    if (cubeLayout[11]==3 && cubeLayout[27]==0) {
      top[2] = "o2";
      back[0] = "y2";
      right[2]= "b0";
    } else if (cubeLayout[11]==5 && cubeLayout[27]==3) {
      top[2]="o8";
      back[0] = "b6";
      right[2]= "w8";
    } else if (cubeLayout[11]==0 && cubeLayout[27]==4) {
      top[2]="o0";
      back[0] = "g2";
      right[2]= "y8";
    } else if (cubeLayout[11]==4 && cubeLayout[27]==5) {
      top[2]="o6";
      back[0] = "w2";
      right[2]= "g8";
    }
  } else if (cubeLayout[2]==2) {
    if (cubeLayout[11]==3 && cubeLayout[27]==5) {
      top[2] = "r6";
      back[0] = "w6";
      right[2]= "b8";
    } else if (cubeLayout[11]==0 && cubeLayout[27]==3) {
      top[2]="r0";
      back[0] = "b2";
      right[2]= "y0";
    } else if (cubeLayout[11]==5 && cubeLayout[27]==4) {
      top[2]="r8";
      back[0] = "g6";
      right[2]= "w0";
    } else if (cubeLayout[11]==4 && cubeLayout[27]==0) {
      top[2]="r2";
      back[0] = "y6";
      right[2]= "g0";
    }
  } else if (cubeLayout[2]==3) {
    if (cubeLayout[11]==5 && cubeLayout[27]==2) {
      top[2] = "b8";
      back[0] = "r6";
      right[2]= "w6";
    } else if (cubeLayout[11]==2 && cubeLayout[27]==0) {
      top[2]="b2";
      back[0] = "y0";
      right[2]= "r0";
    } else if (cubeLayout[11]==1 && cubeLayout[27]==5) {
      top[2]="b6";
      back[0] = "w8";
      right[2]= "o8";
    } else if (cubeLayout[11]==0 && cubeLayout[27]==1) {
      top[2]="b0";
      back[0] = "o2";
      right[2]= "y2";
    }
  } else if (cubeLayout[2]==4) {
    if (cubeLayout[11]==0 && cubeLayout[27]==2) {
      top[2] = "g0";
      back[0] = "r2";
      right[2]= "y6";
    } else if (cubeLayout[11]==2 && cubeLayout[27]==5) {
      top[2]="g6";
      back[0] = "w0";
      right[2]= "r8";
    } else if (cubeLayout[11]==1 && cubeLayout[27]==0) {
      top[2]="g2";
      back[0] = "y8";
      right[2]= "o0";
    } else if (cubeLayout[11]==5 && cubeLayout[27]==1) {
      top[2]="g8";
      back[0] = "o6";
      right[2]= "w2";
    }
  } else if (cubeLayout[2]==5) {
    if (cubeLayout[11]==1 && cubeLayout[27]==4) {
      top[2] = "w2";
      back[0] = "g8";
      right[2]= "o6";
    } else if (cubeLayout[11]==4 && cubeLayout[27]==2) {
      top[2]="w0";
      back[0] = "r8";
      right[2]= "g6";
    } else if (cubeLayout[11]==3 && cubeLayout[27]==1) {
      top[2]="w8";
      back[0] = "o8";
      right[2]= "b6";
    } else if (cubeLayout[11]==2 && cubeLayout[27]==3) {
      top[2]="w6";
      back[0] = "b8";
      right[2]= "r6";
    }
  }


  if (cubeLayout[6]==0) {
    if (cubeLayout[36]==2 && cubeLayout[20]==3) {
      top[6] = "y0";
      front[0] = "r0";
      left[2] = "b2";
    } else if (cubeLayout[36]==3 && cubeLayout[20]==1) {
      top[6]="y2";
      front[0] = "b0";
      left[2] = "o2";
    } else if (cubeLayout[36]==1 && cubeLayout[20]==4) {
      top[6]="y8";
      front[0] = "o0";
      left[2] = "g2";
    } else if (cubeLayout[36]==4 && cubeLayout[20]==2) {
      top[6]="y6";
      front[0] = "g0";
      left[2] = "r2";
    }
  } else if (cubeLayout[6]==1) {
    if (cubeLayout[36]==0 && cubeLayout[20]==3) {
      top[6] = "o2";
      front[0] = "y2";
      left[2] = "b0";
    } else if (cubeLayout[36]==3 && cubeLayout[20]==5) {
      top[6]="o8";
      front[0] = "b6";
      left[2] = "w8";
    } else if (cubeLayout[36]==0 && cubeLayout[20]==4) {
      top[6]="o0";
      front[0] = "g2";
      left[2] = "y8";
    } else if (cubeLayout[36]==4 && cubeLayout[20]==5) {
      top[6]="o6";
      front[0] = "w2";
      left[2] = "g8";
    }
  } else if (cubeLayout[6]==2) {
    if (cubeLayout[36]==5 && cubeLayout[20]==3) {
      top[6] = "r6";
      front[0] = "w6";
      left[2] = "b8";
    } else if (cubeLayout[36]==3 && cubeLayout[20]==2) {
      top[6]="r0";
      front[0] = "b2";
      left[2] = "y0";
    } else if (cubeLayout[36]==4 && cubeLayout[20]==5) {
      top[6]="r8";
      front[0] = "g6";
      left[2] = "w0";
    } else if (cubeLayout[36]==0 && cubeLayout[20]==4) {
      top[6]="r2";
      front[0] = "y6";
      left[2] = "g0";
    }
  } else if (cubeLayout[6]==3) {
    if (cubeLayout[36]==2 && cubeLayout[20]==5) {
      top[6] = "b8";
      front[0] = "r6";
      left[2] = "w6";
    } else if (cubeLayout[36]==0 && cubeLayout[20]==2) {
      top[6]="b2";
      front[0] = "y0";
      left[2] = "r0";
    } else if (cubeLayout[36]==5 && cubeLayout[20]==1) {
      top[6]="b6";
      front[0] = "w8";
      left[2] = "o8";
    } else if (cubeLayout[36]==1 && cubeLayout[20]==0) {
      top[6]="b0";
      front[0] = "o2";
      left[2] = "y2";
    }
  } else if (cubeLayout[6]==4) {
    if (cubeLayout[36]==2 && cubeLayout[20]==0) {
      top[6] = "g0";
      front[0] = "r2";
      left[2] = "y6";
    } else if (cubeLayout[36]==5 && cubeLayout[20]==2) {
      top[6]="g6";
      front[0] = "w0";
      left[2] = "r8";
    } else if (cubeLayout[36]==0 && cubeLayout[20]==1) {
      top[6]="g2";
      front[0] = "y8";
      left[2] = "o0";
    } else if (cubeLayout[36]==1 && cubeLayout[20]==5) {
      top[6]="g8";
      front[0] = "o6";
      left[2] = "w2";
    }
  } else if (cubeLayout[6]==5) {
    if (cubeLayout[36]==4 && cubeLayout[20]==1) {
      top[6] = "w2";
      front[0] = "g8";
      left[2] = "o6";
    } else if (cubeLayout[36]==2 && cubeLayout[20]==4) {
      top[6]="w0";
      front[0] = "r8";
      left[2] = "g6";
    } else if (cubeLayout[36]==1 && cubeLayout[20]==3) {
      top[6]="w8";
      front[0] = "o8";
      left[2] = "b6";
    } else if (cubeLayout[36]==3 && cubeLayout[20]==2) {
      top[6]="w6";
      front[0] = "b8";
      left[2] = "r6";
    }
  }


  if (cubeLayout[8]==0) {
    if (cubeLayout[38]==3 && cubeLayout[9]==2) {
      top[8] = "y0";
      right[0] = "r0";
      front[2] = "b2";
    } else if (cubeLayout[38]==1 && cubeLayout[9]==3) {
      top[8]="y2";
      right[0] = "b0";
      front[2] = "o2";
    } else if (cubeLayout[38]==4 && cubeLayout[9]==1) {
      top[8]="y8";
      right[0] = "o0";
      front[2] = "g2";
    } else if (cubeLayout[38]==2 && cubeLayout[9]==4) {
      top[8]="y6";
      right[0] = "g0";
      front[2] = "r2";
    }
  } else if (cubeLayout[8]==1) {
    if (cubeLayout[38]==3 && cubeLayout[9]==0) {
      top[8] = "o2";
      right[0] = "y2";
      front[2] = "b0";
    } else if (cubeLayout[38]==5 && cubeLayout[9]==3) {
      top[8]="o8";
      right[0] = "b6";
      front[2] = "w8";
    } else if (cubeLayout[38]==0 && cubeLayout[9]==4) {
      top[8]="o0";
      right[0] = "g2";
      front[2] = "y8";
    } else if (cubeLayout[38]==4 && cubeLayout[9]==5) {
      top[8]="o6";
      right[0] = "w2";
      front[2] = "g8";
    }
  } else if (cubeLayout[8]==2) {
    if (cubeLayout[38]==3 && cubeLayout[9]==5) {
      top[8] = "r6";
      right[0] = "w6";
      front[2] = "b8";
    } else if (cubeLayout[38]==0 && cubeLayout[9]==3) {
      top[8]="r0";
      right[0] = "b2";
      front[2] = "y0";
    } else if (cubeLayout[38]==5 && cubeLayout[9]==4) {
      top[8]="r8";
      right[0] = "g6";
      front[2] = "w0";
    } else if (cubeLayout[38]==4 && cubeLayout[9]==0) {
      top[8]="r2";
      right[0] = "y6";
      front[2] = "g0";
    }
  } else if (cubeLayout[8]==3) {
    if (cubeLayout[38]==5 && cubeLayout[9]==2) {
      top[8] = "b8";
      right[0] = "r6";
      front[2] = "w6";
    } else if (cubeLayout[38]==2 && cubeLayout[9]==0) {
      top[8]="b2";
      right[0] = "y0";
      front[2] = "r0";
    } else if (cubeLayout[38]==1 && cubeLayout[9]==5) {
      top[8]="b6";
      right[0] = "w8";
      front[2] = "o8";
    } else if (cubeLayout[38]==0 && cubeLayout[9]==1) {
      top[8]="b0";
      right[0] = "o2";
      front[2] = "y2";
    }
  } else if (cubeLayout[8]==4) {
    if (cubeLayout[38]==0 && cubeLayout[9]==2) {
      top[8] = "g0";
      right[0] = "r2";
      front[2] = "y6";
    } else if (cubeLayout[38]==2 && cubeLayout[9]==5) {
      top[8]="g6";
      right[0] = "w0";
      front[2] = "r8";
    } else if (cubeLayout[38]==1 && cubeLayout[9]==0) {
      top[8]="g2";
      right[0] = "y8";
      front[2] = "o0";
    } else if (cubeLayout[38]==5 && cubeLayout[9]==1) {
      top[8]="g8";
      right[0] = "o6";
      front[2] = "w2";
    }
  } else if (cubeLayout[8]==5) {
    if (cubeLayout[38]==1 && cubeLayout[9]==4) {
      top[8] = "w2";
      right[0] = "g8";
      front[2] = "o6";
    } else if (cubeLayout[38]==4 && cubeLayout[9]==2) {
      top[8]="w0";
      right[0] = "r8";
      front[2] = "g6";
    } else if (cubeLayout[38]==3 && cubeLayout[9]==1) {
      top[8]="w8";
      right[0] = "o8";
      front[2] = "b6";
    } else if (cubeLayout[38]==2 && cubeLayout[9]==3) {
      top[8]="w6";
      right[0] = "b8";
      front[2] = "r6";
    }
  }










  if (cubeLayout[45]==0) {
    if (cubeLayout[42]==3 && cubeLayout[26]==2) {
      down[0] = "y0";
      left[8] = "r0";
      front[6] = "b2";
    } else if (cubeLayout[42]==1 && cubeLayout[26]==3) {
      down[0]="y2";
      left[8] = "b0";
      front[6] = "o2";
    } else if (cubeLayout[42]==4 && cubeLayout[26]==1) {
      down[0]="y8";
      left[8] = "o0";
      front[6] = "g2";
    } else if (cubeLayout[42]==2 && cubeLayout[26]==4) {
      down[0]="y6";
      left[8] = "g0";
      front[6] = "r2";
    }
  } else if (cubeLayout[45]==1) {
    if (cubeLayout[42]==3 && cubeLayout[26]==0) {
      down[0] = "o2";
      left[8] = "y2";
      front[6] = "b0";
    } else if (cubeLayout[42]==5 && cubeLayout[26]==3) {
      down[0]="o8";
      left[8] = "b6";
      front[6] = "w8";
    } else if (cubeLayout[42]==0 && cubeLayout[26]==4) {
      down[0]="o0";
      left[8] = "g2";
      front[6] = "y8";
    } else if (cubeLayout[42]==4 && cubeLayout[26]==5) {
      down[0]="o6";
      left[8] = "w2";
      front[6] = "g8";
    }
  } else if (cubeLayout[45]==2) {
    if (cubeLayout[42]==3 && cubeLayout[26]==5) {
      down[0] = "r6";
      left[8] = "w6";
      front[6] = "b8";
    } else if (cubeLayout[42]==0 && cubeLayout[26]==3) {
      down[0]="r0";
      left[8] = "b2";
      front[6] = "y0";
    } else if (cubeLayout[42]==5 && cubeLayout[26]==4) {
      down[0]="r8";
      left[8] = "g6";
      front[6] = "w0";
    } else if (cubeLayout[42]==4 && cubeLayout[26]==0) {
      down[0]="r2";
      left[8] = "y6";
      front[6] = "g0";
    }
  } else if (cubeLayout[45]==3) {
    if (cubeLayout[42]==5 && cubeLayout[26]==2) {
      down[0] = "b8";
      left[8] = "r6";
      front[6] = "w6";
    } else if (cubeLayout[42]==2 && cubeLayout[26]==0) {
      down[0]="b2";
      left[8] = "y0";
      front[6] = "r0";
    } else if (cubeLayout[42]==1 && cubeLayout[26]==5) {
      down[0]="b6";
      left[8] = "w8";
      front[6] = "o8";
    } else if (cubeLayout[42]==0 && cubeLayout[26]==1) {
      down[0]="b0";
      left[8] = "o2";
      front[6] = "y2";
    }
  } else if (cubeLayout[45]==4) {
    if (cubeLayout[42]==0 && cubeLayout[26]==2) {
      down[0] = "g0";
      left[8] = "r2";
      front[6] = "y6";
    } else if (cubeLayout[42]==2 && cubeLayout[26]==5) {
      down[0]="g6";
      left[8] = "w0";
      front[6] = "r8";
    } else if (cubeLayout[42]==1 && cubeLayout[26]==0) {
      down[0]="g2";
      left[8] = "y8";
      front[6] = "o0";
    } else if (cubeLayout[42]==5 && cubeLayout[26]==1) {
      down[0]="g8";
      left[8] = "o6";
      front[6] = "w2";
    }
  } else if (cubeLayout[45]==5) {
    if (cubeLayout[42]==1 && cubeLayout[26]==4) {
      down[0] = "w2";
      left[8] = "g8";
      front[6] = "o6";
    } else if (cubeLayout[42]==4 && cubeLayout[26]==2) {
      down[0]="w0";
      left[8] = "r8";
      front[6] = "g6";
    } else if (cubeLayout[42]==3 && cubeLayout[26]==1) {
      down[0]="w8";
      left[8] = "o8";
      front[6] = "b6";
    } else if (cubeLayout[42]==2 && cubeLayout[26]==3) {
      down[0]="w6";
      left[8] = "b8";
      front[6] = "r6";
    }
  }


  if (cubeLayout[47]==0) {
    if (cubeLayout[15]==3 && cubeLayout[44]==2) {
      down[2] = "y0";
      front[8] = "r0";
      right[6]= "b2";
    } else if (cubeLayout[15]==1 && cubeLayout[44]==3) {
      down[2]="y2";
      front[8] = "b0";
      right[6] = "o2";
    } else if (cubeLayout[15]==4 && cubeLayout[44]==1) {
      down[2]="y8";
      front[8] = "o0";
      right[6] = "g2";
    } else if (cubeLayout[15]==2 && cubeLayout[44]==4) {
      down[2]="y6";
      front[8] = "g0";
      right[6] = "r2";
    }
  } else if (cubeLayout[47]==1) {
    if (cubeLayout[15]==3 && cubeLayout[44]==0) {
      down[2] = "o2";
      front[8] = "y2";
      right[6]= "b0";
    } else if (cubeLayout[15]==5 && cubeLayout[44]==3) {
      down[2]="o8";
      front[8] = "b6";
      right[6]= "w8";
    } else if (cubeLayout[15]==0 && cubeLayout[44]==4) {
      down[2]="o0";
      front[8] = "g2";
      right[6]= "y8";
    } else if (cubeLayout[15]==4 && cubeLayout[44]==5) {
      down[2]="o6";
      front[8] = "w2";
      right[6]= "g8";
    }
  } else if (cubeLayout[47]==2) {
    if (cubeLayout[15]==3 && cubeLayout[44]==5) {
      down[2] = "r6";
      front[8] = "w6";
      right[6]= "b8";
    } else if (cubeLayout[15]==0 && cubeLayout[44]==3) {
      down[2]="r0";
      front[8] = "b2";
      right[6]= "y0";
    } else if (cubeLayout[15]==5 && cubeLayout[44]==4) {
      down[2]="r8";
      front[8] = "g6";
      right[6]= "w0";
    } else if (cubeLayout[15]==4 && cubeLayout[44]==0) {
      down[2]="r2";
      front[8] = "y6";
      right[6]= "g0";
    }
  } else if (cubeLayout[47]==3) {
    if (cubeLayout[15]==5 && cubeLayout[44]==2) {
      down[2] = "b8";
      front[8] = "r6";
      right[6]= "w6";
    } else if (cubeLayout[15]==2 && cubeLayout[44]==0) {
      down[2]="b2";
      front[8] = "y0";
      right[6]= "r0";
    } else if (cubeLayout[15]==1 && cubeLayout[44]==5) {
      down[2]="b6";
      front[8] = "w8";
      right[6]= "o8";
    } else if (cubeLayout[15]==0 && cubeLayout[44]==1) {
      down[2]="b0";
      front[8] = "o2";
      right[6]= "y2";
    }
  } else if (cubeLayout[47]==4) {
    if (cubeLayout[15]==0 && cubeLayout[44]==2) {
      down[2] = "g0";
      front[8] = "r2";
      right[6]= "y6";
    } else if (cubeLayout[15]==2 && cubeLayout[44]==5) {
      down[2]="g6";
      front[8] = "w0";
      right[6]= "r8";
    } else if (cubeLayout[15]==1 && cubeLayout[44]==0) {
      down[2]="g2";
      front[8] = "y8";
      right[6]= "o0";
    } else if (cubeLayout[15]==5 && cubeLayout[44]==1) {
      down[2]="g8";
      front[8] = "o6";
      right[6]= "w2";
    }
  } else if (cubeLayout[47]==5) {
    if (cubeLayout[15]==1 && cubeLayout[44]==4) {
      down[2] = "w2";
      front[8] = "g8";
      right[6]= "o6";
    } else if (cubeLayout[15]==4 && cubeLayout[44]==2) {
      down[2]="w0";
      front[8] = "r8";
      right[6]= "g6";
    } else if (cubeLayout[15]==3 && cubeLayout[44]==1) {
      down[2]="w8";
      front[8] = "o8";
      right[6]= "b6";
    } else if (cubeLayout[15]==2 && cubeLayout[44]==3) {
      down[2]="w6";
      front[8] = "b8";
      right[6]= "r6";
    }
  }


  if (cubeLayout[51]==0) {
    if (cubeLayout[24]==3 && cubeLayout[35]==2) {
      down[6] = "y0";
      back[8] = "r0";
      left[6] = "b2";
    } else if (cubeLayout[24]==1 && cubeLayout[35]==3) {
      down[6]="y2";
      back[8] = "b0";
      left[6] = "o2";
    } else if (cubeLayout[24]==4 && cubeLayout[35]==1) {
      top[8]="y8";
      back[8] = "o0";
      left[6] = "g2";
    } else if (cubeLayout[24]==2 && cubeLayout[35]==4) {
      down[6]="y6";
      back[8] = "g0";
      left[6] = "r2";
    }
  } else if (cubeLayout[51]==1) {
    if (cubeLayout[24]==3 && cubeLayout[35]==0) {
      down[6] = "o2";
      back[8] = "y2";
      left[6] = "b0";
    } else if (cubeLayout[24]==5 && cubeLayout[35]==3) {
      down[6]="o8";
      back[8] = "b6";
      left[6] = "w8";
    } else if (cubeLayout[24]==0 && cubeLayout[35]==4) {
      down[6]="o0";
      back[8] = "g2";
      left[6] = "y8";
    } else if (cubeLayout[24]==4 && cubeLayout[35]==5) {
      down[6]="o6";
      back[8] = "w2";
      left[6] = "g8";
    }
  } else if (cubeLayout[51]==2) {
    if (cubeLayout[24]==3 && cubeLayout[35]==5) {
      down[6] = "r6";
      back[8] = "w6";
      left[6] = "b8";
    } else if (cubeLayout[24]==0 && cubeLayout[35]==3) {
      down[6]="r0";
      back[8] = "b2";
      left[6] = "y0";
    } else if (cubeLayout[24]==5 && cubeLayout[35]==4) {
      down[6]="r8";
      back[8] = "g6";
      left[6] = "w0";
    } else if (cubeLayout[24]==4 && cubeLayout[35]==0) {
      down[6]="r2";
      back[8] = "y6";
      left[6] = "g0";
    }
  } else if (cubeLayout[51]==3) {
    if (cubeLayout[24]==5 && cubeLayout[35]==2) {
      down[6] = "b8";
      back[8] = "r6";
      left[6] = "w6";
    } else if (cubeLayout[24]==2 && cubeLayout[35]==0) {
      down[6]="b2";
      back[8] = "y0";
      left[6] = "r0";
    } else if (cubeLayout[24]==1 && cubeLayout[35]==5) {
      down[6]="b6";
      back[8] = "w8";
      left[6] = "o8";
    } else if (cubeLayout[24]==0 && cubeLayout[35]==1) {
      down[6]="b0";
      back[8] = "o2";
      left[6] = "y2";
    }
  } else if (cubeLayout[51]==4) {
    if (cubeLayout[24]==0 && cubeLayout[35]==2) {
      down[6] = "g0";
      back[8] = "r2";
      left[6] = "y6";
    } else if (cubeLayout[24]==2 && cubeLayout[35]==5) {
      down[6]="g6";
      back[8] = "w0";
      left[6] = "r8";
    } else if (cubeLayout[24]==1 && cubeLayout[35]==0) {
      down[6]="g2";
      back[8] = "y8";
      left[6] = "o0";
    } else if (cubeLayout[24]==5 && cubeLayout[35]==1) {
      down[6]="g8";
      back[8] = "o6";
      left[6] = "w2";
    }
  } else if (cubeLayout[51]==5) {
    if (cubeLayout[24]==1 && cubeLayout[35]==4) {
      down[6] = "w2";
      back[8] = "g8";
      left[6] = "o6";
    } else if (cubeLayout[24]==4 && cubeLayout[35]==2) {
      down[6]="w0";
      back[8] = "r8";
      left[6] = "g6";
    } else if (cubeLayout[24]==3 && cubeLayout[35]==1) {
      down[6]="w8";
      back[8] = "o8";
      left[6] = "b6";
    } else if (cubeLayout[24]==2 && cubeLayout[35]==3) {
      down[6]="w6";
      back[8] = "b8";
      left[6] = "r6";
    }
  }


  if (cubeLayout[53]==0) {
    if (cubeLayout[33]==3 && cubeLayout[17]==2) {
      down[8] = "y0";
      right[8] = "r0";
      back[6] = "b2";
    } else if (cubeLayout[33]==1 && cubeLayout[17]==3) {
      down[8]="y2";
      right[8] = "b0";
      back[6] = "o2";
    } else if (cubeLayout[33]==4 && cubeLayout[17]==1) {
      down[8]="y8";
      right[8] = "o0";
      back[6] = "g2";
    } else if (cubeLayout[33]==2 && cubeLayout[17]==4) {
      down[8]="y6";
      right[8] = "g0";
      back[6] = "r2";
    }
  } else if (cubeLayout[53]==1) {
    if (cubeLayout[33]==3 && cubeLayout[17]==0) {
      down[8] = "o2";
      right[8] = "y2";
      back[6] = "b0";
    } else if (cubeLayout[33]==5 && cubeLayout[17]==3) {
      down[8]="o8";
      right[8] = "b6";
      back[6] = "w8";
    } else if (cubeLayout[33]==0 && cubeLayout[17]==4) {
      down[8]="o0";
      right[8] = "g2";
      back[6] = "y8";
    } else if (cubeLayout[33]==4 && cubeLayout[17]==5) {
      down[8]="o6";
      right[8] = "w2";
      back[6] = "g8";
    }
  } else if (cubeLayout[53]==2) {
    if (cubeLayout[33]==3 && cubeLayout[17]==5) {
      down[8] = "r6";
      right[8] = "w6";
      back[6] = "b8";
    } else if (cubeLayout[33]==0 && cubeLayout[17]==3) {
      down[8]="r0";
      right[8] = "b2";
      back[6] = "y0";
    } else if (cubeLayout[33]==5 && cubeLayout[17]==4) {
      down[8]="r8";
      right[8] = "g6";
      back[6] = "w0";
    } else if (cubeLayout[33]==4 && cubeLayout[17]==0) {
      down[8]="r2";
      right[8] = "y6";
      back[6] = "g0";
    }
  } else if (cubeLayout[53]==3) {
    if (cubeLayout[33]==5 && cubeLayout[17]==2) {
      down[8] = "b8";
      right[8] = "r6";
      back[6] = "w6";
    } else if (cubeLayout[33]==2 && cubeLayout[17]==0) {
      down[8]="b2";
      right[8] = "y0";
      back[6] = "r0";
    } else if (cubeLayout[33]==1 && cubeLayout[17]==5) {
      down[8]="b6";
      right[8] = "w8";
      back[6] = "o8";
    } else if (cubeLayout[33]==0 && cubeLayout[17]==1) {
      down[8]="b0";
      right[8] = "o2";
      back[6] = "y2";
    }
  } else if (cubeLayout[53]==4) {
    if (cubeLayout[33]==0 && cubeLayout[17]==2) {
      down[8] = "g0";
      right[8] = "r2";
      back[6] = "y6";
    } else if (cubeLayout[33]==2 && cubeLayout[17]==5) {
      down[8]="g6";
      right[8] = "w0";
      back[6] = "r8";
    } else if (cubeLayout[33]==1 && cubeLayout[17]==0) {
      down[8]="g2";
      right[8] = "y8";
      back[6] = "o0";
    } else if (cubeLayout[33]==5 && cubeLayout[17]==1) {
      down[8]="g8";
      right[8] = "o6";
      back[6] = "w2";
    }
  } else if (cubeLayout[53]==5) {
    if (cubeLayout[33]==1 && cubeLayout[17]==4) {
      down[8] = "w2";
      right[8] = "g8";
      back[6] = "o6";
    } else if (cubeLayout[33]==4 && cubeLayout[17]==2) {
      down[8]="w0";
      right[8] = "r8";
      back[6] = "g6";
    } else if (cubeLayout[33]==3 && cubeLayout[17]==1) {
      down[8]="w8";
      right[8] = "o8";
      back[6] = "b6";
    } else if (cubeLayout[33]==2 && cubeLayout[17]==3) {
      down[8]="w6";
      right[8] = "b8";
      back[6] = "r6";
    }
  }









  if (cubeLayout[1]==0) {
    if (cubeLayout[28]==1) {
      top[1]="y5";
      back[1]="o1";
    } else if (cubeLayout[28]==2) {
      top[1]="y3";
      back[1]="r1";
    } else if (cubeLayout[28]==3) {
      top[1]="y1";
      back[1]="b1";
    } else if (cubeLayout[28]==4) {
      top[1]="y7";
      back[1]="g1";
    }
  } else if (cubeLayout[1]==1) {

    if (cubeLayout[28]==0) {
      top[1]="o1";
      back[1]="y5";
    } else if (cubeLayout[28]==4) {
      top[1]="o3";
      back[1]="g5";
    } else if (cubeLayout[28]==5) {
      top[1]="o7";
      back[1]="w5";
    } else if (cubeLayout[28]==3) {
      top[1]="o5";
      back[1]="b3";
    }
  } else if (cubeLayout[1]==2) {

    if (cubeLayout[28]==4) {
      top[1]="r5";
      back[1]="g5";
    } else if (cubeLayout[28]==3) {
      top[1]="r3";
      back[1]="b5";
    } else if (cubeLayout[28]==0) {
      top[1]="r1";
      back[1]="y3";
    } else if (cubeLayout[28]==5) {
      top[1]="r7";
      back[1]="w3";
    }
  } else if (cubeLayout[1]==3) {

    if (cubeLayout[28]==2) {
      top[1]="b5";
      back[1]="r3";
    } else if (cubeLayout[28]==1) {
      top[1]="b3";
      back[1]="o5";
    } else if (cubeLayout[28]==0) {
      top[1]="b1";
      back[1]="y1";
    } else if (cubeLayout[28]==5) {
      top[1]="b7";
      back[1]="w7";
    }
  } else if (cubeLayout[1]==4) {

    if (cubeLayout[28]==1) {
      top[1]="g5";
      back[1]="o3";
    } else if (cubeLayout[28]==2) {
      top[1]="g3";
      back[1]="r5";
    } else if (cubeLayout[28]==0) {
      top[1]="g1";
      back[1]="y7";
    } else if (cubeLayout[28]==5) {
      top[1]="g7";
      back[1]="w1";
    }
  } else if (cubeLayout[1]==5) {

    if (cubeLayout[28]==1) {
      top[1]="w5";
      back[1]="o7";
    } else if (cubeLayout[28]==2) {
      top[1]="w3";
      back[1]="r7";
    } else if (cubeLayout[28]==4) {
      top[1]="w1";
      back[1]="g7";
    } else if (cubeLayout[28]==3) {
      top[1]="w7";
      back[1]="b7";
    }
  }



  if (cubeLayout[3]==0) {
    if (cubeLayout[19]==1) {
      top[3]="y5";
      left[1]="o1";
    } else if (cubeLayout[19]==2) {
      top[3]="y3";
      left[1]="r1";
    } else if (cubeLayout[19]==3) {
      top[3]="y1";
      left[1]="b1";
    } else if (cubeLayout[19]==4) {
      top[3]="y7";
      left[1]="g1";
    }
  } else if (cubeLayout[3]==1) {

    if (cubeLayout[19]==0) {
      top[3]="o1";
      left[1]="y5";
    } else if (cubeLayout[19]==4) {
      top[3]="o3";
      left[1]="g5";
    } else if (cubeLayout[19]==5) {
      top[3]="o7";
      left[1]="w5";
    } else if (cubeLayout[19]==3) {
      top[3]="o5";
      left[1]="b3";
    }
  } else if (cubeLayout[3]==2) {

    if (cubeLayout[19]==4) {
      top[3]="r5";
      left[1]="g5";
    } else if (cubeLayout[19]==3) {
      top[3]="r3";
      left[1]="b5";
    } else if (cubeLayout[19]==0) {
      top[3]="r1";
      left[1]="y3";
    } else if (cubeLayout[19]==5) {
      top[3]="r7";
      left[1]="w3";
    }
  } else if (cubeLayout[3]==3) {

    if (cubeLayout[19]==2) {
      top[3]="b5";
      left[1]="r3";
    } else if (cubeLayout[19]==1) {
      top[3]="b3";
      left[1]="o5";
    } else if (cubeLayout[19]==0) {
      top[3]="b1";
      left[1]="y1";
    } else if (cubeLayout[19]==5) {
      top[3]="b7";
      left[1]="w7";
    }
  } else if (cubeLayout[3]==4) {

    if (cubeLayout[19]==1) {
      top[3]="g5";
      left[1]="o3";
    } else if (cubeLayout[19]==2) {
      top[3]="g3";
      left[1]="r5";
    } else if (cubeLayout[19]==0) {
      top[3]="g1";
      left[1]="y7";
    } else if (cubeLayout[19]==5) {
      top[3]="g7";
      left[1]="w1";
    }
  } else if (cubeLayout[3]==5) {

    if (cubeLayout[19]==1) {
      top[3]="w5";
      left[1]="o7";
    } else if (cubeLayout[19]==2) {
      top[3]="w3";
      left[1]="r7";
    } else if (cubeLayout[19]==4) {
      top[3]="w1";
      left[1]="g7";
    } else if (cubeLayout[19]==3) {
      top[3]="w7";
      left[1]="b7";
    }
  }


  if (cubeLayout[5]==0) {
    if (cubeLayout[10]==1) {
      top[5]="y5";
      right[1]="o1";
    } else if (cubeLayout[10]==2) {
      top[5]="y3";
      right[1]="r1";
    } else if (cubeLayout[10]==3) {
      top[5]="y1";
      right[1]="b1";
    } else if (cubeLayout[10]==4) {
      top[5]="y7";
      right[1]="g1";
    }
  } else if (cubeLayout[5]==1) {

    if (cubeLayout[10]==0) {
      top[5]="o1";
      right[1]="y5";
    } else if (cubeLayout[10]==4) {
      top[5]="o3";
      right[1]="g5";
    } else if (cubeLayout[10]==5) {
      top[5]="o7";
      right[1]="w5";
    } else if (cubeLayout[10]==3) {
      top[5]="o5";
      right[1]="b3";
    }
  } else if (cubeLayout[5]==2) {

    if (cubeLayout[10]==4) {
      top[5]="r5";
      right[1]="g3";
    } else if (cubeLayout[10]==3) {
      top[5]="r3";
      right[1]="b5";
    } else if (cubeLayout[10]==0) {
      top[5]="r1";
      right[1]="y3";
    } else if (cubeLayout[10]==5) {
      top[5]="r7";
      right[1]="w3";
    }
  } else if (cubeLayout[5]==3) {

    if (cubeLayout[10]==2) {
      top[5]="b5";
      right[1]="r3";
    } else if (cubeLayout[10]==1) {
      top[5]="b3";
      right[1]="o5";
    } else if (cubeLayout[10]==0) {
      top[5]="b1";
      right[1]="y1";
    } else if (cubeLayout[10]==5) {
      top[5]="b7";
      right[1]="w7";
    }
  } else if (cubeLayout[5]==4) {

    if (cubeLayout[10]==1) {
      top[5]="g5";
      right[1]="o3";
    } else if (cubeLayout[10]==2) {
      top[5]="g3";
      right[1]="r5";
    } else if (cubeLayout[10]==0) {
      top[5]="g1";
      right[1]="y7";
    } else if (cubeLayout[10]==5) {
      top[5]="g7";
      right[1]="w1";
    }
  } else if (cubeLayout[5]==5) {

    if (cubeLayout[10]==1) {
      top[5]="w5";
      right[1]="o7";
    } else if (cubeLayout[10]==2) {
      top[5]="w3";
      right[1]="r7";
    } else if (cubeLayout[10]==4) {
      top[5]="w1";
      right[1]="g7";
    } else if (cubeLayout[10]==3) {
      top[5]="w7";
      right[1]="b7";
    }
  }


  if (cubeLayout[7]==0) {
    if (cubeLayout[37]==1) {
      top[7]="y5";
      front[1]="o1";
    } else if (cubeLayout[37]==2) {
      top[7]="y3";
      front[1]="r1";
    } else if (cubeLayout[37]==3) {
      top[7]="y1";
      front[1]="b1";
    } else if (cubeLayout[37]==4) {
      top[7]="y7";
      front[1]="g1";
    }
  } else if (cubeLayout[7]==1) {

    if (cubeLayout[37]==0) {
      top[7]="o1";
      front[1]="y5";
    } else if (cubeLayout[37]==4) {
      top[7]="o3";
      front[1]="g5";
    } else if (cubeLayout[37]==5) {
      top[7]="o7";
      front[1]="w5";
    } else if (cubeLayout[37]==3) {
      top[7]="o5";
      front[1]="b3";
    }
  } else if (cubeLayout[7]==2) {

    if (cubeLayout[37]==4) {
      top[7]="r5";
      front[1]="g5";
    } else if (cubeLayout[37]==3) {
      top[7]="r3";
      front[1]="b5";
    } else if (cubeLayout[37]==0) {
      top[7]="r1";
      front[1]="y3";
    } else if (cubeLayout[37]==5) {
      top[7]="r7";
      front[1]="w3";
    }
  } else if (cubeLayout[7]==3) {

    if (cubeLayout[37]==2) {
      top[7]="b5";
      front[1]="r3";
    } else if (cubeLayout[37]==1) {
      top[7]="b3";
      front[1]="o5";
    } else if (cubeLayout[37]==0) {
      top[7]="b1";
      front[1]="y1";
    } else if (cubeLayout[37]==5) {
      top[7]="b7";
      front[1]="w7";
    }
  } else if (cubeLayout[7]==4) {

    if (cubeLayout[37]==1) {
      top[7]="g5";
      front[1]="o3";
    } else if (cubeLayout[37]==2) {
      top[7]="g3";
      front[1]="r5";
    } else if (cubeLayout[37]==0) {
      top[7]="g1";
      front[1]="y7";
    } else if (cubeLayout[37]==5) {
      top[7]="g7";
      front[1]="w1";
    }
  } else if (cubeLayout[7]==5) {

    if (cubeLayout[37]==1) {
      top[7]="w5";
      front[1]="o7";
    } else if (cubeLayout[37]==2) {
      top[7]="w3";
      front[1]="r7";
    } else if (cubeLayout[37]==4) {
      top[7]="w1";
      front[1]="g7";
    } else if (cubeLayout[37]==3) {
      top[7]="w7";
      front[1]="b7";
    }
  }












  if (cubeLayout[52]==0) {
    if (cubeLayout[34]==1) {
      down[7]="y5";
      back[7]="o1";
    } else if (cubeLayout[34]==2) {
      down[7]="y3";
      back[7]="r1";
    } else if (cubeLayout[34]==3) {
      down[7]="y1";
      back[7]="b1";
    } else if (cubeLayout[34]==4) {
      down[7]="y7";
      back[7]="g1";
    }
  } else if (cubeLayout[52]==1) {

    if (cubeLayout[34]==0) {
      down[7]="o1";
      back[7]="y5";
    } else if (cubeLayout[34]==4) {
      down[7]="o3";
      back[7]="g5";
    } else if (cubeLayout[34]==5) {
      down[7]="o7";
      back[7]="w5";
    } else if (cubeLayout[34]==3) {
      down[7]="o5";
      back[7]="b3";
    }
  } else if (cubeLayout[52]==2) {

    if (cubeLayout[34]==4) {
      down[7]="r5";
      back[7]="g5";
    } else if (cubeLayout[34]==3) {
      down[7]="r3";
      back[7]="b5";
    } else if (cubeLayout[34]==0) {
      down[7]="r1";
      back[7]="y3";
    } else if (cubeLayout[34]==5) {
      down[7]="r7";
      back[7]="w3";
    }
  } else if (cubeLayout[52]==3) {

    if (cubeLayout[34]==2) {
      down[7]="b5";
      back[7]="r3";
    } else if (cubeLayout[34]==1) {
      down[7]="b3";
      back[7]="o5";
    } else if (cubeLayout[34]==0) {
      down[7]="b1";
      back[7]="y1";
    } else if (cubeLayout[34]==5) {
      down[7]="b7";
      back[7]="w7";
    }
  } else if (cubeLayout[52]==4) {

    if (cubeLayout[34]==1) {
      down[7]="g5";
      back[7]="o3";
    } else if (cubeLayout[34]==2) {
      down[7]="g3";
      back[7]="r5";
    } else if (cubeLayout[34]==0) {
      down[7]="g1";
      back[7]="y7";
    } else if (cubeLayout[34]==5) {
      down[7]="g7";
      back[7]="w1";
    }
  } else if (cubeLayout[52]==5) {

    if (cubeLayout[34]==1) {
      down[7]="w5";
      back[7]="o7";
    } else if (cubeLayout[34]==2) {
      down[7]="w3";
      back[7]="r7";
    } else if (cubeLayout[34]==4) {
      down[7]="w1";
      back[7]="g7";
    } else if (cubeLayout[34]==3) {
      down[7]="w7";
      back[7]="b7";
    }
  }



  if (cubeLayout[48]==0) {
    if (cubeLayout[25]==1) {
      down[3]="y5";
      left[7]="o1";
    } else if (cubeLayout[25]==2) {
      down[3]="y3";
      left[7]="r1";
    } else if (cubeLayout[25]==3) {
      down[3]="y1";
      left[7]="b1";
    } else if (cubeLayout[25]==4) {
      down[3]="y7";
      left[7]="g1";
    }
  } else if (cubeLayout[48]==1) {

    if (cubeLayout[25]==0) {
      down[3]="o1";
      left[7]="y5";
    } else if (cubeLayout[25]==4) {
      down[3]="o3";
      left[7]="g5";
    } else if (cubeLayout[25]==5) {
      down[3]="o7";
      left[7]="w5";
    } else if (cubeLayout[25]==3) {
      down[3]="o5";
      left[7]="b3";
    }
  } else if (cubeLayout[48]==2) {

    if (cubeLayout[25]==4) {
      down[3]="r5";
      left[7]="g5";
    } else if (cubeLayout[25]==3) {
      down[3]="r3";
      left[7]="b5";
    } else if (cubeLayout[25]==0) {
      down[3]="r1";
      left[7]="y3";
    } else if (cubeLayout[25]==5) {
      down[3]="r7";
      left[7]="w3";
    }
  } else if (cubeLayout[48]==3) {

    if (cubeLayout[25]==2) {
      down[3]="b5";
      left[7]="r3";
    } else if (cubeLayout[25]==1) {
      down[3]="b3";
      left[7]="o5";
    } else if (cubeLayout[25]==0) {
      down[3]="b1";
      left[7]="y1";
    } else if (cubeLayout[25]==5) {
      down[3]="b7";
      left[7]="w7";
    }
  } else if (cubeLayout[48]==4) {

    if (cubeLayout[25]==1) {
      down[3]="g5";
      left[7]="o3";
    } else if (cubeLayout[25]==2) {
      down[3]="g3";
      left[7]="r5";
    } else if (cubeLayout[25]==0) {
      down[3]="g1";
      left[7]="y7";
    } else if (cubeLayout[25]==5) {
      down[3]="g7";
      left[7]="w1";
    }
  } else if (cubeLayout[48]==5) {

    if (cubeLayout[25]==1) {
      down[3]="w5";
      left[7]="o7";
    } else if (cubeLayout[25]==2) {
      down[3]="w3";
      left[7]="r7";
    } else if (cubeLayout[25]==4) {
      down[3]="w1";
      left[7]="g7";
    } else if (cubeLayout[25]==3) {
      down[3]="w7";
      left[7]="b7";
    }
  }


  if (cubeLayout[50]==0) {
    if (cubeLayout[16]==1) {
      down[5]="y5";
      right[7]="o1";
    } else if (cubeLayout[16]==2) {
      down[5]="y3";
      right[7]="r1";
    } else if (cubeLayout[16]==3) {
      down[5]="y1";
      right[7]="b1";
    } else if (cubeLayout[16]==4) {
      down[5]="y7";
      right[7]="g1";
    }
  } else if (cubeLayout[50]==1) {

    if (cubeLayout[16]==0) {
      down[5]="o1";
      right[7]="y5";
    } else if (cubeLayout[16]==4) {
      down[5]="o3";
      right[7]="g5";
    } else if (cubeLayout[16]==5) {
      down[5]="o7";
      right[7]="w5";
    } else if (cubeLayout[16]==3) {
      down[5]="o5";
      right[7]="b3";
    }
  } else if (cubeLayout[50]==2) {

    if (cubeLayout[16]==4) {
      down[5]="r5";
      right[7]="g5";
    } else if (cubeLayout[16]==3) {
      down[5]="r3";
      right[7]="b5";
    } else if (cubeLayout[16]==0) {
      down[5]="r1";
      right[7]="y3";
    } else if (cubeLayout[16]==5) {
      down[5]="r7";
      right[7]="w3";
    }
  } else if (cubeLayout[50]==3) {

    if (cubeLayout[16]==2) {
      down[5]="b5";
      right[7]="r3";
    } else if (cubeLayout[16]==1) {
      down[5]="b3";
      right[7]="o5";
    } else if (cubeLayout[16]==0) {
      down[5]="b1";
      right[7]="y1";
    } else if (cubeLayout[16]==5) {
      down[5]="b7";
      right[7]="w7";
    }
  } else if (cubeLayout[50]==4) {

    if (cubeLayout[16]==1) {
      down[5]="g5";
      right[7]="o3";
    } else if (cubeLayout[16]==2) {
      down[5]="g3";
      right[7]="r5";
    } else if (cubeLayout[16]==0) {
      down[5]="g1";
      right[7]="y7";
    } else if (cubeLayout[16]==5) {
      down[5]="g7";
      right[7]="w1";
    }
  } else if (cubeLayout[50]==5) {

    if (cubeLayout[16]==1) {
      down[5]="w5";
      right[7]="o7";
    } else if (cubeLayout[16]==2) {
      down[5]="w3";
      right[7]="r7";
    } else if (cubeLayout[16]==4) {
      down[5]="w1";
      right[7]="g7";
    } else if (cubeLayout[16]==3) {
      down[5]="w7";
      right[7]="b7";
    }
  }


  if (cubeLayout[46]==0) {
    if (cubeLayout[43]==1) {
      down[1]="y5";
      front[7]="o1";
    } else if (cubeLayout[43]==2) {
      down[1]="y3";
      front[7]="r1";
    } else if (cubeLayout[43]==3) {
      down[1]="y1";
      front[7]="b1";
    } else if (cubeLayout[43]==4) {
      down[1]="y7";
      front[7]="g1";
    }
  } else if (cubeLayout[46]==1) {

    if (cubeLayout[43]==0) {
      down[1]="o1";
      front[7]="y5";
    } else if (cubeLayout[43]==4) {
      down[1]="o3";
      front[7]="g5";
    } else if (cubeLayout[43]==5) {
      down[1]="o7";
      front[7]="w5";
    } else if (cubeLayout[43]==3) {
      down[1]="o5";
      front[7]="b3";
    }
  } else if (cubeLayout[46]==2) {

    if (cubeLayout[43]==4) {
      down[1]="r5";
      front[7]="g5";
    } else if (cubeLayout[43]==3) {
      down[1]="r3";
      front[7]="b5";
    } else if (cubeLayout[43]==0) {
      down[1]="r1";
      front[7]="y3";
    } else if (cubeLayout[43]==5) {
      down[1]="r7";
      front[7]="w3";
    }
  } else if (cubeLayout[46]==3) {

    if (cubeLayout[43]==2) {
      down[1]="b5";
      front[7]="r3";
    } else if (cubeLayout[43]==1) {
      down[1]="b3";
      front[7]="o5";
    } else if (cubeLayout[43]==0) {
      down[1]="b1";
      front[7]="y1";
    } else if (cubeLayout[43]==5) {
      down[1]="b7";
      front[7]="w7";
    }
  } else if (cubeLayout[46]==4) {

    if (cubeLayout[43]==1) {
      down[1]="g5";
      front[7]="o3";
    } else if (cubeLayout[43]==2) {
      down[1]="g3";
      front[7]="r5";
    } else if (cubeLayout[43]==0) {
      down[1]="g1";
      front[7]="y7";
    } else if (cubeLayout[43]==5) {
      down[1]="g7";
      front[7]="w1";
    }
  } else if (cubeLayout[46]==5) {

    if (cubeLayout[43]==1) {
      down[1]="w5";
      front[7]="o7";
    } else if (cubeLayout[43]==2) {
      down[1]="w3";
      front[7]="r7";
    } else if (cubeLayout[43]==4) {
      down[1]="w1";
      front[7]="g7";
    } else if (cubeLayout[43]==3) {
      down[1]="w7";
      front[7]="b7";
    }
  }













  if (cubeLayout[39]==0) {
    if (cubeLayout[23]==1) {
      front[3]="y5";
      left[5]="o1";
    } else if (cubeLayout[23]==2) {
      front[3]="y3";
      left[5]="r1";
    } else if (cubeLayout[23]==3) {
      front[3]="y1";
      left[5]="b1";
    } else if (cubeLayout[23]==4) {
      front[3]="y7";
      left[5]="g1";
    }
  } else if (cubeLayout[39]==1) {

    if (cubeLayout[23]==0) {
      front[3]="o1";
      left[5]="y5";
    } else if (cubeLayout[23]==4) {
      front[3]="o3";
      left[5]="g5";
    } else if (cubeLayout[23]==5) {
      front[3]="o7";
      left[5]="w5";
    } else if (cubeLayout[23]==3) {
      front[3]="o5";
      left[5]="b3";
    }
  } else if (cubeLayout[39]==2) {

    if (cubeLayout[23]==4) {
      front[3]="r5";
      left[5]="g3";
    } else if (cubeLayout[23]==3) {
      front[3]="r3";
      left[5]="b5";
    } else if (cubeLayout[23]==0) {
      front[3]="r1";
      left[5]="y3";
    } else if (cubeLayout[23]==5) {
      front[3]="r7";
      left[5]="w3";
    }
  } else if (cubeLayout[39]==3) {

    if (cubeLayout[23]==2) {
      front[3]="b5";
      left[5]="r3";
    } else if (cubeLayout[23]==1) {
      front[3]="b3";
      left[5]="o5";
    } else if (cubeLayout[23]==0) {
      front[3]="b1";
      left[5]="y1";
    } else if (cubeLayout[23]==5) {
      front[3]="b7";
      left[5]="w7";
    }
  } else if (cubeLayout[39]==4) {

    if (cubeLayout[23]==1) {
      front[3]="g5";
      left[5]="o3";
    } else if (cubeLayout[23]==2) {
      front[3]="g3";
      left[5]="r5";
    } else if (cubeLayout[23]==0) {
      front[3]="g1";
      left[5]="y7";
    } else if (cubeLayout[23]==5) {
      front[3]="g7";
      left[5]="w1";
    }
  } else if (cubeLayout[39]==5) {

    if (cubeLayout[23]==1) {
      front[3]="w5";
      left[5]="o7";
    } else if (cubeLayout[23]==2) {
      front[3]="w3";
      left[5]="r7";
    } else if (cubeLayout[23]==4) {
      front[3]="w1";
      left[5]="g7";
    } else if (cubeLayout[23]==3) {
      front[3]="w7";
      left[5]="b7";
    }
  }


  if (cubeLayout[41]==0) {
    if (cubeLayout[12]==1) {
      front[5]="y5";
      right[3]="o1";
    } else if (cubeLayout[12]==2) {
      front[5]="y3";
      right[3]="r1";
    } else if (cubeLayout[12]==3) {
      front[5]="y1";
      right[3]="b1";
    } else if (cubeLayout[12]==4) {
      front[5]="y7";
      right[3]="g1";
    }
  } else if (cubeLayout[41]==1) {

    if (cubeLayout[12]==0) {
      front[5]="o1";
      right[3]="y5";
    } else if (cubeLayout[12]==4) {
      front[5]="o3";
      right[3]="g5";
    } else if (cubeLayout[12]==5) {
      front[5]="o7";
      right[3]="w5";
    } else if (cubeLayout[12]==3) {
      front[5]="o5";
      right[3]="b3";
    }
  } else if (cubeLayout[41]==2) {

    if (cubeLayout[12]==4) {
      front[5]="r5";
      right[3]="g5";
    } else if (cubeLayout[12]==3) {
      front[5]="r3";
      right[3]="b5";
    } else if (cubeLayout[12]==0) {
      front[5]="r1";
      right[3]="y3";
    } else if (cubeLayout[12]==5) {
      front[5]="r7";
      right[3]="w3";
    }
  } else if (cubeLayout[41]==3) {

    if (cubeLayout[12]==2) {
      front[5]="b5";
      right[3]="r3";
    } else if (cubeLayout[12]==1) {
      front[5]="b3";
      right[3]="o5";
    } else if (cubeLayout[12]==0) {
      front[5]="b1";
      right[3]="y1";
    } else if (cubeLayout[12]==5) {
      front[5]="b7";
      right[3]="w7";
    }
  } else if (cubeLayout[41]==4) {

    if (cubeLayout[12]==1) {
      front[5]="g5";
      right[3]="o3";
    } else if (cubeLayout[12]==2) {
      front[5]="g3";
      right[3]="r5";
    } else if (cubeLayout[12]==0) {
      front[5]="g1";
      right[3]="y7";
    } else if (cubeLayout[12]==5) {
      front[5]="g7";
      right[3]="w1";
    }
  } else if (cubeLayout[41]==5) {

    if (cubeLayout[12]==1) {
      front[5]="w5";
      right[3]="o7";
    } else if (cubeLayout[12]==2) {
      front[5]="w3";
      right[3]="r7";
    } else if (cubeLayout[12]==4) {
      front[5]="w1";
      right[3]="g7";
    } else if (cubeLayout[12]==3) {
      front[5]="w7";
      right[3]="b7";
    }
  }


  if (cubeLayout[30]==0) {
    if (cubeLayout[14]==1) {
      back[3]="y5";
      right[5]="o1";
    } else if (cubeLayout[14]==2) {
      back[3]="y3";
      right[5]="r1";
    } else if (cubeLayout[14]==3) {
      back[3]="y1";
      right[5]="b1";
    } else if (cubeLayout[14]==4) {
      back[3]="y7";
      right[5]="g1";
    }
  } else if (cubeLayout[30]==1) {

    if (cubeLayout[14]==0) {
      back[3]="o1";
      right[5]="y5";
    } else if (cubeLayout[14]==4) {
      back[3]="o3";
      right[5]="g5";
    } else if (cubeLayout[14]==5) {
      back[3]="o7";
      right[5]="w5";
    } else if (cubeLayout[14]==3) {
      back[3]="o5";
      right[5]="b3";
    }
  } else if (cubeLayout[30]==2) {

    if (cubeLayout[14]==4) {
      back[3]="r5";
      right[5]="g5";
    } else if (cubeLayout[14]==3) {
      back[3]="r3";
      right[5]="b5";
    } else if (cubeLayout[14]==0) {
      back[3]="r1";
      right[5]="y3";
    } else if (cubeLayout[14]==5) {
      back[3]="r7";
      right[5]="w3";
    }
  } else if (cubeLayout[30]==3) {

    if (cubeLayout[14]==2) {
      back[3]="b5";
      right[5]="r3";
    } else if (cubeLayout[14]==1) {
      back[3]="b3";
      right[5]="o5";
    } else if (cubeLayout[14]==0) {
      back[3]="b1";
      right[5]="y1";
    } else if (cubeLayout[14]==5) {
      back[3]="b7";
      right[5]="w7";
    }
  } else if (cubeLayout[30]==4) {

    if (cubeLayout[14]==1) {
      back[3]="g5";
      right[5]="o3";
    } else if (cubeLayout[14]==2) {
      back[3]="g3";
      right[5]="r5";
    } else if (cubeLayout[14]==0) {
      back[3]="g1";
      right[5]="y7";
    } else if (cubeLayout[14]==5) {
      back[3]="g7";
      right[5]="w1";
    }
  } else if (cubeLayout[30]==5) {

    if (cubeLayout[14]==1) {
      back[3]="w5";
      right[5]="o7";
    } else if (cubeLayout[14]==2) {
      back[3]="w3";
      right[5]="r7";
    } else if (cubeLayout[14]==4) {
      back[3]="w1";
      right[5]="g7";
    } else if (cubeLayout[14]==3) {
      back[3]="w7";
      right[5]="b7";
    }
  }


  if (cubeLayout[32]==0) {
    if (cubeLayout[21]==1) {
      back[5]="y5";
      left[3]="o1";
    } else if (cubeLayout[21]==2) {
      back[5]="y3";
      left[3]="r1";
    } else if (cubeLayout[21]==3) {
      back[5]="y1";
      left[3]="b1";
    } else if (cubeLayout[21]==4) {
      back[5]="y7";
      left[3]="g1";
    }
  } else if (cubeLayout[32]==1) {

    if (cubeLayout[21]==0) {
      back[5]="o1";
      left[3]="y5";
    } else if (cubeLayout[21]==4) {
      back[5]="o3";
      left[3]="g5";
    } else if (cubeLayout[21]==5) {
      back[5]="o7";
      left[3]="w5";
    } else if (cubeLayout[21]==3) {
      back[5]="o5";
      left[3]="b3";
    }
  } else if (cubeLayout[32]==2) {

    if (cubeLayout[21]==4) {
      back[5]="r5";
      left[3]="g5";
    } else if (cubeLayout[21]==3) {
      back[5]="r3";
      left[3]="b5";
    } else if (cubeLayout[21]==0) {
      back[5]="r1";
      left[3]="y3";
    } else if (cubeLayout[21]==5) {
      back[5]="r7";
      left[3]="w3";
    }
  } else if (cubeLayout[32]==3) {

    if (cubeLayout[21]==2) {
      back[5]="b5";
      left[3]="r3";
    } else if (cubeLayout[21]==1) {
      back[5]="b3";
      left[3]="o5";
    } else if (cubeLayout[21]==0) {
      back[5]="b1";
      left[3]="y1";
    } else if (cubeLayout[21]==5) {
      back[5]="b7";
      left[3]="w7";
    }
  } else if (cubeLayout[32]==4) {

    if (cubeLayout[21]==1) {
      back[5]="g5";
      left[3]="o3";
    } else if (cubeLayout[21]==2) {
      back[5]="g3";
      left[3]="r5";
    } else if (cubeLayout[21]==0) {
      back[5]="g1";
      left[3]="y7";
    } else if (cubeLayout[21]==5) {
      back[5]="g7";
      left[3]="w1";
    }
  } else if (cubeLayout[32]==5) {

    if (cubeLayout[21]==1) {
      back[5]="w5";
      left[3]="o7";
    } else if (cubeLayout[21]==2) {
      back[5]="w3";
      left[3]="r7";
    } else if (cubeLayout[21]==4) {
      back[5]="w1";
      left[3]="g7";
    } else if (cubeLayout[21]==3) {
      back[5]="w7";
      left[3]="b7";
    }
  }


  front[4] = "g4";
  back[4] = "b4";
  left[4] = "r4";
  right[4] = "o4";
  top[4] = "y4";
  down[4] = "w4";
  cube[0]=front[0].charAt(0);
    for (int i = 1; i<18; i++) {
      cube[i]=front[i/2].charAt(i%2);
    }

    for (int i = 0; i<18; i++) {
      cube[i+18]=back[i/2].charAt(i%2);
    }

    for (int i = 0; i<18; i++) {
      cube[i+36]=left[i/2].charAt(i%2);
    }

    for (int i = 0; i<18; i++) {
      cube[i+54]=right[i/2].charAt(i%2);
    }

    for (int i = 0; i<18; i++) {
      cube[i+72]=top[i/2].charAt(i%2);
    }

    for (int i = 0; i<18; i++) {
      cube[i+90]=down[i/2].charAt(i%2);
    }
  

  for(int i = 0; i <108;i++){
   port.write(cube[i]); 
   print(cube[i]);
   //delay(10);
  }
  port.write('-');
  print('-');
  print_whole_cube();
  // for(int i = 0; i <108;i++){
  // print(cubeLayout[i]);
  //}
}
void print_cube(String cube_side[]) {
  // make a for loop for this
  for (int i = 0; i < 1; i++)
  {
    println('\r');
  }

  print("Face: ");
  println(cube_side[4]);

  for (int i = 0; i < 9; i = i + 3)
  {
    print("|");
    print(cube_side[i]);
    print("|");
    print(cube_side[i + 1]);
    print("|");
    print(cube_side[i + 2]);
    println("|");
  }
}

void print_whole_cube() {
  print_cube(top);
  print_cube(down);
  print_cube(back);
  print_cube(left);
  print_cube(front);
  print_cube(right);
}