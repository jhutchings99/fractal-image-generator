#ifndef _GLUTAPP_H_
#define _GLUTAPP_H_

#include "ActionData.h"
#include "MenuData.h"
#include <sstream>

class GlutApp {
public:
  GlutApp(int height, int width);
  void setSize(int height, int width);
  int getHeight() const;
  int getWidth() const;
  void display();

  void createJulia();

  void selectJulia();
  void selectMandelbrot();
  void selectComplexFractal();
  void selectBurningShipFractal();

  void configureGrid(int max); 
  void juliaParameters(double a, double b);
  void fractalPlaneSize(double x_min, double x_max, double y_min, double y_max);
  void fractalCalculate();
  void gridApplyColorTable();

  void createJulia2();
  void createMandelbrot();
  void createMandelbrot2();
  void createComplexFractal();
  void createComplexFractal2();

  void createBurningShipFractal();
  void createBurningShipFractal2();

  enum InteractionMode { IM_FRACTAL, IM_COLORTABLE, IM_MENU, IM_COLOR1, IM_COLOR2, IM_COLOR3 };
  enum FractalMode { M_MANDELBROT, M_JULIA, M_COMPLEX };
  enum MenuMode { M_MENU_TRUE, M_MENU_FALSE };

  void displayColorTable();
  void setInteractionMode(InteractionMode mode);
  void setColorTable();
  void decreaseColorTableSize();
  void increaseColorTableSize();
  void zoomIn();
  void zoomOut();
  void moveLeft();
  void moveRight();
  void moveDown();
  void moveUp();
  void setFractalMode(FractalMode mode);
  void increaseMaxNumber();
  void decreaseMaxNumber();
  void setAB(int x, int y);
  void resetPlane();
  void createFractal();

  void displayMenu(int startSpot);
  void setMenuMode(MenuMode mode);

  Color& fetchColor();

  void increaseChannel(Color& color, int channel);
  void decreaseChannel(Color& color, int channel);

  void increaseRed();
  void decreaseRed();
  void increaseGreen();
  void decreaseGreen();
  void increaseBlue();
  void decreaseBlue();

  void animateAB();

  void zoomInAndMove(int x, int y);

  void writeImage();

  void toggleHSVColor();

protected:
  int mHeight, mWidth;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  ActionData mActionData;
  MenuData mMenuData;
  double mMinX;
  double mMaxX;
  double mMinY;
  double mMaxY;
  double mA = 0.5;
  double mB = 0.2;
  InteractionMode mInteractionMode;
  FractalMode mFractalMode;
  MenuMode mMenuMode;
  int mMaxNumber;
  Color mColor1;
  Color mColor2;
  Color mColor3;
  int mNumColor;

  int mImageNumber;

  bool mHSVColor;
};

#endif /* _GLUTAPP_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */