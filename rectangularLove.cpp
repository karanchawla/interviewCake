#include <iostream>
#include <vector> 

using namespace std;

class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};


class RangeOverlap
{
private:
	int startPoint_;
	int length_;

public:
	RangeOverlap():
	startPoint_(0),
	length_(0)
	{}


	RangeOverlap(int start_point, int length):
	startPoint_(start_point),
	length_(length)
	{}

	int getStartPoint() const
	{
		return startPoint_;
	}

	int getLength() const
	{
		return length_;
	}

	bool overLapExists() const
	{
		return length_ > 0;
	}

	bool operator ==(const RangeOverlap& other) const
	{
		return 
			startPoint_ == other.startPoint_ &&
			length_ == other.length_;
	}

	bool operator !=(const RangeOverlap& other) const
	{
		return !(*this==other);
	}
};


RangeOverlap findRangeOverlap(int point1, int length1, int point2, int length2)
{
	int highestStartingPoint = max(point1, point2);
	int lowestEndingPoint = min(point1+length1, point2+length2);

	if(highestStartingPoint >= lowestEndingPoint)
	{
		return RangeOverlap();
	}

	int overlapLength = lowestEndingPoint - highestStartingPoint;
	return RangeOverlap(highestStartingPoint, overlapLength);
}


Rectangle findRectangularOverlap(
        const Rectangle& rect1,
        const Rectangle& rect2)
{

    // get the x overlap points and lengths
    RangeOverlap xOverlap = findRangeOverlap(
            rect1.getLeftX(), rect1.getWidth(),
            rect2.getLeftX(), rect2.getWidth());

    // get the y overlap points and lengths
    RangeOverlap yOverlap = findRangeOverlap(
            rect1.getBottomY(), rect1.getHeight(),
            rect2.getBottomY(), rect2.getHeight());

    // if no overlap
    if (!xOverlap.overlapExists() || !yOverlap.overlapExists()) {
        return Rectangle();
    }

    return Rectangle(
        xOverlap.getStartPoint(),
        yOverlap.getStartPoint(),
        xOverlap.getLength(),
        yOverlap.getLength()
    );
}










