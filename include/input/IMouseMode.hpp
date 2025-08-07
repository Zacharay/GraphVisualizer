#pragma once


class IMouseMode {
public:
    virtual void onMouseDown(int button, double x, double y) = 0;
    virtual void onMouseUp(int button,double x,double y) = 0;
    virtual void onMouseMove(double x, double y) =0;
    virtual ~IMouseMode() = default;
};




