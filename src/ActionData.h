#ifndef _ACTION_DATA_H
#define _ACTION_DATA_H
#include <iostream>
#include "PPM.h"
#include "NumberGrid.h"
#include "ColorTable.h"

class ActionData {
    public:
        ActionData(std::istream& is, std::ostream& os);
        std::istream& getIS();
        std::ostream& getOS();
        PPM& getInputImage1();
        PPM& getInputImage2();
        PPM& getOutputImage();
        bool getDone() const;
        void setDone();
        ~ActionData();
        NumberGrid& getGrid();
        void setGrid(NumberGrid *grid);
        ColorTable& getTable();
    protected:
        std::istream& mIstream;
        std::ostream& mOstream;
        PPM mImage1;
        PPM mImage2;
        PPM mOutputImage;
        bool mDone;
        NumberGrid* mNumberGrid;
        ColorTable mColorTable;
};

#endif /* _ACTION_DATA_H */