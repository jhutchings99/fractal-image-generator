#include <iostream>
#include "image_menu.h"
#include <vector>

Image::Image() : mHeight(0), mWidth(0) {
    mVector.resize(mHeight * mWidth * 3);
}

Image::Image( const int& height, const int& width ) : mHeight(height), mWidth(width) {
    mVector.resize(mHeight * mWidth * 3);
}

int Image::getHeight() const {
    return mHeight;
}

int Image::getWidth() const {
    return mWidth;
}

int Image::getChannel( const int& row, const int& column, const int& channel ) const {
    if (indexValid(row, column, channel)) {
        return mVector[index(row, column, channel)];
    } else {
        return -1;
    }
}

void Image::setHeight( const int& height ) {
    if (height >= 0) {
        mHeight = height;
        mVector.resize(mHeight * mWidth * 3);
    }
}

void Image::setWidth( const int& width ) {
    if (width >= 0) {
        mWidth = width;
        mVector.resize(mWidth * mHeight * 3);
    }
}

void Image::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if (indexValid(row, column, channel)) {
        mVector[index(row, column, channel)] = value;
    }
}

int Image::index( const int& row, const int& column, const int& channel ) const {
    return (row * mWidth * 3 + column * 3) + channel;
}

bool Image::indexValid( const int& row, const int& column, const int& channel ) const {
    if (row >= mHeight) {
        return false;
    }

    if (row < 0) {
        return false;
    }

    if (column < 0) {
        return false;
    }

    if (column >= mWidth) {
        return false;
    }

    if (channel < 0) {
        return false;
    }

    if (channel > 2) {
        return false;
    }

    return true;
}