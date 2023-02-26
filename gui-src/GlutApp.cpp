#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
  : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream) {
  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);
  mMinX = -2.0;
  mMinY = -2.0;
  mMaxX = 2.0;
  mMaxY = 2.0;
  mInteractionMode = IM_FRACTAL;
  mFractalMode = M_MANDELBROT;
  mMenuMode = M_MENU_FALSE;
  mMaxNumber = 200;
  mA = 0.02354;
  mB = -0.721;
  
  mColor1 = Color(255, 0, 0);
  mColor2 = Color(255, 255, 0);
  mColor3 = Color(0,0,0);
  mNumColor = 32;

  mImageNumber = 1;

  mHSVColor = false;

  setColorTable();
  createFractal();
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const {
  return mHeight;
}
int GlutApp::getWidth() const {
  return mWidth;
}

void GlutApp::display() {
  if (mInteractionMode == IM_FRACTAL) {
    PPM& p = mActionData.getOutputImage();
    double max = static_cast<double>(p.getMaxColorValue());
    double r, g, b;
    int row, column;
    glBegin( GL_POINTS );
    for(row = 0; row < p.getHeight(); row++) {
      for(column = 0; column < p.getWidth(); column++) {
        r = p.getChannel(row, column, 0) / max;
        g = p.getChannel(row, column, 1) / max;
        b = p.getChannel(row, column, 2) / max;
        glColor3d(r, g, b);
        glVertex2i(column, p.getHeight()-row-1);
      }
    }
    glEnd( );
    glColor3f(1,1,1);
    DrawText(10, mHeight - 20, "? menu");
    if (mMenuMode == M_MENU_TRUE) {
      displayMenu(mHeight);
    }

  } else if (mInteractionMode == IM_COLORTABLE) {
    displayColorTable();
  } else if (mInteractionMode == IM_COLOR1 || mInteractionMode == IM_COLOR2 || mInteractionMode == IM_COLOR3) {
    displayColorTable();
  }
}

void GlutApp::displayMenu(int startSpot) {
  DrawText(10, startSpot - 35, "T display color table");
  DrawText(10, startSpot - 50, "t display fractal");
  DrawText(10, startSpot - 65, "> or . increases the color table size");
  DrawText(10, startSpot - 80, "< or , decreases the color table size");
  DrawText(10, startSpot - 95, "n display julia set");  
  DrawText(10, startSpot - 110, "F display complex fractal");  
  DrawText(10, startSpot - 125, "b display mandelbrot set");  
  DrawText(10, startSpot - 140, "mouse click set julia parameters");  
  DrawText(10, startSpot - 155, "z zoom in");  
  DrawText(10, startSpot - 170, "Z zoom out");  
  DrawText(10, startSpot - 185, "left arrow move left");  
  DrawText(10, startSpot - 200, "right arrow move right");  
  DrawText(10, startSpot - 215, "up arrow move up");  
  DrawText(10, startSpot - 230, "down arrow move down");  
  DrawText(10, startSpot - 245, "R reset plane");  
  DrawText(10, startSpot - 260, "+ or = increase max number");  
  DrawText(10, startSpot - 275, "j default julia set");  
  DrawText(10, startSpot - 290, "J second default julia set");  
  DrawText(10, startSpot - 305, "m default mandelbrot set");  
  DrawText(10, startSpot - 320, "M second default mandelbrot set");  
  DrawText(10, startSpot - 335, "x default burningship set");  
  DrawText(10, startSpot - 350, "X second default burningship set");  
  DrawText(10, startSpot - 365, "c default complex fractal");  
  DrawText(10, startSpot - 380, "C default second complex fractal");   
  DrawText(10, startSpot - 395, "A animate julia set on page 'n'");
  DrawText(350, startSpot - 20, "1 select color one");
  DrawText(350, startSpot - 35, "2 select color two");
  DrawText(350, startSpot - 50, "3 select color three");
  DrawText(350, startSpot - 65, "Y increase red value for selected color");
  DrawText(350, startSpot - 80, "y decrease red value for selected color");
  DrawText(350, startSpot - 95, "U increase green value for selected color");
  DrawText(350, startSpot - 110, "u decrease green value for selected color");
  DrawText(350, startSpot - 125, "I increase blue value for selected color");
  DrawText(350, startSpot - 140, "i decrease blue value for selected color");
  DrawText(350, startSpot - 155, "mmb zoom in on mouse cursor");
  DrawText(350, startSpot - 170, "rmb zoom out");
  DrawText(350, startSpot - 185, "w save image");
}

void GlutApp::createJulia() {
  // julia
  selectJulia();
  
  // grid
  configureGrid(200);

  // julia-parameters
  juliaParameters(0.45, -0.32);

  // fractal-plane-size
  fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
  
  // fractal-calculate
  fractalCalculate();

  // grid-apply-color-table
  gridApplyColorTable();
}

void GlutApp::selectJulia() {
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("julia", mMenuData, mActionData);
}

void GlutApp::selectMandelbrot() {
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("mandelbrot", mMenuData, mActionData);
}

void GlutApp::selectComplexFractal() {
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("complex-fractal", mMenuData, mActionData);
}

void GlutApp::selectBurningShipFractal() {
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("burningship", mMenuData, mActionData);
}

// void GlutApp::selectJuliaFourFractal() {
//   mOutputStream.clear();
//   mOutputStream.str("");
//   mInputStream.clear();
//   mInputStream.str("");
//   takeAction("julia-four", mMenuData, mActionData);
// }

void GlutApp::configureGrid(int max) {
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " " << max;
    mInputStream.str(tmp.str());
  }
  takeAction("grid", mMenuData, mActionData);
}

void GlutApp::juliaParameters(double a, double b) {
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << a << " " << b;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters", mMenuData, mActionData);
}

void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max) {
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << x_min << " " << x_max << " "<< y_min << " " << y_max;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size", mMenuData, mActionData);
}

void GlutApp::fractalCalculate() {
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  takeAction("fractal-calculate", mMenuData, mActionData);
}

void GlutApp::gridApplyColorTable() {
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  takeAction("grid-apply-color-table", mMenuData, mActionData);
}

void GlutApp::createJulia2() {
  selectJulia();
  configureGrid(120);
  juliaParameters(-0.7269, 0.1889);
  fractalPlaneSize(-4.5, 4.5, -4.5, 4.5);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::createMandelbrot() {
  selectMandelbrot();
  configureGrid(200);
  fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::createMandelbrot2() {
  selectMandelbrot();
  configureGrid(100);
  fractalPlaneSize(-2, -1.3, -0.1, 0.1);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::createComplexFractal() {
  selectComplexFractal();
  configureGrid(200);
  fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::createComplexFractal2() {
  selectComplexFractal();
  configureGrid(200);
  fractalPlaneSize(-0.05, 0.05, -0.05, 0.05);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::createBurningShipFractal() {
  selectBurningShipFractal();
  configureGrid(200);
  fractalPlaneSize(-1.8, -1.7, -0.02, 0.08);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::createBurningShipFractal2() {
  selectBurningShipFractal();
  configureGrid(200);
  fractalPlaneSize(-1.59, -1.49, -0.048, 0.090);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::displayColorTable() {
  PPM& p = mActionData.getOutputImage();
  double r, g, b;
  int row, column;
  glBegin( GL_POINTS );
  for(row = 0; row < p.getHeight(); row++) {
    for(column = 0; column < p.getWidth(); column++) {
      int i = column * mActionData.getTable().getNumberOfColors() / p.getWidth();
      Color c = mActionData.getTable()[i];
      r = c.getRed() / 255.0;
      g = c.getGreen() / 255.0;
      b = c.getBlue() / 255.0;
      glColor3d(r, g, b);
      glVertex2i(column, row);
    }
  }
  glEnd( );
}

void GlutApp::setInteractionMode(InteractionMode mode) {
  mInteractionMode = mode;
}

void GlutApp::setMenuMode(MenuMode mode) {
  mMenuMode = mode;
}

void GlutApp::setColorTable() {
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mNumColor;
    mInputStream.str(tmp.str());
  }
  takeAction("set-color-table-size", mMenuData, mActionData);

  if (!mHSVColor) {
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
      std::stringstream tmp;
      int half = mNumColor / 2;
      tmp << 0 << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue() << " " 
      << half << " " << mColor2.getRed() << " " << mColor2.getGreen() << " " << mColor2.getBlue();
      mInputStream.str(tmp.str());
    }
    takeAction("set-color-gradient", mMenuData, mActionData);

    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
      std::stringstream tmp;
      int half = mNumColor / 2;
      tmp << half << " " << mColor2.getRed() << " " << mColor2.getGreen() << " " << mColor2.getBlue() << " "
      << mNumColor - 1 << " " << mColor3.getRed() << " " << mColor3.getGreen() << " " << mColor3.getBlue();
      mInputStream.str(tmp.str());
    }
    takeAction("set-color-gradient", mMenuData, mActionData);
  } else {
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
      std::stringstream tmp;
      int half = mNumColor / 2;
      double h1, s1, v1;
      mColor1.getHSV(h1, s1, v1);
      double h2, s2, v2;
      mColor2.getHSV(h2, s2, v2);
      tmp << 0 << " " << h1 << " " << s1 << " " << v1 << " " 
      << half << " " << h2 << " " << s2 << " " << v2;
      mInputStream.str(tmp.str());
    }

    takeAction("set-hsv-gradient", mMenuData, mActionData);

    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
      std::stringstream tmp;
      int half = mNumColor / 2;
      double h2, s2, v2;
      mColor2.getHSV(h2, s2, v2);
      double h3, s3, v3;
      mColor3.getHSV(h3, s3, v3);
      tmp << half << " " << h2 << " " << s2 << " " << v2 << " " 
      << mNumColor - 1 << " " << h3 << " " << s3 << " " << v3;
      mInputStream.str(tmp.str());
    }

    takeAction("set-hsv-gradient", mMenuData, mActionData);
  }
}

void GlutApp::decreaseColorTableSize() {
  if (mNumColor > 10) {
    mNumColor /= 1.1;
    setColorTable();
    gridApplyColorTable();
  }
}

void GlutApp::increaseColorTableSize() {
  if (mNumColor < 1024) {
    mNumColor *= 1.1;
    setColorTable();
    gridApplyColorTable();
  }
}

void GlutApp::zoomIn() {
  double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
  mMinX += dx;
  mMaxX -= dx;
  double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
  mMinY += dy;
  mMaxY -= dy;
}

void GlutApp::zoomOut() {
  double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
  if (mMinX - dx > -2.0 && mMaxX + dx < 2.0) {
    mMinX -= dx;
    mMaxX += dx;
  }

  double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
  if (mMinY - dy > -2.0 && mMaxY + dy < 2.0) {
    mMinY -= dy;
    mMaxY += dy;
  }
}

void GlutApp::moveLeft() {
  double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
  if (mMinX - dx > -2.0) {
    mMinX -= dx;
    mMaxX -= dx;
  }
}

void GlutApp::moveRight() {
  double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
  if (mMaxX + dx < 2.0) {
    mMinX += dx;
    mMaxX += dx;
  }
}

void GlutApp::moveDown() {
  double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
  if (mMinY - dy > -2.0) {
    mMinY -= dy;
    mMaxY -= dy;
  }
}

void GlutApp::moveUp() {
  double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
  if (mMaxY + dy < 2.0) {
    mMinY += dy;
    mMaxY += dy;
  }
}

void GlutApp::setFractalMode(FractalMode mode) {
  mFractalMode = mode;
}

void GlutApp::increaseMaxNumber() {
  if (mMaxNumber < 2048) {
    mMaxNumber *= 1.1;
  }
}

void GlutApp::decreaseMaxNumber() {
  if (mMaxNumber > 11) {
    mMaxNumber /= 1.1;
  }
}

void GlutApp::setAB(int x, int y) {
  if (mFractalMode == M_MANDELBROT) {
    ComplexFractal *cf = dynamic_cast<ComplexFractal *>(&mActionData.getGrid());
    if (cf != 0) {
      mA = mMinX + x * (*cf).getDeltaX();
      mB = mMinY + y * (*cf).getDeltaY();
    }
  }
}

void GlutApp::resetPlane() {
  mMinX = -2.0;
  mMaxX = 2.0;
  mMinY = -2.0;
  mMaxY = 2.0;
}

void GlutApp::createFractal(){
  if (mFractalMode == M_MANDELBROT) {
    selectMandelbrot();
  } else if (mFractalMode == M_JULIA) {
    selectJulia();
    juliaParameters(mA, mB);
  } else if (mFractalMode == M_COMPLEX) {
    selectComplexFractal();
  }
  configureGrid(mMaxNumber);
  fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::animateAB() {
  if (mFractalMode == M_JULIA) {
    for (int i = 0; i < 50; i++) {
      mA += 0.01;
      mB += 0.01;
      createFractal();
      display_cb();
    }

    for (int i = 0; i < 50; i++) {
      mA -= 0.01;
      mB -= 0.01;
      createFractal();
      display_cb();
    }
  }
}

  void GlutApp::increaseChannel(Color& color, int channel) {
    if (channel == 0) {
      color.setChannel(0, color.getChannel(0) + 10);
      if (color.getChannel(0) > 255) {
        color.setChannel(0, 255);
      }
    }

    if (channel == 1) {
      color.setChannel(1, color.getChannel(1) + 10);
      if (color.getChannel(1) > 255) {
        color.setChannel(1, 255);
      }
    }

    if (channel == 2) {
      color.setChannel(2, color.getChannel(2) + 10);
      if (color.getChannel(2) > 255) {
        color.setChannel(2, 255);
      }
    }

    setColorTable();
    gridApplyColorTable();
  }

  void GlutApp::decreaseChannel(Color& color, int channel) {
    if (channel == 0) {
      color.setChannel(0, color.getChannel(0) - 10);
      if (color.getChannel(0) < 0) {
        color.setChannel(0, 0);
      }
    }

    if (channel == 1) {
      color.setChannel(1, color.getChannel(1) - 10);
      if (color.getChannel(1) < 0) {
        color.setChannel(1, 0);
      }
    }

    if (channel == 2) {
      color.setChannel(2, color.getChannel(2) - 10);
      if (color.getChannel(2) < 0) {
        color.setChannel(2, 0);
      }
    }

    setColorTable();
    gridApplyColorTable();
  }

  Color& GlutApp::fetchColor() {
    if (mInteractionMode == IM_COLOR1) {
      return mColor1;
    } else if (mInteractionMode == IM_COLOR2) {
      return mColor2;
    } else if (mInteractionMode == IM_COLOR3) {
      return mColor3;
    } else {
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
  }

  void GlutApp::increaseRed() {
    increaseChannel(fetchColor(), 0);
  }

  void GlutApp::decreaseRed() {
    decreaseChannel(fetchColor(), 0);
  }

  void GlutApp::increaseGreen() {
    increaseChannel(fetchColor(), 1);
  }

  void GlutApp::decreaseGreen() {
    decreaseChannel(fetchColor(), 1);
  }

  void GlutApp::increaseBlue() {
    increaseChannel(fetchColor(), 2);
  }

  void GlutApp::zoomInAndMove(int x, int y) {
    zoomIn();
    int dx = abs(x - mWidth/2);
    int dy = abs(y - mHeight/2);
    if (dx > dy) {
      if (x < mWidth/2) {
        moveLeft();
      } else {
        moveRight();
      }
    } else {
      if (y < mHeight/2) {
        moveUp();
      } else {
        moveDown();
      }
    }
  }

  void GlutApp::decreaseBlue() {
    decreaseChannel(fetchColor(), 2);
  }

  void GlutApp::writeImage() {
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
      std::stringstream tmp;
      tmp << "image-" << mImageNumber << ".ppm";
      mInputStream.str(tmp.str());
    }
    takeAction("write", mMenuData, mActionData);
    mImageNumber++;
  }

void GlutApp::toggleHSVColor() {
  if (mHSVColor) {
    mHSVColor = false;
  } else {
    mHSVColor = true;
  }
  setColorTable();
  gridApplyColorTable();
}