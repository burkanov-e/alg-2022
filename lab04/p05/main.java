final float RED_COLOR = 255;
final int N = 13;
float maxSquareSize;


void setup() {
    fullScreen();
    maxSquareSize = min(width, height) / 2f;
    noStroke();
    rectMode(CENTER);
}

void draw() {
  background(0);
  drawRect(0, width / 2f, height / 2f, maxSquareSize, RED_COLOR);
  
  noLoop();
}

void drawRect(int level, float xc, float yc, float squareSize, float redColor){
  if(level < N){
    
    float x1 = xc - squareSize / 2f;
    float y1 = yc - squareSize / 2f;
    float x2 = xc + squareSize / 2f;
    float y2 = yc - squareSize / 2f;
    float x3 = xc + squareSize / 2f;
    float y3 = yc + squareSize / 2f;
    float x4 = xc - squareSize / 2f;
    float y4 = yc + squareSize / 2f;
    
    drawRect(level + 1, x1, y1, squareSize / 2f, redColor - 250/N);
    drawRect(level + 1, x2, y2, squareSize / 2f, redColor - 250/N);
    drawRect(level + 1, x3, y3, squareSize / 2f, redColor - 250/N);
    drawRect(level + 1, x4, y4, squareSize / 2f, redColor - 250/N);
    
    fill(redColor, 0, 0);
    square(xc, yc, squareSize);
  }
}