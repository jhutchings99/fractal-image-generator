#include "ThreadedGrid.h"
#include <thread>
#include "Task.h"

ThreadedGrid::ThreadedGrid( ) 
: NumberGrid() {
}

ThreadedGrid::ThreadedGrid(const int& height, const int& width) 
: NumberGrid(height, width) {
}

ThreadedGrid::~ThreadedGrid() {
}

void ThreadedGrid::calculateAllNumbers() {
    std::vector<std::thread> threads;
	int max_threads = std::thread::hardware_concurrency();
 	int row;
    int i;


	for (row = 0; row < getHeight(); row++) {
		mTasks.push_back(row);
	}

	for (i = 0; i < max_threads; i++) {
		threads.push_back( std::thread(&ThreadedGrid::worker, this) );
	}

	for(i = 0; i < max_threads; i++) {
    	threads[i].join();
	}
}

void ThreadedGrid::worker() {
	std::vector<int> task_queue;
	int col;
    int row;
    int number;
	
	while (!mTasks.empty()) {
		task_queue.clear();
		mTasks.pop_back(task_queue,1);
		if (task_queue.size() > 0) {
			row = task_queue[0];
			for (col = 0; col < mWidth; col++) {
				number = calculateNumber(row, col);
				setNumber(row, col, number);
			}
		}
	}
}

void ThreadedGrid::setPPM( PPM& ppm, const ColorTable& ct ) {
	if (ct.getNumberOfColors() >= 2) {
		ppm.setHeight(getHeight());
		ppm.setWidth(getWidth());
		ppm.setMaxColorValue(ct.getMaxChannelValue());

		std::vector<std::thread> threads;
		int max_threads = std::thread::hardware_concurrency();
		int row;
		int i;
		for (row = 0; row < getHeight(); row++) {
			mTasks.push_back(row);
		}
		for (i = 0; i < max_threads; i++) {
			threads.push_back( std::thread(&ThreadedGrid::workerSetPPM, this, std::ref(ppm), std::ref(ct)) );
		}
		for(i = 0; i < max_threads; i++) {
			threads[i].join();
		}
	}
}

void ThreadedGrid::workerSetPPM(PPM& ppm, const ColorTable& ct) {
	std::vector<int> task_queue;
	int col;
	int row;
	while (!mTasks.empty()) {
		task_queue.clear();
		mTasks.pop_back(task_queue,1);
		if (task_queue.size() > 0) {
			row = task_queue[0];
			for (col = 0; col < mWidth; col++) {
                if (getNumber(row, col) == getMaxNumber()) {
                    int last_index = ct.getNumberOfColors() - 1;
                    ppm.setPixel(row, col, ct[last_index].getRed(), ct[last_index].getGreen(), ct[last_index].getBlue());
                } else {
                    int index = getNumber(row, col) % ct.getNumberOfColors();
                    ppm.setPixel(row, col, ct[index].getRed(), ct[index].getGreen(), ct[index].getBlue());
                }
			}
		}
	}
}
