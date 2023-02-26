#ifndef _THREADED_GRID_H_
#define _THREADED_GRID_H_
#include "NumberGrid.h"
#include "ThreadedVector.h"
#include "Task.h"

class ThreadedGrid : public NumberGrid {
    public:
        ThreadedGrid( );
        ThreadedGrid(const int& height, const int& width);
        virtual ~ThreadedGrid();
        virtual void calculateAllNumbers();
        virtual void worker();
        virtual void setPPM( PPM& ppm, const ColorTable& ct );
        virtual void workerSetPPM(PPM& ppm, const ColorTable& ct);
    private:
        ThreadedVector<int> mTasks;
};

#endif /* _THREADED_GRID_H */